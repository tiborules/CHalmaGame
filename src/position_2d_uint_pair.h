/**
 * @file
 * 
 * @section license License
 * 
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
 */


#ifndef POSITION_2D_UINT_PAIR_H
#define POSITION_2D_UINT_PAIR_H

#include "position_2d_uint.h"


typedef struct position_2d_uint_pair position_2d_uint_pair;

/**
 * A pair of position_2d_uint.
 * It is the same thing as std::pair of C++.
 */
struct position_2d_uint_pair
{
  position_2d_uint first;
  position_2d_uint second;
};


/**
 * Swap the first and second of a pair of position_2d_uint.
 * @param position A pair of position_2d_uint
 */
void position_2d_uint_pair_swap(position_2d_uint_pair* pair);

/**
 * Print a pair of 2D position of unsigned int with default delimiters.
 * @param position A 2D position of unsigned int
 * @param stream A stream to print
 */
void position_2d_uint_pair_print_default(const position_2d_uint_pair* pair, FILE* stream);

#endif
