/*
 * Relay.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Abdelrhman Badr
 */

#include "STD_DataTypes.h"
#include "BitMath.h"
#include "GPIO.h"
#include "Relay.h"

void Relay_Initiate(Relay_t *Relay)
{
	/*Set relay pin as o/p pins*/
	GPIO_SetPinDirection(Relay->GPIOx , Relay->PinNumber , GPIO_OUTPUT_10MHZ_PUSH_PULL);
	/*Apply low voltage*/
	GPIO_WritePin(Relay->GPIOx , Relay->PinNumber , GPIO_LOW);
}
void Relay_TurnOnRelay(Relay_t *Relay)
{
	GPIO_WritePin(Relay->GPIOx , Relay->PinNumber , GPIO_HIGH);
}
void Relay_TurnOffRelay(Relay_t *Relay)
{
	GPIO_WritePin(Relay->GPIOx , Relay->PinNumber , GPIO_LOW);
}
