#ifndef SEMA_API_H
#define SEMA_API_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Sema.h"
#include "ErrorCodes.h"
/***********************************************************************/

#ifndef __IN
#  define __IN 
/* __IN
* Arg Type        | Characteristics
* ----------------+-----------------------------------------------------
* Immediate value | Input value that must be specified and is essential
*                 | to function operation.
*                 |
* Pointer         | Valid pointer to initialized buffer/variable.
*                 |
*/
#endif
#ifndef __INOPT
#  define __INOPT
/* __INOPT
* Arg Type        | Characteristics
* ----------------+-----------------------------------------------------
* Pointer         | Valid pointer to initialized buffer/variable, or
*                 | NULL Pointer.
*                 | Note: refer to function specification for specifics.
*/
#endif
#ifndef __OUT
#  define __OUT
/* __OUT
* Arg Type        | Characteristics
* ----------------+-----------------------------------------------------
* Pointer         | Valid pointer to destination buffer/variable
*/
#endif
#ifndef __OUTOPT
#  define __OUTOPT

/* __OUTOPT
* Arg Type        | Characteristics
* ----------------+-----------------------------------------------------
* Pointer         | Valid pointer to destination buffer/variable, or
*                 | NULL Pointer.
*                 | Note: refer to function specification for specifics.
*/
#endif
#ifndef __INOUT
#  define __INOUT
/* __INOUT
* Arg Type        | Characteristics
* ----------------+-----------------------------------------------------
* Pointer         | Valid pointer to initialized buffer/variable
*                 | Contents of buffer/variable updated before return.
*/
#endif
typedef signed int RESULT;
/*                           
 * \brief  SemaApi_OverrideCapabilities   
 *                          
 * \details          
 *                          
 * \param	[in]  tSEMACapabilities Cap 
 */                          
DLL_EXPORT
RESULT
SemaApi_OverrideCapabilities(
     __IN tSEMACapabilities Cap
);
/*                           
 * \brief  SemaApi_Trans   
 *                          
 * \details          
 *                          
 * \param	[in]  byte Address 
 * \param	[in]  tTransType Type 
 * \param	[in]  byte *Buffer 
 */                          
DLL_EXPORT
RESULT
SemaApi_Trans(
     __IN byte Address , 
     __IN tTransType Type , 
     __INOUT byte *Buffer 
);
/*                           
 * \brief  SemaApi_TransExt   
 *                          
 * \details          
 *                          
 * \param	[in]  byte BusNumber 
 * \param	[in]  byte Type 
 * \param	[in]  byte Length 
 * \param	[in]  byte *Buffer 
 */                          
DLL_EXPORT
RESULT
SemaApi_TransExt(
     __IN byte BusNumber , 
     __IN byte Type , 
     __IN byte Length , 
     __IN byte *Buffer 
);
/*                           
 * \brief  SemaApi_TransExtSetSpeed   
 *                          
 * \details          
 *                          
 * \param	[in]  byte BusNumber			Transfer type												 
 * \param	[in]  byte Mode 				Number of bytes transferred to BMC (not to external device!)
 * \param	[out]  byte pData	 			Data to transfer/receive
 */                          
DLL_EXPORT
RESULT
SemaApi_TransExtSetSpeed(
     __IN byte BusNumber , 
     __IN byte Mode , 
	 __OUT byte* pData
);
/*                           
 * \brief  SemaApi_TransExtGetSpeed   
 *                          
 * \details          
 *                          
 * \param	[in]  byte BusNumber 
 * \param	[out]  byte* p_output 
 */                          
DLL_EXPORT
RESULT
SemaApi_TransExtGetSpeed(
     __IN byte BusNumber , 
     __OUT byte* p_output
);

/*                           
 * \brief  SemaApi_TransStatus   
 *                          
 * \details          
 *                          
 * \param	[out]  byte *pBuffer 
 */                          
DLL_EXPORT
RESULT
SemaApi_TransStatus(
     __OUT unsigned char* p_output
);

DLL_EXPORT
RESULT
I2C_ProbeRead (
          __IN unsigned char BusNumber , 
          __IN unsigned char Addr
); 

///*                           
// * \brief  SemaApi_GetChipsetID    
// *                          
// * \details          
// *                          
// * \param	[out]  dword 
// */                  
//DLL_EXPORT        
//RESULT
//SemaApi_GetChipsetID (
//     __OUT dword *id
//);
/*                           
 * \brief  SemaApi_SetWatchdog   
 *                          
 * \details Sets watchdog timer.         
 *                          
 * \param	[in]  unsigned short Value		Watchdog timeout in seconds (0 disables watchdog) 
 */                          
DLL_EXPORT
RESULT
SemaApi_SetWatchdog(
     __IN unsigned short Value
);
/*                           
 * \brief  SemaApi_SetPwrUpWatchdog   
 *                          
 * \details	Sets watchdog timer
 *                          
 * \param	[in]  unsigned short Value		Watchdog timeout in seconds (0 disables watchdog)
 */                          
