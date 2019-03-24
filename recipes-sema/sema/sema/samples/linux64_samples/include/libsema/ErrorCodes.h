/**
********************************************************************************
*	\FILE		ErrorCodes.h
*
*	\DESCRIPTION
*		Error- and return codes
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/

#ifndef ERRCODES_H
#define ERRCODES_H


/* ------------------------------ Definitions ------------------------------- */

#define EC_CLASS_FACTOR				100			// Error class factor (see examples below)


#define EC_NO_ERROR					0			// Everything is fine

#define EC_FAILED					-10			// Failed
#define EC_UNSUPPORTED				-11			// Unsupport
#define EC_MORE_DATA				-12			// buffer not enough space
#define EC_NOT_INITIALIZE			-13			// smbus not init
#define EC_INVALID_PARAMETER		-14			

#define EC_SMBUS_CLASS				-1			// Errorclass for module SMBus
#define EC_SMBUS_NO_PORTTALK		-101		// Porttalk.sys driver not accessible
#define EC_SMBUS_UNSUP_CHIPSET		-102		// Unsupported chipset found
#define EC_SMBUS_NO_BMC				-103		// BMC not detected


#define EC_SEMA_APP_CLASS			-2			// Errorclass for module SEMA application
#define EC_SEMA_APP_ALREADY_RUNNING	-201		// SEMA application already running
#define EC_SEMA_APP_BAD_KEY			-202		// Bad key for admin mode


#define EC_FILE_CLASS				-3			// Errorclass for file handling
#define EC_FILE_NOT_FOUND			-301		// File not found
#define EC_FILE_ACCESS_ERROR		-302		// Error during file access

#define EC_SIMULATION_CLASS			-4
#define EC_SIMULATION_NOT_SIMUL		-401

/* ------------------------------- Typedefs  -------------------------------- */

typedef int tErrorCodeType;


/* -------------------------------- Macros ---------------------------------- */
/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */


#endif /* ERRCODES_H */
