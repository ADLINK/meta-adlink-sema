/**
********************************************************************************
*	\FILE		Globals.h
*
*	\DESCRIPTION
*		Global definitions and constants
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/

#ifndef GLOBALS_H
#define GLOBALS_H


/* ------------------------------ Definitions ------------------------------ */

#define PI			3.1415926535897932384626433832795


typedef unsigned char	byte;		///<  8 bit unsigned
typedef unsigned short	word;		///< 16 bit unsigned
typedef unsigned long	dword;		///< 32 bit unsigned
//James 2013.06.11 >>>
typedef unsigned long	*pdword;		///< 32 bit unsigned
//<<<

#ifndef __cplusplus
typedef char bool;					///< bool for standard c
#define false 0
#define true 1
#endif


/* ------------------------------- Typedefs -------------------------------- */

typedef void (*tVoidFunc)(void);	///< Pointer to parameterless void function


/* -------------------------------- Macros --------------------------------- */


#define lengthof(array) (sizeof(array)/sizeof(array[0]))	///< Number of array elements

#define mmax(a, b)	((a)>(b)? (a) : (b))					///< Returns maximum of two values
#define mmin(a, b)	((a)<(b)? (a) : (b))					///< Returns minimum of two values

#define UNUSED(Param)	Param								///< Prevents compiler warning for unused parameters


/* ------------------------------- Functions ------------------------------- */

/* AD:
Note: Below 2 macros were taken care in respective Makefile and if no effect then define here */
//#define VXWORKS 1    // for vxworks, define this macro to 1 - Added as per readme
//#define LP64_MODE 1  // Define this macro 64bit vxworks, if Makefile has no effect

#endif /* GLOBALS_H */