DLL_EXPORT
RESULT
SemaApi_SetPwrUpWatchdog(
     __IN unsigned short Value
);
/*                           
 * \brief  SemaApi_GetVersionString1   
 *                          
 * \details	Get version string #1     
 *                          
 * \param	[out]  byte *Buffer				(at least 33 bytes!!) for version string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetVersionString1(
     __OUT byte *Buffer
);
/*                           
 * \brief  SemaApi_GetVersionString2   
 *                          
 * \details	Get version string #2       
 *                          
 * \param	[in]  byte *Buffer				(at least 33 bytes!!) for version string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetVersionString2(
     __OUT byte *Buffer
);
/*                           
 * \brief  SemaApi_GetAppVersion   
 *                          
 * \details	Get BMC application version string        
 *                          
 * \param	[out]  byte *version			(at least 65 bytes!!) for BMC application version string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetAppVersion(
     __OUT byte *version
);
/*                           
 * \brief  SemaApi_GetManufacturingData   
 *                          
 * \details	Get the Manufacturing Date selcet by the Data paramter
 *                          
 * \param	[in]  byte Data					Manufacturing data index
 * \param	[out]  byte *pBuffer			Buffer for part number 
 */                       
DLL_EXPORT   
RESULT
SemaApi_GetManufacturingData(
     __IN byte Data , 
     __OUT byte *pBuffer 
);
/*                           
 * \brief  SemaApi_GetFanSpeed   
 *                          
 * \details   
 *		Get fan speed (unit: rpm)
 *
 *		Note: If feature is not supported returnvalue is 0
 *                          
 * \param	[in]  byte fan_number			Number of fan starting from by 0
 * \param	[out]  unsigned short* pRPM		fan speed
 */                          
DLL_EXPORT
RESULT
SemaApi_GetFanSpeed(
     __IN byte fan_number , 
     __OUT unsigned short* pRPM
);
/*                           
 * \brief  SemaApi_SmartFanGetTempSetpoints   
 *                          
 * \details SmartFan: Get temperature setpoints (signed, degree Celsius)         
 *                          
 * \param	[in]  byte fan_number 
 * \param	[in]  signed char *lvl1			smartfan level 1 temperature 
 * \param	[in]  signed char *lvl2			smartfan level 2 temperature 
 * \param	[in]  signed char *lvl3			smartfan level 3 temperature 
 * \param	[in]  signed char *lvl4			smartfan level 4 temperature 
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanGetTempSetpoints(
     __IN byte fan_number , 
     __IN signed char *lvl1 , 
     __IN signed char *lvl2 , 
     __IN signed char *lvl3 , 
     __IN signed char *lvl4
);
/*                           
 * \brief  SemaApi_SmartFanGetPWMSetpoints   
 *                          
 * \details SmartFan: Get  PWM setpoints (valid range: 0..100)         
 *                          
 * \param	[in]  byte fan_number 
 * \param	[in]  unsigned char *lvl1		smartfan level 1 PWM 
 * \param	[in]  unsigned char *lvl2 		smartfan level 2 PWM
 * \param	[in]  unsigned char *lvl3 		smartfan level 3 PWM
 * \param	[in]  unsigned char *lvl4 		smartfan level 4 PWM
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanGetPWMSetpoints(
     __IN byte fan_number , 
     __IN unsigned char *lvl1 , 
     __IN unsigned char *lvl2 , 
     __IN unsigned char *lvl3 , 
     __IN unsigned char *lvl4
);
/*                           
 * \brief  SemaApi_SmartFanSetTempSetpoints   
 *                          
 * \details SmartFan: Set  temperature setpoints (signed, degree Celsius)        
 *                          
 * \param	[in]  byte fan_number 
 * \param	[in]  signed char lvl1			smartfan level 1 temperature
 * \param	[in]  signed char lvl2 			smartfan level 2 temperature
 * \param	[in]  signed char lvl3 			smartfan level 3 temperature
 * \param	[in]  signed char lvl4 			smartfan level 4 temperature
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanSetTempSetpoints(
     __IN byte fan_number , 
     __IN signed char lvl1 , 
     __IN signed char lvl2 , 
     __IN signed char lvl3 , 
     __IN signed char lvl4
);
/*                           
 * \brief  SemaApi_SmartFanSetPWMSetpoints   
 *                          
 * \details SmartFan: Set  PWM setpoints (valid range: 0..100)         
 *                          
 * \param	[in]  byte fan_number 
 * \param	[in]  unsigned char lvl1		smartfan level 1 PWM 
 * \param	[in]  unsigned char lvl2 		smartfan level 2 PWM
 * \param	[in]  unsigned char lvl3 		smartfan level 3 PWM
 * \param	[in]  unsigned char lvl4 		smartfan level 4 PWM
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanSetPWMSetpoints(
     __IN byte fan_number , 
     __IN unsigned char lvl1 , 
     __IN unsigned char lvl2 , 
     __IN unsigned char lvl3 , 
     __IN unsigned char lvl4
);
/*                           
 * \brief  SemaApi_SmartFanGetMode   
 *                          
 * \details          
 *                          
 * \param	[in]  byte fan_number 
 * \param	[out]  byte* mode 
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanGetMode(
     __IN byte fan_number , 
     __OUT byte* mode
);
/*                           
 * \brief  SemaApi_SmartFanSetMode   
 *                          
 * \details          
 *                          
 * \param	[in]  byte fan_number 
 * \param	[in]  byte mode 
 */                       
