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

/*
 *  GPIOSetPinDirection( handler , pin , direction )
 *
 *  Sets the specified GPIO pin to be an input or an output
 *  
 *  handler   : the board handle
 *  pin       : the GPIO pin number (values 0 ~ 15)
 *  direction : EAPI_GPIO_INPUT for input
 *              EAPI_GPIO_OUTPUT for output
 *  
 */
void GPIOSetPinDirection(uint32_t handler, uint32_t pin, uint32_t direction)
{
	uint32_t directionCheck;
	uint32_t ret = 0;
	
	printf("Setting pin %d direction\n",pin);
	ret = SemaEApiGPIOSetDirection(handler,EAPI_GPIO_GPIO_ID(pin),0x01,direction);
	if (ret != EAPI_STATUS_SUCCESS) {
		printf("Error setting GPIO direction: 0x%X\n", ret);
	}
	ret = SemaEApiGPIOGetDirection(handler,EAPI_GPIO_GPIO_ID(pin),0x01,&directionCheck);
	if (ret != EAPI_STATUS_SUCCESS) {
		printf("Error checking GPIO direction: 0x%X\n\n", ret);
	} else {
		printf("Direction: %d (1 = input, 0 = output)\n\n",directionCheck);
	}
}

/*
 *  GPIOSetPinLevel( handler , pin , level )
 *  
 *  Sets the specified GPIO pin level to be HIGH (5V) or LOW (0V).
 *  Only affects GPIO pins configured as outputs
 *  
 *  handler   : the board handle
 *  pin       : the GPIO pin number (values 0 ~ 15)
 *  level     : EAPI_GPIO_HIGH for high
 *              EAPI_GPIO_LOW for low
 *  
 */
void GPIOSetPinLevel(uint32_t handler, uint32_t pin,uint32_t level)
{
	uint32_t buffer = 0;																							
	uint32_t ret = 0;

	printf("Setting GPIO pin %d output level ",pin);
	printf("to %d\n",level);
	ret = SemaEApiGPIOSetLevel(handler,EAPI_GPIO_GPIO_ID(pin),0x01,level);
	if (ret != EAPI_STATUS_SUCCESS)
		printf("(Error setting GPIO level: 0x%X)\n", ret);
}

/*
 *  GPIOReadPinLevel( handler , pin )
 *
 *  Reads the specified GPIO pin level and prints it. For use with pins configured as inputs.
 *  
 *  handler   : the board handle
 *  pin       : the GPIO pin number (values 0 ~ 15)
 *  
 */
void GPIOReadPinLevel(uint32_t handler, uint32_t pin)
{
	uint32_t buffer = 0;																							
	uint32_t ret = 0;

	printf("Reading GPIO pin %d input level:  ",pin);
	ret = SemaEApiGPIOGetLevel(handler,EAPI_GPIO_GPIO_ID(pin),0x01,&buffer);
	if (ret != EAPI_STATUS_SUCCESS) {
		printf("Error getting GPIO level: 0x%X\n\n", ret);
	} else {
		printf("%d\n\n",buffer);
	}
}

int main(int argc, char* argv[])
{
	char ipAddr[24] = "127.0.0.1";
	uint32_t handler;
	uint32_t ret = 0;
	uint32_t directions;

	printf("\n******* SEMA EAPI Sample - GPIO Test *******\n");
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


	/* Set GPIO pin 0 to output */
	GPIOSetPinDirection(handler,0,EAPI_GPIO_OUTPUT);

	/* Set GPIO pin 1 to input */
	GPIOSetPinDirection(handler,1,EAPI_GPIO_INPUT);

	/* Set GPIO pin 0 level to HIGH (5V) */
	GPIOSetPinLevel(handler,0,EAPI_GPIO_HIGH);

	/* Read GPIO pin 1 level */
	GPIOReadPinLevel(handler,1);


	/* Uninitialise SEMA Lib */
	SemaEApiLibUnInitialize(handler);
	return 0;
}