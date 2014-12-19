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


#ifndef HALMA_GAME_PLAYERS_H
#define HALMA_GAME_PLAYERS_H


#include "halma_game_player.h"


#define HALMA_GAME_NB_PLAYERS_MIN 2
#define HALMA_GAME_NB_PLAYERS_MAX 4


typedef struct halma_game_players halma_game_players;

/**
 * Players of Halma game.
 */
struct halma_game_players
{
  /**
   * Table of players of Halma game.
   */
  halma_game_player* tab;
  
  /**
   * Number of players.
   */
  unsigned char nb;
};


/**
 * Returns true if a number can be a number of players, otherwise false.
 * @param number Potential number of players
 * @retur True if a number can be a number of players, otherwise false
 */
bool halma_game_players_is_correct_nb(signed char number);

/**
 * Returns true if a table of players is initialized, otherwise false.
 * @param players A table of Halma game players
 * @return True if a table of players is initialized, otherwise false
 */
bool halma_game_players_is_init(const halma_game_players* players);

/**
 * Initialize a table of Halma game players.
 * @param players A table of Halma game players
 * @param nb Number of players
 * @return True if the table of players is initialized, otherwise false
 */
bool halma_game_players_init(halma_game_players* players, signed char nb);

/**
 * Create a table of Halma game players.
 * @param nb Number of players
 * @return A table of Halma game players
 */
halma_game_players halma_game_players_create(signed char nb);

/**
 * Destruct a table of Halma game players (dynamic allocation, etc).
 * @param players A table of Halma game players
 */
void halma_game_players_destruct(halma_game_players* players);

/**
 * Returns true if table of Halma game players is initialized included each player, otherwise false.
 * @param players A table of Halma game players
 * @return True if table of Halma game players is initialized included each player, otherwise false
 */
bool halma_game_players_are_ready(const halma_game_players* players);

/**
 * Return true if a pawn character is used by at least one of the players except one, otherwise false.
 * @param players A table of Halma game players
 * @param char_pawn A pawn character
 * @param exception_index An index not to check
 * @return True if a pawn character is used by at least one of the players except one, otherwise false
 */
bool halma_game_players_is_char_pawn_used_with_exception(const halma_game_players* players, char char_pawn, signed char exception_index);

/**
 * Return true if a pawn character is used by at least one of the players, otherwise false.
 * @param players A table of Halma game players
 * @param char_pawn A pawn character
 * @return True if a pawn character is used by at least one of the players, otherwise false
 */
bool halma_game_players_is_char_pawn_used(const halma_game_players* players, char char_pawn);

/**
 * Set a pawn character to a Halma game player of a table of players.
 * @param players A table of Halma game players
 * @param player_index An index of the table of players
 * @param char_pawn A pawn character
 * @return True if it the pawn character was set, otherwise false
 */
bool halma_game_players_set_player_char_pawn(const halma_game_players* players, size_t player_index, signed char char_pawn);

/**
 * Returns true if table of Halma game players is correct for playing, otherwise false.
 * @param players A table of Halma game players
 * @return True if table of Halma game players is ready for playing, otherwise false
 */
bool halma_game_players_is_correct(const halma_game_players* players);

/**
 * Set a number as pawn character for each player in the order of the table of Halma game players, by starting with a given character and then the nex ones in table of characters.
 * @param players A table of Halma game players
 * @param first_char_pawn A pawn character to start with
 * @return Returns true if it succeeded, otherwise false
 */
bool halma_game_players_set_char_pawns_with_consecutive_chars(halma_game_players* players, char first_char_pawn);

/**
 * Set a number as pawn character for each player in the order of the table of Halma game players.
 * @param players A table of Halma game players
 * @return Returns true if it succeeded, otherwise false
 */
bool halma_game_players_set_char_pawns_with_numbers(halma_game_players* players);


#endif
