#include <unistd.h>
#ifndef VXWORKS
#include <sys/io.h>
#endif
#ifndef __SMBUS_LINUX_H__
#define __SMBUS_LINUX_H__
#include "../Globals.h"
#include "../../driver/linux/LinuxSMBus.h"


/* ------------------------------ Definitions ------------------------------- */
/* ------------------------------- Typedefs  -------------------------------- */
/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */

//James add >>>
dword Rdmsr(dword address, pdword msr);
//<<<

/**
********************************************************************************
*	\FUNCTION		int SMBus_Init(void)
*
*	\DESCRIPTION
*		Identifies chipset and calls chipset specific Init() function
*
*	\RETURNS
*		Returncode (refer to ErrorCodes.h->ERROR_SMBUS_CLASS)
********************************************************************************
**/
int SMBus_Init(void);


/**
********************************************************************************
*	\FUNCTION		byte SMBus_BlockTrans(byte Address, byte Command, byte Length, byte *Buffer)
*
*	\DESCRIPTION
*		Perform a SMBus block transfer (will be passed through to chipset specific function)
*
*	\PARAMETERS
*		Address		SMBus address											\np
*		Command		Command													\np
*		Length		Data length												\np
*		Buffer		Location of data to exchange
*
*	\RETURNS
*		number of exchanged bytes
********************************************************************************
**/
byte SMBus_Trans(byte Address, tTransType Type, byte *Buffer);
byte SMBus_BlockTrans(byte Address, byte Command, byte Length, byte *Buffer);


/**
********************************************************************************
*	\FUNCTION		char* SMBus_GetVersionAddon(void)
*
*	\DESCRIPTION
*		Returns SemaSMB driver Version Addon
*
*	\RETURNS
*		Pointer to Addon-String.
********************************************************************************
**/
char* SMBus_GetVersionAddon(void);

/**
********************************************************************************
*	\FUNCTION		short SMBus_GetVersionMajor(void)
*
*	\DESCRIPTION
*		Returns SemaSMB driver major version number
*
*	\RETURNS
*		Major Version number
********************************************************************************
**/
short SMBus_GetVersionMajor(void);

/**
********************************************************************************
*	\FUNCTION		short SMBus_GetVersionMinor(void)
*
*	\DESCRIPTION
*		Returns SemaSMB driver minor version number
*
*	\RETURNS
*		Minor Version number
********************************************************************************
**/
short SMBus_GetVersionMinor(void);

/**
********************************************************************************
*	\FUNCTION		const char *SMBus_GetChipsetString(void)
*
*	\DESCRIPTION
*		Get chipset ID string (Description)
*
*	\RETURNS
*		Pointer to Chipset String.
*	
********************************************************************************
**/
const char* SMBus_GetChipsetString(void);



/**
********************************************************************************
*	\FUNCTION		void SMBus_Close(void)
*
*	\DESCRIPTION
*		Cleans up and restores registers if necessary
*
*	\RETURNS
*		Returncode (refer to ErrorCodes.h->ERROR_SMBUS_CLASS)
********************************************************************************
**/
void SMBus_Close(void);

#ifdef SEMAADMIN
byte SMBus_GetSubID(void);
dword SMBus_GetChipsetID(void);
#endif

#endif

