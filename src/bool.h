/**
 * @file
 * @author Nicola Spanti (RyDroid) <dev@nicola-spanti.info>
 * 
 * @section license License
 * 
 * License Creative Commons 0 (like the public domain)
 * Use, study, hack and share!
 * Even if you are not force with copyleft to respect freedom of others, please do it.
 * For more informations: https://www.gnu.org/philosophy/free-sw.html
 * This program is provided with no warranty.
 * Names of contributors must not be used to endorse or promote products derived from this software without specific prior written permission.
 * 
 * @section desc Description
 * 
 * stdbool.h of C99 does the same thing.
 * Unfortunately there is nothing for using bool with printf and scanf.
 * The real type can be different with 2 implementations (for example with GCC and Clang).
 * The aim of this header is to be independant of the implementation and to be independant of C99 library.
 */

#ifndef _BOOL_H_
#define _BOOL_H_

/** Specifies whether bool, true and false are defined. */
#define	__bool_true_false_are_defined 1

#ifndef __cplusplus

#define false 0
#define true  1
#define FALSE 0
#define TRUE  1
typedef char bool;

#endif /* __cplusplus  */

#endif /* _BOOL_H_  */
