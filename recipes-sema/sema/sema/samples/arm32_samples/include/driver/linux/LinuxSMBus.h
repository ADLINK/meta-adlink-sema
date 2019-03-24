/**
********************************************************************************
*	\FILE		SMBus.h
*
*	\DESCRIPTION
*		General SMBus declarations and functions
*
*		Note: To add support for new boards/chipsets:						\n
*		enter ChipsetInfo-structs in SMBus.c!
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/

#ifndef LINUXSMBUS_H
#define LINUXSMBUS_H
#include "../../libsema/Globals.h"

#ifdef VXWORKS
#include <sysLib.h>
#include <vxWorks.h>
#undef ARM

extern void sysUsDelay (int uSec);

#endif
/* ------------------------------ Definitions ------------------------------- */

#define PCIADDR					0xcf8
#define PCIDATA					0xcfc
#ifdef VXWORKS
#define Sleep(a)	sysUsDelay(a*1000)
#define usleep(a)	sysUsDelay(a)
#else
#define Sleep(a)	usleep(a*1000)
#endif

#define PI			3.1415926535897932384626433832795

// Legacy defines for old SEMA code
#define PCI_CfgSpAddr(Bus, Dev, Fun)	(0x80000000L+(Bus<<16)+(Dev<<11)+(Fun<<8))	// Calculate PCI config spade address from Bus:Dev.Function

#define	PCI_BASE_ADDRESS( bus, device, function )	( 0x80000000L + ( bus << 16 ) + ( device << 11 ) + ( function << 8 ) )
#define	BUS( bus )			bus
#define	DEVICE( device )		device
#define	FUNCTION( function )		function
#define	REGISTER( PCI_register )	PCI_register

#define	CHIPSET_ID( vendor_id, device_id )	( vendor_id | device_id << 16 )
#define	VENDOR_ID( vendor_id )	( vendor_id )
#define	DEVICE_ID( device_id )	( device_id )

#ifdef ARM		// ARM: no port access, everything is memory mapped
	#define		PortTalk_InByte(PortAddress)			(0)
	#define		PortTalk_OutByte(PortAddress, Value)	
	#define		PortTalk_InDWord(PortAddress)			(0)
	#define		PortTalk_OutDWord(PortAddress, Value)	
#else // ARM
#ifdef VXWORKS
#define	PortTalk_InByte(PortAddress)			sysInByte((word)(PortAddress))
#define	PortTalk_OutByte(PortAddress, Value)	sysOutByte((word)(PortAddress),(byte)(Value))
#define	PortTalk_InDWord(PortAddress)			sysInLong((word)(PortAddress))
#define	PortTalk_OutDWord(PortAddress, Value)	sysOutLong((word)(PortAddress),(dword)Value)
#else
#define	PortTalk_InByte(PortAddress)			inb((word)(PortAddress))
#define	PortTalk_OutByte(PortAddress, Value)	outb((byte)(Value), (word)(PortAddress))
#define	PortTalk_InDWord(PortAddress)			inl((word)(PortAddress))
#define	PortTalk_OutDWord(PortAddress, Value)	outl((dword)Value, (word)(PortAddress))
#endif
#endif // ARM


// Sleep/Wait
#ifdef VXWORKS
#define		SleepMS(msecs)							sysUsDelay(1000*msecs)
#else
#define		SleepMS(msecs)							usleep(1000*msecs)
#endif

/* ------------------------------- Typedefs  -------------------------------- */

typedef enum
{
	TT_WB,
	TT_WBB,
	TT_WBW,
	TT_WWB,
	TT_RB,
	TT_RBB,
	TT_RBW,
	TT_RWB
}tTransType;


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
	TT_E1_RWCB,
	TT_E2_RWCB
}tExtTransType;




typedef void (*InitFuncPtr)(word *Base);												///< Pointer to chipset specific Init() function
typedef byte (*TransFuncPtr)(byte Address, tTransType TransType, byte *Buffer);			///< Pointer to chipset specific Trans() function
typedef byte (*BlkTransFuncPtr)(byte Address, byte Command, byte Length, byte *Buffer);	///< Pointer to chipset specific BlockTrans() function
typedef byte (*MemTransFuncPtr)(byte Address, word MemAddr, byte Length, byte *Buffer);	///< Pointer to chipset specific MemoryTrans() function
typedef void (*CloseFuncPtr)(void);														///< Pointer to chipset specific Close() function
typedef bool (*DetectedFuncPtr)(void);													///< Pointer to chipset specific BMCDetected() function
typedef byte (*SubIDFuncPtr)(void);														///< Pointer to chipset specific DetectSubID() function

