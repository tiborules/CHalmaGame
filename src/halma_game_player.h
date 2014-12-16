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
 *
 * @todo Separate in .h and in .c
 * @todo Add a rule in makefile
 */


#ifndef HALMA_GAME_PLAYER_H
#define HALMA_GAME_PLAYER_H

#include "bool.h"
#include "string_functions.h"
#include "halma_game_essential.h"


typedef struct halma_game_player halma_game_player;

/**
 * A player of Halma game.
 */
struct halma_game_player
{
  /**
   * The name of a player of Halma game.
   */
  char* name;
  
  /**
   * The pawn character of a player of Halma game.
   * It must not be an empty or a mark character.
   */
  char char_pawn;
};


/**
 * Set a name of a Halma game player.
 * @param player A Halma game player
 * @param new_name New name of the player
 * @return True if the player has the new name, otherwise false
 */
bool halma_game_player_set_name(halma_game_player* player, const char* new_name)
{
  if(player->name != NULL)
    free(player->name);

  player->name = (char*) malloc(sizeof(char) * (strlen(new_name) +1));
  strcpy(player->name, new_name);
  string_trim(player->name, ' ');
  return strlen(player->name);
}

/**
 * Returns true if a pawn character is possible for a Halma game player, otherwise false.
 * @param new_paw A potential pawn character of a player
 * @return True if a pawn character is possible for a Halma game player, otherwise false
 */
bool halma_game_player_is_possible_char_pawn(char pawn_char)
{
  return pawn_char != HALMA_GAME_CELL_EMPTY || pawn_char != HALMA_GAME_CELL_MARK;
}

/**
 * Set a character pawn of a Halma game player.
 * @param player A Halma game player
 * @param new_paw New pawn character of the player
 * @return True if the player has the new pawn character, otherwise false
 */
bool halma_game_player_set_char_pawn(halma_game_player* player, char new_pawn)
{
  if(halma_game_player_is_possible_char_pawn(new_pawn))
    {
      player->char_pawn = new_pawn;
      return true;
    }
  return false;
}

/**
 * Initialize a Halma game player.
 * @param player A Halma game player
 * @param new_name New name of the player
 * @param new_paw New pawn character of the player
 * @return True if the player is initialized, otherwise false
 */
bool halma_game_player_init(halma_game_player* player, const char* name, char pawn_char)
{
  return
    halma_hame_player_set_name(player, name) &&
    halma_game_player_set_char_pawn(player, pawn_char);
}

#endif
