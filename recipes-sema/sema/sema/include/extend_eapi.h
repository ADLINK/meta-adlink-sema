/**
 *  \file   extend_eapi.h
 *  \brief  Brief
 *  \author Kevin Bui (kevin.bui@adlinktech.com)
 *  \date    2014
 *  
 *  \copyright Copyright (c) 2014 ADLINK Technology Inc.
 *  All rights reserved.\n
 *  ADLINK Technology Inc. proprietary and confidential.
 *  
 *  \details Details
 */

#ifndef __EXTEND_EAPI_H
#define __EXTEND_EAPI_H

#include <iostream>

#ifndef _WIN32
#include "linux/EApiOs.h"
#else /* _WIN32 */
#include "winnt/EApiOs.h"
#endif /* _WIN32 */

#include "EApi.h"
#include "adlink/SEMA_define.h"

/* EApiCPUGetString */
EApiStatus_t
EAPI_CALLTYPE
EApiCPUGetString(
    __IN    uint32_t Id,
    __OUT   char *pBuffer,
    __INOUT uint32_t *pBufLen
);

/* EApiCPUGetValue */
EApiStatus_t
EAPI_CALLTYPE
EApiCPUGetValue(
    __IN    uint32_t Id,
    __OUT   uint32_t *pValue
);

/* EApiCPUSetValue */
EApiStatus_t
EAPI_CALLTYPE
EApiCPUSetValue(
    __IN    uint32_t Id, /* Value Id */
    __IN    uint32_t Value /* Value */
);

/* EApiMemoryGetValue */
EApiStatus_t
EAPI_CALLTYPE
EApiMemoryGetValue(
    __IN    uint32_t Id,
    __OUT   uint32_t *pValue
);

/* EApiNetworkGetString */
EApiStatus_t
EAPI_CALLTYPE
EApiNetworkGetString(
    __IN    uint32_t Id,
    __IN    uint32_t DeviceId,
    __OUT   char     *pBuffer,
    __INOUT uint32_t *pBufLen
);

/* EApiNetworkGetValue */
EApiStatus_t
EAPI_CALLTYPE
EApiNetworkGetValue(
    __IN    uint32_t Id,
    __IN    uint32_t DeviceId,
    __OUT   uint32_t *pValue
);

/* EApiSystemBootSet */
EApiStatus_t
EAPI_CALLTYPE
EApiSystemBootSet(
    __IN    uint32_t Id,
    __IN    uint32_t delay
);

/* EApiDiskNum */
EApiStatus_t
EAPI_CALLTYPE
EApiDiskNum(
	__OUT   uint32_t *DiskNumber
);

/* EApiDiskInfo */
EApiStatus_t
EAPI_CALLTYPE
EApiDiskInfo(
    __IN    uint32_t DiskId,
    __OUT   char *pBuffer,
    __INOUT uint32_t *pBufLen
);

/* EApiDiskSMARTAll */
EApiStatus_t
EAPI_CALLTYPE
EApiDiskSMARTAll(
    __IN    uint32_t DiskId,
    __OUT   char *pBuffer,
    __INOUT uint32_t *pBufLen
);

/* EApiDiskSMART */
EApiStatus_t
EAPI_CALLTYPE
EApiDiskSMART(
	__IN    uint32_t DiskId,
	__IN    uint32_t ID,
	__OUT   uint32_t *pNormValue,
	__OUT   char     *pRawValue
);


/* EapiGetIDString */
EApiStatus_t
EAPI_CALLTYPE
EapiGetIDString(
    __IN    uint32_t Id,
    __OUT     char     *pBuffer , /* Destination pBuffer */
    __INOUT   uint32_t *pBufLen   /* pBuffer Length */
);

/* EApiSetIDString */
EApiStatus_t
EAPI_CALLTYPE
EApiSetIDString(
    __IN    uint32_t Id,
    __IN	char *pBuffer,
    __IN	uint32_t BufLen
);

/* EApiBIOSUpdate */
EApiStatus_t
EAPI_CALLTYPE
EApiBIOSUpdate(
	__IN	char		*pFileName,
	__IN	char		*pCheckSum
);

/* EApiBMCUpdate */
EApiStatus_t
EAPI_CALLTYPE
EApiBMCUpdate(
	__IN	char		*pFileName,
	__IN	char		*pCheckSum,
	__IN 	bool bReboot,  /* Reboot operating system after FW update?  */
	__IN 	uint32_t Delay  /*the delay in seconds for the reboot */
);


#endif  //__EXTEND_EAPI_H
