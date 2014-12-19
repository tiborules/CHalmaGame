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


#ifndef HALMA_GAME_MOVE_H
#define HALMA_GAME_MOVE_H


#include "position_2d_uint_pair.h"
#include "halma_game_essential.h"


#define HALMA_GAME_MOVE_POSSIBLE          0x11
#define HALMA_GAME_MOVE_IMPOSSIBLE_FIRST  0x10
#define HALMA_GAME_MOVE_IMPOSSIBLE_SECOND 0x01
#define HALMA_GAME_MOVE_IMPOSSIBLE_BOTH   0X00


/**
 * A move in Halma game.
 */
typedef position_2d_uint_pair halma_game_move;


/**
 * Return HALMA_GAME_POSSIBLE_MOVE if a move is possible, otherwise a macro HALMA_GAME_MOVE_IMPOSSIBLE_*.
 * @param tab_2d A pointer of a 2D table of char
 * @param move A move
 * @return HALMA_GAME_MOVE_POSSIBLE if a move is possible, otherwise a macro HALMA_GAME_MOVE_IMPOSSIBLE_*
 */
signed char halma_game_move_is_possible(const tab_2d_char* tab_2d, const halma_game_move* move);


#endif
