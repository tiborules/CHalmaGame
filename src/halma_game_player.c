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


#include "halma_game_player.h"


bool halma_game_player_has_a_name(const halma_game_player* player)
{
  return player != NULL && player->name != NULL && strlen(player->name);
}

bool halma_game_player_set_name(halma_game_player* player, const char* new_name)
{
  if(player == NULL)
    return false;
  
  if(player->name != NULL)
    free(player->name);

  player->name = (char*) malloc(sizeof(char) * (strlen(new_name) +1));
  strcpy(player->name, new_name);
  string_trim(player->name, ' ');
  return strlen(player->name);
}

bool halma_game_player_is_possible_char_pawn(char pawn_char)
{
  return pawn_char != HALMA_GAME_CELL_EMPTY || pawn_char != HALMA_GAME_CELL_MARK;
}

bool halma_game_player_set_char_pawn(halma_game_player* player, char new_pawn)
{
  if(player != NULL && halma_game_player_is_possible_char_pawn(new_pawn))
    {
      player->char_pawn = new_pawn;
      return true;
    }
  return false;
}

bool halma_game_player_is_init(const halma_game_player* player)
{
  return
    halma_game_player_has_a_name(player) &&
    halma_game_player_is_possible_char_pawn(player->char_pawn);
}

bool halma_game_player_init(halma_game_player* player, const char* name, char pawn_char)
{
  return
    halma_game_player_set_name(player, name) &&
    halma_game_player_set_char_pawn(player, pawn_char);
}
