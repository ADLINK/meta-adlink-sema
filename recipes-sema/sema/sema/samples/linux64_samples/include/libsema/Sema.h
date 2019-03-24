/**
*******************************************************************************
*	\FILE		Sema.h
*
*	\DESCRIPTION
*		Smart Embedded Management Agent (SEMA)
*
*		Capsulates access to BMC
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT ADILINK Technology GmbH Germany
*
*******************************************************************************
**/

#ifndef SEMA_H
#define SEMA_H


#ifdef _WIN32
//Disable by SEMA 3.0
//	#define NOMINMAX
	#include <windows.h>
	#include "win32/SMBus_win32.h"	
#else

#ifdef ANDROID
    #include "android/SMBus_Linux.h"
#else
    #include "linux/SMBus_Linux.h"
#endif /* _WIN32 */
#endif

#ifdef WINCE
	#include "WinCE.h"
#endif /* WINCE */


#include "DLL_Exports.h"

#ifdef VXWORKS
	#define SCHAR_MIN   (-128)      /* minimum signed char value */
	#define SCHAR_MAX     127       /* maximum signed char value */
#endif


#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/* ------------------------------ Definitions ------------------------------- */


// BMC Commands
#define SEMA_CMD_GET_BOARDERRLOG	0x1c		///<	Get Board Error Log
#define SEMA_CMD_SET_SYSCTRLREG		0x1f		///< Set SystemControlRegister
#define SEMA_CMD_SET_WD				0x20		///< Set/Clear Watchdog-timer
//#define SEMA_CMD_CLR_RBTC			0x21		///< Clear Recovery-BIOS Timeout Counter
#define SEMA_CMD_SET_PWRUPWD		0x22		///< Set/Clear Initial Watchdog-timer
#define SEMA_CMD_GET_GPIOREG		0x24		///< Get gpio register
#define SEMA_CMD_SET_GPIOREG		0x25		///< Set gpio register
#define SEMA_CMD_SYSCFG				0x27		///< Get/Set system config register
#define SEMA_CMD_MEMSIZE			0x2D		///< Get Memsize on CRR-945GSE (1:512MB, 2:1GB, 3:2GB)
#define SEMA_CMD_CLEAR_EXCEPT		0x2E		///< Clears Exception code (bits 4..0 of BMC flags -> CMD 0x35)
#define SEMA_CMD_CAPABILITIES		0x2F		///< Get BMC Capabilities
#define SEMA_CMD_RD_VERSION1		0x30		///< Read version string 1
#define SEMA_CMD_RD_VERSION2		0x31		///< Read version string 2
#define SEMA_CMD_RD_TOM				0x32		///< Read total uptime minutes
#define SEMA_CMD_RD_PWRUPSECS		0x33		///< Read seconds since power up
#define SEMA_CMD_RD_PWRCYCLES		0x34		///< Read number of power cycles
#define SEMA_CMD_RD_BMC_FLAGS		0x35		///< Read BMC flags (internal BMC Status (bits7..5) + exception code (4..0))
#define SEMA_CMD_RD_RESTARTEVT		0x36		///< Read last system restart event
#define SEMA_CMD_RD_CPUTEMPCUR		0x37		///< Read current CPU temperature
#define SEMA_CMD_RD_BRDTEMPCUR		0x38		///< Read current board temperature
#define SEMA_CMD_RD_MINMAXTEMP		0x39		///< Read minimum/maximum CPU and board temperatures
#define SEMA_CMD_RD_STARTTEMP		0x3A		///< Read startup temperatures of CPU and board
#define SEMA_CMD_RD_BMC_STATUS		0x3D		///< Read BMC Status byte
#define SEMA_CMD_RD_BOOTCOUNT		0x3E		///< Read number of boots
#define SEMA_CMD_RD_BLVERSION		0x3F		///< Read bootloader version
#define SEMA_CMD_SET_ADDRESS		0x40		///< Set address and length for flash access
#define SEMA_CMD_WRITE_DATA			0x41		///< Write data to user flash
#define SEMA_CMD_READ_DATA			0x42		///< Read data from user flash
#define SEMA_CMD_CLEAR_DATA			0x43		///< Clear data from user flash

#define SEMA_CMD_RD_AIN0			0x60		///< Read analog input Ch0
#define SEMA_CMD_RD_AIN1			0x61		///< Read analog input Ch1
#define SEMA_CMD_RD_AIN2			0x62		///< Read analog input Ch2
#define SEMA_CMD_RD_AIN3			0x63		///< Read analog input Ch3
#define SEMA_CMD_RD_AIN4			0x64		///< Read analog input Ch4
#define SEMA_CMD_RD_AIN5			0x65		///< Read analog input Ch5
#define SEMA_CMD_RD_AIN6			0x66		///< Read analog input Ch6
#define SEMA_CMD_RD_AIN7			0x67		///< Read analog input Ch7
#define SEMA_CMD_RD_CPU_FAN			0x68		///< Read CPU fan speed
#define SEMA_CMD_RD_MPCURRENT		0x69		///< Read main power current
#define SEMA_CMD_RD_SYSTEM_FAN_1		0x6A		///< Read system fan #1 speed
#define SEMA_CMD_RD_SYSTEM_FAN_2		0x6B		///< Read system fan #2 speed
#define SEMA_CMD_RD_SYSTEM_FAN_3		0x6C		///< Read system fan #3 speed

#define SEMA_CMD_EXC_CODE_TABLE			0x6F		///< Read exception code table

#define SEMA_CMD_RD_2ND_BRDTEMPCUR		0xE0		///< Read current board 2nd temperature
#define SEMA_CMD_RD_2ND_MINMAXTEMP		0xE1		///< Read minimum/maximum 2nd CPU and 2nd board temperatures
#define SEMA_CMD_RD_2ND_STARTTEMP		0xE2		///< Read 2nd startup temperatures of CPU and board

#define SEMA_CMD_RD_MF_DATA			0x70		///< Read part number

	#define SEMA_MANU_DATA_MAX			10		///< Maximun number of data fields
	#define SEMA_MANU_DATA_HW_REV		0
	#define SEMA_MANU_DATA_SR_NO		1
	#define SEMA_MANU_DATA_LR_DATA		2
	#define SEMA_MANU_DATA_MF_DATE		3
	#define SEMA_MANU_DATA_2HW_REV		4
	#define SEMA_MANU_DATA_2SR_NO		5
	#define SEMA_MANU_DATA_MACID		6
	#define SEMA_MANU_DATA_RES			7
	#define SEMA_MANU_DATA_PLAT_ID		8
	#define SEMA_MANU_DATA_PLAT_SPEC_VER	9

#define SEMA_CMD_BL_SETPWM			0x80		///< Set Backlight PWM
#define SEMA_CMD_BL_GETPWM			0x81		///< Get Backlight PWM

