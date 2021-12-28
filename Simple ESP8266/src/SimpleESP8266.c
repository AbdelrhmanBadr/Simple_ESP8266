/*
 * SimpleESP8266.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Abdelrhman Badr
 */


#include <assert.h>
#include "STD_DataTypes.h"
#include "BitMath.h"
#include <string.h>
#include "RCC.h"
#include "SYSTICK.h"
#include "GPIO.h"
#include "USART.h"
#include "ESP8266.h"
#include "Relay.h"
#include "SimpleESP8266.h"

void EnablePeripheralClock(void)
{
	RCC_Initiate();
	RCC_EnableAPB2PeriphralsClock(2);  /*GPIOA*/
	RCC_EnableAPB2PeriphralsClock(3);  /*GPIOB*/
	RCC_EnableAPB2PeriphralsClock(0);  /*AFIO*/
	RCC_EnableAPB1PeriphralsClock(17); /*USART2*/
}

