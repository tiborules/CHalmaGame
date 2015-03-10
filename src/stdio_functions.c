/**
 * License Creative Commons 0 (like the public domain)
 * Use, study, hack and share!
 * Even if I do not force you with copyleft to respect freedom of others, please do it.
 * For more informations : https://www.gnu.org/philosophy/free-sw.html
 * This program is provided with no warranty.
 */


#include "stdio_functions.h"


void flush_stdin()
{
  int c;
  while((c = getchar()) != '\n' && c != EOF)
    /* discard */;
}

char* fgets_trimmed(char* str, int num, FILE* stream)
{
  char* res = fgets(str, num, stream);

  {
    char* last_char = str + strlen(str) -1;
    if(isspace(*last_char) || iscntrl(*last_char))
      *last_char = '\0';
  }
  
  string_trim(str, ' ');
  string_tolower(str);
  
  return res;
}

int fgets_int(char* str, int num, FILE* stream, bool* succeeded)
{
  fgets_trimmed(str, num, stream);
  
  if(succeeded != NULL)
    *succeeded = string_is_int(str);
  
  return atoi(str);
}

unsigned int fgets_uint(char* str, int num, FILE* stream, bool* succeeded)
{
  fgets_trimmed(str, num, stream);
  
  if(succeeded != NULL)
    *succeeded = string_is_uint(str);
  
  return atoi(str);
}

unsigned int ask_uint_tirelessly(const char* prompt, const char* error_message)
{
  unsigned int result;
  bool is_input_correct;
  char user_answer[20]; /* 2^64-1 has 20 digits */
  do
    {
      fputs(prompt, stdout);
      result = fgets_uint(user_answer, 20, stdin, &is_input_correct);

      if(!is_input_correct && error_message != NULL)
	fputs(error_message, stderr);
    }
  while(!is_input_correct);
  return result;
}