#define SEMA_CMD_TIVA_GPIO_STATUS		0x88
#define SEMA_CMD_TIVA_GPIO_STATUS_WRITE		0x89
#define SEMA_CMD_TIVA_GPIO_MODE			0x8A
#define SEMA_CMD_TIVA_GPIO_MODE_CAP			0x8C

#define SEMA_CMD_SFC_CPU_TMP_SETPTS	0xA0		///< Get/Set Smart Fan control (CPU) temperature setpoints
#define SEMA_CMD_SFC_CPU_PWM_SETPTS	0xA1		///< Get/Set Smart Fan control (CPU) PWM setpoints
#define SEMA_CMD_SFC_SYS_1_TMP_SETPTS		0xA2		///< Get/Set Smart Fan control (System #1) temperature setpoints
#define SEMA_CMD_SFC_SYS_1_PWM_SETPTS		0xA3		///< Get/Set Smart Fan control (System #1) PWM setpoints
#define SEMA_CMD_SFC_SYS_2_TMP_SETPTS		0xA8		///< Get/Set Smart Fan control (System #2) temperature setpoints
#define SEMA_CMD_SFC_SYS_2_PWM_SETPTS		0xA9		///< Get/Set Smart Fan control (System #2) PWM setpoints
#define SEMA_CMD_SFC_SYS_3_TMP_SETPTS		0xAA		///< Get/Set Smart Fan control (System #3) temperature setpoints
#define SEMA_CMD_SFC_SYS_3_PWM_SETPTS		0xAB		///< Get/Set Smart Fan control (System #3) PWM setpoints


#define SEMA_CMD_GET_ADC_SCALE		0xA4		///< Get ADC scale factors (for analog inputs Ch0..7)
#define SEMA_CMD_GET_VOLT_DESCR		0xA5		///< Get voltage descriptions (or nominal values)
#define SEMA_CMD_GET_EXT_VOLT_DESCR 		0xA6		///< Get extended voltage descriptions (or nominal values)


#define SEMA_CMD_IIC4_BLOCK			0xB0		///< I2C block access on external I2C bus #4
#define SEMA_CMD_IIC1_BLOCK			0xB1		///< I2C block access on external I2C bus #1
#define SEMA_CMD_IIC2_BLOCK			0xB2		///< I2C block access on external I2C bus #2
#define SEMA_CMD_IIC3_BLOCK			0xB3		///< I2C block access on external I2C bus #3

#define	SEMA_CMD_IIC4_BYTE_READ 	0xB4		///< I2C byte access on external I2C bus #4
#define SEMA_CMD_IIC1_BYTE_READ		0xB5		///< I2C byte access on external I2C bus #1
#define SEMA_CMD_IIC2_BYTE_READ		0xB6		///< I2C byte access on external I2C bus #2
#define SEMA_CMD_IIC3_BYTE_READ		0xB7		///< I2C byte access on external I2C bus #3

#define SEMA_CMD_IIC4_BYTE_WRITE	0xB8		///< I2C byte access on external I2C bus #4
#define SEMA_CMD_IIC1_BYTE_WRITE	0xB9		///< I2C byte access on external I2C bus #1
#define SEMA_CMD_IIC2_BYTE_WRITE	0xBA		///< I2C byte access on external I2C bus #2
#define SEMA_CMD_IIC3_BYTE_WRITE	0xBB		///< I2C byte access on external I2C bus #3

#define SEMA_CMD_IIC4_COMANND_BYTE_READWRITE	0xBC ///< I2C command byte access on external I2C bus #3
#define SEMA_CMD_IIC1_COMANND_BYTE_READWRITE    0xBD ///< I2C command byte access on external I2C bus #1
#define SEMA_CMD_IIC2_COMANND_BYTE_READWRITE    0xBE ///< I2C command byte access on external I2C bus #2
#define SEMA_CMD_IIC_GETDATA		0xBF		///< I2C get data on external I2C busses

#define SEMA_CMD_IIC1_TRANS		0xC1    		///< I2C transaction access on external I2C bus #1   
#define SEMA_CMD_IIC2_TRANS		0xC2    		///< I2C transaction access on external I2C bus #2
#define SEMA_CMD_IIC3_TRANS		0xC3    		///< I2C transaction access on external I2C bus #3   
#define SEMA_CMD_IIC4_TRANS		0xC0    		///< I2C transaction access on external I2C bus #4 

#define SEMA_CMD_IIC_STATUS		0xC4    		///< I2C status on last transction 

#define SEMA_CMD_RD_AIN8			0xD0		///< Read analog input Ch8
#define SEMA_CMD_RD_AIN9			0xD1		///< Read analog input Ch9
#define SEMA_CMD_RD_AIN10			0xD2		///< Read analog input Ch10
#define SEMA_CMD_RD_AIN11			0xD3		///< Read analog input Ch11
#define SEMA_CMD_RD_AIN12			0xD4		///< Read analog input Ch12
#define SEMA_CMD_RD_AIN13			0xD5		///< Read analog input Ch13
#define SEMA_CMD_RD_AIN14			0xD6		///< Read analog input Ch14
#define SEMA_CMD_RD_AIN15			0xD7		///< Read analog input Ch15

#define	SEMA_CMD_EXTENDED_INDEX_COMMAND		0xEE
#define	SEMA_CMD_EXTENDED_DATA_COMMAND		0xEF

#define SEMA_GPIO_ADDRESS			0x40		///< GPIO PCA9535 chip Address
#define SEMA_GPIO_PORT0_INPUT_REG			0x00		///< GPIO Configuration registers
#define SEMA_GPIO_PORT0_OUTPUT_REG		0x02		///< GPIO Input registers
#define SEMA_GPIO_PORT0_CON_REG			0x06		///< GPIO Direction registers
#define SEMA_GPIO_PORT1_INPUT_REG			0x01		///< GPIO Configuration registers
#define SEMA_GPIO_PORT1_OUTPUT_REG		0x03		///< GPIO Input registers
#define SEMA_GPIO_PORT1_CON_REG			0x07		///< GPIO Direction registers

#define PCA9535_INPUT_CAP			0xFFFF		///< supported inputs (PCA9535)
#define PCA9535_OUTPUT_CAP		0xFFFF		///< supported outputs (PCA9535)

/* ------------------------------ Definitions ------------------------------ */

#define SEMA_FLASH	((word)((Sema_GetCapabilities() & SEMA_C_1KB_FLASH) ? 0x0400 : 0x0200))		///< Size of USER flash area in bytes
#define SEMA_MAX_ANALOG_INPUTS  0x10		// Max number of ADC inputs supported
#define MAX_MEMREAD		0x1000		// max number of bytes (mem read)
#define MAX_BIOS_INDEX	3			// max BIOS index (0:standard 1:fail-safe 2:extern(SPI0 on carrier) 3:Internal BIOS (SPI0 on module))
#define BMCREAD					((unsigned char)(BMC_Address|1))	// BMC slave read address
#define BMCWRITE				((unsigned char)(BMC_Address))		// BMC slave write address

