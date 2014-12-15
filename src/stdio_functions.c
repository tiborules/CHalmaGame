/**
 * License Creative Commons 0 (like the public domain)
 * Use, study, hack and share!
 * Even if I do not force you with copyleft to respect freedom of others, please do it.
 * For more informations : http://www.gnu.org/philosophy/free-sw.html
 * This program is provided with no warranty.
 */


#include "stdio_functions.h"


void flush_stdin()
{
  int c;
  while((c = getchar()) != '\n' && c != EOF)
    /* discard */;
}
