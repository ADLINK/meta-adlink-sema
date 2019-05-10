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
/*
 *  I2C_Standard_Command_Write(handler,bus, addr, cmd, pBuffer, BufLen)
 *
 *  
 *  handler   : the board handle
 *  bus       : the I2C bus
 *  addr	  : the I2C device slave address (8bit)
 *  cmd		  : the I2C device command/index (8bit)         
 *  pBuffer	  : the input data buffer
 *	BufLen	  : the length of written data
 */
void I2C_Standard_Command_Write(uint32_t handler,uint32_t bus, uint32_t addr, uint32_t cmd, char * pBuffer, uint32_t BufLen)
{
	uint32_t ret = 0;
	uint32_t enc_cmd = EAPI_I2C_ENC_STD_CMD(cmd);
	ret = SemaEApiI2CWriteTransfer(handler, bus, addr, enc_cmd, pBuffer, BufLen);
	if (ret != EAPI_STATUS_SUCCESS) 
	{
		printf("Error transfer I2C standard command: 0x%X\n", ret);
	}
}

/*
 *  I2C_Standard_Command_Read(handler,bus, addr, cmd, pBuffer, BufLen)
 *
 *  
 *  handler   : the board handle
 *  bus       : the I2C bus
 *  addr	  : the I2C device slave address (8bit)
 *  cmd		  : the I2C device command/index (8bit)         
 *  pBuffer	  : the output data buffer
 *	BufLen	  : the length of read data
 */
void I2C_Standard_Command_Read(uint32_t handler,uint32_t bus, uint32_t addr, uint32_t cmd, char * pBuffer, uint32_t BufLen)
{
	uint32_t ret = 0;
	uint32_t enc_cmd = EAPI_I2C_ENC_STD_CMD(cmd);
	ret = SemaEApiI2CReadTransfer(handler, bus, addr, enc_cmd, pBuffer, BufLen,BufLen);
	if (ret != EAPI_STATUS_SUCCESS) 
	{
		printf("Error transfer I2C standard command: 0x%X\n", ret);
	}
	else
	{
		printf("I2C standard command output: \n");
		 for(int i=0;i<BufLen;i++)
		 {
			printf(" %d",pBuffer[i]);
		 }
	}
}

/*
 *  I2C_Extended_Command_Write(handler,bus, addr, cmd, pBuffer, BufLen)
 *
 *  
 *  handler   : the board handle
 *  bus       : the I2C bus
 *  addr	  : the I2C device slave address (8bit)
 *  cmd		  : the I2C device command/index (16bit)         
 *  pBuffer	  : the input data buffer
 *	BufLen	  : the length of written data
 */
void I2C_Extended_Command_Write(uint32_t handler,uint32_t bus, uint32_t addr, uint32_t cmd, char * pBuffer, uint32_t BufLen)
{
	uint32_t ret = 0;
	uint32_t enc_cmd = EAPI_I2C_ENC_EXT_CMD(cmd);
	ret = SemaEApiI2CWriteTransfer(handler, bus, addr, enc_cmd, pBuffer, BufLen);
	if (ret != EAPI_STATUS_SUCCESS) 
	{
		printf("Error transfer I2C extended command write: 0x%X\n", ret);
	}
}

/*
 *  I2C_Extended_Command_Read(handler,bus, addr, cmd, pBuffer, BufLen)
 *
 *  
 *  handler   : the board handle
 *  bus       : the I2C bus
 *  addr	  : the I2C device slave address (8bit)
 *  cmd		  : the I2C device command/index (16bit)         
 *  pBuffer	  : the output data buffer
 *	BufLen	  : the length of read data
 */
void I2C_Extended_Command_Read(uint32_t handler,uint32_t bus, uint32_t addr, uint32_t cmd, char * pBuffer, uint32_t BufLen)
{
	uint32_t ret = 0;
	uint32_t enc_cmd = EAPI_I2C_ENC_EXT_CMD(cmd);
	ret = SemaEApiI2CReadTransfer(handler, bus, addr, enc_cmd, pBuffer, BufLen,BufLen);
	if (ret != EAPI_STATUS_SUCCESS) 
	{
		printf("Error transfer I2C extended command read: 0x%X\n", ret);
	}
	else
	{
		printf("I2C standard command output: \n");
		 for(int i=0;i<BufLen;i++)
		 {
			 printf(" %d",pBuffer[i]);
		 }
	}
}


int main(int argc, char* argv[])
{
	char ipAddr[24] = "127.0.0.1";
	uint32_t handler;
	uint32_t ret = 0;
	uint32_t addr =160 ;
	uint32_t cmd =0x0001 ;
	uint32_t BufLen=0;
	uint32_t bus = 0;
	char buffer[33] = {0};
	char rbuffer[33] = {0};
	int temp;
	printf("\n******* SEMA EAPI Sample - I2C Test *******\n");
    if(argc >= 2) {
        strcpy(ipAddr, argv[1]);
        printf("Connect to remote IP address: %s\n", ipAddr);    }
    else{
        printf("Running SEMA EAPIs locally (%s)\n", ipAddr);
    }
    printf("\n");

	/* Initialise SEMA Lib */
	ret = SemaEApiLibInitialize(false, IP_V4, ipAddr, 0, (char*)"123", &handler);
	if (ret != EAPI_STATUS_SUCCESS) {
        printf("Can't initialize SEMA Lib. Error code: %X\n", ret);
        return -1;
    }
	cout << "Please input option : 1 for Write ;2 for Read ( note all value input are in hex, and output are dec"<< endl; 
	cin >> hex >> temp;
	if (temp == 1 )
	{
    cout << "Please input 16 bit command : "<< endl; 
	cin >> hex >> cmd;
	cout << "Please input number of bytes need to write : "<< endl; 
	cin >> hex >> BufLen;
	/*	Encoded cmd to let SEMA know that we use 16bit command    */
	EAPI_I2C_ENC_EXT_CMD(cmd);
	for (int i =0; i < BufLen;i++)
    {
	cout << "Please input data bytes : "<< i << endl; 
	cin >> hex >> temp;
	buffer[i]=temp;
	}
	/*	Write to I2C device use 16bit command    */
	I2C_Extended_Command_Write(handler,bus,addr,cmd,buffer,BufLen);
	}
	if (temp ==2 )
	{
	cout << "Please input 16 bit command : "<< endl; 
	cin >> hex >> cmd;
	cout << "Please input number of bytes need to write : "<< endl; 
	cin >> hex >> BufLen;
	/*	Read from I2C device use 16bit command    */
    I2C_Extended_Command_Read(handler,bus,addr,cmd,rbuffer,BufLen);
	}
	/*	UnInitialise SEMA Lib   */
	SemaEApiLibUnInitialize(handler);
	return 0;
}