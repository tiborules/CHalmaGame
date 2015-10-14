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


#ifndef TAB_2D_CHAR_PRINT_H
#define TAB_2D_CHAR_PRINT_H


#include <stdio.h>
#include "tab_2d_char_essential.h"


/**
 * Print a 2D table of char not in a grid to a stream.
 * @param stream A stream
 * @param tab_2d A pointer of a 2D table of char
 */
void tab_2d_char_print_stream_without_grid(const tab_2d_char* tab_2d, FILE * stream);

/**
 * Print a 2D table of char not in a grid to stdout.
 * @param tab_2d A pointer of a 2D table of char
 */
static inline void tab_2d_char_print_stdout_without_grid(const tab_2d_char* tab_2d)
{
  tab_2d_char_print_stream_without_grid(tab_2d, stdout);
}


#endif
