#ifndef _SEMAEAPI_H_        
#define _SEMAEAPI_H_


#ifndef _WIN32
#include "linux/EApiOs.h"
#else /* _WIN32 */
#include "winnt/EApiOs.h"
#endif /* _WIN32 */

//#include "semaeapi_private.h"
#include "EApi.h"
#include "adlink/SEMA_define.h"

#if defined _WIN32 || defined __CYGWIN__
  #ifdef EAPI_BUILDING_LIB
    #ifdef __GNUC__
      #define SEMA_EAPI_CALLTYPE __attribute__((dllexport))
    #else
      #define SEMA_EAPI_CALLTYPE __declspec(dllexport) /* Note: actually gcc seems to also supports this syntax. */
    #endif
  #else
    #ifdef __GNUC__
      #define SEMA_EAPI_CALLTYPE __attribute__((dllimport))
    #else
      #define SEMA_EAPI_CALLTYPE __declspec(dllimport) /* Note: actually gcc seems to also supports this syntax. */
    #endif
  #endif
#else
  #if __GNUC__ >= 4
    #define SEMA_EAPI_CALLTYPE __attribute__ ((visibility("default")))
  #else
    #define SEMA_EAPI_CALLTYPE
  #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* 
 * \brief  SemaEApiLibInitialize
 * 
 * \details Initialize the access of EAPI on remote target. 
 *
 * \param	[ssl] ssl true for security connection
 * \param	[in] pHostIP  IP address to connect
 * \param	[in] port  port number to conect  <em>(default=9999)</em>
 * \param	[in] pPasswd  pass world to access the remote target
 * \param	[out] pHandler  the board handle to be used for the remote eapi
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiLibInitialize(
		__IN	bool	ssl,
		__IN	IP_Version ipv,
		__IN	char  *pHostIP,
		__IN	uint32_t   port,
		__IN	char   *pPasswd,
		__OUT  	uint32_t  *pHandler
	); 

/* 
 * \brief  SemaEApiLibUnInitialize
 * 
 * \details Uninitialize the access of EAPI on remote target. 
 *
 * \param	[in] Handler  the board handle to be released
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE 
SemaEApiLibUnInitialize(
		__IN  uint32_t Handler
	);



/* 
 * \brief  SemaEApiBoardGetStringA
 * 
 * \details The remote function call for EApiBoardGetStringA. Refer to EApiBoardGetStringA of EAPI 1.0
 *
 * \param	[in] pHandler  board handle
 * \param	[in] Id  Name Id
 * \param	[in] pBuffer  Destination pBuffer
 * \param	[out] pBufLen   pBuffer Length
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBoardGetStringA(
	__IN  uint32_t Handler ,
    __IN      EApiId_t  Id      , /* Name Id */
    __OUT     char     *pBuffer , /* Destination pBuffer */
    __INOUT   uint32_t *pBufLen   /* pBuffer Length */
    );

/* 
 * \brief  SemaEApiBoardSetStringA
 * 
 * \details The remote function call for EApiBoardGetStringA. Refer to EApiBoardGetStringA of EAPI 1.0
 *
 * \param	[in] pHandler  board handle
 * \param	[in] Id  Name Id
 * \param	[in] pBuffer  Destination pBuffer
 * \param	[in] BufLen   pBuffer Length
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBoardSetStringA(
	__IN	uint32_t Handler ,
    __IN	EApiId_t  Id      , /* Name Id */
    __IN	char     *pBuffer , /* Destination pBuffer */
    __IN	uint32_t BufLen   /* pBuffer Length */
    );


/* 
 * \brief  SemaEApiBoardGetValue
 * 
 * \details The remote function call for EApiBoardGetValue. Refer to EApiBoardGetValue of EAPI 1.0
 *
 * \param	[in] pHandler board handle
 * \param	[in] Id   Value Id
 * \param	[out] pValue   Return Value 
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiBoardGetValue(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Value Id */
    __OUT uint32_t *pValue    /* Return Value */
    );

/*******************************************************************************
 *
 *      C P U
 *
 *
 *******************************************************************************/

