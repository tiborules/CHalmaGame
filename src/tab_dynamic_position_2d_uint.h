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


#ifndef TAB_DYNAMIC_POSITION_2D_UINT_H
#define TAB_DYNAMIC_POSITION_2D_UINT_H


#include <stdio.h>
#include <stdlib.h>
#include "position_2d_uint.h"


typedef struct tab_dynamic_position_2d_uint tab_dynamic_position_2d_uint;

/**
 * A structure of table of 2D positions of unsigned int.
 */
struct tab_dynamic_position_2d_uint
{
  /**
   * A table of 2D positions of unsigned int.
   */
  position_2d_uint* tab;

  /**
   * Number of 2D positions of unsigned int.
   */
  size_t nb;
};


/**
 * Allocate a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 - @return True if it succeeded, otherwise false
 */
bool tab_dynamic_position_2d_uint_alloc(tab_dynamic_position_2d_uint* tab);

/**
 * Destruct a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 */
void tab_dynamic_position_2d_uint_destruct(tab_dynamic_position_2d_uint* tab);

/**
 * Create and return a structure of table of 2D positions of unsigned int.
 * @param nb_elements Number of elements of the table
 * @return A structure of table of 2D positions of unsigned int
 */
tab_dynamic_position_2d_uint tab_dynamic_position_2d_uint_create(size_t nb_elements);

/**
 * Return true if a structure of table of 2D positions of unsigned int is initiliazed, otherwise false.
 * @param tab A structure of table of 2D positions of unsigned int
 * @return True if a structure of table of 2D positions of unsigned int is initiliazed, otherwise false
 */
bool tab_dynamic_position_2d_uint_is_init(const tab_dynamic_position_2d_uint* tab);

/**
 * Return the index of an element of a table of 2D positions if it exists.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param position Position to search
 * @return Index of the searched element or an equal or greater value than the tab size
 */
size_t tab_dynamic_position_2d_uint_index_of(const tab_dynamic_position_2d_uint* tab, const position_2d_uint* position_2d_uint);

/**
 * Swap 2 elements of a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param index1 An index
 * @param index2 An other index
 * @return True if a structure of table of 2D positions of unsigned int is initiliazed, otherwise false
 */
bool tab_dynamic_position_2d_uint_swap(tab_dynamic_position_2d_uint* tab, size_t index1, size_t index2);

/**
 * Remove an index of a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param index Index element to remove
 * @return True if the index is removed, otherwise false
 */
bool tab_dynamic_position_2d_uint_remove_index(tab_dynamic_position_2d_uint* tab, size_t index);

/**
 * Remove an element of a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param element An element to remove
 * @return True if the element is removed, otherwise false
 */
bool tab_dynamic_position_2d_uint_remove_element(tab_dynamic_position_2d_uint* tab, const position_2d_uint* element);

/**
 * Add an element to a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param element An element to add
 */
void tab_dynamic_position_2d_uint_add(tab_dynamic_position_2d_uint* tab, const position_2d_uint* element);

/**
 * Add an element to a structure of table of 2D positions of unsigned int if this element is not already in.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param element An element to add
 * @return True if the element is added, otherwise false
 */
void tab_dynamic_position_2d_uint_add_if_not_in(tab_dynamic_position_2d_uint* tab, const position_2d_uint* element);

/**
 * Print a table of 2D positions of unsigned int in a stream.
 * @param tab A table of 2D positions of unsigned int
 * @param stream A stream to print
 */
void tab_position_2d_uint_print_default(const position_2d_uint* tab, size_t nb_elements, FILE* stream);

/**
 * Print a structure of table of 2D positions of unsigned int in a stream.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param stream A stream to print
 */
void tab_dynamic_position_2d_uint_print_default(const tab_dynamic_position_2d_uint* tab, FILE* stream);


#endif