#define SEMA_FAN_CPU		0
#define SEMA_FAN_SYSTEM_1	1
#define SEMA_FAN_SYSTEM_2	2
#define SEMA_FAN_SYSTEM_3	3
#define SEMA_FAN_MODE_AUTO	0	
#define SEMA_FAN_MODE_ON	2
#define SEMA_FAN_MODE_OFF 	1
#define SEMA_FAN_MODE_SOFT_FAN 	3
#define SEMA_FAN_TEMP_CPU	0
#define SEMA_FAN_TEMP_SYS	1
#define SEMA_FAN_TEMP_SYS_1	2

//Ext. I2C defines
#define SEMA_EXT_IIC_BUS_1		0
#define SEMA_EXT_IIC_BUS_2		1
#define SEMA_EXT_IIC_BUS_3		2
#define SEMA_EXT_IIC_BUS_4		3
#define SEMA_EXT_IIC_READ		0x01
#define SEMA_EXT_IIC_BLOCK 		0x02
#define SEMA_EXT_IIC_BYTE		0x04
#define SEMA_EXT_IIC_COMMAND		0x08
#define SEMA_EXT_IIC_EXT_COMMAND		0x10
#define SEMA_EXT_IIC_EXT_COMMAND_WR		0x20

#define SEMA_EXT_IIC_SPEED_100		0x01
#define SEMA_EXT_IIC_SPEED_400		0x02

#define INTERCHANGED_GPIO_LOCATIONS 1
#define BASIC_GPIO_LOCATIONS 0
#define BIT_MASK_INTERCHANED_GPIOS 0x00B0
#define BASIC_GPO0_LOCATION 4
#define BASIC_GPO1_LOCATION 5
#define BASIC_GPO3_LOCATION 7
#define INTERCHANED_GPO0_LOCATION 7
#define INTERCHANED_GPO1_LOCATION 4
#define INTERCHANED_GPO3_LOCATION 5

/* ------------------------------- Typedefs  ------------------------------- */

typedef enum
{
	SEMA_SRE_UNKNOWN	= 0x00,
	SEMA_SRE_SW_RESET	= 0x20,
	SEMA_SRE_HW_RESET	= 0x30,
	SEMA_SRE_WATCHDOG	= 0x40,
	SEMA_SRE_BIOS_FAULT	= 0x50,
	SEMA_SRE_PWR_DOWN	= 0x60,
	SEMA_SRE_PWR_LOSS	= 0x70,
	SEMA_SRE_PWR_CYCLE	= 0x80,
	SEMA_SRE_VIN_DROP	= 0x90,
	SEMA_SRE_PWR_FAIL	= 0xA0,
	SEMA_SRE_CRIT_TEMP	= 0xB0,
	SEMA_SRE_WAKEUP		= 0xC0
} tSEMA_SRE;								///< System Restart Event codes (aka boot reason)


// Capabilities
#define SEMA_C_STANDARD		0x00000000			///< Only standard capabilities available
#define SEMA_C_UPTIME		0x00000001			///< Group 0 bit  0: Uptime & Pwr cycles counter
#define SEMA_C_RESTARTEVENT	0x00000002			///< Group 0 bit  1: System restart event
#define SEMA_C_1KB_FLASH	0x00000004			///< Group 0 bit  2: 1k USER flash memory available
#define SEMA_C_WATCHDOG		0x00000008			///< Group 0 bit  3: Watchdog
#define SEMA_C_TEMPERATURES	0x00000010			///< Group 0 bit  4: Temperature sensors installed/available
#define SEMA_C_VOLTAGES		0x00000020			///< Group 0 bit  5: Voltage sensors installed/available
#define SEMA_C_FAILREASON	0x00000040			///< Group 0 bit  6: Storage of failure reason available (exeption code)
#define SEMA_C_BL_TIMEOUT	0x00000080			///< Group 0 bit  7: Bootloader timeout programmable
#define SEMA_C_DISPLAYCTRL	0x00000100			///< Group 0 bit  8: Display control available
#define SEMA_C_PWRUP_WD		0x00000200			///< Group 0 bit  9: Power up watchdog available
#define SEMA_C_CURRENTS		0x00000400			///< Group 0 bit 10: Current sensors installed/available
#define SEMA_C_BOOTCOUNT	0x00000800			///< Group 0 bit 11: Bootcounter
#define SEMA_C_INPUTVOLT0	0x00001000			///< Group 0 bit 12: Input-Voltage0 V10:00=5V, 01=12V, 10+11=reserved
#define SEMA_C_INPUTVOLT1	0x00002000			///< Group 0 bit 13: Input-Voltage1 V10:00=5V, 01=12V, 10+11=reserved
#define SEMA_C_RSENSE		0x00004000			///< Group 0 bit 14: Rsense for Input-Voltage: 0=8mR, 1=4mR
#define SEMA_C_FAILSAFEBIOS	0x00008000			///< Group 0 bit 15: Fail-Safe-BIOS supported
#define SEMA_C_I2C1		0x00010000			///< Group 0 bit 16: Ext. I2C bus #1 available
#define SEMA_C_I2C2		0x00020000			///< Group 0 bit 17: Ext. I2C bus #2 available
#define SEMA_C_FAN_CPU		0x00040000			///< Group 0 bit 18: Programmable CPU fan available
#define SEMA_C_FAN_1		0x00080000			///< Group 0 bit 19: Programmable system fan available
#define SEMA_C_AT_ATX_MODE	0x00100000			///< Group 0 bit 20: AT/ATX mode supported
#define SEMA_C_THERMAL_SCI	0x00200000			///< Group 0 bit 21: Thermal SCI supported
#define SEMA_C_PWRLASTSTATE	0x00400000			///< Group 0 bit 22: Power up to last state
#define SEMA_C_BACKLGHTRES	0x00800000			///< Group 0 bit 23: Backlight restore
#define SEMA_C_DTS_REGISTER	0x01000000			///< Group 0 bit 24: DTS register
#define SEMA_C_DTS_OFFSET	0x02000000			///< Group 0 bit 25: DTS register offset
#define SEMA_C_FAN_2		0x04000000			///< Group 0 bit 26: Smart fan #3
#define SEMA_C_FAN_3		0x08000000			///< Group 0 bit 27: Smart fan #4
#define SEMA_C_GPIOS		0x10000000			///< Group 0 bit 28: TIVA GPIOs support (12GPIOs)
#define SEMA_C_I2C3		0x20000000			///< Group 0 bit 29: Ext. I2C bus #3 available
#define SEMA_C_I2C4		0x40000000			///< Group 0 bit 30: Ext. I2C bus #4 available
#define SEMA_C_BMC_TIVA		0x80000000			///< Group 0 bit 31: BMC is from TIVA type

