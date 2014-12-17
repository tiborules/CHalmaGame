/**
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


#include <string_functions.h>


void reverse_string(char* string)
{
  size_t length = strlen(string);
  size_t half_length = length / 2;
  size_t i=0;
  char tmp;
  
  while(i < half_length)
    {
      tmp = string[i];
      string[i] = string[length - i -1];
      string[length - i -1] = tmp;
      ++i;
    }
}


char* get_strcpy(const char* string)
{
  char* new_string = (char*) malloc(sizeof(char) * (strlen(string) +1));
  strcpy(new_string, string);
  return new_string;
}


char* get_reverse_string(const char* string)
{
  char* string_reversed = get_strcpy(string);
  reverse_string(string_reversed);
  return string_reversed;
}


void string_ltrim(char* string, char character_to_strip)
{
  while(string[0] == character_to_strip)
    strcpy(string, string + 1);
}


void string_rtrim(char* string, char character_to_strip)
{
  size_t i = strlen(string) -1;
  while(string[i] == character_to_strip)
    string[i--] = '\0';
}


void string_trim(char* string, char character_to_strip)
{
  string_ltrim(string, character_to_strip);
  string_rtrim(string, character_to_strip);
}


void delete_consecutive_characters(char* string, char character_to_strip)
{
  for(size_t i=1; i < strlen(string); ++i)
    {
      if(string[i-1] == character_to_strip && string[i] == character_to_strip)
	strcpy(string + i-1, string + i);
    }
}


unsigned int get_nb_of_character_of_string(const char* string, char character)
{
  unsigned int nb=0;
  for(size_t i=0; i < strlen(string); ++i)
    {
      if(string[i] == character)
	++nb;
    }
  return nb;
}


int string_equals(const char* str1, const char* str2)
{
  return strcmp(str1, str2) == 0;
}

void string_tolower(char* string)
{
  for(size_t i=0; i < strlen(string); ++i)
    {
      string[i] = tolower(string[i]);
    }
}

void string_toupper(char* string)
{
  for(size_t i=0; i < strlen(string); ++i)
    {
      string[i] = toupper(string[i]);
    }
}

bool string_contains_only_digits(const char* string)
{
  for(size_t i=0; i < strlen(string); ++i)
    {
      if(!isdigit(string[i]))
	 return false;
    }
  return true;
}

bool string_is_int(const char* string)
{
  return
    (*string == '+' || *string == '-' || isdigit(*string)) &&
    string_contains_only_digits(++string);
}

bool string_is_uint(const char* string)
{
  return
    (*string == '+' || isdigit(*string)) &&
    string_contains_only_digits(++string);
}
