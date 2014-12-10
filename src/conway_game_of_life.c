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


#include "conway_game_of_life.h"


bool halma_is_cell_empty(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return tab_2d_char_get_element_value(tab_2d, line, column) == HALMA_GAME_CELL_EMPTY;
}

bool halma_is_mark(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return tab_2d_char_get_element_value(tab_2d, line, column) == HALMA_GAME_CELL_MARK;
}

bool halma_is_pawn(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return !halma_is_cell_empty(tab_2d, line, column) && !halma_is_mark(tab_2d, line, column);
}

void halma_mark_possible_moves_of_a_cell(tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  if(halma_is_cell_empty(tab_2d, line-1, column-1))
    tab_2d_char_set_element_value_unsafe(tab_2d, line-1, column-1, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line-1, column))
    tab_2d_char_set_element_value_unsafe(tab_2d, line-1, column, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line-1, column+1))
    tab_2d_char_set_element_value_unsafe(tab_2d, line-1, column+1, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line, column-1))
    tab_2d_char_set_element_value_unsafe(tab_2d, line, column-1, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line, column+1))
    tab_2d_char_set_element_value_unsafe(tab_2d, line, column+1, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line+1, column-1))
    tab_2d_char_set_element_value_unsafe(tab_2d, line+1, column-1, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line+1, column))
    tab_2d_char_set_element_value_unsafe(tab_2d, line+1, column, HALMA_GAME_CELL_MARK);
  if(halma_is_cell_empty(tab_2d, line+1, column+1))
    tab_2d_char_set_element_value_unsafe(tab_2d, line+1, column+1, HALMA_GAME_CELL_MARK);
}

void halma_remove_marks(tab_2d_char* tab_2d)
{
  tab_2d_char_replace(tab_2d, HALMA_GAME_CELL_MARK, HALMA_GAME_CELL_EMPTY);
}

bool halma_pawn_move(tab_2d_char* tab_2d, unsigned int line_pawn, unsigned int column_pawn, unsigned int line_mark, unsigned int column_mark)
{
  if(!halma_is_pawn(tab_2d, line_pawn, column_pawn) || !halma_is_mark(tab_2d, line_mark, column_mark))
    return false;
  
  tab_2d_char_swap(tab_2d, line_pawn, column_pawn, line_mark, column_mark);
  halma_remove_marks(tab_2d);
  return true;
}
