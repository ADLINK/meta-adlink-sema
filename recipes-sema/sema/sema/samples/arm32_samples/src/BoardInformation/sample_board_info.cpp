/**
 *  \file   sample_board_info.cpp
 *  \brief  SEMA sample code for HDD S.M.A.R.T.
 *  \author Fencer Kao
 *  \date   Dec 2014
 *  
 *  \copyright Copyright (c) 2014 ADLINK Technology Inc.
 *  All rights reserved.\n
 *  ADLINK Technology Inc. proprietary and confidential.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>

#ifndef _WIN32
#include "linux/EApiOs.h"
#else /* _WIN32 */
#include "winnt/EApiOs.h"
#endif /* _WIN32 */
#include "EApi.h"
#include "semaeapi.h"
using namespace std;

void getBoardInfo(uint32_t handler, EApiId_t id, string message)
{
    char buffer[256] = {};
    uint32_t ret = 0;
    uint32_t bufLen = 256;

    printf("%s: ", message.c_str());
    // Get data
    ret = SemaEApiBoardGetStringA(handler, id, buffer, &bufLen);
    if (ret != EAPI_STATUS_SUCCESS) {
        printf("ERROR: 0x%X\n", ret);
    }
    else{
        printf("'%s'", buffer);
    }
    printf("\n");
}


int main(int argc, char* argv[])
{
    char ipAddr[24] = "127.0.0.1";
    uint32_t ret = 0;
    uint32_t handler;

    printf("\n******* SEMA EAPI Sample - Board Information *******\n");
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
        printf("Can't initialize SEMA Lib. Error code: %X", ret);
        return -1;
    }

    // Get Board Information Strings
    printf("GETTING BOARD INFORMATION WITH BUFFER 256 bytes...\n");
    getBoardInfo(handler, EAPI_ID_BOARD_MANUFACTURER_STR, "Board Manufacturer");
    getBoardInfo(handler, EAPI_ID_BOARD_NAME_STR, "Board Name");
    getBoardInfo(handler, EAPI_ID_BOARD_REVISION_STR, "Board Revision");
    getBoardInfo(handler, EAPI_ID_BOARD_SERIAL_STR, "Board Serial");
    getBoardInfo(handler, EAPI_ID_BOARD_BIOS_REVISION_STR, "Board BIOS Revision");
    getBoardInfo(handler, EAPI_ID_BOARD_HW_REVISION_STR, "Board HW Revision");
    getBoardInfo(handler, EAPI_ID_BOARD_PLATFORM_TYPE_STR, "Board Platform Type");

    // Uninitialize the SEMA EAPI Lib
    SemaEApiLibUnInitialize(handler);
    return 0;
}