DLL_EXPORT   
RESULT
SemaApi_SmartFanSetMode(
     __IN byte fan_number , 
     __IN byte mode
);
/*                           
 * \brief  SemaApi_SmartFanGetTempSrc   
 *                          
 * \details          
 *                          
 * \param	[in]  byte fan_number 
 * \param	[out]  byte* tempsrc 
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanGetTempSrc(
     __IN byte fan_number , 
     __OUT byte* tempsrc
);
/*                           
 * \brief  SemaApi_SmartFanSetTempSrc   
 *                          
 * \details          
 *                          
 * \param	[in]  byte fan_number 
 * \param	[in]  byte tempsrc 
 */                          
DLL_EXPORT
RESULT
SemaApi_SmartFanSetTempSrc(
     __IN byte fan_number , 
     __IN byte tempsrc
);
/*                           
 * \brief  SemaApi_GetVoltage   
 *                          
 * \details	
 *			Get voltage of selected channel (unit: V, resolution=1/1000 V)
 *      
 * \param	[in]  unsigned char Ch		Channel number starting from 0 
 * 
 * \param	[out]  float* pVolt			voltage		 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetVoltage(
     __IN unsigned char Ch , 
     __OUT float* pVolt
);
/*                           
 * \brief  SemaApi_GetVoltageDescription   
 *                          
 * \details	string for the given analog input
 *                          
 * \param	[in]   unsigned char Ch		Channel number starting from 0 
 * \param	[out]  char *Buffer			Pointer to buffer which receives the description string must 
 *										be at least 17Bytes long(16Bytes string + 1Byte \0 - character)
 */                          			
DLL_EXPORT								
RESULT
SemaApi_GetVoltageDescription(
     __IN unsigned char Ch , 
     __OUT char *Buffer
);
/*                           
 * \brief  SemaApi_GetVoltageDescriptionExt   
 *                          
 * \details	the extended description string for the given analog input
 *                          
 * \param	[in]  unsigned char Ch		Channel number starting from 0
 * \param	[in]  bool truncate 		
 * \param	[out] char *Buffer			Pointer to buffer which receives the description string must 
 *										be at least 17Bytes long (16Bytes string + 1Byte \0-character)
 */                          
DLL_EXPORT
RESULT
SemaApi_GetVoltageDescriptionExt(
     __IN unsigned char Ch ,
     __IN bool truncate  , 
     __OUT char *Buffer
);
/*                           
 * \brief  SemaApi_BacklightSetPWM   
 *                          
 * \details Set new backlight PWM value (range: 0..255)       
 *                          
 * \param	[in]  byte Value new backlight PWM value (range: 0..255)
 */                        
DLL_EXPORT  
RESULT
SemaApi_BacklightSetPWM(
     __IN byte Value
);
/*                           
 * \brief  SemaApi_GetMinMaxTemp   
 *                          
 * \details	Get min and max temperatures of CPU and board         
 *                          
 * \param	[in]  signed char *MinCPU 		Location for min CPU temperature	
 * \param	[in]  signed char *MaxCPU 		Location for max CPU temperature	
 * \param	[in]  signed char *MinBoard		Location for min board temperature	
 * \param	[in]  signed char *MaxBoard		Location for max board temperature
 */                          
DLL_EXPORT
RESULT
SemaApi_GetMinMaxTemp(
     __IN signed char *MinCPU , 
     __IN signed char *MaxCPU , 
     __IN signed char *MinBoard , 
     __IN signed char *MaxBoard
);
/*                           
 * \brief  SemaApi_GetCPUMinMaxTemp   
 *                          
 * \details	Get min and max temperatures of CPU       
 *                          
 * \param	[in]  signed char *MinCPU 		Location for min CPU temperature	
 * \param	[in]  signed char *MaxCPU 		Location for max CPU temperature	
 */                          
DLL_EXPORT
RESULT
SemaApi_GetCPUMinMaxTemp(
	__OUT signed char *MinCPU,
	__OUT signed char *MaxCPU
);
/*                           
 * \brief  SemaApi_GetCPUMinMaxTemp   
 *                          
 * \details	Get min and max temperatures of Board       
 *                          
 * \param	[in]  signed char *MinBoard		Location for min board temperature
 * \param	[in]  signed char *MaxBoard		Location for max board temperature
 */
DLL_EXPORT
RESULT
SemaApi_GetBoardMinMaxTemp(
     __IN signed char *MinBoard , 
     __IN signed char *MaxBoard
);
/*                           
 * \brief  SemaApi_GetStartupTemp   
 *                          
 * \details	Get startup temperatures of CPU and board          
 *                          
 * \param	[out]  signed char *pStartCPU	Location for startup CPU temperature	
 * \param	[out]  signed char *pStartBoard	Location for startup board temperature
 */                          
DLL_EXPORT
RESULT
SemaApi_GetStartupTemp(
     __OUT signed char *pStartCPU , 
     __OUT signed char *pStartBoard
);
/*                           
 * \brief  SemaApi_GetBoardStartupTemp   
 *                          
 * \details	Get startup temperatures of board          
 *                          	
 * \param	[out]  signed char *pStartBoard	Location for startup board temperature
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBoardStartupTemp(
     __OUT signed char *pStartBoard
);
/*                           
 * \brief  SemaApi_GetCPUStartupTemp   
 *                          
 * \details	Get startup temperatures of CPU         
 *                          
 * \param	[out]  signed char *pStartCPU	Location for startup CPU temperature	
 */                          