/**
 *  \brief SemaEApiCPUGetString
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Id           Value Id
 *  \param [in] pBuffer      Pointer to destination buffer
 *  \param [inout] pBufLen   Pointer to buffer length variable
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiCPUGetString.
 *  Refer to SemaEApiCPUGetString of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiCPUGetString(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __OUT   char *pBuffer,
    __INOUT uint32_t *pBufLen
    );


/**
 *  \brief SemaEApiCPUGetValue
 *  
 *  \param [in]  BoardHandler Board Handler
 *  \param [in]  Id           Value Id
 *  \param [in] pValue       Pointer to return value
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiCPUGetValue.
 *  Refer to SemaEApiCPUGetValue of SEMA_Extended_EAPI
 *  
 *  \warning If the ID is EAPI_ID_SEMA_CPU_USAGE, 2 conditions must be required:\n
 *  1. Need to wait at least 550ms from the time when SemaEApiLib was initialized
 *  before calling this API
 *  2. In order to get the new CPU usage value, the interval between 2 times
 *  calling this API must be equal or greater than 550ms
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiCPUGetValue(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __OUT   uint32_t *pValue
);


/**
 *  \brief SemaEApiCPUSetValue
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Id           Value Id
 *  \param [in] Value        Value to set
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiCPUSetValue.
 *  Refer to SemaEApiCPUSetValue of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiCPUSetValue(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __IN    uint32_t pValue
);


/*******************************************************************************
 *
 *      M E M O R Y
 *
 *
 *******************************************************************************/

/**
 *  \brief SemaEApiMemoryGetValue
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Id           Value Id
 *  \param [in] pValue       Pointer to return value
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiMemoryGetValue.
 *  Refer to SemaEApiMemoryGetValue of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiMemoryGetValue(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __OUT   uint32_t *pValue
);


/*******************************************************************************
 *
 *      N E T W O R K
 *
 *
 *******************************************************************************/

/**
 *  \brief SemaEApiNetworkGetString
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Id           Value Id
 *  \param [in] DeviceId     Device Id
 *  \param [in] pBuffer      Pointer to destination buffer
 *  \param [inout] pBufLen   Pointer to buffer length variable
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiNetworkGetString.
 *  Refer to SemaEApiNetworkGetString of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiNetworkGetString(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __IN    uint32_t DeviceId,
    __OUT   char     *pBuffer,
    __INOUT uint32_t *pBufLen
);


/**
 *  \brief SemaEApiNetworkGetValue
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Id           Value Id
 *  \param [in] DeviceId     Device Id
 *  \param [in] pValue       Pointer to return value
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiNetworkGetValue.
 *  Refer to SemaEApiNetworkGetValue of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiNetworkGetValue(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __IN    uint32_t DeviceId,
    __OUT   uint32_t *pValue
);


/*******************************************************************************
 *
 *      B A C K L I G H T
 *
 *
 *******************************************************************************/

/* 
 * \brief SemaEApiVgaGetBacklightEnable
 * 
 * \details The remote function call for EApiVgaGetBacklightEnable. Refer to EApiVgaGetBacklightEnable of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Value Id
 * \param	[out] pEnable   Return Value 
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiVgaGetBacklightEnable( 
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Backlight Id */
    __OUT uint32_t *pEnable   /* Backlight Enable */
    );

/* 
 * \brief SemaEApiVgaSetBacklightEnable
 * 
 * \details The remote function call for EApiVgaSetBacklightEnable. Refer to EApiVgaSetBacklightEnable of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Value Id
 * \param	[in] Enable   set value
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiVgaSetBacklightEnable(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Backlight Id */
    __IN  uint32_t  Enable    /* Backlight Enable */
    );
/* 
 * \brief SemaEApiVgaSetBacklightEnable
 * 
 * \details The remote function call for EApiVgaSetBacklightEnable. Refer to EApiVgaSetBacklightEnable of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Value Id
 * \param	[out] pBright  value of brightness 
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiVgaGetBacklightBrightness( 
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Backlight Id */
    __OUT uint32_t *pBright   /* Backlight Brightness */
    );
/* 
 * \brief SemaEApiVgaSetBacklightBrightness
 * 
 * \details The remote function call for EApiVgaSetBacklightBrightness. Refer to EApiVgaSetBacklightBrightness of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Value Id
 * \param	[in] Bright  value of brightness 
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE
SemaEApiVgaSetBacklightBrightness(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Backlight Id */
    __IN  uint32_t  Bright    /* Backlight Brightness */
    );


/*******************************************************************************
*
* 	 S T O R A G E
*
*
*******************************************************************************/

/* 
 * \brief SemaEApiStorageCap
 * 
 * \details The remote function call for EApiStorageCap. Refer to EApiStorageCap of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Value Id
 * \param	[out] pStorageSize  total size of storage
 * \param	[out] pBlockLength  Write Block Length
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiStorageCap(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id            , /* Storage Area Id */
    __OUT uint32_t  *pStorageSize , /* Total */
    __OUT uint32_t  *pBlockLength   /* Write Block Length
                                     				  * & Alignment 
                                     				  */
    );
