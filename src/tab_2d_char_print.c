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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * @author Spanti Nicola (RyDroid)
 */


#include "tab_2d_char_print.h"


void tab_2d_char_print_stream_without_grid(const tab_2d_char* tab_2d, FILE * stream)
{
  if(tab_2d != NULL && tab_2d->tab != NULL)
    {
      for(size_t line=0, column; line < tab_2d->nb_lines; ++line)
	{
	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      fputc(tab_2d_char_get_element_value_unsafe(tab_2d, line, column), stream);
	    }
	  fprintf(stream, "\n");
	}
    }
}
