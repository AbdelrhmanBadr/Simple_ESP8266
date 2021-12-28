/*
 * ESP8266_Config.h
 *
 *  Created on: Dec 28, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef ESP8266_CONFIG_H_
#define ESP8266_CONFIG_H_

/* Define USART number : USART1 , USART2 , USART3 */
#define ESP8266_USART			(USART2)

/* Define wifi name*/
#define ESP8266_WIFI_NAME		"a_badr"

/* Define wifi password*/
#define ESP8266_WIFI_PASSWORD	"12345678"

/* Define Server IP*/
#define ESP8266_SERVER_IP		"162.253.155.226"

/* Define web URL begin with http and end with /file.txt that contain data to get */
/* --> For example : http://smarthome99.freevar.com/lightstatus.txt <-- */
#define ESP8266_HTTP_REQ		"http://smarthome99.freevar.com/lightstatus.txt"



#endif /* ESP8266_CONFIG_H_ */
