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


#ifndef HALMA_GAME_PLAYER_MOVE_H
#define HALMA_GAME_PLAYER_MOVE_H


#include "halma_game_player.h"


/**
 * Return true if a move is possible for a player, otherwise false.
 * @param player A Halma game player
 * @param tab_2d A pointer of a 2D table of char
 * @param move A move
 * @return True if a move is possible for a player, otherwise false
 */
bool halma_game_player_is_possible_move(const halma_game_player* player, const tab_2d_char* tab_2d, const halma_game_move* move)
{
  if(!halma_game_player_is_init(player) || player->char_pawn != tab_2d_char_get_element_value(tab_2d, move->first.line, move->first.column))
    return false;
  
  tab_2d_char tab_2d_tmp = tab_2d_char_get_copy(tab_2d);
  halma_mark_possible_moves_of_a_cell(&tab_2d_tmp, move->first.line, move->first.column);
  bool result = halma_game_move_is_possible(tab_2d, move);
  tab_2d_char_destruct(&tab_2d_tmp);
  return result;
}

/**
 * A function for a player to choose a move with stdin.
 * @param[in]  player A Halma game player
 * @param[in]  tab_2d A 2D table of characters
 * @param[out] move A move to do
 */
void halma_game_player_ask_move(const halma_game_player* player, const tab_2d_char* tab_2d, halma_game_move* move)
{
  if(!halma_game_player_is_init(player) || !tab_2d_char_is_init(tab_2d) || move == NULL)
    {
      move->first.line    = 0;
      move->first.column  = 0;
      move->second.line   = 0;
      move->second.column = 0;
    }
  else
    {
      puts("Choose a pawn to move:");
      move->first.line = ask_uint_tirelessly("* Line: ", NULL);
      move->first.column = ask_uint_tirelessly("* Column: ", NULL);
      
      if(halma_is_pawn(tab_2d, move->first.line, move->first.column))
	{
	  tab_2d_char tab_2d_tmp = tab_2d_char_get_copy(tab_2d);
	  halma_mark_possible_moves_of_a_cell(&tab_2d_tmp, move->first.line, move->first.column);
	  if(halma_is_there_at_least_one_mark(&tab_2d_tmp))
	    {
	      printf("Possible moves are marked with '%c'\n", HALMA_GAME_CELL_MARK);
	      tab_2d_char_print_stdout_without_grid(&tab_2d_tmp);
	      puts("Choose a destination cell:");
	      move->second.line = ask_uint_tirelessly("* Line: ", NULL);
	      move->second.column = ask_uint_tirelessly("* Column: ", NULL);
	    }
	  else
	    {
	      if(tab_2d_char_element_exists(&tab_2d_tmp, move->first.line, move->first.column))
		fprintf(stderr, "The pawn [%u, %u] can not move.\n", move->first.line, move->first.column);
	      else
		fprintf(stderr, "The cell [%u, %u] does not exist.\n", move->first.line, move->first.column);
	    }
	  tab_2d_char_destruct(&tab_2d_tmp);
	}
      else
	{
	  fprintf(stderr, "The [%u, %u] is not a pawn.\n", move->first.line, move->first.column);
	}
    }
}

/**
 * A function for a player to choose a random move.
 * @param[in]  player A Halma game player
 * @param[in]  tab_2d A 2D table of characters
 * @param[out] move A move to do
 */
void halma_game_player_choose_random_move(const halma_game_player* player, const tab_2d_char* tab_2d, halma_game_move* move)
{
  if(!halma_game_player_is_init(player) || !tab_2d_char_is_init(tab_2d) || move == NULL)
    {
      move->first.line    = 0;
      move->first.column  = 0;
      move->second.line   = 0;
      move->second.column = 0;
    }
  else
    {
      tab_2d_char tab_2d_tmp = tab_2d_char_get_copy(tab_2d);
      /* TODO select a pawn (move->first) */
      halma_mark_possible_moves_of_a_cell(&tab_2d_tmp, move->first.line, move->first.column);
      /* TODO select a new random possible position for the pawn (move->second) */
      tab_2d_char_destruct(&tab_2d_tmp);
    }
}


#endif
