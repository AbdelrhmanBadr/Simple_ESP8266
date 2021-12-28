/*
 * SYSTICK_Private.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

/*Define Systick clock modes*/
 #define SYSTICK_AHB_CLK			(1)
 #define SYSTICK_AHB_CLK_OVER_8		(0)

/*Define Systick interrupts*/
#define SYSTICK_ENABLE_INTERRUPT	(1)
#define SYSTICK_DISABLE_INTERRUPT	(0)

/*Define bit mask*/
#define SYSTICK_STK_CTRL_BIT_MASK	(0x07)
#define SYSTICK_ENABLE				(0x01)
typedef struct
{
	__IO__ uint32t STK_CTRL;
	__IO__ uint32t STK_LOAD;
	__IO__ uint32t STK_VAL;
	__I__  uint32t STK_CALIB;
}SYSTICK_Registers_t;

#define SYSTICK    ((__IO__ SYSTICK_Registers_t *)(0xE000E010))


#define STK_CTRL_ENABLE_BIT		(0)
#define STK_CTRL_FLAG_BIT		(16)
#endif /* SYSTICK_PRIVATE_H_ */
