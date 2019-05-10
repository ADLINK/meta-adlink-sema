/**
********************************************************************************
*	\FILE		WinCE.h
*
*	\DESCRIPTION
*		Functions from Win32 Api miising in WinCE
*
*	\AUTHOR		Simon Berg
*				(c) LiPPERT Embedded Computers GmbH Germany
*
*	\CHANGE_HISTORY	
*		2009-12-3 - V0.1	- Created										- SB
********************************************************************************
**/
#ifndef __WINCE_H__
#define __WINCE_H__

#ifdef WINCE

#include <windows.h>
#include <types.h>


#define _getch() getchar()


/**
********************************************************************************
*	\FUNCTION time(time_t* timer)
*
*	\DESCRIPTION
*		Get the current time from the system clock. Stores that value in timer. 
*       If timer is null, the value is not stored, but it is still returned
*       by the function
*
*	\PARAMETERS
*		timer	Pointer to time variable 
*
*	\RETURNS
*		Time in seconds form January, 1, 1970 
********************************************************************************
**/
time_t time(time_t* timer);

#endif
#endif