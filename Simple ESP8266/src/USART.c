/*
 * USART.c
 *
 *  Created on: Dec 19, 2021
 *      Author: Abdelrhman Badr
 */

#include "BitMath.h"
#include "STD_DataTypes.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "USART.h"

void USART_Initiate(volatile USART_Registers_t *USARTn , USART_Config_t *USART_Config)
{
	uint8t BaudRateFraction = 0;
	uint16t BaudRateMantisa = 0;

	/* 2) Define word lenght */
	USARTn->USART_CR1 &= USART_WORD_LENGTH_BIT_MASK;
	USARTn->USART_CR1 |= (USART_Config -> USART_WordLength) << CR1_M_BIT;

	/* 3) Define number of stop-bits */
	USARTn->USART_CR2 &= USART_STOP_BIT_MASK;
	USARTn->USART_CR2 |= (USART_Config -> USART_StopBit) << CR2_STOP_BIT;

	/* 4) Set the baudrate*/
	/*These formulas are from ST STD library*/
	BaudRateMantisa = (USART_SYSTEM_CLK) / (16 * (USART_Config->USART_BaudRate));
	BaudRateFraction = (((float)(USART_SYSTEM_CLK) / (16.00 * (USART_Config->USART_BaudRate)) - ((uint32t) BaudRateMantisa)) * 16) + 0.5;
	USARTn->USART_BRR = BaudRateFraction | (BaudRateMantisa << 4);
	/* 5) Set the Tx and Rx enable mode*/
	USARTn->USART_CR1 &= USART_TX_RX_ENABLE_BIT_MASK;
	USARTn->USART_CR1 |= ((USART_Config -> USART_RecieverEnable) << CR2_RE_BIT)|((USART_Config -> USART_TransmitterEnable) << CR2_TE_BIT);
	/*(1) Enable the USART*/
	SET_BIT(USARTn->USART_CR1 , CR1_UE_BIT);

}

void USART_SendDataAsynch(volatile USART_Registers_t *USARTn , uint16t Data)
{
	/*Insert data to the register*/
	USARTn->USART_DR = Data;
	/*Wait until transmision complete*/
	while(GET_BIT(USARTn->USART_SR , SR_TC_BIT) == 0);
}

uint16t USART_RecieveData(volatile USART_Registers_t *USARTn ,USART_Errors_t *ReturnedError)
{
	uint16t ReturnedValue = 0;
	*ReturnedError = USART_NoError;
	uint32t TimeOutCounter = 0;
	/*Wait until recieve data*/
	while((GET_BIT(USARTn->USART_SR , SR_RXNE_BIT) == 0) && (TimeOutCounter < USART_TIME_OUT))
	{
		TimeOutCounter++;
	}
	if(TimeOutCounter == USART_TIME_OUT)
	{
		*ReturnedError = USART_TimeOut;
	}
	else
	{
		/*Read the data*/
		ReturnedValue = USARTn->USART_DR;

		/*Clear the flag*/
		CLEAR_BIT(USARTn->USART_SR , SR_RXNE_BIT);

	    /*Check for error flags*/
	    if(GET_BIT(USARTn->USART_SR , SR_PE_BIT) == 1)
	    {
	    	*ReturnedError = USART_PE;
	    }
	    else if(GET_BIT(USARTn->USART_SR , SR_FE_BIT) == 1)
	    {
	    	*ReturnedError = USART_FE;
	    }
	    else if(GET_BIT(USARTn->USART_SR , SR_NE_BIT) == 1)
	    {
	    	*ReturnedError = USART_NE;
	    }
	    else if(GET_BIT(USARTn->USART_SR , SR_ORE_BIT) == 1)
	    {
	    	*ReturnedError = USART_ORE;
	    }
	}

	return ReturnedValue;
}

void USART1_ReMap(void)
{
  SET_BIT(USART_AIFO,2);
}












