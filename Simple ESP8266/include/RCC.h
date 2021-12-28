/*
 * RCC.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef RCC_H_
#define RCC_H_

typedef enum
{
	RCC_ExternalClockSystem,
	RCC_InternalClockSystem,
	RCC_PLLClockSystem
}RCC_ClockSystem_t;

typedef enum
{
	RCC_SystemClock = 4,
	RCC_Internal_CLOCK,
	RCC_External_CLOCK,
	RCC_PLL_CLOCK

}RCC_MCOModes_t;

void RCC_Deinit(void);
void RCC_Initiate(void);
void RCC_AdjustInternalClock(uint8t CalibrationValue);
RCC_ClockSystem_t RCC_GetClockSystem (void);
void RCC_SetMCOPinClk (RCC_MCOModes_t MCO_Mode);
void RCC_EnableAPB2PeriphralsClock(uint8t Peripheral);
void RCC_EnableAPB1PeriphralsClock(uint8t Peripheral);
void RCC_EnableAHBPeriphralsClock(uint8t Peripheral);

#endif /* RCC_H_ */
