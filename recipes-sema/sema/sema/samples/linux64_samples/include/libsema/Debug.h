/**
********************************************************************************
*	\FILE		Debug.h
*
*	\DESCRIPTION
*		Debug functions
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/

#ifndef DEBUG_H
#define DEBUG_H

#include "Globals.h"
#include "DLL_Exports.h"
#include <stdio.h>


/* ------------------------------ Definitions ------------------------------- */
/* ------------------------------- Typedefs  -------------------------------- */
/* -------------------------------- Macros ---------------------------------- */

#define Dbg		Debug_Enable


/* ------------------------------- Variables -------------------------------- */

DLL_EXPORT extern bool Debug_Enable;


/* ------------------------------- Functions -------------------------------- */
void Dbg_Continue(void);




#endif /* DEBUG_H */
