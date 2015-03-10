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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef TAB_2D_CHAR_SCAN_H
#define TAB_2D_CHAR_SCAN_H


#include "tab_2d_char_essential.h"
#include "stdio_functions.h"


/**
 * Ask values of a 2D table with stdin.
 * @param tab_2d A pointer of a 2D table of char
 */
void tab_2d_char_scan_stdin_table(tab_2d_char* tab_2d);

/**
 * Ask size and values of a 2D table with stdin.
 * @param tab_2d A pointer of a 2D table of char
 */
void tab_2d_char_scan_stdin(tab_2d_char* tab_2d);


#endif
