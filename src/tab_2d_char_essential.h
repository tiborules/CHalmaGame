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


#ifndef TAB_2D_CHAR_ESSENTIAL_H
#define TAB_2D_CHAR_ESSENTIAL_H


#include <stdlib.h>
#include <string.h>
#include "bool.h"


typedef struct tab_2d_char tab_2d_char;

/**
 * A struct that defines a 2D table of char.
 * It has a tab and the number of lines and columns.
 */
struct tab_2d_char
{
  /**
   * The content of the 2D table of char.
   * Only functions should use it.
   */
  char* tab;
  
  /**
   * The number of lines.
   */
  unsigned int nb_lines;
  
  /**
   * The number of columns.
   */
  unsigned int nb_columns;
};


/**
 * Returns true if the 2D table of char is init.
 * @param tab_2d A pointer of a 2D table of char
 * @return True if the 2D table of char is init, otherwise false.
 */
bool tab_2d_char_is_init(const tab_2d_char* tab_2d);

/**
 * Allocate unsafely (NULL pointer and size) a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 */
void tab_2d_char_alloc_unsafe(tab_2d_char* tab_2d);

/**
 * Allocate with checks a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 * @return True if a non null allocation was possible, otherwise false.
 */
bool tab_2d_char_alloc(tab_2d_char* tab_2d);

/**
 * Initialize the 2D table of char unsafely.
 * There is no check on pointers.
 * @param tab_2d A pointer of a 2D table of char
 * @param size Size of the 2D table of char
 */
void tab_2d_char_init_unsafe(tab_2d_char* tab_2d, unsigned int nb_lines, unsigned int nb_columns);

/**
 * Initialise the 2D table of char for the first time.
 * tab should be NULL.
 * @param tab_2d A pointer of a 2D table of char
 * @param size Size of the 2D table of char
 */
void tab_2d_char_init_one_time_only(tab_2d_char* tab_2d, unsigned int nb_lines, unsigned int nb_columns);

/**
 * Initialize the 2D table of char safely.
 * There are checks on pointer.
 * @param tab_2d A pointer of a 2D table of char
 * @param size Size of the 2D table of char
 */
void tab_2d_char_init(tab_2d_char* tab_2d, unsigned int nb_lines, unsigned int nb_columns);

/**
 * Create a 2D table of char.
 * @param size Size of the 2D table of char
 * @return tab_2d A 2D table of char
 */
tab_2d_char tab_2d_char_create(unsigned int nb_lines, unsigned int nb_columns);

/**
 * Destructs properly a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 */
void tab_2d_char_destruct(tab_2d_char* tab_2d);

/**
 * Returns true if a line of the 2D table of char is init.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @return True if a line of the 2D table of char exists, otherwise false
 */
bool tab_2d_char_line_exists(const tab_2d_char* tab_2d, unsigned int line);

/**
 * Returns true if a column of the 2D table of char is init.
 * @param tab_2d A pointer of a 2D table of char
 * @param column A column of the 2D table of char
 * @return True if a column of the 2D table of char exists, otherwise false
 */
bool tab_2d_char_column_exists(const tab_2d_char* tab_2d, unsigned int column);

/**
 * Returns true if an element of the 2D table of char is init.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return True if an element of the 2D table of char exists, otherwise false.
 */
bool tab_2d_char_element_exists(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the pointer of an element of a 2D table of char with no check.
 * There is no check of the existence of the tab_2d, the tab of the tab_2d, the line and the column.
 * It is useful for optimization, but seg fault and null pointer can occur.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return The pointer of the element (line, column) of the 2D table of char
 */
char* tab_2d_char_get_element_pointer_unsafe(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the pointer of an element of a 2D table of char with checks.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return The pointer of the element (line, column) of the 2D table of char
 */
char* tab_2d_char_get_element_pointer(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the value of an element of a 2D table of char with no check.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return The value of the element (line, column) of the 2D table of char
 */
char tab_2d_char_get_element_value_unsafe(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the value of an element of a 2D table of char with checks.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return The value of the element (line, column) of the 2D table of char
 */
char tab_2d_char_get_element_value(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Set the value of the element (line, column) of a 2D table of char with no check.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @param value New value of the element
 */
void tab_2d_char_set_element_value_unsafe(tab_2d_char* tab_2d, unsigned int line, unsigned int column, char value);

/**
 * Set the value of the element (line, column) of a 2D table of char with checks.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @param value New value of the element
 */
void tab_2d_char_set_element_value(tab_2d_char* tab_2d, unsigned int line, unsigned int column, char value);

/**
 * Swap value of [line1, column1] with [line2, column2] of a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 * @param line1 A first line of the 2D table of char
 * @param column1 A first column of the 2D table of char
 * @param line2 A second line of the 2D table of char
 * @param column2 A second column of the 2D table of char
 * @return succeed True if the swap goes well, otherwise false.
 */
bool tab_2d_char_swap(tab_2d_char* tab_2d, unsigned int line1, unsigned int column1, unsigned int line2, unsigned int column2);

/**
 * Fill a 2D table of char with a constant.
 * @param tab_2d A pointer of a 2D table of char
 * @param value_for_filling A value for filling
 */
void tab_2d_char_fill_with_const(tab_2d_char* tab_2d, char value_for_filling);

/**
 * Replace a character by an other one in a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 * @param value_to_replace A char value to replace
 * @param new_value A new value to replace the old one
 */
void tab_2d_char_replace(tab_2d_char* tab_2d, char value_to_replace, char new_value);

/**
 * Copy a table of 2D char in an other one.
 * @param destination A destination table 2D of char
 * @param source A source table 2D of char
 */
void tab_2d_char_copy(tab_2d_char* destination, const tab_2d_char* source);

/**
 * Returns a copy of a table 2D of char.
 * @param source A source table 2D of char
 * @return A copy of the source table 2D of char
 */
tab_2d_char tab_2d_char_get_copy(const tab_2d_char* source);

/* TODO
char * tab_2d_char_get_line_copy(tab_2d* tab, unsigned int line);
char * tab_2d_char_get_column_copy(tab_2d* tab, unsigned int column);
 */

#endif
