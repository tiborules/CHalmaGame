/**
 * Copyright (C) 2014  Spanti Nicola (RyDroid) <rydroid_dev@yahoo.com>
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Spanti Nicola (RyDroid)
 */


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "stdio_functions.h"
#include "tab_2d_char_io.h"
#include "tab_2d_char_file.h"
#include "halma_game_essential.h"

#define USER_ANSWER_LENGTH_MAX 255


void print_help()
{
  printf("h|help -- Print memo of commands.\n");
  printf("q|quit|k|kill|exit -- Quit the program.\n");
  printf("l|load -- Load a board game.\n");
  printf("n|next -- Compute next turn of the Halma game on the current board.\n");
  printf("p|print|display -- Print the board game.\n");
  printf("nb_turns -- Print the current turn number.\n");
  printf("grid_size -- Print the size of the grid.\n");
  printf("nb_lines -- Print the number of lines.\n");
  printf("nb_columns -- Print the number of columns.\n");
  printf("debug_status -- Print the status of debugging.\n");
  printf("debug_on -- Put debug on.\n");
  printf("debug_off -- Put debug off.\n");
}

/**
 * Ask information to the user with text in order to load a universe.
 * @param universe A future universe
 * @return succeeded True if a universe is loaded, otherwise false
 */
bool ask_load_board_game(tab_2d_char* board_game)
{
  if(board_game == NULL)
    {
      fprintf(stderr, "ask_load_board_game => board_game == NULL\n");
      return false;
    }
  
  tab_2d_char_destruct(board_game);
  
  printf("File path of the board game to load: ");
  char file_path[2000];
  fgets(file_path, 2000, stdin);
  if(isspace(file_path[strlen(file_path)-1]) || iscntrl(file_path[strlen(file_path)-1]))
    file_path[strlen(file_path)-1] = '\0';
    
  if(strlen(file_path) == 0)
    tab_2d_char_scan_stdin(board_game);
  else
    tab_2d_char_get_from_file_path(board_game, file_path);
  
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
	  puts("The author of this program is Spanti Nicola, also known as RyDroid.");
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
  
  tab_2d_char board_game = tab_2d_char_create(number_of_lines, number_of_columns);
  tab_2d_char_print_stdout_without_grid(&square);
  TODO Generate randomly*/
  
  puts("A free/libre Halma game");
  puts("Use 'help' command if you need it.");
  puts("");
  
  tab_2d_char board_game = tab_2d_char_create(0, 0);
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
	  tab_2d_char_destruct(&board_game);
	  return EXIT_SUCCESS;
	}
      else if(string_equals(user_answer, "l") || string_equals(user_answer, "load"))
	{
	  if(ask_load_board_game(&board_game))
	    nb_turns = 0;
	  else
	    board_game.tab = NULL;
	}
      else if(string_equals(user_answer, "c") || string_equals(user_answer, "continue") || string_equals(user_answer, "n") || string_equals(user_answer, "next"))
	{
	  if(tab_2d_char_is_init(&board_game))
	    {
	      unsigned int line_pawn, column_pawn, line_mark, column_mark;
	      bool moved = false;
	      while(!moved)
		{
		  puts("Choose a pawn to move:");
		  line_pawn = ask_uint_tirelessly("* Line: ", NULL);
		  column_pawn = ask_uint_tirelessly("* Column: ", NULL);
		  
		  if(halma_is_pawn(&board_game, line_pawn, column_pawn))
		    {
		      halma_mark_possible_moves_of_a_cell(&board_game, line_pawn, column_pawn);
		      if(halma_is_there_at_least_one_mark(&board_game))
			{
			  printf("Possible moves are marked with '%c'\n", HALMA_GAME_CELL_MARK);
			  tab_2d_char_print_stdout_without_grid(&board_game);
			  puts("Choose a destination cell:");
			  line_mark = ask_uint_tirelessly("* Line: ", NULL);
			  column_mark = ask_uint_tirelessly("* Column: ", NULL);
			  
			  if(halma_pawn_move(&board_game, line_pawn, column_pawn, line_mark, column_mark))
			    {
			      moved = true;
			    }
			  else
			    {
			      if(tab_2d_char_element_exists(&board_game, line_mark, column_mark))
				fprintf(stderr, "The move did not succeed.\n");
			      else
				fprintf(stderr, "The cell [%u, %u] does not exist.\n", line_mark, column_mark);
			    }
			}
		      else
			{
			  if(tab_2d_char_element_exists(&board_game, line_pawn, column_pawn))
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
		  tab_2d_char_save_to_file_path(&board_game, file_path);
		}

	      /*if(halma_game_is_board_game_over(&board_game))
		{
		  user_answer[0] = 'o';
		  user_answer[1] = 'v';
		  user_answer[2] = 'e';
		  user_answer[3] = 'r';
		  user_answer[4] = '\0';
		  }*/
	    }
	  else
	    fprintf(stderr, "There is no board game. :(\n");
	}
      else if(string_equals(user_answer, "p") || string_equals(user_answer, "print") || string_equals(user_answer, "display"))
	{
	    tab_2d_char_print_stdout_without_grid(&board_game);
	}
      else if(string_equals(user_answer, "nb_turns"))
	{
	  printf("Turn %u\n", nb_turns);
	}
      else if(string_equals(user_answer, "grid_size"))
	{
	  printf("%u", board_game.nb_lines);
	  fputs(" line", stdout);
	  if(board_game.nb_lines > 1)
	    fputc('s', stdout);
	  fputs(" and ", stdout);
	  printf("%u", board_game.nb_columns);
	  fputs(" column", stdout);
	  if(board_game.nb_columns > 1)
	    fputc('s', stdout);
	  puts("");
	}
      else if(string_equals(user_answer, "nb_lines"))
	{
	  printf("Number of lines: %u\n", board_game.nb_lines);
	}
      else if(string_equals(user_answer, "nb_columns"))
	{
	  printf("Number of columns %u\n", board_game.nb_columns);
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
