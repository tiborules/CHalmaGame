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


#include "position_2d_uint_pair.h"


void position_2d_uint_pair_swap(position_2d_uint_pair* pair)
{
  if(pair != NULL)
    {
      position_2d_uint tmp = pair->first;
      pair->first = pair->second;
      pair->second = tmp;
    }
}

void position_2d_uint_pair_print_default(const position_2d_uint_pair* pair, FILE* stream)
{
  fputc('[', stream);
  position_2d_uint_print_default(&pair->first, stream);
  fputc(',', stream);
  position_2d_uint_print_default(&pair->second, stream);
  fputc(']', stream);
}
