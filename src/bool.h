/**
 * @file
 * @author Spanti Nicola (RyDroid) <rydroid_dev@yahoo.com>
 * 
 * @section license License
 * 
 * License Creative Commons 0 (like the public domain)
 * Use, study, hack and share!
 * Even if I do not force you with copyleft to respect freedom of others, please do it.
 * For more informations : https://www.gnu.org/philosophy/free-sw.html
 * This program is provided with no warranty.
 * 
 * @section desc Description
 * 
 * stdbool.h of C99 does the same thing.
 * Unfortunately there is nothing for using bool with printf and scanf.
 * The real type can be different with 2 implementations (for example with GCC and Clang).
 * The aim of this header is to be independant of the implementation and to be independant of C99 compiler.
 */

#ifndef _BOOL_H_
#define _BOOL_H_

#define	__bool_true_false_are_defined 1

#ifndef __cplusplus

#define false 0
#define true  1
#define FALSE 0
#define TRUE  1
typedef char bool;

#endif /* __cplusplus  */

#endif /* _BOOL_H_  */