/* 
 * \brief SemaEApiStorageAreaRead
 * 
 * \details The remote function call for EApiStorageAreaRead. Refer to EApiStorageAreaRead of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Storage Area Id
 * \param	[in] Offset   Byte Offset
 * \param	[out] pBuffer  Pointer to Data pBuffer
 * \param	[in] BufLen  Data pBuffer Size
 * \param	[in] ByteCnt  Number of bytes to read 
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiStorageAreaRead(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Storage Area Id */
    __IN  uint32_t  Offset  , /* Byte Offset */
    __OUT     void *pBuffer , /* Pointer to Data pBuffer */
    __IN  uint32_t  BufLen  , /* Data pBuffer Size in 
                               * bytes 
                               */
    __IN  uint32_t  ByteCnt   /* Number of bytes to read */
    );
/* 
 * \brief SemaEApiStorageAreaWrite
 * 
 * \details The remote function call for EApiStorageAreaWrite. Refer to EApiStorageAreaWrite of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Storage Area Id
 * \param	[in] Offset   Byte Offset
 * \param	[in] pBuffer  Pointer to Data pBuffer
 * \param	[in] ByteCnt  Number of bytes to read 
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiStorageAreaWrite(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Storage Area Id */
    __IN  uint32_t  Offset  , /* Byte Offset */
    __IN      void *pBuffer , /* Pointer to Data pBuffer */
    __IN  uint32_t  ByteCnt   /* Number of bytes to write */
    );

/*******************************************************************************
*
* 	  I 2 C
*
*
*******************************************************************************/
/* 
 * \brief SemaEApiI2CGetBusCap
 * 
 * \details The remote function call for EApiI2CGetBusCap. Refer to EApiI2CGetBusCap of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   Storage Area Id
 * \param	[out] pMaxBlkLen   Max Block Length Supported on this interface
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiI2CGetBusCap(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id         , /* I2C Bus Id */
    __OUT uint32_t *pMaxBlkLen   /* Max Block Length 
                                  * Supported on this
                                  * interface 
                                  */
    );
/* 
 * \brief SemaEApiI2CWriteReadRaw
 * 
 * \details The remote function call for EApiI2CWriteReadRaw. Refer to EApiI2CWriteReadRaw of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   I2C Bus Id
 * \param	[in] Addr   Encoded 7Bit I2C Device Address 
 * \param	[in] pWBuffer   Write Data pBuffer
 * \param	[in] WriteBCnt   Number of Bytes to write plus 1
 * \param	[out] pRBuffer   Read Data pBuffer
 * \param	[in] RBufLen   Data pBuffer Length
 * \param	[in] ReadBCnt   Number of Bytes to Read plus 1
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiI2CWriteReadRaw(
	__IN  	uint32_t Handler ,
	__IN	 EApiId_t  Id		, /* I2C Bus Id */
	__IN	 uint8_t   Addr 	, /* Encoded 7Bit I2C
								   * Device Address 
								   */
	__INOPT  void	  *pWBuffer , /* Write Data pBuffer */
	__IN	 uint32_t  WriteBCnt, /* Number of Bytes to 
								   * write plus 1
								   */
	__OUTOPT void	  *pRBuffer , /* Read Data pBuffer */
	__IN	 uint32_t  RBufLen	, /* Data pBuffer Length */
	__IN	 uint32_t  ReadBCnt   /* Number of Bytes to 
								   * Read plus 1
								   */
	);

#define SemaEApiI2CWriteRaw(Handler,Id, Addr, pBuffer, ByteCnt)         \
          SemaEApiI2CWriteReadRaw(Handler,Id, Addr, pBuffer, ByteCnt, NULL, 0, 0)
#define SemaEApiI2CReadRaw(Handler,Id, Addr, pBuffer, BufLen, ByteCnt) \
          SemaEApiI2CWriteReadRaw(Handler,Id, Addr, NULL, 0, pBuffer, BufLen, ByteCnt)

/* 
 * \brief SemaEApiI2CReadTransfer
 * 
 * \details The remote function call for EApiI2CReadTransfer. Refer to EApiI2CReadTransfer of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   I2C Bus Id
 * \param	[in] Addr   Encoded 7/10Bit I2C Device Address
 * \param	[in] Cmd    I2C Command/Offset
 * \param	[out] pBuffer  Transfer Data pBuffer 
 * \param	[in] BufLen  Data pBuffer Length 
 * \param	[in] ByteCnt   Byte Count to read
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiI2CReadTransfer(
	__IN  uint32_t Handler ,
	__IN  EApiId_t	Id		, /* I2C Bus Id */
	__IN  uint32_t	Addr	, /* Encoded 7/10Bit I2C
							   * Device Address
							   */
	__IN  uint32_t	Cmd 	, /* I2C Command/Offset */
	__OUT	  void *pBuffer , /* Transfer Data pBuffer */
	__IN  uint32_t	BufLen	, /* Data pBuffer Length */
	__IN  uint32_t	ByteCnt   /* Byte Count to read */
	);