DLL_EXPORT
RESULT
SemaApi_GetCPUStartupTemp(
     __OUT signed char *pStartCPU 
);
/*                           
 * \brief  SemaApi_GetBoard2ndMinMaxTemp
 *                          
 * \details	Get min and max 2nd temperatures of Board       
 *                          
 * \param	[in]  signed char *MinBoard		Location for min board temperature
 * \param	[in]  signed char *MaxBoard		Location for max board temperature
 */
DLL_EXPORT
RESULT
SemaApi_GetBoard2ndMinMaxTemp(
     __IN signed char *MinBoard , 
     __IN signed char *MaxBoard
);
/*                           
 * \brief  SemaApi_GetBoard2ndStartupTemp   
 *                          
 * \details	Get startup temperatures of board          
 *                          	
 * \param	[out]  signed char *pStartBoard	Location for startup board temperature
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBoard2ndStartupTemp(
     __OUT signed char *pStartBoard
);
/*                           
 * \brief  SemaApi_GetCurrentBoard2ndTemp
 *                          
 * \details	Get current temperatures of board          
 *                          	
 * \param	[out]  signed char *p_output Location for current board temperature
 */                          
DLL_EXPORT
RESULT
SemaApi_GetCurrentBoard2ndTemp (
     __OUT signed char* p_output
);
/*                           
 * \brief  SemaApi_SetGPIOReg   
 *                          
 * \details	Set status of GPIO register (only on 86DX platform)
 *                          
 * \param	[in]  unsigned char GpioReg		New status of GPIO register 
 */                          
DLL_EXPORT
RESULT
SemaApi_SetGPIOReg(
     __IN unsigned char GpioReg
);
/*                           
 * \brief  SemaApi_SetSysCtrlReg   
 *                          
 * \details Set new status of system control register
 *			Note: Most significant byte will be transferred first
 *                          
 * \param	[in]  unsigned int val				New status of system control register
 */                          
DLL_EXPORT
RESULT
SemaApi_SetSysCtrlReg(
     __IN unsigned int val
);
/*                           
 * \brief  SemaApi_SetSoftStrapRegOTF   
 *                          
 * \details	Set status of SoftStrap register "on the fly" (i.e. without power cycle)
 *                          
 * \param	[in]  unsigned char SStrapReg		GpioReg	- New status of SoftStrap register
 */                          
DLL_EXPORT
RESULT
SemaApi_SetSoftStrapRegOTF(
     __IN unsigned char SStrapReg
);
/*                           
 * \brief  SemaApi_SetSoftStrapRegPC   
 *                          
 * \details	Set status of SoftStrap register "permanently" (i.e. with power cycle)
 *                          
 * \param	[in]  unsigned char SStrapReg		GpioReg	- New status of SoftStrap register 
 */                          
DLL_EXPORT
RESULT
SemaApi_SetSoftStrapRegPC(
     __IN unsigned char SStrapReg
);
/*                           
 * \brief  SemaApi_MemoryRead   
 *                          
 * \details Read from flash memory          
 *                          
 * \param	[in]  unsigned short Adr			Start address
 * \param	[in]  unsigned char Size			Number of bytes to read 
 * \param	[out]  byte *Buffer					Buffer for read bytes
 */                          
DLL_EXPORT
RESULT
SemaApi_MemoryRead(
     __IN unsigned short Adr , 
     __IN unsigned char Size  ,
     __OUT byte *Buffer 
);
/*                           
 * \brief  SemaApi_MemoryWrite   
 *                          
 * \details Writes to flash memory         
 *                          
 * \param	[in]  unsigned short Adr			Start address
 * \param	[in]  unsigned char Size 			Number of bytes to read
 * \param	[in]  byte *Buffer					Buffer for bytes to write
 */                          
DLL_EXPORT
RESULT
SemaApi_MemoryWrite(
     __IN unsigned short Adr , 
     __IN unsigned char Size ,
     __IN byte *Buffer 
);
/*                           
 * \brief  SemaApi_IsValidAddress   
 *                          
 * \details	Tests if address is within valid range          
 *                          
 * \param	[in]  word Adr 
 * \param	[out]  bool* result 
 */                          
DLL_EXPORT
RESULT
SemaApi_IsValidAddress(
     __IN word Adr , 
	 __OUT bool * result
);
/*                           
 * \brief  SemaApi_AdjustSize   
 *                          
 * \details Adjusts size to valid values (boundaries, max length, ...)         
 *                          
 * \param	[in]	address		number of bytes	
 * \param	[inout] size		Start address
 */                          
DLL_EXPORT
RESULT
SemaApi_AdjustSize(
     __IN word address, 
     __INOUT word *size 
);
/*                           
 * \brief  SemaApi_PrintMem   
 *                          
 * \details Prints memory contents to formatted string
 *                          
 * \param	[in]  word address		Start address			
 * \param	[in]  word size 		number of bytes			
 * \param	[in]  char *output 		Pointer to output buffer
 */                          
DLL_EXPORT
RESULT
SemaApi_PrintMem(
     __IN word address , 
     __IN word size , 
     __OUT char *output
);
/*                           
 * \brief  SemaApi_SelectBIOS   
 *                          
 * \details Select BIOS (only available if Faile-Safe-BIOS is supported)
 *                          
 * \param	[in]  byte Index 
 */                          
