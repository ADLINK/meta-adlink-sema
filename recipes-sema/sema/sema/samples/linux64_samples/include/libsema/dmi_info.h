/**
********************************************************************************
*	\FILE		dmi_info.h
*
*	\DESCRIPTION
*		Basisc acces to the BIOS version string over the SMBios
*		This File made use of function writen by Mark Russinovich
*		Systems Internals for the tool physmem. The complete source 
*		is avalable here: http://court.shrock.org/sysinternals-bt/
*
*	\AUTHOR		Simon Berg
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/
#ifndef DMI_INFO_H
#define DMI_INFO_H

#include "DLL_Exports.h"

#ifdef __cplusplus
extern "C" {
#endif	 

	DLL_EXPORT int DMI_GetBiosVersion(char* version);

#ifdef __cplusplus
}
#endif	 
#endif /* DMI_INFO_H */

#ifdef VXWORKS

#define PAGE_SIZE (4*1024)
int getpagesize();

#endif