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


bool conway_game_of_life_is_universe(const tab_2d_char* tab_2d)
{
  if(!tab_2d_char_is_init(tab_2d))
    return false;
  
  for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
    {
      for(column=0; column < tab_2d->nb_columns; ++column)
	{
	  if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) != CONWAY_GAME_OF_LIFE_CELL_LIVING && tab_2d_char_get_element_value_unsafe(tab_2d, line, column) != CONWAY_GAME_OF_LIFE_CELL_EMPTY)
	    return false;
	}
    }
  return true;
}

bool conway_game_of_life_is_universe_over(const tab_2d_char* tab_2d)
{
  if(!tab_2d_char_is_init(tab_2d))
    return false;
  
  for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
    {
      for(column=0; column < tab_2d->nb_columns; ++column)
	{
	  if(tab_2d_char_get_element_value_unsafe(tab_2d, line, column) != CONWAY_GAME_OF_LIFE_CELL_EMPTY)
	    return false;
	}
    }
  return true;
}

unsigned char conway_game_of_life_nb_of_near_living_cells_cross_like_add(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  if(!tab_2d_char_is_init(tab_2d))
    return 0;
  
  unsigned char nb = 0;
  if(tab_2d_char_get_element_value(tab_2d, line, column-1) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  if(tab_2d_char_get_element_value(tab_2d, line-1, column) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  if(tab_2d_char_get_element_value(tab_2d, line+1, column) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  if(tab_2d_char_get_element_value(tab_2d, line, column+1) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  return nb;
}

unsigned char conway_game_of_life_nb_of_near_living_cells_corners(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  if(!tab_2d_char_is_init(tab_2d))
    return 0;
  
  unsigned char nb = 0;
  if(tab_2d_char_get_element_value(tab_2d, line-1, column-1) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  if(tab_2d_char_get_element_value(tab_2d, line-1, column+1) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  if(tab_2d_char_get_element_value(tab_2d, line+1, column-1) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  if(tab_2d_char_get_element_value(tab_2d, line+1, column+1) == CONWAY_GAME_OF_LIFE_CELL_LIVING)
    ++nb;
  return nb;
}

unsigned char conway_game_of_life_nb_of_near_living_cells_square(const tab_2d_char* tab_2d, unsigned int line, unsigned int column)
{
  return conway_game_of_life_nb_of_near_living_cells_cross_like_add(tab_2d, line, column) + conway_game_of_life_nb_of_near_living_cells_corners(tab_2d, line, column);
}

tab_2d_char conway_game_of_life_get_next_turn(const tab_2d_char* tab_2d)
{
  if(!tab_2d_char_is_init(tab_2d))
    return *tab_2d; 
  
  tab_2d_char tab_2d_next_turn = tab_2d_char_create(tab_2d->nb_lines, tab_2d->nb_columns);
  char nb_of_nearing_living_cells;
  
  for(unsigned int line=0, column; line < tab_2d->nb_lines; ++line)
    {
      for(column=0; column < tab_2d->nb_columns; ++column)
	{
	  nb_of_nearing_living_cells = conway_game_of_life_nb_of_near_living_cells_square(tab_2d, line, column);

	  tab_2d_char_set_element_value_unsafe(
					       &tab_2d_next_turn,
					       line,
					       column,
					       (
						tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == CONWAY_GAME_OF_LIFE_CELL_LIVING &&
						(nb_of_nearing_living_cells == 2 || nb_of_nearing_living_cells == 3)
						)
					       ||
					       (
						tab_2d_char_get_element_value_unsafe(tab_2d, line, column) == CONWAY_GAME_OF_LIFE_CELL_EMPTY && nb_of_nearing_living_cells == 3
						)
					       ? CONWAY_GAME_OF_LIFE_CELL_LIVING
					       : CONWAY_GAME_OF_LIFE_CELL_EMPTY
					       );
	}
    }

  return tab_2d_next_turn;
}