DLL_EXPORT
RESULT
SemaApi_SelectBIOS(
     __IN byte Index
);
/*                           
 * \brief  SemaApi_Init    
 *                          
 * \details Initializes SMBus access and queries BMC capabilities         
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_Init (
);
/*                           
 * \brief  SemaApi_GetCapabilities    
 *                          
 * \details	Returns BMC capabilities
 *                          
 * \param	[out]  tSEMACapabilities* pCapabilities		Capabilities of BMC
 */                          
DLL_EXPORT
RESULT
SemaApi_GetCapabilities (
     __IN unsigned Group,
     __OUT tSEMACapabilities* pCapabilities
);

/*                           
 * \brief  SemaApi_GetChipsetString    
 *                          
 * \details	Gets chipset IDs string 
 *                          
 * \param	[out]  const char* pChipset			Pointer to chipset ID string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetChipsetString (
     __OUT const char** pChipset
);
/*                           
 * \brief  SemaApi_GetMemSize    
 *                                    
 * \details	Get memory size (currently only implemented for CRR-ATOM)
 *                          
 * \param	[out]  unsigned char* pSize			1:512MB, 2:1GB, 3:2GB
 */                          
DLL_EXPORT
RESULT
SemaApi_GetMemSize (
     __OUT unsigned char* pSize
);
/*                           
 * \brief  SemaApi_GetTotalUpTime    
 *                          
 * \details	Get total uptime [minutes]
 *                          
 * \param	[out]  unsigned long* pTime			Total uptime [minutes] 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetTotalUpTime (
     __OUT unsigned long* pTime
);
/*                           
 * \brief  SemaApi_GetPwrUpTime    
 *                          
 * \details	Get power uptime [seconds]
 *                          
 * \param	[out]  unsigned long* pUptime		Uptime since last boot [seconds] 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetPwrUpTime (
     __OUT unsigned long* pUptime
);
/*                           
 * \brief  SemaApi_GetPwrCycles    
 *                          
 * \details	Get number of power cycles		
 *                          
 * \param	[out]  unsigned long* pCycles		number of power cycles
 */                          
DLL_EXPORT
RESULT
SemaApi_GetPwrCycles (
     __OUT unsigned long* pCycles
);
/*                           
 * \brief  SemaApi_GetBootCount    
 *                          
 * \details	Get number of boots
 *                          
 * \param	[out]  unsigned long*pCount			Number of boots 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBootCount (
     __OUT unsigned long* pCount
);
/*                           
 * \brief  SemaApi_GetBMCFlags    
 *                          
 * \details	Get BMC flags
 *                          
 * \param	[out]  unsigned char*pFlags			flags BMC flags
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBMCFlags (
     __OUT unsigned char* pFlags
);
/*                           
 * \brief  SemaApi_GetBMCStatus    
 *                          
 * \details	Get BMC status register
 *                          
 * \param	[out]  unsigned char* pStatus		BMC status 
 */  
/*
DLL_EXPORT
RESULT
SemaApi_GetBMCStatus (
		 __OUT dword * pStatus
);
*/
DLL_EXPORT
RESULT
SemaApi_GetBMCStatus (
     __OUT unsigned char* pStatus
);
/*                           
 * \brief  SemaApi_GetRestartEvent    
 *                          
 * \details	Get last system restart event
 *                          
 * \param	[out]  unsigned char* pEvent		Restart event code 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetRestartEvent (
     __OUT unsigned char* pEvent
);
/*                           
 * \brief  SemaApi_GetRestartEventText    
 *                          
 * \details	Get last system restart event
 *                          
 * \param	[out]  const char** pText		Restart event description text 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetRestartEventText (
     __OUT const char** pText
);
/*                           
 * \brief  SemaApi_GetMainPowerCurrent    
 *                          
 * \details	Get main power current (unit: mA, resolution=1/10 mA)     
 *                          
 * \param	[out]  unsigned short* pPower	main power current
 */                          
DLL_EXPORT
RESULT
SemaApi_GetMainPowerCurrent (
     __OUT unsigned short* pPower
);
/*                           
 * \brief  SemaApi_BacklightGetPWM    
 *                          
 * \details Get main power current (unit: mA, resolution=1/10 mA)      
 *                          
 * \param	[out] pValue					main power current 
 */                          
DLL_EXPORT
RESULT
SemaApi_BacklightGetPWM (
     __OUT byte* pValue
);
/*                           
 * \brief  SemaApi_GetCurrentCPUTemp    
 *                          
 * \details	Current CPU temperature 
 *                          
 * \param	[out]  float* pTemp				Current CPU temperature (resolution=1/10 degC)
 */                          
DLL_EXPORT
RESULT
SemaApi_GetCurrentCPUTemp (
     __OUT float* pTemp
);
/*                           
 * \brief  SemaApi_GetCurrentBoardTemp    
 *                          
 * \details	Get current board temperature
 *                          
 * \param	[out]  signed char* pTemp		Current board temperature 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetCurrentBoardTemp (
     __OUT signed char* pTemp
);
/*                           
 * \brief  SemaApi_GetGPIOReg    
 *                          
 * \details	Get current status of GPIO register (only on 86DX platform)          
 *                          
 * \param	[out]  unsigned char* pGPIO		Current status of GPIO register
 */                          
