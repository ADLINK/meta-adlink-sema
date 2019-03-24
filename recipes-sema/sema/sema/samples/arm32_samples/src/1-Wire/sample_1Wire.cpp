/**
 *  \file   sample_watchdog.cpp
 *  \brief  SEMA sample code for WatchDog
 *  \author Annie
 *  \date   Jul 2015
 *  
 *  \copyright Copyright (c) 2014 ADLINK Technology Inc.
 *  All rights reserved.\n
 *  ADLINK Technology Inc. proprietary and confidential.
 */

#include <cstdlib>
#include <stdio.h>

#ifndef _WIN32
    #include "linux/EApiOs.h"
    #include "unistd.h"
#else /* _WIN32 */
    #include "winnt/EApiOs.h"
    #include "Windows.h"
#endif /* _WIN32 */

#include "EApi.h"
#include "semaeapi.h"

#define	FAMILY_CODE( VALUE )	( VALUE )

#define	SERIAL_NO( VALUE1, VALUE2, VALUE3, VALUE4, VALUE5, VALUE6 )	VALUE1, VALUE2, VALUE3, VALUE4, VALUE5, VALUE6

#define	CRC( VALUE )		( VALUE )

int main(int argc, char* argv[])
{
    char ipAddr[24] = "127.0.0.1";
    uint32_t ret = 0;
    uint32_t handler;

    printf("\n******* SEMA EAPI Sample - WatchDog Trigger *******\n");
    if(argc >= 2) {
        strcpy(ipAddr, argv[1]);
        printf("Connect to remote IP address: %s\n", ipAddr);    }
    else{
        printf("Running SEMA EAPIs locally (%s)\n", ipAddr);
    }
    printf("\n");

    // Initialize the SEMA EAPI Lib
    ret = SemaEApiLibInitialize(false, IP_V4, ipAddr, 0, (char*)"123", &handler);
    if (ret != EAPI_STATUS_SUCCESS) {
        printf("Can't initialize SEMA Lib. Error code: %X\n", ret);
        return -1;
    }

	// Write data to EEPROM
	{
		char	acSerialNo[] = { SERIAL_NO( 0x0, 0x0, 0x15, 0xc, 0x50, 0xbf ) };

		char	acCommand[] = { 0xf };

		char	acData[] = { 0x1c, 0x00, 0xab, 0xbb };

		ret	= SemaEApi1WireSendFunctionCmd( handler, FAMILY_CODE( 0x2d ), acSerialNo, CRC( 0xc ), acCommand, sizeof( acCommand ) / sizeof( *acCommand ), acData, sizeof( acData ) / sizeof( *acData ) );

		if( ret != EAPI_STATUS_SUCCESS )
			printf( "Write EEPROM : Failed to send function command.\n" );

	}

	// Read data from EEPROM
	{
		char	acSerialNo[] = { SERIAL_NO( 0x0, 0x0, 0x15, 0xc, 0x50, 0xbf ) };

		char	acCommand[] = { 0xaa };

		char	acData[] = { 0x1c, 0x00 };

		ret	= SemaApi_1WireSendFunctionCmd( handler, FAMILY_CODE( 0x2d ), acSerialNo, CRC( 0xc ), acCommand, sizeof( acCommand ) / sizeof( *acCommand ), acData, sizeof( acData ) / sizeof( *acData ) );

		if( ret != EAPI_STATUS_SUCCESS )
			printf( "Read EEPROM : Failed to send function command.\n" );

		char	acBuffer[ 16 ] = { 0 };

		int	iLoop;

		ret	= SemaEApi1WireRead( handler, cBuffer , sizeof( cBuffer ) / sizeof( *cBuffer ), 8 );

		if( ret != EAPI_STATUS_SUCCESS )
			printf( "Read EEPROM : Failed to read data from 1-Wire device.\n" );

		for( iLoop = 0 ; iLoop < sizeof( cBuffer ) / sizeof( *cBuffer ) ; ++iLoop )
			printf( "0x%x ", *( cBuffer + iLoop ) );

	}

    // Uninitialize SEMA lib and free resources
    SemaEApiLibUnInitialize(handler);
 

    return 0;
}

