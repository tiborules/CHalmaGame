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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "halma_game_board.h"


bool halma_game_board_fill_for_new_party(halma_game_board* board, const halma_game_players* players)
{
  if(!tab_2d_char_is_init(board) || !halma_game_players_is_init(players) ||
     board->nb_lines != 16 || board->nb_columns != 16 ||
     players->nb < 2 || players->nb > 4)
    return false;
  
  tab_2d_char_fill_with_const(board, HALMA_GAME_CELL_EMPTY);
  
  /* The code for 1 player is here but it is not managed in winning, so it disabled with the previous if. */
  if(players->nb == 1 || players->nb == 2)
    {
      /* Top left corner */
      tab_2d_char_fill_part_of_line_with_char(board, 0, 0, 5, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 1, 0, 5, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 2, 0, 4, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 3, 0, 3, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 4, 0, 2, players->tab[0].char_pawn);

      if(players->nb == 2)
	{
	  /* Bottom right corner */
	  tab_2d_char_fill_part_of_line_with_char(board, 11, 14, 2, players->tab[1].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 12, 13, 3, players->tab[1].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 13, 12, 4, players->tab[1].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 14, 11, 5, players->tab[1].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 15, 11, 5, players->tab[1].char_pawn);
	}
    }
  else if(players->nb > 2)
    {
      /* Top left corner */
      tab_2d_char_fill_part_of_line_with_char(board, 0, 0, 4, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 1, 0, 4, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 2, 0, 3, players->tab[0].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 3, 0, 2, players->tab[0].char_pawn);

      /* Bottom right corner */
      tab_2d_char_fill_part_of_line_with_char(board, 12, 14, 2, players->tab[1].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 13, 13, 3, players->tab[1].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 14, 12, 4, players->tab[1].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 15, 12, 4, players->tab[1].char_pawn);
      
      /* Top right corner */
      tab_2d_char_fill_part_of_line_with_char(board, 0, 12, 4, players->tab[2].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 1, 12, 4, players->tab[2].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 2, 13, 3, players->tab[2].char_pawn);
      tab_2d_char_fill_part_of_line_with_char(board, 3, 14, 2, players->tab[2].char_pawn);
      
      if(players->nb == 4)
	{
	  /* Bottom left corner */
	  tab_2d_char_fill_part_of_line_with_char(board, 12, 0, 2, players->tab[3].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 13, 0, 3, players->tab[3].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 14, 0, 4, players->tab[3].char_pawn);
	  tab_2d_char_fill_part_of_line_with_char(board, 15, 0, 4, players->tab[3].char_pawn);
	}
    }

  return true;
}

bool halma_game_board_construct_for_new_party(halma_game_board* board, const halma_game_players* players)
{
  return
    tab_2d_char_alloc(board) &&
    halma_game_board_fill_for_new_party(board, players);
}