DLL_EXPORT
RESULT
SemaApi_GetGPIOReg (
     __OUT unsigned char* pGPIO
);
/*                           
 * \brief  SemaApi_GetSysCtrlReg    
 *                          
 * \details	
 *		Get current status of system control register
 *		
 *		Note: First byte of I2C data block is interpreted as most significant byte
 *                          
 * \param	[out]  unsigned int* pReg		Current status of system control register
 */ 
DLL_EXPORT
RESULT
SemaApi_CheckTivaGPIODirectionCap(
__OUTOPT unsigned int *pInputs, __OUTOPT unsigned int *pOutputs);

DLL_EXPORT
RESULT
SemaApi_GetSysCtrlReg (
     __OUT unsigned int* pReg
);
/*                           
 * \brief  SemaApi_GetSoftStrapReg    
 *                          
 * \details	Get current status of SoftStrap register
 *                          
 * \param	[out]  unsigned char* pReg		Current status of SoftStrap register 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetSoftStrapReg (
     __OUT unsigned char* pReg
);
/*                           
 * \brief  SemaApi_GetBIOS    
 *                          
 * \details	Gets selected BIOS (only available if Fail-Safe-BIOS is supported)      
 *                          
 * \param	[out]  byte* index				BIOS number/index (0:FS-BIOS not supported or normal BIOS selected / 1: FS-BIOS selected) 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBIOS (
     __OUT byte* index
);
/*                           
 * \brief  SemaApi_IsAdminMode    
 *                          
 * \details          
 *                          
 * \param	[out]  bool* p_output 
 */                          
DLL_EXPORT
RESULT
SemaApi_IsAdminMode (
     __OUT bool* p_output
);
/*                           
 * \brief  SemaApi_PrintCapabilities   
 *                          
 * \details Print BMC capabilities          
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_PrintCapabilities(
     void
);
/*                           
 * \brief  SemaApi_Close   
 *                          
 * \details Cleans up
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_Close(
     void
);
/*                           
 * \brief  SemaApi_ClearExceptionCode   
 *                          
 * \details	Clears BMC exception code
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_ClearExceptionCode(
     void
);
/*                           
 * \brief  SemaApi_MemoryClear   
 *                          
 * \details Clears user flash memory
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_MemoryClear(
     void
);
/*                           
 * \brief  SemaApi_MemoryRestore   
 *                          
 * \details Restores first 64 bytes of user flash memory (partNo, serial, etc)
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_MemoryRestore(
     void
);
/*                           
 * \brief  SemaApi_EnableAdminMode   
 *                          
 * \details 
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_EnableAdminMode(
     void
);
/*                           
 * \brief  SemaApi_DisableAdminMode   
 *                          
 * \details          
 *                          
 */                    
DLL_EXPORT      
RESULT
SemaApi_DisableAdminMode(
     void
);

/*                           
 * \brief  SemaApi_CheckFfsHeader   
 *                          
 * \details Test if flash file system is ok
 *                          
 */                          
DLL_EXPORT
RESULT
SemaApi_CheckFfsHeader(
     void 
);
/*                           
 * \brief  SemaApi_Prog   
 *                          
 * \details          
 *                          
 * \param	[in]  char *key 
 * \param	[in]  word address 
 * \param	[in]  char *filename 
 */                          
DLL_EXPORT
RESULT
SemaApi_Prog(
     __IN char *key , 
     __IN word address , 
     __IN char *filename
);
/*                           
 * \brief  SemaApi_UpdateBMC   
 *                          
 * \details          
 *                          
 * \param	[in]  char *filename				BMC frimware binary file
 * \param	[in]  bool shutdown_after_update	shutdown operating system after BL/FW update?
 * \param	[in]  unsigned int delay			default boot delay time [seconds] after BL/FW-update under Windows -> 255
 *																									 under Linux   -> 1
 */
DLL_EXPORT
RESULT
SemaApi_UpdateBMC(
	__IN char *			filename				,
	__IN bool			shutdown_after_update	,
	__IN unsigned int	delay
);
/*                           
 * \brief  SemaApi_Update   
 *                          
 * \details          
 *                          
 * \param	[in]  char *filename				BMC frimware binary file
 */                          
#define SemaApi_Update(filename) SemaApi_UpdateBMC(filename , false , 0)
/*                           
 * \brief  SemaApi_UpdateAndShutdown   
 *                          
 * \details          
 *                          
 * \param	[in]  char *filename				BMC frimware binary file
 */                          
#ifdef WIN32
#	define SemaApi_UpdateAndShutdown(filename) SemaApi_UpdateBMC(filename , true , 0xff)
#else
#	define SemaApi_UpdateAndShutdown(filename) SemaApi_UpdateBMC(filename , true , 0x1)
#endif
/*                           
 * \brief  SemaApi_UpdateTiva   
 *                          
 * \details          
 *                          
 * \param	[in]  char *filename 
 */                          
DLL_EXPORT
RESULT
SemaApi_UpdateTiva(
     __IN char *filename
);
/*                           
 * \brief  SemaApi_UpdateLegacy   
 *                          
 * \details          
 *                          
 * \param	[in]  char *filename 
 */                          
DLL_EXPORT
RESULT
SemaApi_UpdateLegacy(
     __IN char *filename
);
/*                           
 * \brief  SemaApi_InitBMC   
 *                          
 * \details          
 *                          
 * \param	[in]  char Init 
 * \param	[in]  char *key 
 */                          
