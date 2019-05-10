/**
 *  \file   sample_hdd_smart.cpp
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

#ifndef _WIN32
    #include "linux/EApiOs.h"
    #include "unistd.h"
#else /* _WIN32 */
    #include "winnt/EApiOs.h"
    #include "Windows.h"
#endif /* _WIN32 */

#include "EApi.h"
#include "semaeapi.h"

using namespace std;

int delay(unsigned long ms)
{
#if defined(_WIN32)
    SetLastError(0);
    Sleep(ms);
    return GetLastError() ?-1 :0;
#else
    return usleep(1000 * ms);
#endif
}


void getDiskInfo(uint32_t handler)
{
    printf("HDD Disk Information\n");

    uint32_t pBufLen = 10*1024;
    char * lpBuf = (char*)malloc( pBufLen );
    uint32_t ret = SemaEApiDiskInfo(handler, 0, lpBuf, &pBufLen);
    switch (ret)
    {
    case EAPI_STATUS_SUCCESS:
        cout << "Result: '" << lpBuf << "'" << endl;
        break;
    case EAPI_STATUS_UNSUPPORTED:
        cout << "SemaEApiDiskInfo unsupported" << endl;
        break;
    default:
        cout << "SemaEApiDiskInfo ERROR code: " << ret << endl;
        break;
    }
    free(lpBuf);
}


void getDiskSMARTAll(uint32_t handler)
{
    printf("HDD S.M.A.R.T. Information\n");

    uint32_t pBufLen = 10*1024;
    char * lpBuf = (char*)malloc( pBufLen );
    uint32_t ret = SemaEApiDiskSMARTAll(handler, 0, lpBuf, &pBufLen);
    switch (ret)
    {
    case EAPI_STATUS_SUCCESS:
        cout << "Result: '" << lpBuf << "'" << endl;
        break;
    case EAPI_STATUS_UNSUPPORTED:
        cout << "SemaEApiDiskSMARTAll unsupported" << endl;
        break;
    default:
        cout << "SemaEApiDiskSMARTAll ERROR code: " << ret << endl;
        break;
    }
    free(lpBuf);
}


int main(int argc, char* argv[])
{
    char ipAddr[24] = "127.0.0.1";
    uint32_t ret = 0;
    uint32_t handler;

    printf("\n******* SEMA EAPI Sample - HDD S.M.A.R.T Information *******\n");
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

    // Get Disk Information
    getDiskInfo(handler);
    // Get all SMART Information
    getDiskSMARTAll(handler);
    
    // Get SMART single information
    uint32_t nvalue = 0;
    char* raw =(char*)malloc(8);   // Allocate 8 bytes for result buffer
    printf("Delay for 5s before continue ...\n");
    delay(5000);
    while(1) {
#if defined(_WIN32)
        system("cls");
#else
        system("clear");
#endif
        ret = SemaEApiDiskSMART(handler, 0, 194 ,&nvalue, raw);
        cout << "HDD Temperature: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 1 ,&nvalue, raw);
        cout << "Raw_Read_Error_Rate: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 3 ,&nvalue, raw);
        cout << "Spin_Up_Time: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 4 ,&nvalue, raw);
        cout << "Start_Stop_Count: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 5 ,&nvalue, raw);
        cout << "Reallocated_Sector_Ct: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 7 ,&nvalue, raw);
        cout << "Seek_Error_Rate: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 9 ,&nvalue, raw);
        cout << "HDD Power_On_Hours: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 10 ,&nvalue, raw);
        cout << "Spin_Retry_Count: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 12 ,&nvalue, raw);
        cout << "Power_Cycle_Count: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 184 ,&nvalue, raw);
        cout << "End-to-End_Error: '" << nvalue << "'" << endl;

        ret = SemaEApiDiskSMART(handler, 0, 187 ,&nvalue, raw);
        cout << "Reported_Uncorrect: '" << nvalue << "'" << endl;

        // Delay 1s for each loop
        delay(1000);
    }

    // Uninitialize SEMA lib and free resources
    SemaEApiLibUnInitialize(handler);
    free(raw);

    return 0;
}

