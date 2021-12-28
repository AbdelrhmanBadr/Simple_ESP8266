/*
 * SYSTICK.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Abdelrhman Badr
 */
#include "BitMath.h"
#include "STD_DataTypes.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"
#include "SYSTICK.h"

/*Global pointer to isr*/
void (*SYSTICK_PointerToIsr) (void) = NULL;

void SYSTICK_Initiate(void)
{
	SYSTICK->STK_CTRL &= SYSTICK_STK_CTRL_BIT_MASK;
	SYSTICK->STK_CTRL = SYSTICK_ENABLE | (SYSTICK_INTERRUPT << 1) | (SYSTICK_CLOCK << 2);
}

void SYSTICK_DisableTimer(void)
{
	CLEAR_BIT(SYSTICK->STK_CTRL , STK_CTRL_ENABLE_BIT);
}

void SYSTICK_EnableTimer(void)
{
	SET_BIT(SYSTICK->STK_CTRL , STK_CTRL_ENABLE_BIT);
}

void SYSTICK_SetBusyWait(uint32t BusyWaitVal)
{
	SYSTICK->STK_LOAD = BusyWaitVal;
	while(GET_BIT(SYSTICK->STK_CTRL , STK_CTRL_FLAG_BIT) == 0);
	CLEAR_BIT(SYSTICK->STK_CTRL , STK_CTRL_FLAG_BIT);
}

uint32t SYSTICK_GetCurrentCounterValue(void)
{
   uint32t ReturnedVal = 0;
   ReturnedVal = SYSTICK -> STK_VAL;
   return ReturnedVal;
}

void SYSTICK_SetTimerValueSynch(uint32t Ticks , void (*PointerToFunction) (void))
{
	if(PointerToFunction != NULL)
	{
		/*assign ticks to the register*/
		SYSTICK->STK_LOAD = Ticks;
		/*Set the global pointer to point to this function*/
		SYSTICK_PointerToIsr = PointerToFunction;
	}
}
void SYSTICK_SetBusyWaitms(uint32t MilliSeconds)
{
	SYSTICK->STK_LOAD = MilliSeconds * 1000; /*To convert from ms to us*/
    while(GET_BIT(SYSTICK->STK_CTRL , STK_CTRL_FLAG_BIT) == 0);
    CLEAR_BIT(SYSTICK->STK_CTRL , STK_CTRL_FLAG_BIT);
}

/*ISR*/
void SysTick_Handler(void)
{
	if(SYSTICK_PointerToIsr != NULL)
	{
		SYSTICK_PointerToIsr();
		/*Clear the flag*/
		CLEAR_BIT(SYSTICK->STK_CTRL , STK_CTRL_FLAG_BIT);
	}

}
