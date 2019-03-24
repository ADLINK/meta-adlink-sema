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


int main(int argc, char* argv[])
{
    char ipAddr[24] = "127.0.0.1";
    uint32_t ret = 0;
    uint32_t handler;
	uint32_t pMaxDelay = 0;
	uint32_t pMaxEventTimeout = 0;
	uint32_t pMaxResetTimeout;
	uint32_t triggerTimes;

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

	// Strat WatchDog
	pMaxResetTimeout = 10000; // 10s
	ret = SemaEApiWDogStart(handler, pMaxDelay, pMaxEventTimeout, pMaxResetTimeout);
	if(ret != EAPI_STATUS_SUCCESS) {
		printf("Can't start SEMA watchdog. Error code: %X\n",ret);
	}else{
		printf("Start WatchDog...\n\n");
	}

	// Trigger WatchDog
	triggerTimes = 5; // Run 5 times SEMA WatchDog Trigger
	while(triggerTimes>0){
		printf("Waiting for 5s, and then trigger watchdog\n");
		delay(5000);
		ret = SemaEApiWDogTrigger(handler);
		if(ret != EAPI_STATUS_SUCCESS) {
			printf("Can't trigger SEMA watchdog. Error code: %X",ret);
		}else{
			printf("Trigger Times : %d \n",triggerTimes);
			printf("Trigger WatchDog...\n\n");
		}
		triggerTimes--;
	}

	// Stop WatchDog
	ret = SemaEApiWDogStop(handler);
	if(ret != EAPI_STATUS_SUCCESS) {
		printf("Can't stop SEMA watchdog. Error code: %X\n",ret);
	}else{
		printf("Stop WatchDog...\n");
	}
	 

    // Uninitialize SEMA lib and free resources
    SemaEApiLibUnInitialize(handler);
 

    return 0;
}

