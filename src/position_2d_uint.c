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


#include "position_2d_uint.h"


void position_2d_uint_swap(position_2d_uint* position)
{
  if(position != NULL)
    {
      unsigned int tmp = position->line;
      position->line = position->column;
      position->column = tmp;
    }
}

bool position_2d_uint_equals(const position_2d_uint* position1, const position_2d_uint* position2)
{
  return
    position1 != NULL && position2 != NULL &&
    position1->first == position2->first && position1->second == position2->second;
}

void position_2d_uint_print(const position_2d_uint* position, FILE* stream, const char* delimiter_start, const char* separator, const char* delimiter_end)
{
  if(position != NULL && stream != NULL && delimiter_start != NULL && separator != NULL && delimiter_end != NULL)
    {
      fprintf(stream, "%s%u%s%u%s", delimiter_start, position->line, separator, position->column, delimiter_end);
    }
}

void position_2d_uint_print_default(const position_2d_uint* position, FILE* stream)
{
  position_2d_uint_print(position, stream, "[", ",", "]");
}
