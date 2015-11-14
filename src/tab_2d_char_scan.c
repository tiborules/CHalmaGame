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


#include "tab_2d_char_scan.h"


void tab_2d_char_scan_stdin_table(tab_2d_char* tab_2d)
{
  if(tab_2d_char_is_init(tab_2d))
    {
      for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
	{
	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      printf("tab_2d[line=%u][column=%u] = ", line, column);
	      flush_stdin();
	      scanf("%c", tab_2d_char_get_element_pointer_unsafe(tab_2d, line, column));
	    }
	}
    }
}

void tab_2d_char_scan_stdin(tab_2d_char* tab_2d)
{
  if(tab_2d != NULL)
    {
      printf("Number of lines: ");
      scanf("%u", &(tab_2d->nb_lines));
      printf("Number of columns: ");
      scanf("%u", &(tab_2d->nb_columns));
      tab_2d_char_init(tab_2d, tab_2d->nb_lines, tab_2d->nb_columns);
      tab_2d_char_scan_stdin_table(tab_2d);
    }
}