typedef void (*PECSwitchPtr)(unsigned);														///< Pointer to chipset specific PEC() function


typedef struct
{
	dword			PCIBaseAdr;			// SMBus controller address (0x8000000 + Dev&0b11111<<11 + Fun&0b111<<8) == (0x80000000+0b dddd dfff 0000 0000)
	byte			Register;			// Base address register location
	dword			ChipsetID;			// Chipset ID (VendorID and DeviceID)
	const char		*Description;		// Descriptive text
	InitFuncPtr		Initfunc;			// Pointer to chipset specific Init() function
	TransFuncPtr	Transfunc;			// Pointer to chipset specific Trans() function
	BlkTransFuncPtr	BlockTransfunc;		// Pointer to chipset specific BlockTrans() function
	MemTransFuncPtr	MemoryTransfunc;	// Pointer to chipset specific MemoryTrans() function
	CloseFuncPtr	Closefunc;			// Pointer to chipset specific Close() function
	DetectedFuncPtr	BMCDetectedfunc;	// Pointer to chipset specific BMCDetected() function
	SubIDFuncPtr	SubIDfunc;			// Pointer to chipset specific DetectSubID() function
	PECSwitchPtr	PECSwitch;		// Pointer to chipset specific PEC() function
} tSMBusInfo;


/* -------------------------------- Macros ---------------------------------- */

#define BMC_IsReadAdr(a)	(a&1)		///< Tests if address is read address
#define BMC_IsWriteAdr(a)	(!(a&1))	///< Tests if address is write address

#define TT_IsWriteAccess(x)	(((Type==TT_WB) || (Type==TT_WBB) || (Type==TT_WBW) || (Type==TT_WWB))?1:0)
#define TT_IsReadAccess(x)	(((Type==TT_RB) || (Type==TT_RBB) || (Type==TT_RBW) || (Type==TT_RWB))?1:0)

#define lengthof(array) (sizeof(array)/sizeof(array[0]))	///< Number of array elements

#define mmax(a, b)	((a)>(b)? (a) : (b))					///< Returns maximum of two values
#define mmin(a, b)	((a)<(b)? (a) : (b))					///< Returns minimum of two values

#define UNUSED(Param)	Param								///< Prevents compiler warning for unused parameters

/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */


/**
********************************************************************************
*	\FUNCTION		const char *SMBus_GetChipsetString(void)
*
*	\DESCRIPTION
*		Get chipset ID string (Description)
*
*	\RETURNS
*		pointer to chipset ID string
********************************************************************************
**/
const char *Linux_SMBus_GetChipsetString(void);


/**
********************************************************************************
*	\FUNCTION		dword SMBus_GetChipsetID(void)
*
*	\DESCRIPTION
*		Get chipset ID (Vendor- + Device ID)
*
*	\RETURNS
*		Vendor- + Device ID
********************************************************************************
**/
dword Linux_SMBus_GetChipsetID(void);


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
int Linux_SMBus_Init(void);


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
byte Linux_SMBus_Trans(byte Address, tTransType Type, byte *Buffer);
byte Linux_SMBus_BlockTrans(byte Address, byte Command, byte Length, byte *Buffer);
byte Linux_SMBus_MemoryTrans(byte Address, word MemoryAddr, byte Length, byte *Buffer);


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
void Linux_SMBus_Close(void);


/**
********************************************************************************
*	\FUNCTION		char* id SMBus_GetVersionAddon(void)
********************************************************************************
**/
char* Linux_SMBus_GetVersionAddon(void);

/**
********************************************************************************
*	\FUNCTION		short Linux_SMBus_GetVersionMajor(void)
********************************************************************************
**/
short Linux_SMBus_GetVersionMajor(void);


/**
********************************************************************************
*	\FUNCTION		short Linux_SMBus_GetVersionMinor(void)
********************************************************************************
**/
short Linux_SMBus_GetVersionMinor(void);

bool Linux_SMBus_BMCDetected(void);
byte Linux_SMBus_GetSubID(void);


#endif /* LINUXSMBUS_H */
