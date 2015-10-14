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


#ifndef TAB_2D_CHAR_FILE_H
#define TAB_2D_CHAR_FILE_H

#include "tab_2d_char_print.h"


/**
 * Parse a stream file to fill a 2D table of char
 * @param tab_2d A 2D table of char filled by parsing the file
 * @param file A file stream
 */
void tab_2d_char_get_from_file(tab_2d_char* tab_2d, FILE* file);

/**
 * Parse a file with its path to fill a 2D table of char
 * @param tab_2d A 2D table of char filled by parsing the file
 * @param file_path A file path
 */
void tab_2d_char_get_from_file_path(tab_2d_char* tab_2d, const char* file_path);

/**
 * Put in a stream the content of a 2D table of char
 * @param tab_2d A 2D table of char to put in a file
 * @param file A file stream
 */
void tab_2d_char_save_to_file(const tab_2d_char* tab_2d, FILE* file);

/**
 * Put in a file with its path the content of a 2D table of char
 * @param tab_2d A 2D table of char to put in a file
 * @param file_path A file path
 */
void tab_2d_char_save_to_file_path(const tab_2d_char* tab_2d, const char* file_path);

#endif
