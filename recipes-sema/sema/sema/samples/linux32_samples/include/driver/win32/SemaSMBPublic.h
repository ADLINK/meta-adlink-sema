/**
********************************************************************************
*	\FILE		SemaSMBPublic.h
*
*	\DESCRIPTION
*		IOCtls and data Structures for use in user mode programms
*       This code runs in: 
*			User and Kernel mode
*
*	\AUTHOR		Simon Berg
*				(c) LiPPERT ADILINK Technology GmbH Germany
*
********************************************************************************
**/
#ifndef SEMASMBPUBLIC_H
#define SEMASMBPUBLIC_H

/* ------------------------------ Definitions ------------------------------- */
#ifdef DEFINE_GUID
DEFINE_GUID (GUID_SemaSMB_INTERFACE, 
   0xa9cadf51, 0x3832, 0x4f75, 0x9b, 0xf0, 0x0e, 0x87, 0x27, 0x51, 0xbb, 0x75);
#else /* DEFINE_GUID */
	typedef unsigned char UINT8; 
#endif /* DEFINE_GUID */

#define FILEIO_TYPE 40001

// IO for block read/write
#define IOCTL_SemaSMB_READ_WRITE_BLOCK \
	CTL_CODE(FILEIO_TYPE, 0x900, METHOD_BUFFERED, FILE_ANY_ACCESS )

// IO for normal read/write
#define IOCTL_SemaSMB_READ_WRITE \
	CTL_CODE(FILEIO_TYPE, 0x901, METHOD_BUFFERED, FILE_ANY_ACCESS )

#define IOCTL_SemaSMB_GETVERSION \
	CTL_CODE(FILEIO_TYPE, 0x902, METHOD_BUFFERED, FILE_ANY_ACCESS )

#define IOCTL_SemaSMB_GETVERSION_ADDON \
	CTL_CODE(FILEIO_TYPE, 0x903, METHOD_BUFFERED, FILE_ANY_ACCESS )

#define IOCTL_SemaSMB_GETSMBSTRING \
	CTL_CODE(FILEIO_TYPE, 0x904, METHOD_BUFFERED, FILE_ANY_ACCESS )
	
//James >>>
#define IOCTL_SemaSMB_READ_MSR \
        CTL_CODE(FILEIO_TYPE, 0x905, METHOD_BUFFERED, FILE_ANY_ACCESS )
//#define IOCTL_SemaSMB_WRITE_MSR \
//     CTL_CODE(FILEIO_TYPE, 0x906, METHOD_BUFFERED, FILE_ANY_ACCESS )  
//<<<
#define IOCTL_SemaSMB_PEC\
        CTL_CODE(FILEIO_TYPE, 0x990, METHOD_BUFFERED, FILE_ANY_ACCESS)

//<<<
#define IOCTL_SemaSMB_SMITEMP_STOP\
        CTL_CODE(FILEIO_TYPE, 0x991, METHOD_BUFFERED, FILE_ANY_ACCESS)

//<<<
#define IOCTL_SemaSMB_SMITEMP_START\
        CTL_CODE(FILEIO_TYPE, 0x992, METHOD_BUFFERED, FILE_ANY_ACCESS)



#define SMB_MAX_LENGTH 32			// Maximun Bytes to transmit in one Block Read/Write
#define SEMASMB_VERSION_ADDON_MAXSIZE 32
#define SEMASMB_VERSION_GETSMBSTRING_SIZE 0x40
#define SEMASMB_PEC_SIZE 0x01


/* ------------------------------- Typedefs  -------------------------------- */
typedef enum {
	TT_WB,		// Write Byte
	TT_WBB,		// Write Byte(Cmd) Byte
	TT_WBW,		// Write Byte(Cmd) Word
	TT_WWB,		// Write Word(Cmd) Byte
	TT_RB,		// Read Byte	
	TT_RBB,		// Read Byte(Cmd) Byte
	TT_RBW,		// Read Byte(Cmd) Word
	TT_RWB,		// Read Word(Cmd) Byte
	TT_RBL,		// Read Block
	TT_WBL		// Write Block
}tTransType;

typedef struct _SMB_COMMAND {
	UINT8	address;				// 7! Bit SMB Address
	UINT8	transferType;			// One of tTransType
	UINT8	command;				// Command Byte for Block Read/Write
	UINT8	datalength;				// Length of data to write
	UINT8   data[SMB_MAX_LENGTH];	// Data Array for receive/send data
} SMB_COMMAND, * PSMB_COMMAND;

typedef struct _MSR_COMMAND {
      unsigned long address;
} MSR_COMMAND, * PMSR_COMMAND;

/* -------------------------------- Macros ---------------------------------- */
/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */

#endif /* SEMASMBPUBLIC_H */
