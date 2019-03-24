/**
********************************************************************************
*	\FILE		SMBus.h
*
*	\DESCRIPTION
*		General SMBus declarations and functions for Windows systems
*
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/

#ifndef __SMBUS_H__
#define __SMBUS_H__
#include "../Globals.h"
#include "../../driver/win32/SemaSMBPublic.h"

//James 2013.06.11 >>>
dword Rdmsr(dword index, pdword eax, pdword edx);
//<<<
void nsleep (dword msecs);
/* ------------------------------ Definitions ------------------------------- */
//#define	SleepMS(msecs)		Sleep(msecs)
#define	SleepMS(msecs)	 nsleep(msecs)

/* ------------------------------- Typedefs  -------------------------------- */
typedef enum
{
	TT_E1_WBL,		// ext. bus #1 write block
	TT_E1_RBL,		// ext. bus #1 read block
	TT_E1_WBY,		// ext. bus #1 write byte
	TT_E1_RBY,		// ext. bus #1 read byte
	TT_E2_WBL,		// ext. bus #2 write block
	TT_E2_RBL,		// ext. bus #2 read block
	TT_E2_WBY,		// ext. bus #2 write byte
	TT_E2_RBY,		// ext. bus #2 read byte
    TT_E1_RWCB,     // ext. bus #1 read/write command byte
    TT_E2_RWCB      // ext. bus #2 read/write command byte

}tExtTransType;





/* -------------------------------- Macros ---------------------------------- */
#define IsReadAdr(a)	(a&1)		///< Tests if address is read address
#define IsWriteAdr(a)	(!(a&1))	///< Tests if address is write address

/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */


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
char* SMBus_GetChipsetString(void);
/**
********************************************************************************
*	\FUNCTION		int SMBus_PEC(unsigned)
********************************************************************************

void SMBus_PEC( unsigned PECFlag );
{
/**
********************************************************************************
*	\FUNCTION		int SMBus_SMI_Temp(unsigned)
********************************************************************************
**/


int  SMBus_SMI_Temp( unsigned SMI_Temp );



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

#endif
