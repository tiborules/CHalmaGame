/**
 * @file
 * 
 * @section license License
 * 
 * License Creative Commons 0 (like the public domain)
 * Use, study, hack and share!
 * Even if I do not force you with copyleft to respect freedom of others, please do it.
 * For more informations : http://www.gnu.org/philosophy/free-sw.html
 * This program is provided with no warranty.
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
  signed char nb;
};


/**
 * Returns true if a number can be a number of players, otherwise false.
 * @param number Potential number of players
 * @retur True if a number can be a number of players, otherwise false
 */
bool halma_game_players_is_correct_nb(signed char number);

/**
 * Returns true if a table of players is initialized, otherwise false.
 * @param player A table of Halma game players
 * @return True if a table of players is initialized, otherwise false
 */
bool halma_game_players_is_init(const halma_game_players* players);

/**
 * Initialize a table of Halma game players.
 * @param player A table of Halma game players
 * @param nb Number of players
 * @return True if the table of players is initialized, otherwise false
 */
bool halma_game_players_init(halma_game_players* players, signed char nb);

/**
 * Destruct a table of Halma game players (dynamic allocation, etc).
 * @param player A table of Halma game players
 */
void halma_game_players_destruct(halma_game_players* players);

#endif
