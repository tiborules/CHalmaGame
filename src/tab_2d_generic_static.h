/*
 * Copyright (C) 2015  Nicola Spanti (RyDroid) <dev@nicola-spanti.info>
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


/**
 * @file
 */


#ifndef TAB_2D_GENERIC_STATIC_H
#define TAB_2D_GENERIC_STATIC_H


#include <stdlib.h>
#include "bool.h"


/**
 * @brief Define a struct that defines a 2D table of a type.
 * @param type The type of the elements of the table
 * It has a 1D table, that only functions should use it.
 * Of course, it has also the number of lines and columns.
 * It is static type while using it (no void*).
 */
#define DEFINE_TAB_2D_GENERIC_STATIC(type)	\
  struct tab_2d_##type				\
  {						\
    type * tab;					\
    unsigned int nb_lines;			\
    unsigned int nb_columns;			\
  };						\
  typedef struct tab_2d_##type tab_2d_##type;

/**
 * @brief Returns true if the 2D table of something is init.
 * @param tab_2d A pointer of a 2D table of something
 * @return True if the 2D table of something is init, otherwise false.
 */
#define TAB_2D_GENERIC_STATIC_POINTER_IS_INIT(tab_2d)	\
  ( (tab_2d)      != NULL &&				\
    (tab_2d)->tab != NULL &&				\
    (tab_2d)->nb_lines   > 0 &&				\
    (tab_2d)->nb_columns > 0 )

/**
 * @brief Free properly dynamic allocated memory of a not null pointer on a 2D table of something.
 * @param tab_2d A not null pointer of a 2D table of something
 */
#define TAB_2D_GENERIC_STATIC_POINTER_FREE_UNSAFE(tab_2d)	\
  if((tab_2d)->tab != NULL)					\
    {								\
      free((tab_2d)->tab);					\
      (tab_2d)->tab = NULL;					\
    }

/**
 * @brief Destructs properly a not null pointer on a 2D table of something.
 * @param tab_2d A not null pointer of a 2D table of something
 */
#define TAB_2D_GENERIC_STATIC_POINTER_DESTRUCT_UNSAFE(tab_2d)	\
  do								\
    {								\
      TAB_2D_GENERIC_STATIC_POINTER_FREE_UNSAFE(tab_2d);	\
      (tab_2d)->nb_lines   = 0;					\
      (tab_2d)->nb_columns = 0;					\
    }								\
  while(false);

/**
 * @brief Destructs properly a 2D table of something.
 * @param tab_2d A pointer of a 2D table of something
 */
#define TAB_2D_GENERIC_STATIC_POINTER_DESTRUCT(tab_2d)		\
  if(tab_2d != NULL)						\
    {								\
      TAB_2D_GENERIC_STATIC_POINTER_DESTRUCT_UNSAFE(tab_2d);	\
    }

#define TAB_2D_GENERIC_STATIC_POINTER_ALLOC_UNSAFE(tab_2d, type)	\
  (tab_2d)->tab = (type *) malloc((tab_2d)->nb_lines   *		\
				  (tab_2d)->nb_columns *		\
				  sizeof(type))

#define TAB_2D_GENERIC_STATIC_POINTER_ALLOC_NULL_UNSAFE(tab_2d, type)	\
  (tab_2d)->tab = (type *) calloc((tab_2d)->nb_lines * (tab_2d)->nb_columns, \
				  sizeof(type))

#define TAB_2D_GENERIC_STATIC_POINTER_GET_ELEMENT_POINTER_UNSAFE(tab_2d, line, column, type) \
  ( (tab_2d)->tab + ((line) * (tab_2d)->nb_columns + (column)) * sizeof(type) )

#define TAB_2D_GENERIC_STATIC_POINTER_GET_ELEMENT_VALUE_UNSAFE(tab_2d, line, column, type) \
  (* TAB_2D_GENERIC_STATIC_POINTER_GET_ELEMENT_POINTER_UNSAFE(tab_2d, line, column, type) )

#define TAB_2D_GENERIC_STATIC_POINTER_SET_ELEMENT_VALUE_UNSAFE(tab_2d, line, column, value, type) \
  (* TAB_2D_GENERIC_STATIC_POINTER_GET_ELEMENT_POINTER_UNSAFE(tab_2d, line, column, type) = value )

#define TAB_2D_GENERIC_STATIC_POINTER_LINE_EXISTS(tab_2d, line) \
  ( TAB_2D_GENERIC_STATIC_POINTER_IS_INIT(tab_2d) &&		\
    line < (tab_2d)->nb_lines )

#define TAB_2D_GENERIC_STATIC_POINTER_COLUMN_EXISTS(tab_2d, column)	\
  ( TAB_2D_GENERIC_STATIC_POINTER_IS_INIT(tab_2d) &&			\
    column < (tab_2d)->nb_columns )

#define TAB_2D_GENERIC_STATIC_POINTER_ELEMENT_EXISTS(tab_2d, line, column) \
  ( TAB_2D_GENERIC_STATIC_POINTER_IS_INIT(tab_2d) &&			\
    line   < (tab_2d)->nb_lines                   &&			\
    column < (tab_2d)->nb_columns )


#endif