DLL_EXPORT
RESULT
SemaApi_InitBMC(
     __IN char Init , 
     __IN char *key
);
/*                           
 * \brief  SemaApi_Stat   
 *                          
 * \details          
 *                          
 * \param	[in]  char *key 
 */                          
DLL_EXPORT
RESULT
SemaApi_Stat(
     __IN char *key
);
/*                           
 * \brief  SemaApi_SetGpioDirection   
 *                          
 * \details Set GPIO direction of the I/O pins.
 *                          
 * \param	[in]  unsigned int dwData		New status of Configuration register 
 */                          
DLL_EXPORT
RESULT
SemaApi_SetGpioDirection(
     __IN unsigned int dwData
);
/*                           
 * \brief  SemaApi_SetGpioWrite   
 *                          
 * \details Get GPIO Output of the I/O pins         
 *                          
 * \param	[in]  unsigned int dwData		New status of Output register 
 */                          
DLL_EXPORT
RESULT
SemaApi_SetGpioWrite(
     __IN unsigned int dwData
);
/*                           
 * \brief  SemaApi_GpioXorAndXor   
 *                          
 * \details	Set GPIO Output of the I/O pins.
 *                          
 * \param	[in]  unsigned int Value1		value to Xor the I/O pins 
 * \param	[in]  unsigned int Value2		value to And the I/O pins 
 * \param	[in]  unsigned int Value3		value to Xor the I/O pins 
 */                          
DLL_EXPORT
RESULT
SemaApi_GpioXorAndXor(
     __IN unsigned int Value1 , 
     __IN unsigned int Value2 , 
     __IN unsigned int Value3
);
/*                           
 * \brief  SemaApi_SetBMCAddress   
 *                          
 * \details          
 *                          
 * \param	[in]  byte Address 
 */                          
DLL_EXPORT
RESULT
SemaApi_SetBMCAddress(
     __IN byte Address
);
/*                           
 * \brief  SemaApi_IsSimulationMode   
 *                          
 * \details          
 *                          
 */                          
DLL_EXPORT
RESULT
SemaApi_IsSimulationMode(
     void 
);
/*                           
 * \brief  SemaApi_GpiosAreInterchanged   
 *                          
 * \details          
 *                          
 * \param	[in]  bool interchanged 
 */                          
DLL_EXPORT
RESULT
SemaApi_GpiosAreInterchanged(
     __IN bool interchanged
);
/*                           
 * \brief  SemaApi_GetBootVersion   
 *                          
 * \details	Get BMC bootloader version string
 *                          
 * \param	[out]  byte *Buffer				Buffer for BMC bootloader version string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBootVersion(
     __OUT byte *pBuffer
);
/*                           
 * \brief  SemaApi_GetBootVersionExt   
 *                          
 * \details	Get BMC bootloader version string if it is > 32 Byte
 *                          
 * \param	[out]  byte *pBuffer			Buffer for BMC bootloader version string 64 Bytes at least.
 */                          
DLL_EXPORT
RESULT
SemaApi_GetBootVersionExt(
     __OUT byte *pBuffer
);
/*                           
 * \brief  SemaApi_GetGpioDirection   
 *                          
 * \details	Get GPIO direction of the I/O pins.          
 *                          
 * \param	[out]  unsigned int *dwData		Pointer to current status of Configuration register
 */                          
DLL_EXPORT
RESULT
SemaApi_GetGpioDirection(
     __OUT unsigned int *dwData
);
/*                           
 * \brief  SemaApi_GetGpioRead   
 *                          
 * \details	Get GPIO Input of the I/O pins.
 *                          
 * \param	[out]  unsigned int *dwData		Pointer to current status of Input register
 */                          
DLL_EXPORT
RESULT
SemaApi_GetGpioRead(
     __OUT unsigned int *dwData
);
/*                           
 * \brief  SemaApi_GetLibraryMajor   
 *                          
 * \details Get the Manufacturing Date selcet by the Data paramter
 *                          
 * \param	[out]  word * pMajor			major library version number
 */                          
DLL_EXPORT
RESULT
SemaApi_GetLibraryMajor(
     __OUT word * pMajor
);
/*                           
 * \brief  SemaApi_GetLibraryMinor   
 *                          
 * \details          
 *                          
 * \param	[out]  word * pMinor			minor library version number
 */                          
DLL_EXPORT
RESULT
SemaApi_GetLibraryMinor(
     __OUT word * pMinor
);
/*                           
 * \brief  SemaApi_GetLibraryAddon   
 *                          
 * \details          
 *                          
 * \param	[out]  const char ** pAddon		the library version addon string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetLibraryAddon(
     __OUT const char ** pAddon
);
/*                           
 * \brief  SemaApi_GetHardwareAddon   
 *                          
 * \details          
 *                          
 * \param	[out]  const char* pAddon		the hardware driver/library  addon string
 */                          
DLL_EXPORT
RESULT
SemaApi_GetHardwareAddon(
     __OUT const char** pAddon
);
/*                           
 * \brief  SemaApi_GetHardwareMajor   
 *                          
 * \details          
 *                          
 * \param	[out]  word * pMajor			major hardware driver/library version number
 */                          
DLL_EXPORT
RESULT
SemaApi_GetHardwareMajor(
     __OUT word * pMajor
);
/*                           
 * \brief  SemaApi_GetHardwareMinor   
 *                          
 * \details          
 *                          
 * \param	[out]  word * pMinor			minor hardware driver/library version number 
 */                          
