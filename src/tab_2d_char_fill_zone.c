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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "tab_2d_char_fill_zone.h"


void tab_2d_char_fill_part_of_line_with_char(tab_2d_char* tab_2d, size_t line, size_t begin_at_column, size_t nb_char, char character)
{
  if(tab_2d_char_line_exists(tab_2d, line))
    {
      while(begin_at_column < tab_2d->nb_columns && nb_char-- > 0)
	{
	  tab_2d_char_set_element_value_unsafe(tab_2d, line, begin_at_column++, character);
	}
    }
}

void tab_2d_char_fill_part_of_column_with_char(tab_2d_char* tab_2d, size_t column, size_t begin_at_line, size_t nb_char, char character)
{
  if(tab_2d_char_column_exists(tab_2d, column))
    {
      while(begin_at_line < tab_2d->nb_lines && nb_char-- > 0)
	{
	  tab_2d_char_set_element_value_unsafe(tab_2d, begin_at_line++, column, character);
	}
    }
}
