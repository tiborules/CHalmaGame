/**
 * @file
 * 
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


#ifndef POSITION_2D_UINT_H
#define POSITION_2D_UINT_H


#include <stdio.h>


typedef struct position_2d_uint position_2d_uint;

/**
 * A 2D position of unsigned int.
 */
struct position_2d_uint
{
  unsigned int line;
  unsigned int column;
};

/**
 * Swap the line and the column of a position 2D of unsigned int.
 * @param position A 2D position of unsigned int
 */
void position_2d_uint_swap(position_2d_uint* position);

/**
 * Return true if 2 2D positions of unsigned int are equal, otherwise false.
 * @param position1 A first position
 * @param position2 A second position
 * @return True if 2 2D positions of unsigned int are equal, otherwise false
 */
bool position_2d_uint_equals(const position_2d_uint* position1, const position_2d_uint* position2);

/**
 * Print a 2D position of unsigned int with line first and column second.
 * @param position A 2D position of unsigned int
 * @param stream A stream to print
 * @param delimiter_start A delimiter before the line number
 * @param separator A separator bewteen line and column
 * @param delimiter_end A delimiter after the column number
 */
void position_2d_uint_print(const position_2d_uint* position, FILE* stream, const char* delimiter_start, const char* separator, const char* delimiter_end);

/**
 * Print a 2D position of unsigned int with default delimiters and with line first and column second.
 * @param position A 2D position of unsigned int
 * @param stream A stream to print
 */
void position_2d_uint_print_default(const position_2d_uint* position, FILE* stream);

#endif
