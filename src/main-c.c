/**
 * Copyright (C) 2014  Nicola Spanti (RyDroid) <dev@nicola-spanti.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * @author Nicola Spanti (RyDroid)
 */


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "stdio_functions.h"
#include "tab_2d_char_io.h"
#include "tab_2d_char_file.h"
#include "halma_game_board.h"

#define USER_ANSWER_LENGTH_MAX 255


void print_help()
{
  puts("h|help -- Print memo of commands.");
  puts("q|quit|k|kill|exit -- Quit the program.");
  puts("new|start|begin -- Start a new Halma game party.");
  puts("l|load -- Load a game board.");
  puts("n|next -- Compute next turn of the Halma game on the current board.");
  puts("p|print|display|view -- Print the game board.");
  puts("nb_turns -- Print the current turn number.");
  puts("grid_size -- Print the size of the grid.");
  puts("nb_lines -- Print the number of lines.");
  puts("nb_columns -- Print the number of columns.");
  puts("print_players -- Print the players.");
  puts("debug_status -- Print the status of debugging.");
  puts("debug_on -- Put debug on.");
  puts("debug_off -- Put debug off.");
}

/**
 * Ask information to the user with text in order to load a universe.
 * @param universe A future universe
 * @return succeeded True if a universe is loaded, otherwise false
 */
bool ask_load_game_board(tab_2d_char* game_board)
{
  if(game_board == NULL)
    {
      fprintf(stderr, "ask_load_game_board => game_board == NULL\n");
      return false;
    }
  
  tab_2d_char_destruct(game_board);
  
  printf("File path of the game board to load: ");
  char file_path[2000];
  fgets(file_path, 2000, stdin);
  if(isspace(file_path[strlen(file_path)-1]) || iscntrl(file_path[strlen(file_path)-1]))
    file_path[strlen(file_path)-1] = '\0';
    
  if(strlen(file_path) == 0)
    tab_2d_char_scan_stdin(game_board);
  else
    tab_2d_char_get_from_file_path(game_board, file_path);
  
  return true;
}

