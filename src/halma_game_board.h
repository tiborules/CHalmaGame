/**
 * @file
 * 
 * @section license License
 * 
 * License Creative Commons 0 (like the public domain)
 * Use, study, hack and share!
 * Even if I do not force you with copyleft to respect freedom of others, please do it.
 * For more informations : https://www.gnu.org/philosophy/free-sw.html
 * This program is provided with no warranty.
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
