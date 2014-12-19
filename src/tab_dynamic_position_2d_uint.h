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
bool tab_dynamic_position_2d_uint_alloc(tab_dynamic_position_2d_uint* tab)
{
  if(tab != NULL && tab->nb > 0)
    {
      if(tab->tab != NULL)
	free(tab->tab);
      tab->tab = (position_2d_uint*) malloc(tab->nb * sizeof(position_2d_uint));
      return true;
    }
  return false;
}

/**
 * Destruct a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 */
void tab_dynamic_position_2d_uint_destruct(tab_dynamic_position_2d_uint* tab)
{
  if(tab->tab != NULL)
    {
      free(tab->tab);
      tab->tab = NULL;
    }
  tab->nb = 0;
}

/**
 * Create and return a structure of table of 2D positions of unsigned int.
 * @param nb_elements Number of elements of the table
 * @return A structure of table of 2D positions of unsigned int
 */
tab_dynamic_position_2d_uint tab_dynamic_position_2d_uint_create(size_t nb_elements)
{
  tab_dynamic_position_2d_uint tab;
  tab.nb = nb_elements;
  tab_dynamic_position_2d_uint_alloc(&tab);
  return tab;
}

/**
 * Return true if a structure of table of 2D positions of unsigned int is initiliazed, otherwise false.
 * @param tab A structure of table of 2D positions of unsigned int
 * @return True if a structure of table of 2D positions of unsigned int is initiliazed, otherwise false
 */
bool tab_dynamic_position_2d_uint_is_init(const tab_dynamic_position_2d_uint* tab)
{
  return tab != NULL && tab->tab != NULL && tab->nb != 0;
}

/**
 * Return the index of an element of a table of 2D positions if it exists.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param position Position to search
 * @return Index of the searched element or an equal or greater value than the tab size
 */
size_t tab_dynamic_position_2d_uint_index_of(const tab_dynamic_position_2d_uint* tab, const position_2d_uint* position_2d_uint)
{
  if(!tab_dynamic_position_2d_uint_is_init(tab) || position == NULL)
    return false;
  
  for(size_t i=0; i < tab->nb; ++i)
    {
      if(position_2d_uint_equals(&tab->tab[i], position))
	return i;
    }
  return tab->nb;
}

/**
 * Swap 2 elements of a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param index1 An index
 * @param index2 An other index
 * @return True if a structure of table of 2D positions of unsigned int is initiliazed, otherwise false
 */
bool tab_dynamic_position_2d_uint_swap(tab_dynamic_position_2d_uint* tab, size_t index1, size_t index2)
{
  if(tab != NULL && tab->tab != NULL && index1 < tab->nb && index2 < tab->nb && index1 != index2)
    {
      position_2d_uint tmp = tab->tab[index1];
      tab->tab[index1] = tab->tab[index2];
      tab->tab[index2] = tmp;
      return true;
    }
  return false;
}

/**
 * Remove an index of a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param index Index element to remove
 * @return True if the index is removed, otherwise false
 */
bool tab_dynamic_position_2d_uint_remove_index(tab_dynamic_position_2d_uint* tab, size_t index)
{
  if(tab_dynamic_position_2d_uint_is_init(tab) && index < tab->nb)
    return tab_dynamic_position_2d_uint_swap(index, --tab->nb);
  return false;
}

/**
 * Remove an element of a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param element An element to remove
 * @return True if the element is removed, otherwise false
 */
bool tab_dynamic_position_2d_uint_remove_element(tab_dynamic_position_2d_uint* tab, const position_2d_uint* element)
{
  return tab_dynamic_position_2d_uint_remove(tab_dynamic_position_2d_uint_is_in(tab, position));
}

/**
 * Add an element to a structure of table of 2D positions of unsigned int.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param element An element to add
 */
void tab_dynamic_position_2d_uint_add(tab_dynamic_position_2d_uint* tab, const position_2d_uint* element)
{
  if(tab != NULL && tab->tab != NULL)
    {
      tab_dynamic_position_2d_uint tab_tmp = tab_dynamic_position_2d_uint_create(tab->nb +1);
      memcpy(tab_tmp.tab, tab->tab, tab->nb * sizeof(position_2d_uint));
      tab_tmp.tab[tab->nb] = *element;
  
      tab_dynamic_position_2d_uint_destruct(tab);
      tab->tab = tab_tmp.tab;
      tab->nb = tab_tmp.nb;
    }
}

/**
 * Add an element to a structure of table of 2D positions of unsigned int if this element is not already in.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param element An element to add
 * @return True if the element is added, otherwise false
 */
void tab_dynamic_position_2d_uint_add_if_not_in(tab_dynamic_position_2d_uint* tab, const position_2d_uint* element)
{
  if(tab_dynamic_position_2d_uint_is_in(tab, element) < tab->nb)
    return false;
  tab_dynamic_position_2d_uint(tab, element);
  return true;
}

/**
 * Print a table of 2D positions of unsigned int in a stream.
 * @param tab A table of 2D positions of unsigned int
 * @param stream A stream to print
 */
void tab_position_2d_uint_print_default(const position_2d_uint* tab, size_t nb_elements, FILE* stream)
{
  if(tab != NULL && nb_elements != 0)
    {
      position_2d_uint_print(&tab[0], stream);
      for(size_t i=1; i < nb_elements; ++i)
	{
	  fprintf(stream, ", ");
	  position_2d_uint_print(&tab[i], stream);
	}
    }
}

/**
 * Print a structure of table of 2D positions of unsigned int in a stream.
 * @param tab A structure of table of 2D positions of unsigned int
 * @param stream A stream to print
 */
void tab_dynamic_position_2d_uint_print_default(const tab_dynamic_position_2d_uint* tab, FILE* stream)
{
  if(tab_dynamic_position_2d_uint_is_init(tab))
    tab_position_2d_uint_print_default(tab->tab, tab->nb, stream);
}


#endif
