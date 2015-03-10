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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H


#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "bool.h"


/**
 * Reverse the order of characters in the string.
 * @param string String to reverse
 */
void reverse_string(char* string);

/**
 * Returns a copy of a string.
 * @param string String to copy
 * @return new_string A copy of a string
 */
char* get_strcpy(const char* string);

/**
 * Returns a string reversed.
 * @param string String to reverse
 * @return string_reversed A string reversed
 */
char* get_reverse_string(const char* string);

/**
 * Trim to the left a string with a character to strip.
 * @param string String to trim to the left
 * @param character_to_strip A character to strip
 */
void string_ltrim(char* string, char character_to_strip);

/**
 * Trim to the right a string with a character to strip.
 * @param string String to trim to the right
 * @param character_to_strip A character to strip
 */
void string_rtrim(char* string, char character_to_strip);

/**
 * Trim to the left and right a string with a character to strip.
 * @param string String to trim to the left and right
 * @param character_to_strip A character to strip
 */
void string_trim(char* string, char character_to_strip);

/**
 * Delete consecutive characters with a character to strip.
 * @param string A string
 * @param character_to_strip A character to strip
 */
void delete_consecutive_characters(char* string, char character_to_strip);

/**
 * Returns the number of occurrences of a character in a string
 * @param string A string
 * @param character_to_strip A character to count
 * @return The number of occurrences of a character in a string
 */
unsigned int get_nb_of_character_of_string(const char* string, char character);

/**
 * Returns true if the 2 strings are equals, otherwise false.
 * @param str1 A first string
 * @param str1 A second string
 * @return True if the 2 strings are equals, otherwise false
 */
bool string_equals(const char* str1, const char* str2);

/**
 * All characters of a string become lower cases.
 * @param string String lowercase
 */
void string_tolower(char* string);

/**
 * All characters of a string become upper cases.
 * @param string String to uppercase
 */
void string_toupper(char* string);

/**
 * Returns true if a string contains only digits, otherwise false.
 * @param string A string
 * @return True if a string contains only digits, otherwise false
 */
bool string_contains_only_digits(const char* string);

/**
 * Returns true if a string is an integer, otherwise false.
 * @param string A string
 * @return True if a string is an integer, otherwise false
 */
bool string_is_int(const char* string);

/**
 * Returns true if a string is an unsigned integer, otherwise false.
 * @param string A string
 * @return True if a string is an unsigned integer, otherwise false
 */
bool string_is_uint(const char* string);


#endif