int main(int argc, char* argv[])
{
  bool debug = false;
  bool error_for_empty_command = false;
  
  if(argc > 1)
    {
      if(string_equals(argv[1], "-h") || string_equals(argv[1], "--help") || string_equals(argv[1], "--aide"))
	{
	  puts("A free/libre Halma game");
	  print_help();
	  return EXIT_SUCCESS;
	}
      if(string_equals(argv[1], "--license") || string_equals(argv[1], "--licence") || string_equals(argv[1], "--copyright"))
	{
	  puts("This program is under GNU Lesser General Public License 3 as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.");
	  return EXIT_SUCCESS;
	}
      if(string_equals(argv[1], "--author") || string_equals(argv[1], "--auteur"))
	{
	  puts("The author of this program is Nicola Spanti, also known as RyDroid.");
	  return EXIT_SUCCESS;
	}
      if(string_equals(argv[1], "-g") || string_equals(argv[1], "--debug"))
	debug = true;
    }
  
  
  /*unsigned int number_of_lines, number_of_columns;
  printf("Number of lines : ");
  scanf("%u", &number_of_lines);
  printf("Number of columns : ");
  scanf("%u", &number_of_columns);
  
  tab_2d_char game_board = tab_2d_char_create(number_of_lines, number_of_columns);
  tab_2d_char_print_stdout_without_grid(&square);
  TODO Generate randomly*/
  
  puts("A free/libre Halma game");
  puts("Use 'help' command if you need it.");
  puts("");
  
  tab_2d_char game_board = tab_2d_char_create(0, 0);
  halma_game_players players = halma_game_players_create(0);
  char user_answer[USER_ANSWER_LENGTH_MAX] = "";
  unsigned int nb_turns = 0;
  
  while(true)
    {
      fputs("Command: ", stdout);
      fgets_trimmed(user_answer, USER_ANSWER_LENGTH_MAX, stdin);

      
      if(string_equals(user_answer, "h") || string_equals(user_answer, "help") || string_equals(user_answer, "commands") || string_equals(user_answer, "aide"))
	{
	  print_help();
	}
      else if
	(
	      string_equals(user_answer, "q") ||
	      string_equals(user_answer, "quit") ||
	      string_equals(user_answer, "k") ||
	      string_equals(user_answer, "kill") ||
	      string_equals(user_answer, "exit") ||
	      string_equals(user_answer, "close") ||
	      string_equals(user_answer, "over") ||
	      string_equals(user_answer, "good bye")
	 )
	{
	  tab_2d_char_destruct(&game_board);
	  halma_game_players_destruct(&players);
	  return EXIT_SUCCESS;
	}
      else if(string_equals(user_answer, "start") || string_equals(user_answer, "begin") || string_equals(user_answer, "new") || string_equals(user_answer, "new_game"))
	{
	  nb_turns = 0;
	  
	  halma_game_players_destruct(&players);
	  while(!halma_game_players_init(&players, players.nb))
	    {
	      printf("Number of players must be between %u and %u.\n", HALMA_GAME_NB_PLAYERS_MIN, HALMA_GAME_NB_PLAYERS_MAX);
	      players.nb = ask_uint_tirelessly("Number of players: ", NULL);
	    }
	  
	  {
	    unsigned int nb_non_bots = players.nb;
	    
	    while(nb_non_bots >= players.nb)
	      nb_non_bots = ask_uint_tirelessly("Number of non bot players: ", NULL);
	    
	    for(unsigned int i=0; i < players.nb; ++i)
	      {
		if(i < nb_non_bots)
		  {
		    do
		      {
			printf("Name of player %u: ", i);
			fgets_trimmed(user_answer, USER_ANSWER_LENGTH_MAX, stdin);
		      }
		    while(!halma_game_player_set_name(&players.tab[i], user_answer));
		    --nb_non_bots;
		  }
		else
		  {
		    sprintf(user_answer, "Bot %u", i);
		    halma_game_player_set_name(&players.tab[i], user_answer); /* TODO verif pas 2 fois meme name */
		  }
	      }
	  }
	  
	  if(!halma_game_players_set_char_pawns_with_numbers(&players))
	    {
	      unsigned int i=0;
	      while(i < players.nb)
		{
		  printf("Choose a pawn character for player %u: ", i);
		  fgets_trimmed(user_answer, USER_ANSWER_LENGTH_MAX, stdin);
		  if(halma_game_players_set_player_char_pawn(&players, i, *user_answer))
		    ++i;
		  else
		    fprintf(stderr, "The character '%c' is not authorized for this player.\n", *user_answer);
		}
	    }
	  
	  tab_2d_char_destruct(&game_board);
	  game_board.nb_lines = 16;
	  game_board.nb_columns = 16;
	  if(!halma_game_board_construct_for_new_party(&game_board, &players))
	    fprintf(stderr, "The game board was not successfully created. :(\n");
	}
      else if(string_equals(user_answer, "l") || string_equals(user_answer, "load"))
	{
	  if(ask_load_game_board(&game_board))
	    nb_turns = 0;
	  else
	    game_board.tab = NULL;
	}
      else if(string_equals(user_answer, "c") || string_equals(user_answer, "continue") || string_equals(user_answer, "n") || string_equals(user_answer, "next"))
	{
	  if(tab_2d_char_is_init(&game_board))
	    {
	      unsigned int line_pawn, column_pawn, line_mark, column_mark;
	      bool moved = false;
	      while(!moved)
		{
		  puts("Choose a pawn to move:");
		  line_pawn = ask_uint_tirelessly("* Line: ", NULL);
		  column_pawn = ask_uint_tirelessly("* Column: ", NULL);
		  
		  if(halma_is_pawn(&game_board, line_pawn, column_pawn))
		    {
		      halma_mark_possible_moves_of_a_cell(&game_board, line_pawn, column_pawn);
		      if(halma_is_there_at_least_one_mark(&game_board))
			{
			  printf("Possible moves are marked with '%c'\n", HALMA_GAME_CELL_MARK);
			  tab_2d_char_print_stdout_without_grid(&game_board);
			  puts("Choose a destination cell:");
			  line_mark = ask_uint_tirelessly("* Line: ", NULL);
			  column_mark = ask_uint_tirelessly("* Column: ", NULL);
			  
			  if(halma_pawn_move(&game_board, line_pawn, column_pawn, line_mark, column_mark))
			    {
			      moved = true;
			    }
			  else
			    {
			      if(tab_2d_char_element_exists(&game_board, line_mark, column_mark))
				fprintf(stderr, "The move did not succeed.\n");
			      else
				fprintf(stderr, "The cell [%u, %u] does not exist.\n", line_mark, column_mark);
			    }
			}
		      else
			{
			  if(tab_2d_char_element_exists(&game_board, line_pawn, column_pawn))
			    fprintf(stderr, "The pawn [%u, %u] can not move.\n", line_pawn, column_pawn);
			  else
			    fprintf(stderr, "The cell [%u, %u] does not exist.\n", line_pawn, column_pawn);
			}
		    }
		  else
		    {
		      fprintf(stderr, "The [%u, %u] is not a pawn.\n", line_pawn, column_pawn);
		    }
		}
	      ++nb_turns;
	      
	      if(debug)
		{
		  char file_path[6 + 1 + nb_turns / 1];
		  sprintf(file_path, "debug-%u", nb_turns);
		  tab_2d_char_save_to_file_path(&game_board, file_path);
		}

	      /*if(halma_game_is_game_board_over(&game_board))
		{
		  user_answer[0] = 'o';
		  user_answer[1] = 'v';
		  user_answer[2] = 'e';
		  user_answer[3] = 'r';
		  user_answer[4] = '\0';
		  }*/
	    }
	  else
	    fprintf(stderr, "There is no game board. :(\n");
	}
      else if(string_equals(user_answer, "p") || string_equals(user_answer, "print") || string_equals(user_answer, "display") || string_equals(user_answer, "view"))
	{
	    tab_2d_char_print_stdout_without_grid(&game_board);
	}
      else if(string_equals(user_answer, "nb_turns"))
	{
	  printf("Turn %u\n", nb_turns);
	}
      else if(string_equals(user_answer, "grid_size"))
	{
	  printf("%u", game_board.nb_lines);
	  fputs(" line", stdout);
	  if(game_board.nb_lines > 1)
	    fputc('s', stdout);
	  fputs(" and ", stdout);
	  printf("%u", game_board.nb_columns);
	  fputs(" column", stdout);
	  if(game_board.nb_columns > 1)
	    fputc('s', stdout);
	  puts("");
	}
      else if(string_equals(user_answer, "nb_lines"))
	{
	  printf("Number of lines: %u\n", game_board.nb_lines);
	}
      else if(string_equals(user_answer, "nb_columns"))
	{
	  printf("Number of columns %u\n", game_board.nb_columns);
	}
      else if(string_equals(user_answer, "print_players"))
	{
	  if(halma_game_players_is_init(&players))
	    {
	      for(unsigned int i=0; i < players.nb; ++i)
		{
		  printf("%u. %s (name), '%c' (pawn character), %c (ready)\n", i, players.tab[i].name, players.tab[i].char_pawn, halma_game_player_is_init(&players.tab[i]) ? 'y' : 'n');
		}
	      
	      if(halma_game_players_is_correct(&players))
		 printf("Players are corrects for playing.\n");
	      else
		 printf("Players are not corrects for playing.\n");
	    }
	  else
	    {
	      printf("Players are not initialized.\n");
	    }
	}
      else if(string_equals(user_answer, "debug_status"))
	{
	  if(debug)
	    fputs("Debug enabled.", stdout);
	  else
	    fputs("Debug disabled.", stdout);
	  puts("");
	}
      else if(string_equals(user_answer, "debug_on"))
	{
	  debug = true;
	}
      else if(string_equals(user_answer, "debug_off"))
	{
	  debug = false;
	}
      else if(*user_answer == '\0')
	{
	  if(error_for_empty_command)
	    {
	      fputs("Empty command.", stderr);
	      puts("");
	    }
	}
      else
	{
	  fputs("Unknown command.", stderr);
	  puts("");
	}
    }
}
