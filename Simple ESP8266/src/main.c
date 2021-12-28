/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: Abdelrhman Badr
 */
/*
 * Server link : http://smarthome99.freevar.com
 * */
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

void main (void)
{
	EnablePeripheralClock();
	Relay_t Lamp = {GPIOB,0};
	SYSTICK_Initiate();
	Relay_Initiate(&Lamp);
	ESP8266_Initiate();
	ESP8266_Connect();
	uint8t Response = 0;
	while(1)
	{
		Response = ESP8266_GetDataFromServer();
		if(Response == CLOSE_LAMP)
		{
			Relay_TurnOffRelay(&Lamp);
		}
		if(Response == OPEN_LAMP)
		{
			Relay_TurnOnRelay(&Lamp);
		}
	}
}

