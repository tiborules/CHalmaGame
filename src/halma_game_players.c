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


#include "halma_game_players.h"


bool halma_game_players_is_correct_nb(signed char number)
{
  return number >= HALMA_GAME_NB_PLAYERS_MIN && number <= HALMA_GAME_NB_PLAYERS_MAX;
}

bool halma_game_players_is_init(const halma_game_players* players)
{
  return players != NULL && players->tab != NULL && halma_game_players_is_correct_nb(players->nb);
}

bool halma_game_players_init(halma_game_players* players, signed char nb)
{
  if(players == NULL || !halma_game_players_is_correct_nb(nb))
    return false;
  
  players->nb = nb;
  
  if(players->tab != NULL)
    free(players->tab);
  players->tab = (halma_game_player*) malloc(sizeof(halma_game_player) * nb);
  
  return true;
}

halma_game_players halma_game_players_create(signed char nb)
{
  halma_game_players players = { NULL, 0 };
  halma_game_players_init(&players, nb);
  return players;
}

void halma_game_players_destruct(halma_game_players* players)
{
  if(players != NULL)
    {
      if(players->tab != NULL)
	{
	  for(signed char i=0; i < players->nb; ++i)
	    {
	      halma_game_player_destruct(&players->tab[i]);
	    }
	  
	  free(players->tab);
	  players->tab = NULL;
	} 
      
      players->nb = 0;
    }
}

bool halma_game_players_are_ready(const halma_game_players* players)
{
  if(!halma_game_players_is_init(players))
    return false;

  for(signed char i=0; i < players->nb; ++i)
    {
      if(!halma_game_player_is_init(&players->tab[i]))
	return false;
    }
  return true;
}

bool halma_game_players_is_char_pawn_used_with_exception(const halma_game_players* players, char char_pawn, signed char exception_index)
{
  if(!halma_game_players_are_ready(players))
    return false;
  
  for(signed char i=0; i < players->nb; ++i)
    {
      if(i != exception_index && players->tab[i].char_pawn == char_pawn)
	return true;
    }
  return false;
}

bool halma_game_players_is_char_pawn_used(const halma_game_players* players, char char_pawn)
{
 return halma_game_players_is_char_pawn_used_with_exception(players, char_pawn, players->nb);
}

bool halma_game_players_set_player_char_pawn(const halma_game_players* players, size_t player_index, signed char char_pawn)
{
  if(!halma_game_players_are_ready(players) || halma_game_players_is_char_pawn_used(players, char_pawn))
    return false;
  
  halma_game_player_set_char_pawn(&players->tab[player_index], char_pawn);
  return true;
}

bool halma_game_players_is_correct(const halma_game_players* players)
{
  if(!halma_game_players_are_ready(players))
    return false;
  
  for(signed char i=1; i < players->nb; ++i)
    {
      if(halma_game_players_is_char_pawn_used_with_exception(players, players->tab[i].char_pawn, i))
	return false;
    }
  return true;
}

bool halma_game_players_set_char_pawns_with_consecutive_chars(halma_game_players* players, char first_char_pawn)
{
  if(!halma_game_players_is_init(players))
    return false;

  for(signed char i=0; i < players->nb; ++i)
    {
      if(!halma_game_player_set_char_pawn(&players->tab[i], first_char_pawn + i))
	return false;
    }
  return true;
}

bool halma_game_players_set_char_pawns_with_numbers(halma_game_players* players)
{
  return halma_game_players_set_char_pawns_with_consecutive_chars(players, '1');
}
