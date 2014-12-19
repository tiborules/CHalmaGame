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


#ifndef HALMA_GAME_PLAYER_MOVE_H
#define HALMA_GAME_PLAYER_MOVE_H


#include "stdio_functions.h"
#include "halma_game_player.h"


/**
 * Return true if a move is possible for a player, otherwise false.
 * @param player A Halma game player
 * @param tab_2d A pointer of a 2D table of char
 * @param move A move
 * @return True if a move is possible for a player, otherwise false
 */
bool halma_game_player_is_possible_move(const halma_game_player* player, const tab_2d_char* tab_2d, const halma_game_move* move);

/**
 * A function for a player to choose a move with stdin.
 * @param[in]  player A Halma game player
 * @param[in]  tab_2d A 2D table of characters
 * @param[out] move A move to do
 */
void halma_game_player_ask_move(const halma_game_player* player, const tab_2d_char* tab_2d, halma_game_move* move);

/**
 * A function for a player to choose a random move.
 * @param[in]  player A Halma game player
 * @param[in]  tab_2d A 2D table of characters
 * @param[out] move A move to do
 */
void halma_game_player_choose_random_move(const halma_game_player* player, const tab_2d_char* tab_2d, halma_game_move* move);


#endif
