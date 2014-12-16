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

void halma_game_players_destruct(halma_game_players* players)
{
  if(players != NULL)
    {
      if(players->tab != NULL)
	{
	  for(size_t i=0; i < players->nb; ++i)
	    {
	      halma_game_player_destruct(&players->tab[i]);
	    }
	  
	  free(players->tab);
	  players->tab = NULL;
	} 
      
      players->nb = 0;
    }
}
