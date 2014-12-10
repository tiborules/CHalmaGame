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


#ifndef CONWAY_GAME_OF_LIFE_CELL_H
#define CONWAY_GAME_OF_LIFE_CELL_H

#include "bool.h"
#include "tab_2d_char_file.h"

#define CONWAY_GAME_OF_LIFE_CELL_EMPTY  '.'
#define CONWAY_GAME_OF_LIFE_CELL_LIVING '*'


/**
 * Returns true if a 2D table of char is a universe for Conway's Game of Life, otherwise false.
 * @param tab_2d A 2D table of char
 * @return is_universe True if a 2D table of char is a universe for Conway's Game of Life, otherwise false
 */
bool conway_game_of_life_is_universe(const tab_2d_char* tab_2d);

/**
 * Returns true if a universe for Conway's Game of Life won't evolve anymore, otherwise false.
 * @param tab_2d A 2D table of char
 * @return is_universe_over True if a universe for Conway's Game of Life won't evolve anymore, otherwise false
 */
bool conway_game_of_life_is_universe_over(const tab_2d_char* tab_2d);

/**
 * Returns the number of near living cells in top, bottom, left and right.
 * .1.
 * 2*3
 * .4.
 * @param tab_2d A 2D table of char
 * @return nb The number of near living cells in top, bottom, left and right
 */
unsigned char conway_game_of_life_nb_of_near_living_cells_cross_like_add(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the number of near living cells in corners.
 * 1.2
 * .*.
 * 3.4
 * @param tab_2d A 2D table of char
 * @return nb The number of near living cells in corners
 */
unsigned char conway_game_of_life_nb_of_near_living_cells_corners(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the number of near living cells.
 * 123
 * 4*5
 * 678
 * @param tab_2d A 2D table of char
 * @return nb The number of near living cells
 */
unsigned char conway_game_of_life_nb_of_near_living_cells_square(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns the next turn of a a universe for Conway's Game of Life.
 * @param tab_2d A 2D table of char
 * @return The next turn of a a universe for Conway's Game of Life
 */
tab_2d_char conway_game_of_life_get_next_turn(const tab_2d_char* tab_2d);

#endif
