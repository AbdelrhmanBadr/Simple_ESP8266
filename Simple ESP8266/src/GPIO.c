/*
 * GPIO.c
 *
 *  Created on: Nov 19, 2021
 *      Author: Abdelrhman Badr
 */

/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "BitMath.h"
#include "STD_DataTypes.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "GPIO.h"

void GPIO_SetPinDirection(volatile GPIO_Register_t * GPIOx, uint8t PinNumber, uint8t PinMode)
{
	if(PinMode % 4 == 0) /*Input case*/
	{
		/*CRL register will be used*/
		if(PinNumber <= 7)
		{
			GPIOx -> GPIOx_CRL &= (~(0x0F << (PinNumber*4))); /*Mask the register*/
			switch(PinMode)
			{
			case GPIO_INPUT_ANALOG:
									GPIOx -> GPIOx_CRL |= (PinMode << (PinNumber*4)); /*Set the mode*/
									break;
			case GPIO_INPUT_FLOATING:
									GPIOx -> GPIOx_CRL |= (PinMode << (PinNumber*4)); /*Set the mode*/
									break;
			case GPIO_INPUT_PULLDOWN:
									GPIOx -> GPIOx_CRL |= (INPUT_PULLDOWN_MODE << (PinNumber*4)); /*Set the mode*/
									SET_BIT(GPIOx->GPIOx_BRR,PinNumber);
									break;
			case GPIO_INPUT_PULLUP:
									GPIOx -> GPIOx_CRL |= (PinMode << (PinNumber*4)); /*Set the mode*/
									SET_BIT(GPIOx->GPIOx_BSRR,PinNumber);
									break;
			default: /*ERROR*/ break;
			}
		}
		/*CRH will be used*/
		else if(PinNumber > 7)
		{
			GPIOx -> GPIOx_CRH &= (~(0x0F << ((PinNumber - 8)*4))); /*Mask the register*/
			switch(PinMode)
		    {
		    case GPIO_INPUT_ANALOG:
		    	            GPIOx -> GPIOx_CRH |= (PinMode << ((PinNumber - 8)*4)); /*Set the mode*/
		    				break;
		    case GPIO_INPUT_FLOATING:
		    	            GPIOx -> GPIOx_CRH |= (PinMode << ((PinNumber - 8)*4)); /*Set the mode*/
		    				break;
		    case GPIO_INPUT_PULLDOWN:
		    	            GPIOx -> GPIOx_CRH |= (INPUT_PULLDOWN_MODE << ((PinNumber - 8)*4)); /*Set the mode*/
		    				SET_BIT(GPIOx->GPIOx_BRR,PinNumber);
		    				break;
		    case GPIO_INPUT_PULLUP:
		    	            GPIOx -> GPIOx_CRH |= (PinMode << ((PinNumber - 8)*4)); /*Set the mode*/
		    				SET_BIT(GPIOx->GPIOx_BSRR,PinNumber);
		    				break;
		    default: /*ERROR*/ break;
		    }
		}
	}
	else /*Output case*/
	{
		/*CRL register will be used*/
		if(PinNumber <= 7)
		{
			GPIOx -> GPIOx_CRL &= (~(0x0F << (PinNumber*4))); /*Mask the register*/
			GPIOx -> GPIOx_CRL |= (PinMode << (PinNumber*4)); /*Set the mode*/
		}
		/*CRH will be used*/
		else if(PinNumber > 7)
		{
			GPIOx -> GPIOx_CRH &= (~(0x0F << ((PinNumber - 8)*4))); /*Mask the register*/
			GPIOx -> GPIOx_CRH |= (PinMode << ((PinNumber - 8)*4)); /*Set the mode*/
		}
	}
}

void GPIO_WritePin(volatile GPIO_Register_t * GPIOx,uint8t PinNumber, uint8t DigitalVal)
{
	switch(DigitalVal)
	{
		case GPIO_HIGH: SET_BIT(GPIOx->GPIOx_BSRR,PinNumber); break;
		case GPIO_LOW:  SET_BIT(GPIOx->GPIOx_BRR,PinNumber);  break;
	}
}

void GPIO_ReadPin(volatile GPIO_Register_t * GPIOx,uint8t PinNumber, uint8t * ReturnedDigitalValue)
{
	*ReturnedDigitalValue = GET_BIT(GPIOx->GPIOx_IDR , PinNumber);
}

