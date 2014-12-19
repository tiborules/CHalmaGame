/**
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


#include "tab_2d_char_essential.h"


bool tab_2d_char_is_init(const tab_2d_char* tab_2d)
{
  return tab_2d != NULL && tab_2d->tab != NULL && tab_2d->nb_lines > 0 && tab_2d->nb_columns > 0;
}

void tab_2d_char_alloc_unsafe(tab_2d_char* tab_2d)
{
  tab_2d->tab = (char *) malloc(sizeof(char) * tab_2d->nb_lines * tab_2d->nb_columns);
}

bool tab_2d_char_alloc(tab_2d_char* tab_2d)
{
  if(tab_2d_char_is_init(tab_2d))
    free(tab_2d->tab);
  
  if(tab_2d->nb_lines == 0 || tab_2d->nb_columns == 0)
    return false;
  
  tab_2d_char_alloc_unsafe(tab_2d);
  return true;
}

void tab_2d_char_init_unsafe(tab_2d_char* tab_2d, unsigned int nb_lines, unsigned int nb_columns)
{
  tab_2d->nb_lines = nb_lines;
  tab_2d->nb_columns = nb_columns;
  tab_2d_char_alloc_unsafe(tab_2d);
}

void tab_2d_char_init_one_time_only(tab_2d_char* tab_2d, unsigned int nb_lines, unsigned int nb_columns)
{
  if(tab_2d != NULL)
    tab_2d_char_init_unsafe(tab_2d, nb_lines, nb_columns);
}

void tab_2d_char_init(tab_2d_char* tab_2d, unsigned int nb_lines, unsigned int nb_columns)
{
  if(!tab_2d_char_is_init(tab_2d))
    tab_2d_char_init_unsafe(tab_2d, nb_lines, nb_columns);
}

tab_2d_char tab_2d_char_create(unsigned int nb_lines, unsigned int nb_columns)
{
  tab_2d_char tab_2d = {NULL, 0, 0};
  tab_2d_char_init_unsafe(&tab_2d, nb_lines, nb_columns);
  return tab_2d;
}

void tab_2d_char_destruct(tab_2d_char* tab_2d)
{
  if(tab_2d != NULL)
    {
      if(tab_2d->tab != NULL)
	{
	  free(tab_2d->tab);
	  tab_2d->tab = NULL;
	}
      
      tab_2d->nb_lines = 0;
      tab_2d->nb_columns = 0;
    }
}

bool tab_2d_char_line_exists(const tab_2d_char* tab_2d, unsigned int line)
{
  return tab_2d_char_is_init(tab_2d) && line < tab_2d->nb_lines;
}

bool tab_2d_char_column_exists(const tab_2d_char* tab_2d, unsigned int column)
{
  return tab_2d_char_is_init(tab_2d) && column < tab_2d->nb_columns;
}

bool tab_2d_char_element_exists(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return tab_2d_char_is_init(tab_2d) && line < tab_2d->nb_lines && column < tab_2d->nb_columns;
}

char* tab_2d_char_get_element_pointer_unsafe(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return tab_2d->tab + sizeof(char) * (line * tab_2d->nb_lines + column);
}

char* tab_2d_char_get_element_pointer(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  if(!tab_2d_char_element_exists(tab_2d, line, column))
    return NULL;
  return tab_2d_char_get_element_pointer_unsafe(tab_2d, line, column);
}

char tab_2d_char_get_element_value_unsafe(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return *tab_2d_char_get_element_pointer_unsafe(tab_2d, line, column);
}

char tab_2d_char_get_element_value(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  char * pointer = tab_2d_char_get_element_pointer(tab_2d, line, column);
  return pointer == NULL ? '\0' : *pointer;
}

void tab_2d_char_set_element_value_unsafe(tab_2d_char* tab_2d, unsigned int line, unsigned int column, char value)
{
  *tab_2d_char_get_element_pointer_unsafe(tab_2d, line, column) = value;
}

void tab_2d_char_set_element_value(tab_2d_char* tab_2d, unsigned int line, unsigned int column, char value)
{
  char * pointer = tab_2d_char_get_element_pointer(tab_2d, line, column);
  if(pointer != NULL)
    *pointer = value;
}

bool tab_2d_char_swap(tab_2d_char* tab_2d, unsigned int line1, unsigned int column1, unsigned int line2, unsigned int column2)
{
  if(!tab_2d_char_is_init(tab_2d) || !tab_2d_char_element_exists(tab_2d, line1, column1) || !tab_2d_char_element_exists(tab_2d, line2, column2))
    return false;
  
  char tmp = tab_2d_char_get_element_value(tab_2d, line1, column1);
  tab_2d_char_set_element_value(tab_2d, line1, column1,
				tab_2d_char_get_element_value(tab_2d, line2, column2));
  tab_2d_char_set_element_value(tab_2d, line2, column2, tmp);
  return true;
}

void tab_2d_char_fill_with_const(tab_2d_char* tab_2d, char value_for_filling)
{
  if(tab_2d_char_is_init(tab_2d))
    {
      unsigned int line, column;
      
      for(line=0; line < tab_2d->nb_lines; ++line)
	{
	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      tab_2d_char_set_element_value_unsafe(tab_2d, line, column, value_for_filling);
	    }
	}
    }
}

void tab_2d_char_replace(tab_2d_char* tab_2d, char value_to_replace, char new_value)
{
  if(tab_2d_char_is_init(tab_2d))
    {
      for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
	{
	  for(column=0; column < tab_2d->nb_columns; ++column)
	    {
	      if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == value_to_replace)
		{
		  tab_2d_char_set_element_value_unsafe(tab_2d, line, column, new_value);
		}
	    } 
	}
    }
}

void tab_2d_char_copy(tab_2d_char* destination, const tab_2d_char* source)
{
  destination->nb_lines = source->nb_lines;
  destination->nb_columns = source->nb_columns;
  if(tab_2d_char_alloc(destination))
    memcpy(destination, source, source->nb_lines * source->nb_columns);
}

tab_2d_char tab_2d_char_get_copy(const tab_2d_char* source)
{
  tab_2d_char tab_2d_copy = tab_2d_char_create(source->nb_lines, source->nb_columns);
  tab_2d_char_copy(&tab_2d_copy, source);
  return tab_2d_copy;
}
