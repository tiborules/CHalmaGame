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

#include "bool.h"
#include "stdio_functions.h"
#include "string_functions.h"
#include "tab_2d_char_io.h"
#include "tab_2d_char_file.h"
#include "conway_game_of_life.h"

#define USER_ANSWER_LENGTH_MAX 255


void print_help()
{
  puts("help Print memo of commands.");
  puts("quit Quit the program.");
  puts("load Load a universe.");
  puts("next Compute next turn of the universe.");
  puts("nb_turns Print the current turn number.");
  puts("grid_size Print the size of the grid.");
  puts("nb_lines Print the number of lines.");
  puts("nb_columns Print the number of columns.");
  puts("debug_status Print the status of debugging.");
  puts("debug_on Put debug on.");
  puts("debug_on Put debug off.");
}

/**
 * Ask information to the user with text in order to load a universe.
 * @param universe A future universe
 * @return succeeded True if a universe is loaded, otherwise false
 */
bool ask_load_universe(tab_2d_char* universe)
{
  if(universe == NULL)
    {
      fprintf(stderr, "ask_load_universe => universe == NULL\n");
      return false;
    }
  
  tab_2d_char_destruct(universe);
  
  {
    printf("File path of the universe to load: ");
    char file_path[2000];
    fgets(file_path, 2000, stdin);
    if(isspace(file_path[strlen(file_path)-1]) || iscntrl(file_path[strlen(file_path)-1]))
      file_path[strlen(file_path)-1] = '\0';
    
    if(strlen(file_path) == 0)
      tab_2d_char_scan_stdin(universe);
    else
      tab_2d_char_get_from_file_path(universe, file_path);
  }
  
  return true;
}

int main(int argc, char* argv[])
{
  bool debug = false;
  
  if(argc > 1)
    {
      if(string_equals(argv[1], "-h") || string_equals(argv[1], "--help") || string_equals(argv[1], "--aide"))
	{
	  puts("A free/libre Conway's Game of Life");
	  print_help();
	  return EXIT_SUCCESS;
	}
      if(string_equals(argv[1], "--license") || string_equals(argv[1], "--licence"))
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
  
  tab_2d_char universe = tab_2d_char_create(number_of_lines, number_of_columns);
  tab_2d_char_print_stdout_without_grid(&square);
  TODO Generate randomly*/
  
  puts("A free/libre Conway's Game of Life");
  puts("Use 'help' command if you need it.");
  puts("");
  
  tab_2d_char universe = tab_2d_char_create(0, 0);
  char user_answer[USER_ANSWER_LENGTH_MAX] = "";
  unsigned int nb_turns = 0;
  
  while(true)
    {
      //flush_stdin();
      fputs("Command: ", stdout);
      fgets(user_answer, USER_ANSWER_LENGTH_MAX, stdin);
      if(isspace(user_answer[strlen(user_answer)-1]) || iscntrl(user_answer[strlen(user_answer)-1]))
	user_answer[strlen(user_answer)-1] = '\0';
      string_trim(user_answer, ' ');
      string_tolower(user_answer);

      
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
	  tab_2d_char_destruct(&universe);
	  return EXIT_SUCCESS;
	}
      else if(string_equals(user_answer, "l") || string_equals(user_answer, "load"))
	{
	  if(ask_load_universe(&universe))
	    nb_turns = 0;
	  else
	    universe.tab = NULL;
	}
      else if(string_equals(user_answer, "c") || string_equals(user_answer, "continue") || string_equals(user_answer, "n") || string_equals(user_answer, "next"))
	{
	  if(tab_2d_char_is_init(&universe))
	    {
	      universe = conway_game_of_life_get_next_turn(&universe);
	      ++nb_turns;
      
	      if(debug)
		{
		  char file_path[6 + 1 + nb_turns / 1];
		  sprintf(file_path, "debug-%u", nb_turns);
		  tab_2d_char_save_to_file_path(&universe, file_path);
		}

	      if(conway_game_of_life_is_universe_over(&universe))
		{
		  user_answer[0] = 'o';
		  user_answer[1] = 'v';
		  user_answer[2] = 'e';
		  user_answer[3] = 'r';
		  user_answer[4] = '\0';
		}
	    }
	  else
	    fprintf(stderr, "There is no universe. :(\n");
	}
      else if(string_equals(user_answer, "p") || string_equals(user_answer, "print") || string_equals(user_answer, "display"))
	{
	    tab_2d_char_print_stdout_without_grid(&universe);
	}
      else if(string_equals(user_answer, "nb_turns"))
	{
	  printf("Turn %u\n", nb_turns);
	}
      else if(string_equals(user_answer, "grid_size"))
	{
	  printf("%u", universe.nb_lines);
	  fputs(" line", stdout);
	  if(universe.nb_lines > 1)
	    fputc('s', stdout);
	  fputs(" and ", stdout);
	  printf("%u", universe.nb_columns);
	  fputs(" column", stdout);
	  if(universe.nb_columns > 1)
	    fputc('s', stdout);
	  puts("");
	}
      else if(string_equals(user_answer, "nb_lines"))
	{
	  printf("Number of lines: %u\n", universe.nb_lines);
	}
      else if(string_equals(user_answer, "nb_columns"))
	{
	  printf("Number of columns %u\n", universe.nb_columns);
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
	  fputs("Empty command.", stderr);
	  puts("");
	}
      else
	{
	  fputs("Unknown command.", stderr);
	  puts("");
	}
    }
}
