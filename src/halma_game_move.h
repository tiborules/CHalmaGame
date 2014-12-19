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


#ifndef HALMA_GAME_MOVE_H
#define HALMA_GAME_MOVE_H


#include "string_functions.h"
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
signed char halma_game_move_is_possible(const tab_2d_char* tab_2d, const halma_game_move* move)
{
  return
    halma_is_pawn(tab_2d, move->first.line, move->first.column) &&
    halma_is_mark(tab_2d, move->second.line, move->second.column) << 1;
}


#endif
