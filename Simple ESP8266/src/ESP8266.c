/*
 * ESP8266.c
 *
 *  Created on: Dec 27, 2021
 *      Author: Abdelrhman Badr
 */

#include "BitMath.h"
#include "STD_DataTypes.h"
#include <string.h>
#include "USART.h"
#include "SYSTICK.h"
#include "GPIO.h"
#include "ESP8266_Config.h"
#include "ESP8266_Private.h"
#include "ESP8266.h"

/**************************************< Define Private data >*******************************/
char ResponseBuffer [100];
static void ReciveResponse (void);
static void SendCommand (char *str);
static void ClearBuffer (void);
static void ConvertNumberToString(uint8t Number , char *string);
static void ReverseString(char *String);
/********************************************************************************************/


USART_Config_t ESP8266_Config = {115200,USART_8_DATA_BIT,USART_DISABLE_PARITY_MODE,USART_1_STOP_BIT,USART_ENABLE_TX,USART_ENABLE_RX};

static void ReciveResponse (void)
{
	uint8t i = 0;
	USART_Errors_t Error = USART_NoError;

	while(Error != USART_TimeOut)
	{
	  ResponseBuffer[i] = USART_RecieveData(ESP8266_USART,&Error);
	  i++;
	}
}

static void SendCommand (char *str)
{
	uint8t size = strlen(str);
	uint8t i = 0;
	for(i = 0 ; i < size ; i++)
	{
		USART_SendDataAsynch(USART2,str[i]);
	}
}

static void ClearBuffer (void)
{
	uint8t i = 0;
	for(i = 0 ; i < 100 ; i++)
	{
		ResponseBuffer[i] = '0';
	}
}

static void ConvertNumberToString(uint8t Number , char *string)
{
	uint8t i = 0;
	while(Number != 0)
	{
		string[i] = (Number%10) + '0';
		Number /= 10;
		i++;
	}
}

static void ReverseString(char *String)
{
	uint8t StringLength = strlen(String);
	uint8t i = 0;
	uint8t Temp = 0;
	for(i = 0 ; i < (StringLength/2) ; i++)
	{
		Temp = String[i]; /*Temp = A*/
		String[i] = String[StringLength - 1 - i];
		String[StringLength - 1 - i] = Temp;
	}
}

void ESP8266_Initiate (void)
{
	/*Set ESP pin direction*/
	if(ESP8266_USART == USART1)
	{

	}
	else if (ESP8266_USART == USART2)
	{
		GPIO_SetPinDirection(GPIOA,2,GPIO_OUTPUT_10MHZ_AF_PUSH_PULL);
		GPIO_SetPinDirection(GPIOA,3,GPIO_INPUT_FLOATING);
	}
	else if (ESP8266_USART == USART3)
	{
		GPIO_SetPinDirection(GPIOB,10,GPIO_OUTPUT_10MHZ_AF_PUSH_PULL);
		GPIO_SetPinDirection(GPIOB,11,GPIO_INPUT_FLOATING);
	}

	/*Initiate the USART*/
	USART_Initiate(ESP8266_USART,&ESP8266_Config);

	/*Disable ECHO mode*/

	/*Send AT command to check if the wifi is working or not*/
	SendCommand("AT\r\n");
	SYSTICK_SetBusyWaitms(3000);

	/*check for the incoming string "OK"*/

	/*Clear the buffer*/
	ClearBuffer();

	/*Set the station mode */
	SendCommand(ESP8266_SET_STATION_MODE);
	SYSTICK_SetBusyWaitms(ESP8266_STATION_MODE_DELAY);

	/*Set normal transmition mode*/
	SendCommand(ESP8266_NORMAL_TX_MODE);
	SYSTICK_SetBusyWaitms(ESP8266_NORMAL_TX_MODE_DELAY);
}

void ESP8266_Connect(void)
{
	ClearBuffer();
	/*Connect to wifi netwrok*/
	/* sending command : "AT+CWJAP_CUR="wifi name","password"\r\n"*/
	SendCommand("AT+CWJAP_CUR=");
	SendCommand("\"");
	SendCommand(ESP8266_WIFI_NAME);
	SendCommand("\",");
	SendCommand("\"");
	SendCommand(ESP8266_WIFI_PASSWORD);
	SendCommand("\"\r\n");

	SYSTICK_SetBusyWaitms(ESP8266_CONNECT_WIFI_DELAY);
}

uint8t ESP8266_GetDataFromServer(void)
{
	uint8t ReturnedValue;
	uint8t ESP8266_HTTP_REQ_Length = 0;
	char   ESP8266_HTTP_REQ_String[2];

	ClearBuffer();
	/*Connect to Server*/
	/*Sending command --> AT+CIPSTART=\"TCP\",\"162.253.155.226\",80\r\n */
	SendCommand("AT+CIPSTART=\"TCP\",");
	SendCommand("\"");
	SendCommand(ESP8266_SERVER_IP);
	SendCommand("\"");
	SendCommand(",80\r\n");

	ReciveResponse();
	ClearBuffer();
	//SYSTICK_SetBusyWaitms(2000);

	/*Get string length*/
	ESP8266_HTTP_REQ_Length = strlen(ESP8266_HTTP_REQ);
	ESP8266_HTTP_REQ_Length += 6;

	/*Convert the number to string */
	ConvertNumberToString(ESP8266_HTTP_REQ_Length,ESP8266_HTTP_REQ_String);
	ReverseString(ESP8266_HTTP_REQ_String);
	/*Send http request*/
	/*Send the command : AT+CIPSEND=52\r\n*/
	SendCommand("AT+CIPSEND=");
	SendCommand(ESP8266_HTTP_REQ_String);
	SendCommand("\r\n");
	ReciveResponse();
	ClearBuffer();
	SYSTICK_SetBusyWaitms(ESP8266_HTTP_REQ_DELAY);

	/*Send Get methode to get the data in file*/
	/*Send the command : GET http://smarthome99.freevar.com/lightstatus.txt\r\n */
	SendCommand("GET");
	SendCommand(" ");
	SendCommand(ESP8266_HTTP_REQ);
	SendCommand("\r\n");

	ReciveResponse();
	ReturnedValue = ResponseBuffer[37] - '0';

	SYSTICK_SetBusyWaitms(ESP8266_RECONNECTION_DELAY);

	return ReturnedValue;
}
