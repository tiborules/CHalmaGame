/**
 * @section license License
 * 
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
 */


#include "tab_2d_char_file.h"


void tab_2d_char_get_from_file(tab_2d_char* tab_2d, FILE* file)
{
  if(tab_2d != NULL)
    {
      if(file != NULL)
	{
	  fscanf(file, "%u %u\n", &(tab_2d->nb_lines), &(tab_2d->nb_columns));
	  tab_2d_char_init(tab_2d, tab_2d->nb_lines, tab_2d->nb_columns);
      
	  for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
	    {
	      for(column=0; column < tab_2d->nb_columns; ++column)
		{
		  fscanf(file, "%c", tab_2d_char_get_element_pointer(tab_2d, line, column));
		  if (tab_2d_char_get_element_value(tab_2d, line, column) == '\n')
		    {
		      fscanf(file, "%c", tab_2d_char_get_element_pointer(tab_2d, line, column));
		    }
		}
	    }
	}
      else
	{
	  tab_2d->tab = NULL;
	  tab_2d->nb_lines = tab_2d->nb_columns = 0;
	}
    }
}

void tab_2d_char_get_from_file_path(tab_2d_char* tab_2d, const char* file_path)
{
  FILE* file = fopen(file_path, "r");
  if(file != NULL)
    {
      tab_2d_char_get_from_file(tab_2d, file);
      fclose(file);
    }
}

void tab_2d_char_save_to_file(const tab_2d_char* tab_2d, FILE* file)
{
  fprintf(file, "%u %u", tab_2d->nb_lines, tab_2d->nb_columns);
  tab_2d_char_print_stream_without_grid(tab_2d, file);
}

void tab_2d_char_save_to_file_path(const tab_2d_char* tab_2d, const char* file_path)
{
  FILE* file = fopen(file_path, "w");
  if(file != NULL)
    {
      tab_2d_char_save_to_file(tab_2d, file);
      fclose(file);
    }
}
