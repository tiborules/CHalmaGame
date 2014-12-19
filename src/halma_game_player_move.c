/**
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


#include "halma_game_player_move.h"


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