DLL_EXPORT
RESULT
SemaApi_GetHardwareMinor(
     __OUT word * pMinor
);
/*                           
 * \brief  SemaApi_BoardGetErrorLog   
 *                          
 * \details          
 *                          
 * \param	[out]  word * pMinor			minor hardware driver/library version number 
 */    
 
DLL_EXPORT
RESULT
SemaApi_BoardGetErrorLog(
	 __IN	dword pos,
	 __OUT	byte * buffer
);


DLL_EXPORT
RESULT
SemaApi_GetManufacturingDataAdminMode(
     __IN byte Data , 
     __OUT byte *Buffer 
);

DLL_EXPORT
RESULT
SemaApi_GetExceptionDescription(
	 __IN	byte errcode,
	 __OUT	byte * buffer
);


DLL_EXPORT
RESULT
SemaApi_GetErrorDescription(
	 __IN	dword errnum,
	 __OUT	byte * pBuffer
);


/*                           
 * \brief  SemaApi_1WireReset
 *                          
 * \details          
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireReset( void );

/*                           
 * \brief  SemaApi_1WireProbeRomID
 *                          
 * \details          
 *
 * \param	[out]  byte * pFamilyCode		Family code 
 * \param	[out]  byte * pSerialNo			The 6 bytes array of Serial number
 * \param	[out]  byte * pCRC			CRC
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireProbeRomID( __OUT byte *pFamilyCode, __OUT byte *pSerialNo, __OUT byte *pCRC );

/*                           
 * \brief  SemaApi_1WireGetStatus
 *                          
 * \details          
 *
 * \param	[out]  dword * pStatus			The status of 1-wire
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireGetStatus( __OUT dword *pStatus );

/*                           
 * \brief  SemaApi_1WireSendFunctionCmd
 *                          
 * \details          
 *
 * \param	[in]  byte    FamilyCode		The family code
 * \param	[in]  byte *  pSerialNo			The 6 bytes array of serial number
 * \param	[in]  byte    CRC			The CRC
 * \param	[in]  byte * pComs			The buffer of command
 * \param	[in]  byte   CmdLen			The buffer length of command
 * \param	[in]  byte   pData			The buffer of data
 * \param	[in]  byte   DataLen			The buffer length of data
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireSendFunctionCmd( __IN byte FamilyCode, __IN byte *pSerialNo, __IN byte CRC, __IN byte *pComs, __IN byte CmdLen, __IN byte *pData, __IN byte DataLen );

/*                           
 * \brief  SemaApi_1WireRead
 *                          
 * \details          
 *
 * \param	[out]  byte  * pBuffer			The buffer for reading data
 * \param	[in]   dword * BufLen			The buffer length of data
 * \param	[in]   dword * ByteCnt			The counter of reading data
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireRead( __OUT byte *pBuffer, __IN dword BufLen, __IN dword ByteCnt );

/*                           
 * \brief  SemaApi_1WireSelectGPIOPin
 *                          
 * \details          
 *
 * \param	[in]  byte  GPIONum			The GPIO number
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireSelectGPIOPin( __IN dword GPIONum );

/*                           
 * \brief  SemaApi_1WireGetSelectGPIOPin
 *                          
 * \details          
 *
 * \param	[in]  byte  *GPIONum			The GPIO number
 *
 */                          
DLL_EXPORT
RESULT
SemaApi_1WireGetSelectGPIOPin( __OUT dword *GPIONum );

DLL_EXPORT
RESULT 
SemaApi_SetDefault();

DLL_EXPORT
RESULT
SemaApi_BoardSetManufactureData(__IN	dword Id,__IN	char *pBuffer);

DLL_EXPORT
RESULT
SemaApi_GetIOCurrent( __IN unsigned char Ch ,  __OUT float* pVolt );

DLL_EXPORT
RESULT
SemaApi_GPIOPinGetCap( __IN byte ID, __OUT dword *Cpabilites );

DLL_EXPORT
RESULT
SemaApi_GPIOPinSetConfig( __IN byte ID, __IN dword Configuration );

DLL_EXPORT
RESULT
SemaApi_GPIOPinGetConfig( __IN byte ID, __OUT dword *Configuration );

DLL_EXPORT
RESULT
SemaApi_GPIOGetADCValue( __IN byte ID, __OUT dword *Value );

DLL_EXPORT
RESULT
SemaApi_BoardGetCurrentPosErrorLog(
	 __OUT	byte * buffer
);

DLL_EXPORT
RESULT
SemaApi_SMBusBlockWrite( __IN dword Address, __IN dword Command, __IN dword Length, __IN byte *Buffer );

DLL_EXPORT
RESULT
SemaApi_SMBusBlockRead( __IN dword Address, __IN dword Command, __IN dword Length, __OUT byte *Buffer );

DLL_EXPORT
RESULT
SemaApi_SMBusWrite( __IN dword Address, __IN dword SMBusAccessIndex, __IN byte *Buffer );

DLL_EXPORT
RESULT
SemaApi_SMBusRead( __IN dword Address, __IN dword SMBusAccessIndex, __OUT byte *Buffer );

DLL_EXPORT
RESULT
SemaApi_BusTransStatus( __IN byte BusNumber, __OUT byte *Buffer );

#ifdef __cplusplus
	}
#endif


#endif
