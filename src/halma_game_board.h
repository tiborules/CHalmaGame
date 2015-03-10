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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef HALMA_GAME_BOARD_H
#define HALMA_GAME_BOARD_H


#include "tab_2d_char_fill_zone.h"
#include "halma_game_players.h"


/**
 * A board Halma game
 */
typedef tab_2d_char halma_game_board;


/**
 * Fill a board game of Halma with players information.
 * @param board_game A board Halma game
 * @param players Players of a Halma game
 * @return True if the board game was successfully filled, otherwise false.
 */
bool halma_game_board_fill_for_new_party(halma_game_board* board, const halma_game_players* players);

/**
 * Allocate and fill a board game of Halma with players information.
 * @param board_game A board Halma game
 * @param players Players of a Halma game
 * @return True if the board game was successfully constructed, otherwise false.
 */
bool halma_game_board_construct_for_new_party(halma_game_board* board, const halma_game_players* players);
// The name contains 'construct', not 'init', because there is no parameter nb_lines and nb_columns.


#endif
