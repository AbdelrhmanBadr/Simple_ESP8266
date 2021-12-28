/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "BitMath.h"
#include "STD_DataTypes.h"
#include "RCC_Config.h"
#include "RCC_Private.h"
#include "RCC.h"

void RCC_Deinit(void)
{
  RCC_REGISTER -> RCC_CR  = 0x83;
  RCC_REGISTER -> RCC_CFGR = 0x00;
  RCC_REGISTER -> RCC_CIR = 0x00;
  RCC_REGISTER -> RCC_APB2RSTR = 0x00;
  RCC_REGISTER -> RCC_APB1RSTR = 0x00;
  RCC_REGISTER -> RCC_AHBENR = 0x14;
  RCC_REGISTER -> RCC_APB2ENR = 0x00;
  RCC_REGISTER -> RCC_APB1ENR = 0x00;
  RCC_REGISTER -> RCC_BDCR = 0x00;
  RCC_REGISTER -> RCC_CSR = 0x0C00;
}                            


 void RCC_Initiate(void)
{
   uint16t BusClock = 0;
  /*---------------------------- Set system clock -----------------------------------------------------------------------*/
  #if RCC_SYSTEM_CLK == RCC_EXTERNAL_SYSTEM_CLK
	RCC_REGISTER->RCC_CR &= (uint32t)RCC_CR_HSE_MASK;
	RCC_REGISTER->RCC_CR |= ((uint32t)RCC_EXTERNAL_CLK_TYPE << RCC_CR_HSEON); /*Turn on HSE with its configuration*/
	while(GET_BIT(RCC_REGISTER->RCC_CR,RCC_CR_HSERDY) != RCC_HSE_READY);
	RCC_REGISTER->RCC_CFGR &= (uint32t)RCC_CFGR_HSE_MASK;
  #elif RCC_SYSTEM_CLK == RCC_INTERNAL_SYSTEM_CLK
	SET_BIT(RCC_REGISTER->RCC_CR,RCC_CR_HSION); /*Turn on for HSI*/  
	while(GET_BIT(RCC_REGISTER->RCC_CR,RCC_CR_HSIRDY) != RCC_HSI_READY);
	RCC_REGISTER->RCC_CFGR &= (uint32t)RCC_CFGR_HSI_MASK;
  #elif RCC_SYSTEM_CLK == RCC_PLL_SYSTEM_CLK
		RCC_REGISTER->RCC_CFGR &= (uint32t)RCC_CFGR_PLL_MASK;
		#if (RCC_SYSTEM_CLK == RCC_EXTERNAL_CLK_PLL)
			RCC_REGISTER->RCC_CFGR |= ((uint32t)RCC_PLL_EXTERNAL_SOURCE << RCC_CFGR_PLLSRC); /*Set PLL source*/
		#elif RCC_SYSTEM_CLK == RCC_EXTERNAL_CLK_PLL_DIVIDED_BY_2
			RCC_REGISTER->RCC_CFGR |= ((uint32t)RCC_PLL_EXTERNAL_SOURCE_DIVEDED_BY_2 << RCC_CFGR_PLLSRC);
		#elif RCC_SYSTEM_CLK == RCC_INTERNAL_CLK_PLL
			RCC_REGISTER->RCC_CFGR |= ((uint32t)RCC_PLL_INTERNAL_SOURCE << RCC_CFGR_PLLSRC);
		#endif /*Nested if*/
	RCC_REGISTER->RCC_CFGR |= ((uint32t)RCC_PLL_FACTOR << RCC_CFGR_PLLMUL); /*Set PLL MUL Factor*/
	SET_BIT(RCC_REGISTER->RCC_CR,RCC_CR_PLLON); /*Turn on for PLL*/ 
	while(GET_BIT(RCC_REGISTER->RCC_CR,RCC_CR_PLLRDY) != RCC_PLL_READY); /*wait until clock be stable*/
  #elif
		#error "Error in RCC_SYSTEM_CLK at RCC_Config.h file"
  #endif /*RCC_SYSTEM_CLK*/
  RCC_REGISTER->RCC_CFGR |= RCC_SYSTEM_CLK; /*Set system clock*/
  /*---------------------------- Set buses clock -----------------------------------------------------------------------*/
  RCC_REGISTER->RCC_CFGR &= RCC_CFGR_BUS_CLK_MASK;
  BusClock = (RCC_AHP_CLK) | (RCC_APB1_CLK << 4) | (RCC_APB2_CLK << 7);
  RCC_REGISTER->RCC_CFGR |= ((uint32t)BusClock << 4); /*Set buses clock*/
  /*---------------------------- Security system -----------------------------------------------------------------------*/
  #ifdef RCC_ENABLE_SECURITY_SYSTEM
  SET_BIT(RCC_REGISTER->RCC_CR,RCC_CR_CSSON); /*Enable clock security system*/
  #endif /*RCC_ENABLE_SECURITY_SYSTEM*/
}

void RCC_AdjustInternalClock(uint8t CalibrationValue)
{
	/*Check for input parameter*/
	assert(IS_RCC_CALIBRATION_VALUE(CalibrationValue));
	/*Insert the value*/
	RCC_REGISTER->RCC_CR &= RCC_CR_HSITRIM_MASK;
	RCC_REGISTER->RCC_CR |= CalibrationValue << 3;
}

RCC_ClockSystem_t RCC_GetClockSystem (void)
{
	RCC_ClockSystem_t ReturnedValue = RCC_ExternalClockSystem;
	uint8t ClockSystemVal = 0;
	ClockSystemVal = ((uint8t)RCC_REGISTER -> RCC_CFGR )>> 2;
	ClockSystemVal &= (uint8t) 0x03;
	switch(ClockSystemVal)
	{
	case 1:ReturnedValue = RCC_InternalClockSystem; break;
	case 2:ReturnedValue = RCC_PLLClockSystem; break;
	}
	return ReturnedValue;
}

void RCC_SetMCOPinClk (RCC_MCOModes_t MCO_Mode)
{
	RCC_REGISTER->RCC_CFGR &= RCC_CFGR_MCO_MASK;
	RCC_REGISTER->RCC_CFGR |= (MCO_Mode << 24); /*Set MCO clock pin*/
}

void RCC_EnableAPB2PeriphralsClock(uint8t Peripheral)
{
	/*Check the parameter*/
	assert(IS_RCC_APB2Periphral_VALUE(Peripheral));
	/*Set the peripheral clock*/
	SET_BIT((RCC_REGISTER->RCC_APB2ENR),Peripheral);
}

void RCC_EnableAPB1PeriphralsClock(uint8t Peripheral)
{
	/*Check the parameter*/
	assert(IS_RCC_APB1Periphral_VALUE(Peripheral));
	/*Set the peripheral clock*/
	SET_BIT((RCC_REGISTER->RCC_APB1ENR),Peripheral);
}

void RCC_EnableAHBPeriphralsClock(uint8t Peripheral)
{
	/*Check the parameter*/
	assert(IS_RCC_AHBPeriphral_VALUE(Peripheral));
	/*Set the peripheral clock*/
	SET_BIT((RCC_REGISTER->RCC_AHBENR),Peripheral);
}