#define SEMA_C_TEMPERATURES_1	0x00000001			///< Group 1 bit  0 : Extend Byte ( Bit 32 ): Temperature sensors 1 installed/available
#define SEMA_C_SMBUS_PEC	0x00000002			///< Group 1 bit  1 : Extend Byte ( Bit 33 ): SM-Bus PEC protocol
#define SEMA_C_RESERVED_BIT_34	0x00000004			///< Group 1 bit  2 : Extend Byte ( Bit 34 ): This bit is reserved in BMC
#define SEMA_C_ERROR_LOG	0x00000008			///< Group 1 bit  3 : Extend Byte ( Bit 35 ): Error log
#define SEMA_C_1WIRE		0x00000010			///< Group 1 bit  4 : Extend Byte ( Bit 36 ): 1-wire bus
#define SEMA_C_BMC_WAKE		0x00000020			///< Group 1 bit  5 : Extend Byte ( Bit 37 ): Wake by BMC
#define SEMA_C_GPIO_ADC		0x00000040			///< Group 1 bit  6 : Extend Byte ( Bit 38 ): GPIO with alternate function
#define SEMA_C_SOFT_FAN		0x00000080			///< Group 1 bit  7 : Extend Byte ( Bit 39 ): Software fan
#define SEMA_C_PARAMETER_MEMORY	0x00000100			///< Group 1 bit  8 : Extend Byte ( Bit 40 ): Parameter memory
#define SEMA_C_EXTENDED_I2C	0x00000200			///< Group 1 bit  9 : Extend Byte ( Bit 41 ): Extended I2C command

#define SEMA_C_SIMULATION	0x001CCB1D			///< Some function which can be simualted

#define	SEMA_MAX_CAPABILITY_GROUP	8

#define	SEMA_CAPABILITY_GROUP0		0
#define	SEMA_CAPABILITY_GROUP1		1
#define	SEMA_CAPABILITY_GROUP2		2
#define	SEMA_CAPABILITY_GROUP3		3
#define	SEMA_CAPABILITY_GROUP4		4
#define	SEMA_CAPABILITY_GROUP5		5
#define	SEMA_CAPABILITY_GROUP6		6
#define	SEMA_CAPABILITY_GROUP7		7

typedef unsigned int tSEMACapabilities;		///< 32 capability bits (bit desctiptions: see SEMA_C_*)


/* ------------------------------ Variables -------------------------------- */

DLL_EXPORT extern const char	*BIOS_Names[MAX_BIOS_INDEX+1];
DLL_EXPORT extern unsigned char Sema_BootDelay;	// default boot delay time [seconds] after BL/FW-update
DLL_EXPORT extern bool Sema_ShutDownAfterUpdate;	// shutdown operating system after BL/FW update?
extern byte BMC_Address;

/* ------------------------------- Functions ------------------------------- */


