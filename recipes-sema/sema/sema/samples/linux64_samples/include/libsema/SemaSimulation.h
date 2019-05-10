/**
********************************************************************************
*	\FILE		LinuxSMBusVersion.h
*
*	\DESCRIPTION
*		Static varibale and data for the SEMA simualtion mode. All date here is
*		only used as example data.
*
*	\AUTHOR		Simon Berg
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/
#ifndef SEMASIMULATION_H
#define SEMASIMULATION_H


#define SEMA_SIMULATION_MAXTEMP_SYS 98
#define SEMA_SIMULATION_MAXTEMP_CPU 118.54f
#define SEMA_SIMULATION_MINTEMP_SYS -14
#define SEMA_SIMULATION_MINTEMP_CPU -8.12f

#define SEMA_SIMULATION_VERSION_MAJOR 1
#define SEMA_SIMULATION_VERSION_MINOR 0
const char* Sema_Simulator_Addon =  "Simulator";
const char* Sema_Simulator_Id =  "Sema Simulator Library Mode!";

byte Sema_Simulation_Flash[0x400];
short Sema_Simulation_Watchdog = 0;
short Sema_Simulation_PwrUpWatchdog = 0;
const char* Sema_Simulation_Version_1 = "Sema Simulated BMC v1 ";
const char* Sema_Simulation_Version_2 = "BMC v2 (c) LATG";

const char* Sema_Simulation_MF_Data[SEMA_MANU_DATA_MAX] = { "72103-0A30-0000",
															"0123456789",
															"0000/00/00",
															"2013/02/24",
															"72103-0A30-2222",
															"ABCDFEGHJI",
															"AABBCCDDEEFF",
															"RESERVED"};
const char* Sema_Simulation_Bootloader = "Bootloader V10";
unsigned long Sema_Simulation_TotalUptime = 0x1312;
unsigned long Sema_Simulation_PowerUptime = 0x0;
unsigned long Sema_Simulation_PowerCycles = 0x12;
unsigned long Sema_Simulation_BootCount   = 0x1A;
unsigned short Sema_Simulation_FanCPU = 0x0;
unsigned short Sema_Simulation_FanSystem = 0x0;
char Sema_Simulation_FanCPUTemp[4]  = { 0x00 , 0x10, 0x20, 0x30 };
char Sema_Simulation_FanSystemTemp[4]  = { 0x00 , 0x10, 0x20, 0x30 };
char Sema_Simulation_FanCPUPWM[4]  = { 0x00 , 0x35, 0x50, 0x64 };
char Sema_Simulation_FanSystemPWM[4]  = { 0x00 , 0x35, 0x50, 0x64 };
byte Sema_Simulation_Backlight = 0x64;
float Sema_Simulation_Temp_CPU = 20.0;
signed char Sema_Simulation_Temp_System = 10;
signed char Sema_Simulation_Temp_MinMax[4] = { -20, 90, -23, 70 };
signed char Sema_Simulation_Temp_Boot[2] = { 13, 7 };
byte Sema_Simulation_BIOS = 0;


#endif /* SEMASIMULATION_H */