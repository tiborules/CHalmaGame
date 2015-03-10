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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
  if(string == NULL)
    return NULL;
  
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
  if(string != NULL)
    {
      while(*string == character_to_strip)
	strcpy(string, string + 1);
    }
}


void string_rtrim(char* string, char character_to_strip)
{
  if(string != NULL)
    {
      string += strlen(string) -1;
      while(*string == character_to_strip)
	{
	  *string = '\0';
	  --string;
	}
    }
}


void string_trim(char* string, char character_to_strip)
{
  string_ltrim(string, character_to_strip);
  string_rtrim(string, character_to_strip);
}


void delete_consecutive_characters(char* string, char character_to_strip)
{
  if(string != NULL)
    {
      ++string;
      while(*string)
	{
	  if(*(string -1) == character_to_strip && *string == character_to_strip)
	    strcpy(string -1, string);
	  ++string;
	}
    }
}


unsigned int get_nb_of_character_of_string(const char* string, char character)
{
  if(string == NULL)
    return 0;
  
  unsigned int nb=0;
  while(*string)
    {
      if(*string == character)
	++nb;
      ++string;
    }
  return nb;
}


bool string_equals(const char* str1, const char* str2)
{
  return strcmp(str1, str2) == 0;
}

void string_tolower(char* string)
{
  if(string != NULL)
    {
      while(*string)
	{
	  *string = tolower(*string);
	  ++string;
	}
    }
}

void string_toupper(char* string)
{
  if(string != NULL)
    {
      while(*string)
	{
	  *string = toupper(*string);
	  ++string;
	}
    }
}

bool string_contains_only_digits(const char* string)
{
  if(string == NULL)
    return false;
  
  while(*string)
    {
      if(!isdigit(*string))
	 return false;
      ++string;
    }
  return true;
}

bool string_is_int(const char* string)
{
  return
    string != NULL &&
    (*string == '+' || *string == '-' || isdigit(*string)) &&
    string_contains_only_digits(++string);
}

bool string_is_uint(const char* string)
{
  return
    string != NULL &&
    (*string == '+' || isdigit(*string)) &&
    string_contains_only_digits(++string);
}