/* 
 * \brief SemaEApiI2CWriteTransfer
 * 
 * \details The remote function call for EApiI2CWriteTransfer. Refer to EApiI2CWriteTransfer of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   I2C Bus Id
 * \param	[in] Addr   Encoded 7/10Bit I2C Device Address
 * \param	[in] Cmd    I2C Command/Offset
 * \param	[in] pBuffer  Transfer Data pBuffer 
 * \param	[in] ByteCnt   Byte Count to read
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE
SemaEApiI2CWriteTransfer(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* I2C Bus Id */
    __IN  uint32_t  Addr    , /* Encoded 7/10Bit I2C 
                               * Device Address 
                               */
    __IN  uint32_t  Cmd     , /* I2C Command/Offset */
    __IN      void *pBuffer , /* Transfer Data pBuffer */
    __IN  uint32_t  ByteCnt   /* Byte Count to write */
    );
/* 
 * \brief SemaEApiI2CProbeDevice
 * 
 * \details The remote function call for EApiI2CProbeDevice. Refer to EApiI2CProbeDevice of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   I2C Bus Id
 * \param	[in] Addr   Encoded 7/10Bit I2C Device Address
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE
SemaEApiI2CProbeDevice(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id   , /* I2C Bus Id */
    __IN  uint32_t  Addr   /* Encoded 7/10Bit 
                            * I2C Device Address 
                            */
    );


/*******************************************************************************
*
* 	  W A T C H D O G
*
*
*******************************************************************************/

/* 
 * SemaEApiWDogGetCap
 * 
 * \details The remote function call for EApiWDogGetCap. Refer to EApiWDogGetCap of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] pMaxDelay   Maximum Supported Delay in milliseconds
 * \param	[in] pMaxEventTimeout  Maximum Supported Event Timeout in milliseconds (0 == Unsupported)
 * \param	[in] pMaxResetTimeout   Maximum Supported Reset Timeout in milliseconds
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE
SemaEApiWDogGetCap(
	__IN  uint32_t Handler ,
    __OUTOPT uint32_t *pMaxDelay       , /* Maximum Supported 
                                         * Delay in milliseconds
                                         */
    __OUTOPT uint32_t *pMaxEventTimeout, /* Maximum Supported 
                                         * Event Timeout in 
                                         * milliseconds
                                         * 0 == Unsupported
                                         */
    __OUTOPT uint32_t *pMaxResetTimeout  /* Maximum Supported 
                                         * Reset Timeout in 
                                         * milliseconds
                                         */
    );
/* 
 * SemaEApiWDogStart
 * 
 * \details The remote function call for EApiWDogStart. Refer to EApiWDogStart of EAPI 1.0 \n

 * if AutoTrigger=false, program need call SemaEApiWDogTrigger manually to reset the watch dog. \n
 * Currently SEMA only suport ResetTimeout, the EventTimeout should be set as 0 \n
 * For the performance issue, the ResetTimeout should not less than 3 seconds. 
 * \param	[in] pHandler  board handle
 * \param 	[in] AutoTrigger auto reset the watch dog timer
 * \param	[in] Delay   Delay in milliseconds
 * \param	[in] EventTimeout  Event Timeout in in milliseconds 
 * \param	[in] ResetTimeout   Reset Timeout in in milliseconds
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiWDogStart(
	__IN  uint32_t Handler ,
    __IN  uint32_t Delay       , /* Delay in milliseconds */
    __IN  uint32_t EventTimeout, /* Event Timeout in 
                                  * milliseconds 
                                  */
    __IN  uint32_t ResetTimeout  /* Reset Timeout in 
                                  * milliseconds 
                                  */
    );

/* 
 * SemaEApiWDogTrigger
 * 
 * \details The remote function call for EApiWDogTrigger. Refer to EApiWDogTrigger of EAPI 1.0
 * \param	[in] pHandler  board handle
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiWDogTrigger(
	__IN  uint32_t Handler
);

/* 
 * SemaEApiWDogStop
 * 
 * \details The remote function call for EApiWDogStop. Refer to EApiWDogStop of EAPI 1.0
 * \param	[in] pHandler  board handle
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiWDogStop(
	__IN  uint32_t Handler 
);

/* 
 * SemaEApiWDogSetPwrUp
 * 
 * \details The remote function call for EApiWDogStop. Refer to EApiWDogStop of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Value   Value in milliseconds
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiPwrUpWDogStart(
	__IN  uint32_t Handler,
	__IN  uint32_t Value  /* Value in milliseconds */
);

EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiPwrUpWDogStop(
	__IN  uint32_t Handler
);

/*******************************************************************************
*
* 	  G P I O
*
*
*******************************************************************************/

/* 
 * SemaEApiGPIOGetDirectionCaps
 * 
 * \details The remote function call for EApiGPIOGetDirectionCaps. Refer to EApiGPIOGetDirectionCaps of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   GPIO Id
 * \param	[out] pInputs  Supported GPIO Input Bit Mask 
 * \param	[out] pOutputs  Supported GPIO Output Bit Mask 
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE 
SemaEApiGPIOGetDirectionCaps(
	__IN  	uint32_t Handler ,
    __IN     EApiId_t Id        , /* GPIO Id */
    __OUTOPT uint32_t *pInputs  , /* Supported GPIO Input
                                   * Bit Mask 
                                   */
    __OUTOPT uint32_t *pOutputs   /* Supported GPIO Output
                                   * Bit Mask 
                                   */
    );
/* 
 * SemaEApiGPIOGetDirection
 * 
 * \details The remote function call for EApiGPIOGetDirection. Refer to EApiGPIOGetDirection of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   GPIO Id
 * \param	[in] Bitmask  Bit mask of Affected Bits
 * \param	[out] pDirection  Current Direction
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiGPIOGetDirection(
	__IN  	uint32_t Handler ,
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected
                                  * Bits 
                                  */
    __OUT uint32_t *pDirection   /* Current Direction */
    );
/* 
 * SemaEApiGPIOSetDirection
 * 
 * \details The remote function call for EApiGPIOSetDirection. Refer to EApiGPIOSetDirection of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   GPIO Id
 * \param	[in] Bitmask  Bit mask of Affected Bits
 * \param	[in] Direction Direction
 */
EApiStatus_t 
SEMA_EAPI_CALLTYPE 
SemaEApiGPIOSetDirection(
	__IN  	uint32_t Handler ,
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected 
                                  * Bits 
                                  */
    __IN  uint32_t Direction     /* Direction */
    );
/* 
 * SemaEApiGPIOGetLevel
 * 
 * \details The remote function call for EApiGPIOGetLevel. Refer to EApiGPIOGetLevel of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   GPIO Id
 * \param	[in] Bitmask  Bit mask of Affected Bits
 * \param	[out] pLevel Current Level
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE 
SemaEApiGPIOGetLevel(
	__IN  	uint32_t Handler ,
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected
                                  * Bits 
                                  */
    __OUT uint32_t *pLevel       /* Current Level */
    );
/* 
 * SemaEApiGPIOSetLevel
 * 
 * \details The remote function call for EApiGPIOSetLevel. Refer to EApiGPIOSetLevel of EAPI 1.0
 * \param	[in] pHandler  board handle
 * \param	[in] Id   GPIO Id
 * \param	[in] Bitmask  Bit mask of Affected Bits
 * \param	[in] Level  Level
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE 
SemaEApiGPIOSetLevel(
	__IN  	uint32_t Handler ,
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected 
                                  * Bits 
                                  */
    __IN  uint32_t Level         /* Level */  
    );

/*******************************************************************************
*
* 	  F A N
*
*
*******************************************************************************/

/* 
 * SemaEApiSmartFanSetTempSetpoints
 * 
 * \details  Set temperature setpoints (signed, degree Celsius)
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
 * \param	[in] Level1  Level 1
 * \param	[in] Level2  Level 2
 * \param	[in] Level3  Level 3
 * \param	[in] Level4  Level 4
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanSetTempSetpoints(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t  Id , /* FAN Id */
	__IN int32_t  Level1, /* Level 1 */
	__IN int32_t  Level2, /* Level 2*/
	__IN int32_t  Level3, /* Level 3*/
	__IN int32_t  Level4 /* Level 4*/
	);
/* 
 * SemaEApiSmartFanGetTempSetpoints
 * 
 * \details  Get temperature setpoints (signed, degree Celsius)
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
 * \param	[out] pLevel1  Level 1
 * \param	[out] pLevel2  Level 2
 * \param	[out] pLevel3  Level 3
 * \param	[out] pLevel4  Level 4
 */

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanGetTempSetpoints(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t Id , /* FAN Id */
	__OUT int32_t * pLevel1, /* Level 1 */
	__OUT int32_t * pLevel2, /* Level 2*/
	__OUT int32_t * pLevel3, /* Level 3*/
	__OUT int32_t * pLevel4 /* Level 4*/
	);


