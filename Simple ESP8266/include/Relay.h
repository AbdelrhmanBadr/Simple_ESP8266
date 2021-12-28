/*
 * Relay.h
 *
 *  Created on: Dec 28, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef RELAY_H_
#define RELAY_H_


typedef struct
{
	volatile GPIO_Register_t * GPIOx;
	uint8t PinNumber;
}Relay_t;

void Relay_Initiate(Relay_t *Relay);
void Relay_TurnOnRelay(Relay_t *Relay);
void Relay_TurnOffRelay(Relay_t *Relay);

#endif /* RELAY_H_ */
