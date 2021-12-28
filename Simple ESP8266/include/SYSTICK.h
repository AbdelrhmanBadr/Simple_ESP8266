/*
 * SYSTICK.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

/*
 * @brief: This function is used to initiate the systick with configurations in Config file
 * @para: void
 * @return: void
 */
void SYSTICK_Initiate(void);

/*
 * @brief: This function is used to set the counter value to count from this value to zero
 * @para: 1) Number of ticks in range 24-bits		2) Pointer to function that will be executed when the counter is done
 * @return: void
 */
void SYSTICK_SetTimerValueSynch(uint32t Ticks , void (*PointerToFunction) (void));

/*
 * @brief: This function is used to hold processor from doing anything during certain time (sth like delay fucntion)
 * @para: value to wait
 * @return: void
 */
void SYSTICK_SetBusyWait(uint32t BusyWaitVal);

/*
 * @brief: This function is used to disable timer
 * @para: void
 * @return: void
 */
void SYSTICK_DisableTimer(void);

/*
 * @brief: This function is used to enable timer
 * @para: void
 * @return: void
 */
void SYSTICK_EnableTimer(void);
/*
 * @brief: This function is used to return what is the value the counter reach now
 * @para: void
 * @return : Value of the current timer value in 24-bit
 */
uint32t SYSTICK_GetCurrentCounterValue(void);

/*
 * @brief: This function is used to delay time in ms
 * @para: void
 * @return : Value of the current timer value in 24-bit
 * @note : This function will work sucessfully if : 1)Systick_Clk = 1MHZ (Systick_clk_mode = AHB_CLK/8 where AHB_CLK = 8MHZ)
 */
void SYSTICK_SetBusyWaitms(uint32t MilliSeconds);
#endif /* SYSTICK_H_ */