/* 
 * SemaEApiSmartFanSetWPMSetpoints
 * 
 * \details  Set PWM setpoints  (valid range: 0..100)
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
 * \param	[in] Level1  Level 1
 * \param	[in] Level2  Level 2
 * \param	[in] Level3  Level 3
 * \param	[in] Level4  Level 4
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanSetPWMSetpoints(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t  Id , /* FAN Id */
	__IN uint32_t  Level1, /* Level 1 */
	__IN uint32_t  Level2, /* Level 2*/
	__IN uint32_t  Level3, /* Level 3*/
	__IN uint32_t  Level4 /* Level 4*/
	);
/* 
 * SemaEApiSmartFanGetPWMSetpoints
 * 
 * \details  Get PWM setpoints (valid range: 0..100)
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
 * \param	[out] pLevel1  Level 1
 * \param	[out] pLevel2  Level 2
 * \param	[out] pLevel3  Level 3
 * \param	[out] pLevel4  Level 4
 */

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanGetPWMSetpoints(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t Id , /* FAN Id */
	__OUT uint32_t * pLevel1, /* Level 1 */
	__OUT uint32_t * pLevel2, /* Level 2*/
	__OUT uint32_t * pLevel3, /* Level 3*/
	__OUT uint32_t * pLevel4 /* Level 4*/
	);
/* 
 * SemaEApiSmartFanGetFanMode
 * 
 * \details  Get Fan Mode  
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
  * \param	[Out]   FAN Mode
 */

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanGetMode(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t  Id , /* FAN Id */
	__OUT int32_t * pMode /* Fan mode*/
	);

/* 
 * SemaEApiSmartFanSetFanMode
 * 
 * \details  Set Fan Mode  
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
 * \param    [in] Fan Mode
 */

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanSetMode(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t  Id , /* FAN Id */
	__IN int32_t  fmode /* Level 1 */
	);
/* 
 * SemaEApiSmartFanGetTempSrc
 * 
 * \details  Get Temperature Source
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
  * \param	[Out]   TempSrc
 */


EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanGetTempSrc(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t Id , /* FAN Id */
	__OUT int32_t * pTemp_src /* Temperature source */
	);
/* 
 * SemaEApiSmartFanSetTempSrc
 * 
 * \details  Set Temperature Source
 * \param	[in] pHandler  board handle
 * \param	[in] Id   FAN Id
 * \param    [in] Temperature Sourc
 */

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSmartFanSetTempSrc(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t  Id , /* FAN Id */
	__IN int32_t  Temp_src /* Temperature source */
	);
/*******************************************************************************
*
* 	  B I O S
*
*
*******************************************************************************/

/* 
 * SemaEApiGetActiveBIOSBank
 * 
 * \details  Get active bank number of BIOS
 * \param	[in] pHandler  board handle
 * \param	[out] pbank  active bank of BIOS
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiGetActiveBIOSBank(
	__IN uint32_t Handler, /* handler for remote target */
	__OUT uint32_t * pbank  /*active bank of BIOS */
	);
/* 
 * SemaEApiSetActiveBIOSBank
 * 
 * \details  Set active bank number of BIOS
 * \param	[in] pHandler  board handle
 * \param	[in] bank  active bank of BIOS
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSetActiveBIOSBank(
	__IN uint32_t Handler, /* handler for remote target */
	__IN uint32_t bank  /*active bank of BIOS */
	);


/**
 *  \brief SemaEApiBIOSUpdate
 *  
 *  \param [in]  BoardHandler	Board Handler
 *  \param [in]  CheckSum		C string of checksum
 *  \param [in]  FileName		C string of BIOS file name
 *  \return EAPI status code
 *  
 *  \details The remote/local function call for SemaEApiBIOSUpdate.
 *  Refer to SemaEApiBIOSUpdate of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBIOSUpdate(
	__IN	uint32_t	BoardHandler,
	__IN	char		*FileName,
	__IN	char		*CheckSum
);



/*******************************************************************************
*
* 	  B M C   F I R M W A R E
*
*
*******************************************************************************/
/**
 *  \brief SemaEApiBMCUpdate
 *  
 *  \param [in]  BoardHandler	Board Handler
 *  \param [in]  CheckSum		C string of checksum
 *  \param [in]  FileName		C string of BMC firmware file name
 *  \return EAPI status code
 *  
 *  \details The remote/local function call for SemaEApiBMCUpdate.
 *  Refer to SemaEApiBMCUpdate of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBMCUpdate(
	__IN	uint32_t	BoardHandler,
	__IN	char		*FileName,
	__IN	char		*CheckSum,
	__IN	bool		bReboot,	/* Reboot operating system after FW update?  */
	__IN	uint32_t	Delay  /*the delay in seconds for the reboot */
);