/**
*******************************************************************************
*	\FUNCTION	int Sema_Init(void)
*
*	\DESCRIPTION
*		Initializes SMBus access and queries BMC capabilities
*
*	\RETURNS
*		\c true if requested number of bytes could be read
*******************************************************************************
**/
DLL_EXPORT int Sema_Init(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_PrintCapabilities(void)
*
*	\DESCRIPTION
*		Print BMC capabilities
*******************************************************************************
**/
DLL_EXPORT void Sema_PrintCapabilities(void);


/**
*******************************************************************************
*	\FUNCTION	tSEMYCapabilities Sema_GetCapabilities(void)
*
*	\DESCRIPTION
*		Returns BMC capabilities (does not perform any tests!)
*
*	\RETURNS
*		Capabilities of BMC
*******************************************************************************
**/
DLL_EXPORT tSEMACapabilities Sema_GetCapabilities(void);

/**
*******************************************************************************
*	\FUNCTION	tSEMYCapabilities Sema_GetCapabilities_extend(void)
*
*	\DESCRIPTION
*		Returns BMC extended capabilities (does not perform any tests!)
*
*	\RETURNS
*		Capabilities of BMC
*******************************************************************************
**/
DLL_EXPORT tSEMACapabilities Sema_GetCapabilities_EX(void);

/**
*******************************************************************************
*	\FUNCTION	void Sema_OverrideCapabilities(tSEMACapabilities Cap)
*
*	\DESCRIPTION
*		Overrides BMC capabilities (USE WITH CARE!!!)
*
*	\PARAMETERS
*		Cap			Capabilities of BMC
*******************************************************************************
**/
DLL_EXPORT void Sema_OverrideCapabilities(tSEMACapabilities Cap);


/**
*******************************************************************************
*	\FUNCTION	byte Sema_Trans(byte Address, tTransType Type, byte *Buffer)
*
*	\DESCRIPTION
*		Initiates Raw I2C transfer
*
*	\RETURNS
*		1: success, 0: fail
*******************************************************************************
**/
DLL_EXPORT byte Sema_Trans(byte Address, tTransType Type, byte *Buffer);


/**
*******************************************************************************
*	\FUNCTION	byte Sema_TransExt(tTransType Type, byte Length, byte *Buffer)
*
*	\DESCRIPTION
*		Initiates transfer on external I2C busses
*
*	\PARAMETERS
*		Type		Transfer type											\np
*		Length		Number of bytes transferred to BMC (not to external device!)	\np
*		Buffer		Data to transfer/receive
*
*	\RETURNS
*		unused yet
*******************************************************************************
**/
DLL_EXPORT byte Sema_TransExt(byte BusNumber, byte Type, byte Length, byte *Buffer);

DLL_EXPORT byte Sema_TransExtSetSpeed(byte BusNumber, byte Mode);
DLL_EXPORT byte Sema_TransExtGetSpeed(byte BusNumber);

/**
********************************************************************************
*	\FUNCTION		dword Sema_GetChipsetID(void)
*
*	\DESCRIPTION
*		Get chipset ID (Vendor- + Device ID)
*
*	\RETURNS
*		Vendor- + Device ID
********************************************************************************
**/
DLL_EXPORT dword Sema_GetChipsetID(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_Close(void)
*
*	\DESCRIPTION
*		Cleans up
*******************************************************************************
**/
DLL_EXPORT void Sema_Close(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_SetWatchdog(unsigned short Value)
*
*	\DESCRIPTION
*		Sets watchdog timer
*
*	\PARAMETERS
*		Value		Watchdog timeout in seconds (0 disables watchdog)
*******************************************************************************
**/
DLL_EXPORT void Sema_SetWatchdog(unsigned short Value);


/**
*******************************************************************************
*	\FUNCTION	void Sema_SetWatchdog(unsigned short Value)
*
*	\DESCRIPTION
*		Sets watchdog timer
*
*	\PARAMETERS
*		Value		Watchdog timeout in seconds (0 disables watchdog)
*******************************************************************************
**/
DLL_EXPORT void Sema_SetPwrUpWatchdog(unsigned short Value);


/**
*******************************************************************************
*	\FUNCTION	 char *Sema_GetChipsetString(void)
*
*	\DESCRIPTION
*		Gets chipset IDs string 
*
*	\RETURNS
*		Pointer to chipset ID string
*******************************************************************************
**/
DLL_EXPORT const char* Sema_GetChipsetString(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_ClearExceptionCode(void)
*
*	\DESCRIPTION
*		Clears BMC exception code
*******************************************************************************
**/
DLL_EXPORT void Sema_ClearExceptionCode(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_GetVersionString1(byte *Buffer)
*
*	\DESCRIPTION
*		Get version string #1
*
*	\PARAMETERS
*		*Buffer		Buffer (at least 33 bytes!!) for version string
*******************************************************************************
**/
DLL_EXPORT void Sema_GetVersionString1(byte *Buffer);


/**
*******************************************************************************
*	\FUNCTION	void Sema_GetVersionString2(byte *Buffer)
*
*	\DESCRIPTION
*		Get version string #2
*
*	\PARAMETERS
*		*Buffer		Buffer (at least 33 bytes!!) for version string
*******************************************************************************
**/
DLL_EXPORT void Sema_GetVersionString2(byte *Buffer);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_GetAppVersion(byte *version)
*
*	\DESCRIPTION
*		Get BMC application version string
*
*	\PARAMETERS
*		*Buffer		Buffer (at least 65 bytes!!) for BMC application version string
*******************************************************************************
**/
DLL_EXPORT bool Sema_GetAppVersion(byte *version);


/**
*******************************************************************************
*	\FUNCTION	void Sema_GetManufacturingData(byte *Buffer, byte Data)
*
*	\DESCRIPTION
*		Get the Manufacturing Date selcet by the Data paramter
*
*	\PARAMETERS
*		*Buffer		Buffer for part number
*		Data		Manufacturing data index
*******************************************************************************
**/
DLL_EXPORT void Sema_GetManufacturingData(byte *Buffer, byte Data);


/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_GetMemSize(void)
*
*	\DESCRIPTION
*		Get memory size (currently only implemented for CRR-ATOM)
*
*	\RETURNS
*		1:512MB, 2:1GB, 3:2GB
*******************************************************************************
**/
DLL_EXPORT unsigned char Sema_GetMemSize(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned long Sema_GetTotalUpTime(void)
*
*	\DESCRIPTION
*		Get total uptime [minutes]
*
*	\RETURNS
*		Total uptime [minutes]
*******************************************************************************
**/
DLL_EXPORT unsigned long Sema_GetTotalUpTime(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned long Sema_GetPwrUpTime(void)
*
*	\DESCRIPTION
*		Get power uptime [seconds]
*
*	\RETURNS
*		Uptime since last boot [seconds]
*******************************************************************************
**/
DLL_EXPORT unsigned long Sema_GetPwrUpTime(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned long Sema_GetPwrCycles(void)
*
*	\DESCRIPTION
*		Get number of power cycles
*
*	\RETURNS
*		Number of power cycles
*******************************************************************************
**/
DLL_EXPORT unsigned long Sema_GetPwrCycles(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned long Sema_GetBootCount(void)
*
*	\DESCRIPTION
*		Get number of boots
*
*	\RETURNS
*		Number of boots
*******************************************************************************
**/
DLL_EXPORT unsigned long Sema_GetBootCount(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_GetBMCFlags(void)
*
*	\DESCRIPTION
*		Get BMC flags
*
*	\RETURNS
*		BMC flags
*******************************************************************************
**/
DLL_EXPORT unsigned char Sema_GetBMCFlags(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_GetBMCStatus(void)
*
*	\DESCRIPTION
*		Get BMC status register
*
*	\RETURNS
*		BMC status
*******************************************************************************
**/
DLL_EXPORT unsigned char Sema_GetBMCStatus(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_GetRestartEvent(void)
*
*	\DESCRIPTION
*		Get last system restart event
*
*	\RETURNS
*		Restart event code
*******************************************************************************
**/
DLL_EXPORT unsigned char Sema_GetRestartEvent(void);


/**
*******************************************************************************
*	\FUNCTION	const char* Sema_GetRestartEventText(void)
*
*	\DESCRIPTION
*		Get last system restart event
*
*	\RETURNS
*		Restart event description text
*******************************************************************************
**/
DLL_EXPORT const char* Sema_GetRestartEventText(void);


/**
*******************************************************************************
*	\FUNCTION	unsigned short Sema_GetFanSpeed(byte fan_number)
*
*	\DESCRIPTION
*		Get fan speed (unit: rpm)
*
*		Note: If feature is not supported returnvalue is 0
*
*	\PARAMETER
*		fan_number	Number of fan starting from by 0
*
*	\RETURNS
*		fan speed
*******************************************************************************
**/
DLL_EXPORT unsigned short Sema_GetFanSpeed(byte fan_number);



/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_SmartFanGetTempSetpoint(byte fan_number,signed char *lvl1, signed char *lvl2, signed char *lvl3, signed char *lvl4)
*
*	\DESCRIPTION
*		SmartFan: Get temperature setpoints (signed, degree Celsius)
*
*	\PARAMETER
*		fan_number	Number of fan starting by 0									\np
*		lvl1	value for TEMP_LEVEL1										\np
*		lvl2	value for TEMP_LEVEL2										\np
*		lvl3	value for TEMP_LEVEL3										\np
*		lvl4	value for TEMP_LEVEL4
*
*	\RETURNS
*		true if operation was successful
*******************************************************************************
**/
DLL_EXPORT bool Sema_SmartFanGetTempSetpoints(byte fan_number, signed char *lvl1, signed char *lvl2, signed char *lvl3, signed char *lvl4);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_SmartFanGetPWMSetpoints(byte fan_number, unsigned char *lvl1, unsigned char *lvl2, unsigned char *lvl3, unsigned char *lvl4)
*
*	\DESCRIPTION
*		SmartFan: Get PWM setpoints (valid range: 0..100)
*
*	\PARAMETER
*		fan_number	Number of fan starting by 0									\np
*		lvl1	value for PWM_LEVEL1										\np
*		lvl2	value for PWM_LEVEL2										\np
*		lvl3	value for PWM_LEVEL3										\np
*		lvl4	value for PWM_LEVEL4
*
*	\RETURNS
*		true if operation was successful
*******************************************************************************
**/
DLL_EXPORT bool Sema_SmartFanGetPWMSetpoints(byte fan_number, unsigned char *lvl1, unsigned char *lvl2, unsigned char *lvl3, unsigned char *lvl4);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_SmartFanSetTempSetpoints(byte fan_number, signed char lvl1, signed char lvl2, signed char lvl3, signed char lvl4)
*
*	\DESCRIPTION
*		SmartFan: Set temperature setpoints (signed, degree Celsius)
*
*	\PARAMETER
*		fan_number	Number of fan starting by 0									\np
*		lvl1	value for TEMP_LEVEL1										\np
*		lvl2	value for TEMP_LEVEL2										\np
*		lvl3	value for TEMP_LEVEL3										\np
*		lvl4	value for TEMP_LEVEL4
*
*	\RETURNS
*		true if operation was successful
*******************************************************************************
**/
DLL_EXPORT bool Sema_SmartFanSetTempSetpoints(byte fan_number, signed char lvl1, signed char lvl2, signed char lvl3, signed char lvl4);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_SmartFanSetPWMSetpoints(byte fan_number, unsigned char lvl1, unsigned char lvl2, unsigned char lvl3, unsigned char lvl4)
*
*	\DESCRIPTION
*		SmartFan: Set PWM setpoints (valid range: 0..100)
*
*	\PARAMETER
*		fan_number	Number of fan starting by 0									\np
*		lvl1	value for PWM_LEVEL1										\np
*		lvl2	value for PWM_LEVEL2										\np
*		lvl3	value for PWM_LEVEL3										\np
*		lvl4	value for PWM_LEVEL4
*
*	\RETURNS
*		true if operation was successful
*******************************************************************************
**/
DLL_EXPORT bool Sema_SmartFanSetPWMSetpoints(byte fan_number, unsigned char lvl1, unsigned char lvl2, unsigned char lvl3, unsigned char lvl4);

DLL_EXPORT byte Sema_SmartFanGetMode(byte fan_number);
DLL_EXPORT void Sema_SmartFanSetMode(byte fan_number, byte mode);
DLL_EXPORT byte Sema_SmartFanGetTempSrc(byte fan_number);
DLL_EXPORT void Sema_SmartFanSetTempSrc(byte fan_number, byte tempsrc);

/**
*******************************************************************************
*	\FUNCTION	float Sema_GetVoltage(unsigned char Ch)
*
*	\DESCRIPTION
*		Get voltage of selected channel (unit: V, resolution=1/1000 V)
*
*		Note: If feature is not supported or invalid channel selected,
*		returnvalue is 0.000
*
*	\RETURNS
*		voltage
*******************************************************************************
**/
DLL_EXPORT float Sema_GetVoltage(unsigned char Ch);

DLL_EXPORT bool Sema_GetVoltageDescription(unsigned char Ch, char *Buffer);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_GetVoltageDescriptionExt(unsigned char Ch, char *Buffer)
*
*	\DESCRIPTION
*		Returns the extended description string for the given analog input
*
*	\PARAMETER
*		Ch		Channel number starting from 0
*		Buffer	Pointer to buffer which receives the description string must 
*				be at least 17Bytes long (16Bytes string + 1Byte \0-character)
*
*	\RETURNS
*		True if operaton was successful
*******************************************************************************
**/
DLL_EXPORT bool Sema_GetVoltageDescriptionExt(unsigned char Ch, char *Buffer, bool truncate);


/**
*******************************************************************************
*	\FUNCTION	unsigned short Sema_GetMainPowerCurrent(void)
*
*	\DESCRIPTION
*		Get main power current (unit: mA, resolution=1/10 mA)
*
*	\RETURNS
*		main power current
*******************************************************************************
**/
DLL_EXPORT unsigned short Sema_GetMainPowerCurrent(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_BacklightSetPWM(byte Value)
*
*	\DESCRIPTION
*		Set new backlight PWM value (range: 0..255)
*
*	\PARAMETER
*		Value	new backlight PWM value (range: 0..255)
*******************************************************************************
**/
DLL_EXPORT void Sema_BacklightSetPWM(byte Value);


/**
*******************************************************************************
*	\FUNCTION	byte Sema_BacklightGetPWM(void)
*
*	\DESCRIPTION
*		Get current backlight PWM value (range: 0..255)
*
*	\RETURNS
*		current backlight PWM value
*******************************************************************************
**/
DLL_EXPORT byte Sema_BacklightGetPWM(void);


/**
*******************************************************************************
*	\FUNCTION	float Sema_GetCurrentCPUTemp(void)
*
*	\DESCRIPTION
*		Get current CPU temperature
*
*	\RETURNS
*		Current CPU temperature (resolution=1/10 degC)
*******************************************************************************
**/
DLL_EXPORT float Sema_GetCurrentCPUTemp(void);


/**
*******************************************************************************
*	\FUNCTION	signed char Sema_GetCurrentBoardTemp(void)
*
*	\DESCRIPTION
*		Get current board temperature
*
*	\RETURNS
*		Current board temperature
*******************************************************************************
**/
DLL_EXPORT signed char Sema_GetCurrentBoardTemp(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_GetMinMaxTemp(signed char *MinCPU, signed char *MaxCPU, signed char *MinBoard, signed char *MaxBoard)
*
*	\DESCRIPTION
*		Get min and max temperatures of CPU and board
*
*	\PARAMETERS
*		*MinCPU		Location for min CPU temperature						\np
*		*MaxCPU		Location for max CPU temperature						\np
*		*MinBoard	Location for min board temperature						\np
*		*MaxBoard	Location for max board temperature
*******************************************************************************
**/
DLL_EXPORT void Sema_GetMinMaxTemp(signed char *MinCPU, signed char *MaxCPU, signed char *MinBoard, signed char *MaxBoard);


/**
*******************************************************************************
*	\FUNCTION	void Sema_GetStartupTemp(signed char *StartCPU, signed char *StartBoard)
*
*	\DESCRIPTION
*		Get startup temperatures of CPU and board
*
*	\PARAMETERS
*		*StartCPU	Location for startup CPU temperature					\np
*		*StartBoard	Location for startup board temperature
*******************************************************************************
**/
DLL_EXPORT void Sema_GetStartupTemp(signed char *StartCPU, signed char *StartBoard);


/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_GetGPIOReg(void)
*
*	\DESCRIPTION
*		Get current status of GPIO register (only on 86DX platform)
*
*	\Returns
*		Current status of GPIO register
*******************************************************************************
**/
DLL_EXPORT unsigned char Sema_GetGPIOReg(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_SetGPIOReg(unsigned char GpioReg)
*
*	\DESCRIPTION
*		Set status of GPIO register (only on 86DX platform)
*
*	\PARAMETERS
*		GpioReg		New status of GPIO register
*******************************************************************************
**/
DLL_EXPORT void Sema_SetGPIOReg(unsigned char GpioReg);


/**
*******************************************************************************
*	\FUNCTION	unsigned short Sema_GetSysCtrlReg(void)
*
*	\DESCRIPTION
*		Get current status of system control register
*
*		Note: First byte of I2C data block is interpreted as most significant byte
*
*	\RETURNS
*		Current status of system control register
*******************************************************************************
**/
DLL_EXPORT unsigned int Sema_GetSysCtrlReg(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_SetSysCtrlReg(unsigned short val)
*
*	\DESCRIPTION
*		Set new status of system control register
*
*		Note: Most significant byte will be transferred first
*
*	\PARAMETER
*		val		New status of system control register
*******************************************************************************
**/
DLL_EXPORT void Sema_SetSysCtrlReg(unsigned int val);


/**
*******************************************************************************
*	\FUNCTION	unsigned char Sema_GetSoftStrapReg(void)
*
*	\DESCRIPTION
*		Get current status of SoftStrap register
*
*	\Returns
*		Current status of SoftStrap register
*******************************************************************************
**/
DLL_EXPORT unsigned char Sema_GetSoftStrapReg(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_SetSoftStrapRegOTF(unsigned char SStrapReg)
*
*	\DESCRIPTION
*		Set status of SoftStrap register "on the fly" (i.e. without power cycle)
*
*	\PARAMETERS
*		GpioReg		New status of SoftStrap register
*******************************************************************************
**/
DLL_EXPORT void Sema_SetSoftStrapRegOTF(unsigned char SStrapReg);


/**
*******************************************************************************
*	\FUNCTION	void Sema_SetSoftStrapRegPC(unsigned char SStrapReg)
*
*	\DESCRIPTION
*		Set status of SoftStrap register "permanently" (i.e. with power cycle)
*
*	\PARAMETERS
*		GpioReg		New status of SoftStrap register
*******************************************************************************
**/
DLL_EXPORT void Sema_SetSoftStrapRegPC(unsigned char SStrapReg);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_MemoryRead(byte *Buffer, unsigned short Adr, unsigned char Size)
*
*	\DESCRIPTION
*		Read from flash memory
*
*	\PARAMETERS
*		*Buffer		Buffer for read bytes									\np
*		Adr			Start address											\np
*		Size		Number of bytes to read
*
*	\RETURNS
*		\c true if requested number of bytes could be read
*******************************************************************************
**/
DLL_EXPORT bool Sema_MemoryRead(byte *Buffer, unsigned short Adr, unsigned char Size);


/**
*******************************************************************************
*	\FUNCTION	void Sema_MemoryWrite(byte *Buffer, unsigned short Adr, unsigned char Size)
*
*	\DESCRIPTION
*		Writes to flash memory
*
*	\PARAMETERS
*		*Buffer		Buffer for bytes to write								\np
*		Adr			Start address											\np
*		Size		Number of bytes to read
*******************************************************************************
**/
DLL_EXPORT void Sema_MemoryWrite(byte *Buffer, unsigned short Adr, unsigned char Size);


/**
*******************************************************************************
*	\FUNCTION	void Sema_MemoryClear(void)
*
*	\DESCRIPTION
*		Clears user flash memory
*******************************************************************************
**/
DLL_EXPORT void Sema_MemoryClear(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_MemoryRestore(void)
*
*	\DESCRIPTION
*		Restores first 64 bytes of user flash memory (partNo, serial, etc)
*******************************************************************************
**/
DLL_EXPORT void Sema_MemoryRestore(void);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_IsValidAddress(word Adr)
*
*	\DESCRIPTION
*		Tests if address is within valid range
*******************************************************************************
**/
DLL_EXPORT bool Sema_IsValidAddress(word Adr);


/**
*******************************************************************************
*	\FUNCTION	void Sema_AdjustSize(word *size, word address)
*
*	\DESCRIPTION
*		Adjusts size to valid values (boundaries, max length, ...)
*
*	\PARAMETERS
*		*size		number of bytes											\np
*		address		Start address
*******************************************************************************
**/
DLL_EXPORT void Sema_AdjustSize(word *size, word address);


/**
*******************************************************************************
*	\FUNCTION	void Sema_PrintMem(word address, word size, char *output)
*
*	\DESCRIPTION
*		Prints memory contents to formatted string
*
*	\PARAMETERS
*		address		Start address											\np
*		size		number of bytes											\np
*		*output		Pointer to output buffer
*******************************************************************************
**/
DLL_EXPORT void Sema_PrintMem(word address, word size, char *output);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_SelectBIOS(byte Index)
*
*	\DESCRIPTION
*		Select BIOS (only available if Fail-Safe-BIOS is supported)
*
*	\PARAMETERS
*		Index		BIOS number/index (0 or 1)
*
*	\RETURNS
*		true if successful, otherwise false
*******************************************************************************
**/
DLL_EXPORT bool Sema_SelectBIOS(byte Index);


/**
*******************************************************************************
*	\FUNCTION	byte Sema_GetBIOS(void)
*
*	\DESCRIPTION
*		Gets selected BIOS (only available if Fail-Safe-BIOS is supported)
*
*	\RETURNS
*		BIOS number/index (0:FS-BIOS not supported or normal BIOS selected / 1: FS-BIOS selected)
*******************************************************************************
**/
DLL_EXPORT byte Sema_GetBIOS(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_EnableAdminMode(void)
*
*	\DESCRIPTION
*		Enables admin mode
*******************************************************************************
**/
DLL_EXPORT void Sema_EnableAdminMode(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_DisableAdminMode(void)
*
*	\DESCRIPTION
*		Disables admin mode
*******************************************************************************
**/
DLL_EXPORT void Sema_DisableAdminMode(void);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_IsAdminMode(void)
*
*	\RETURNS
*		true if AdminMode is currently enabled
*******************************************************************************
**/
DLL_EXPORT bool Sema_IsAdminMode(void);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_GetBootVersion(byte *Buffer)
*
*	\DESCRIPTION
*		Get BMC bootloader version string
*
*	\PARAMETERS
*		*Buffer		Buffer for BMC bootloader version string
*
*	\RETURNS
*		true if successful, otherwise false
*******************************************************************************
**/
DLL_EXPORT bool Sema_GetBootVersion(byte *Buffer);

/**
*******************************************************************************
*	\FUNCTION	bool Sema_GetBootVersionExt(byte *Buffer)
*
*	\DESCRIPTION
*		Get BMC bootloader version string if it is > 32 Byte
*
*	\PARAMETERS
*		*Buffer		Buffer for BMC bootloader version string 64 Bytes at least.
*
*	\RETURNS
*		true if successful, otherwise false
*******************************************************************************
**/
DLL_EXPORT bool Sema_GetBootVersionExt(byte *Buffer);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_CheckFfsHeader(void)
*
*	\DESCRIPTION
*		Test if flash file system is ok
*
*	\RETURNS
*		1 if ffs is ok, 0 if ffs is bad 
*******************************************************************************
**/
DLL_EXPORT bool Sema_CheckFfsHeader(void);


/**
*******************************************************************************
*	\FUNCTION	int Sema_Prog(char *key, word address, char *filename)
*
*	\DESCRIPTION
*		Programs file content to specified memory address
*******************************************************************************
**/
DLL_EXPORT int Sema_Prog(char *key, word address, char *filename);


/**
*******************************************************************************
*	\FUNCTION	int Sema_Update(char *filename)
*
*	\DESCRIPTION
*		Updates BMC
*******************************************************************************
**/
DLL_EXPORT int Sema_Update(char *filename);
DLL_EXPORT int Sema_UpdateTiva(char *filename);
DLL_EXPORT int Sema_UpdateLegacy(char *filename);

/**
*******************************************************************************
*	\FUNCTION	int Sema_InitBMC(char *key)
*
*	\DESCRIPTION
*		Initialization function (LiPPERT internal use only)
*******************************************************************************
**/
DLL_EXPORT int Sema_InitBMC(char Init, char *key);


/**
*******************************************************************************
*	\FUNCTION	int Sema_Stat(char *key)
*
*	\DESCRIPTION
*		Initialization function (LiPPERT internal use only)
*******************************************************************************
**/
DLL_EXPORT int Sema_Stat(char *key);

/**
*******************************************************************************
*	\FUNCTION	bool Sema_SetGpioDirection(unsigned int dwData)
*
*	\DESCRIPTION
*		Set GPIO direction of the I/O pins.
*
*	\PARAMETERS
*		Value		New status of Configuration register
*******************************************************************************
**/
DLL_EXPORT bool Sema_SetGpioDirection(unsigned int dwData);

/**
*******************************************************************************
*	\FUNCTION	void Sema_GetGpioDirection(unsigned int *dwData)
*
*	\DESCRIPTION
*		Get GPIO direction of the I/O pins.
*
*	\PARAMETERS
*		*Buffer		Pointer to current status of Configuration register
*******************************************************************************
**/
DLL_EXPORT bool Sema_GetGpioDirection(unsigned int *dwData);

/**
*******************************************************************************
*	\FUNCTION	void Sema_GetGpioRead(unsigned int *dwData)
*
*	\DESCRIPTION
*		Get GPIO Input of the I/O pins.
*
*	\PARAMETERS
*		Value		Pointer to current status of Input register
*******************************************************************************
**/
DLL_EXPORT bool Sema_GetGpioRead(unsigned int *dwData);

/**
*******************************************************************************
*	\FUNCTION	bool Sema_SetGpioWrite(unsigned int dwData)
*
*	\DESCRIPTION
*		Get GPIO Output of the I/O pins.
*
*	\PARAMETERS
*		*Buffer		New status of Output register
*******************************************************************************
**/
DLL_EXPORT bool Sema_SetGpioWrite(unsigned int dwData);

/**
*******************************************************************************
*	\FUNCTION	bool Sema_GpioXorAndXor(unsigned int Value1, unsigned int Value2, unsigned int Value3)
*
*	\DESCRIPTION
*		Set GPIO Output of the I/O pins.
*
*	\PARAMETERS
*		Value1	value to Xor the I/O pins										\np
*		Value2	value to And the I/O pins										\np
*		Value3	value to Xor the I/O pins										\np
*******************************************************************************
**/
DLL_EXPORT bool Sema_GpioXorAndXor(unsigned int Value1, unsigned int Value2, unsigned int Value3);

#ifndef WIN32
/**
*******************************************************************************
*	\FUNCTION	bool Sema_Check(bool CheckOnly)
*
*	\DESCRIPTION
*		Checks if BMC is up-to-date (LiPPERT internal use only)
*
*	\PARAMETERS
*		CheckOnly	if true, check versions only (do not update anything)
*
*	\RETURNS
*		true if BL+FW up-to-date
*******************************************************************************
**/
bool Sema_Check(bool CheckOnly);
#endif // WIN32

/**
*******************************************************************************
*	\FUNCTION	bool Sema_SetBMCAdress(void)
*
*	\RETURNS
*		Sets BMC SMBus address
*******************************************************************************
**/
DLL_EXPORT void Sema_SetBMCAddress(byte Address);

/**
*******************************************************************************
*	\FUNCTION	word Sema_GetLibraryMajor(void)
*
*	\RETURNS
*		Returns major library version number
*******************************************************************************
**/
DLL_EXPORT word Sema_GetLibraryMajor(void);


/**
*******************************************************************************
*	\FUNCTION	word Sema_GetLibraryMinor(void)
*
*	\RETURNS
*		Returns minor library version number
*******************************************************************************
**/
DLL_EXPORT word Sema_GetLibraryMinor(void);

/**
*******************************************************************************
*	\FUNCTION	const char *Sema_GetLibraryAddon(void)
*
*	\RETURNS
*		Returns the library version addon string
*******************************************************************************
**/
DLL_EXPORT const char *Sema_GetLibraryAddon(void);


/**
*******************************************************************************
*	\FUNCTION	char *Sema_GetHardwareAddon(void)
*
*	\RETURNS
*		Returns the hardware driver/library  addon string
*******************************************************************************
**/
DLL_EXPORT const char* Sema_GetHardwareAddon(void);


/**
*******************************************************************************
*	\FUNCTION	word Sema_GetHardwareMajor(void)
*
*	\RETURNS
*		Returns major hardware driver/library version number
*******************************************************************************
**/
DLL_EXPORT word Sema_GetHardwareMajor(void);


/**
*******************************************************************************
*	\FUNCTION	word Sema_GetHardwareMinor(void)
*
*	\RETURNS
*		Returns minor hardware driver/library version number
*******************************************************************************
**/
DLL_EXPORT word Sema_GetHardwareMinor(void);


/**
*******************************************************************************
*	\FUNCTION	bool Sema_IsSimulationMode(void)
*
*	\RETURNS
*		Returns true if lib is in demo mode (no hw detected!)
*******************************************************************************
**/
DLL_EXPORT bool Sema_IsSimulationMode(void);


/**
*******************************************************************************
*	\FUNCTION	void Sema_GpiosAreInterchanged(bool interchanged)
*
*	\DESCRIPTION
*		Sets the global variable Sema_GpiosInterchanged.
*		Sema_GpiosInterchanged controls the behaviour of adjustDwData.
*******************************************************************************
**/
DLL_EXPORT void Sema_GpiosAreInterchanged(bool interchanged);

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* SEMA_H */