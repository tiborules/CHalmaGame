/**
 * @file
 * 
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


#ifndef HALMA_GAME_ESSENTIAL_H
#define HALMA_GAME_ESSENTIAL_H


#include "bool.h"
#include "tab_2d_char_file.h"


#define HALMA_GAME_CELL_EMPTY '.'
#define HALMA_GAME_CELL_MARK  '*'


/**
 * Returns true if a cell of a Halma game is empty, otherwise returns false.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return True if a cell of a Halma game is empty, otherwise false
 */
bool halma_is_cell_empty(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns true if a cell of a Halma game is a mark, otherwise returns false.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return True if a cell of a Halma game is a mark, otherwise false
 */
bool halma_is_mark(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Returns true if a cell of a Halma game is a pawn, otherwise returns false.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return True if a cell of a Halma game is a pawn, otherwise false
 */
bool halma_is_pawn(const tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Put a mark in a board Halma game unsafely (possible null pointer, segfaut, etc).
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 */
void halma_board_game_cell_put_mark_unsafe(tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Put a mark in a board Halma game.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 */
void halma_board_game_cell_put_mark(tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Apply a function around for each cell around a cell if a verification is true.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @param function_verify_cell A function that returns a boolean depending of a given cell
 * @param function_apply_cell A function that can be applied to a given cell
 * @return Number of times the applying function has been called.
 */
unsigned int halma_apply_a_function_around_a_cell(tab_2d_char* tab_2d, unsigned int line, unsigned int column, bool (*function_verify_cell)(const tab_2d_char* tab_2d, unsigned int line, unsigned int column), void (*function_apply_cell)(tab_2d_char* tab_2d, unsigned int line, unsigned int column));

/**
 * Marks possible moves around a given cell that has to be a pawn.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return Number of new marks added
 */
unsigned int halma_mark_possible_moves_around_a_pawn(tab_2d_char* tab_2d, unsigned int line, unsigned int column);


/**
 * Marks possible jumps around a given cell that has to be marked.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return Number of new marks added
 */
unsigned int halma_mark_possible_jumps_around_a_marked_cell(tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Marks possible moves of a cell of a Halma game in a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 * @param line A line of the 2D table of char
 * @param column A column of the 2D table of char
 * @return Number of new marks added
 */
unsigned int halma_mark_possible_moves_of_a_cell(tab_2d_char* tab_2d, unsigned int line, unsigned int column);

/**
 * Removes all marks of a 2D table of char used for a Halma game.
 * @param tab_2d A pointer of a 2D table of char
 */
void halma_remove_marks(tab_2d_char* tab_2d);

/**
 * If parameters are good, move a pawn to a mark and remove marks.
 * @param tab_2d A pointer of a 2D table of char
 * @param line_pawn Line of the pawn
 * @param column_pawn Column of the pawn
 * @param line_mark Line of the mark
 * @param column_mark Column of the mark
 * @return True if the move is done, otherwise false
 */
bool halma_pawn_move(tab_2d_char* tab_2d, unsigned int line_pawn, unsigned int column_pawn, unsigned int line_mark, unsigned int column_mark);

/**
 * Returns true if there is at least one mark in a 2D table of char, otherwise false.
 * @param tab_2d A pointer of a 2D table of char
 * @return True if there is at least one mark in a 2D table of char, otherwise false.
 */
bool halma_is_there_at_least_one_mark(const tab_2d_char* tab_2d);

/**
 * Returns number of marks of a 2D table of char.
 * @param tab_2d A pointer of a 2D table of char
 * @return Number of marks of a 2D table of char
 */
unsigned int halma_get_number_of_marks(const tab_2d_char* tab_2d);

#endif