/*******************************************************************************
*
*   S Y S T E M    B O O T
*
*
*******************************************************************************/

/**
 *  \brief SemaEApiSystemBootSet
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Id           Value Id
 *  \param [in] delay        The delay in second to trigger the action
 *  \return EAPI status code
 *  
 *  \details The remote function call for SemaEApiSystemBootSet.
 *  Refer to SemaEApiSystemBootSet of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSystemBootSet(
    __IN    uint32_t BoardHandler,
    __IN    uint32_t Id,
    __IN    uint32_t delay
);



/*******************************************************************************
*
*   D I S K   I N F O
*
*
*******************************************************************************/

/**
 *  \brief SemaEApiDiskNum
 *  
 *  \param [in]  BoardHandler	Board Handler
 *  \param [out] pDiskNumber	Value Id
 *  \return EAPI status code
 *  
 *  \details The remote/local function call for SemaEApiDiskNum.
 *  Refer to SemaEApiDiskNum of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiDiskNum(
	__IN    uint32_t BoardHandler,
	__OUT   uint32_t *pDiskNumber
);

/**
 *  \brief SemaEApiDiskInfo
 *  
 *  \param [in]  BoardHandler	Board Handler
 *  \param [in]  DiskIndex		Disk index number
 *  \param [out] pInfo			Pointer to return string
 *  \param [inout] pLength		Pointer to variable indicate the string length
 *  \return EAPI status code
 *  
 *  \details The remote/local function call for SemaEApiDiskInfo.
 *  Refer to SemaEApiDiskInfo of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiDiskInfo(
	__IN    uint32_t BoardHandler,
	__IN    uint32_t DiskIndex,
	__OUT   char *pInfo,
	__INOUT uint32_t *pLength
);


/**
 *  \brief SemaEApiDiskSMARTAll
 *  
 *  \param [in]  BoardHandler Board Handler
 *  \param [in]  DiskIndex    Disk index number
 *  \param [out] pInfo     Pointer to return string
 *  \param [inout] pLength   Pointer to variable indicate the string length
 *  \return EAPI status code
 *  
 *  \details The remote/local function call for SemaEApiDiskSMARTAll.
 *  Refer to SemaEApiDiskSMARTAll of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiDiskSMARTAll(
  __IN    uint32_t BoardHandler,
  __IN    uint32_t DiskIndex,
  __OUT   char *pInfo,
  __INOUT uint32_t *pLength
);


/**
 *  \brief SemaEApiDiskSMART
 *  
 *  \param [in]  BoardHandler Board Handler
 *  \param [in]  DiskIndex    Disk index number
 *  \param [in]  ID           SMART ID
 *  \param [out] pNormValue   SMART normalized value
 *  \param [out] pRawValue    SMART raw value
 *  \return EAPI status code
 *  
 *  \details The remote/local function call for SemaEApiDiskSMART.
 *  Refer to SemaEApiDiskSMART of SEMA_Extended_EAPI
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiDiskSMART(
  __IN    uint32_t BoardHandler,
  __IN    uint32_t DiskIndex,
  __IN    uint32_t ID,
  __OUT   uint32_t *pNormValue,
  __OUT   char     *pRawValue
);

/*******************************************************************************
*
*   H E A R T B E A T
*
*
*******************************************************************************/

/**
 *  \brief SemaEApiHeartBeat
 *  
 *  \param [in] BoardHandler Board Handler
 *  \param [in] Keepalive        The time interval to check the alive
 *  \param [in] Deadtime        The expired time for the determination of dead link
 *  \param [in] Action filename of script or execute file to run when heartbeat expired
 *  
 *  \details To start the heart beat and remote server will keep watch it. if the remote server can't
 *   receive the heart beat with in deadtime, it will execute the action. The hearbeat on exist with BoardHandler validated.
 *   Please note if SemaEApiLibUnInitialize called without SemaEApiHeartBeatStop , 

 *   this will make the client hearbeat stop and remote monitor trigger the action after deadtime expired.
 *  
 */

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiHeartBeat(
	__IN	uint32_t BoardHandler,
	__IN	uint32_t  Keepalive,
	__IN	uint32_t  Deadtime,
	__IN	char * Action
);

/**
 *  \brief SemaEApiHeartBeatStop
 *  
 *  \param [in] BoardHandler Board Handler
 *  
 *  \details stop the heartbeat
 */
EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiHeartBeatStop(
	__IN	uint32_t BoardHandler
);

EApiStatus_t 
SEMA_EAPI_CALLTYPE
SemaEApiBoardGetVoltageMonitor(
	__IN  uint32_t Handler ,
    __IN  EApiId_t  Id      , /* Value Id */
     __OUTOPT uint32_t *pValue ,    /* Return Value */
     __OUTOPT char *pBuffer /* Return Voltage description */
    );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBoardGetErrorLog (
__IN 	uint32_t Handler , /* handler for remote target */
__IN 	uint32_t position, /* The pointer of error log */
__OUT 	uint32_t *ErrorNumber,        
__OUT 	uint8_t  *Flags,   
__OUT   uint8_t  *RestartEvent, 
__OUT   uint32_t *PwrCycles,  
__OUT   uint32_t *Bootcount,     
__OUT   uint32_t *Time,     
__OUT   uint16_t *Status,        
__OUT   signed char *CPUtemp,
__OUT   signed char *Boardtemp
);

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBoardGetErrorNumberDescription (
__IN uint32_t Handler , /* handler for remote target */
__IN uint32_t  ErrorNumber , /* Error number */
__OUT char *pBuffer /* Return error description */
);

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireReset( __IN  uint32_t Handler );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireProbeRomID( __IN  uint32_t Handler, __OUT uint8_t *pFamilyCode, __OUT uint8_t *pSerialNo, __OUT uint8_t *pCRC );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireGetStatus( __IN  uint32_t Handler, __OUT uint32_t *pStatus );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireSendFunctionCmd( __IN  uint32_t Handler, __IN uint8_t FamilyCode, __IN uint8_t *pSerialNo, __IN uint8_t CRC, __IN uint8_t *pComs, __IN uint8_t CmdLen, __IN uint8_t *pData, __IN uint8_t DataLen );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireRead( __IN  uint32_t Handler, __OUT uint8_t *pBuffer, __IN uint32_t BufLen, __IN uint32_t ByteCnt );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireSelectGPIOPin( __IN  uint32_t Handler, __IN uint32_t GPIONum );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApi1WireGetSelectGPIOPin( __IN  uint32_t Handler, __OUT uint32_t *GPIONum );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiGPIOXorAndXor( __IN  uint32_t Handler, __IN uint32_t Value1, __IN uint32_t Value2, __IN uint32_t Value3 );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiGPIOPinGetCap( __IN  uint32_t Handler, __IN uint8_t ID, __OUT uint32_t *pCapabilites );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiGPIOPinSetConfig( __IN  uint32_t Handler, __IN uint8_t ID, __IN uint32_t Configuration );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiGPIOPinGetConfig( __IN  uint32_t Handler, __IN uint8_t ID, __OUT uint32_t *pConfiguration );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiGPIOPinGetADCValue( __IN  uint32_t Handler, __IN uint8_t ID, __OUT uint32_t *pValue );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBoardGetCurrentPosErrorLog (
__IN 	uint32_t Handler , /* handler for remote target */
__OUT 	uint32_t *ErrorNumber,        
__OUT 	uint8_t  *Flags,   
__OUT   uint8_t  *RestartEvent, 
__OUT   uint32_t *PwrCycles,  
__OUT   uint32_t *Bootcount,     
__OUT   uint32_t *Time,     
__OUT   uint16_t *Status,        
__OUT   signed char *CPUtemp,
__OUT   signed char *Boardtemp
);

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiBoardGetExceptionDescription(
	__IN	uint32_t Handler,
	__IN	uint8_t errcode,
	__OUT	char * buffer
);

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusRead( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __OUT uint8_t *ByteData );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusReadByte( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint32_t Command, __OUT uint8_t *ByteData );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusReadWord( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint32_t Command, __OUT uint8_t *WordData );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusWrite( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint8_t *ByteData  );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusWriteByte( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint32_t Command, __IN uint8_t *ByteData );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusWriteWord( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint32_t Command, __IN uint8_t *WordData );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusBlockRead( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint32_t Command, __IN uint32_t Length, __OUT uint8_t *Buffer  );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiSMBusBlockWrite( __IN uint32_t Handler, __IN uint32_t Mode, __IN uint32_t Address, __IN uint32_t Command, __IN uint32_t Length, __IN uint8_t *Buffer  );

EApiStatus_t
SEMA_EAPI_CALLTYPE
SemaEApiI2CGetStatus( __IN uint32_t Handler, __IN uint32_t BusNumber, __OUT uint32_t *Status );

#ifdef __cplusplus
	}
#endif
	
#endif /* _SEMAEAPI_H_ */



