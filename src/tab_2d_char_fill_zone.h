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


#ifndef TAB_2D_CHAR_FILL_ZONE_H
#define TAB_2D_CHAR_FILL_ZONE_H


#include "tab_2d_char_essential.h"


/**
 * Fill partly a line starting at a specified column with a character.
 * @param tab_2d A 2D table of characters
 * @param line A line to fill partly
 * @param begin_at_column Column to start filling
 * @param nb_char Number of characters to fill starting at begin_at_column
 * @param character A character for filling
 */
void tab_2d_char_fill_part_of_line_with_char(tab_2d_char* tab_2d, size_t line, size_t begin_at_column, size_t nb_char, char character);

/**
 * Fill partly a column starting at a specified line with a character.
 * @param tab_2d A 2D table of characters
 * @param column A column to fill partly
 * @param begin_at_line Line to start filling
 * @param nb_char Number of characters to fill starting at begin_at_line
 * @param character A character for filling
 */
void tab_2d_char_fill_part_of_column_with_char(tab_2d_char* tab_2d, size_t column, size_t begin_at_line, size_t nb_char, char character);


#endif
