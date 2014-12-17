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


#ifndef STDIO_FUNCTIONS_H
#define STDIO_FUNCTIONS_H


#include <stdio.h>
#include "string_functions.h"


/**
 * Read and discard characters up to the next newline of stdin.
 */
void flush_stdin();

/**
 * fgets of stdio.h with trim of the string.
 * @param str Pointer to an array of chars where the string read is copied.
 * @param num Maximum number of characters to be copied into str (including the terminating null-character).
 * @param stream Pointer to a FILE object that identifies an input stream.
 * @return On success, the function returns str, otherwise a null pointer is returned (but the contents pointed by str may have changed).
 */
char* fgets_trimmed(char* str, int num, FILE* stream);

/**
 * fgets of stdio.h used to have an integer.
 * @param str Pointer to an array of chars where the string read is copied.
 * @param num Maximum number of characters to be copied into str (including the terminating null-character).
 * @param stream Pointer to a FILE object that identifies an input stream.
 * @param succeeded If the string is an integer, it is set to true otherwise false.
 * @return On success, the function returns the converted integral number as an int value, otherwise it causes undefined behavior.
 */
int fgets_int(char* str, int num, FILE* stream, bool* succeeded);

/**
 * fgets of stdio.h used to have an unsigned integer.
 * @param str Pointer to an array of chars where the string read is copied.
 * @param num Maximum number of characters to be copied into str (including the terminating null-character).
 * @param stream Pointer to a FILE object that identifies an input stream.
 * @param succeeded If the string is an integer, it is set to true otherwise false.
 * @return On success, the function returns the converted unsigned integral number as an uint value, otherwise it causes undefined behavior.
 */
unsigned int fgets_uint(char* str, int num, FILE* stream, bool* succeeded);

/**
 * Ask a unsigned int as long as it something else, and returns it.
 * @param prompt A prompt written to stdout before the user can enter an unsigned int
 * @return An unsigned integer
 */
unsigned int ask_uint_tirelessly(const char* prompt);


#endif
