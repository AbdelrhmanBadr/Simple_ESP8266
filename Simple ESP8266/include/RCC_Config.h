#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H
 

/*
*@brief: The following line is used to determine the system clock mode
* System clock modes : 1) RCC_EXTERNAL_SYSTEM_CLK          2)RCC_INTERNAL_SYSTEM_CLK	3)RCC_PLL_SYSTEM_CLK
*/
#define RCC_SYSTEM_CLK      (RCC_EXTERNAL_SYSTEM_CLK)

/*
*@brief: The following line is used with external clock to determine the type 
* System clock modes : 1) RCC_CRYSTAL_OSC          2) RCC_RC_OSC
*/
#if (RCC_SYSTEM_CLK == RCC_EXTERNAL_SYSTEM_CLK) || (RCC_SYSTEM_CLK == RCC_PLL_SYSTEM_CLK)
    #define RCC_EXTERNAL_CLK_TYPE  (RCC_CRYSTAL_TURN_ON) /*RCC_CRYSTAL_TURN_ON, RCC_RC_TURN_ON*/
#endif /*SYSTEM_CLK*/

/*
*@brief: The following line is used with PLL clock
* System clock modes : RCC_PLL_FACTOR_x2, RCC_PLL_FACTOR_x3, RCC_PLL_FACTOR_x4,
RCC_PLL_FACTOR_x5, RCC_PLL_FACTOR_x6, RCC_PLL_FACTOR_x7, RCC_PLL_FACTOR_x8, 
RCC_PLL_FACTOR_x9, RCC_PLL_FACTOR_x10, RCC_PLL_FACTOR_x11, RCC_PLL_FACTOR_x12,
RCC_PLL_FACTOR_x13, RCC_PLL_FACTOR_x14, RCC_PLL_FACTOR_x15, RCC_PLL_FACTOR_x16 
*/
#if 0
#if (RCC_SYSTEM_CLK == RCC_PLL_SYSTEM_CLK)
    #define RCC_PLL_FACTOR      			(RCC_PLL_FACTOR_x2)
    #define EXTERNAL_CLK_PLL_FACTOR         (EXTERNAL_CLK_PLL_FACTOR_DIVEDED_BY_2)
#endif /*SYSTEM_CLK*/
#endif

/*
 * This line set the AHP peripherals clock w.r.t system clock:
 * 1) RCC_AHP_SYSTEM_CLK	2) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_2  3) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_4 	4) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_8
 * 5) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_16 	6) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_64		7) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_128
 * 8) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_256		9) RCC_AHP_SYSTEM_CLK_DIVIDED_BY_512
 */
#define RCC_AHP_CLK		(RCC_AHP_SYSTEM_CLK)

/*
 * This line set the APB1 peripherals clock:
 * 1) RCC_APB1_AHP_CLK				 2) RCC_APB1_AHP_CLK_DIVIDED_BY_2	 3) RCC_APB1_AHP_CLK_DIVIDED_BY_4
   4) RCC_APB1_AHP_CLK_DIVIDED_BY_8	 5) RCC_APB1_AHP_CLK_DIVIDED_BY_16
 */
#define RCC_APB1_CLK	(RCC_APB1_AHP_CLK)

/*
 * This line set the APB2 peripherals clock:
 * 1) RCC_APB2_AHP_CLK				 2) RCC_APB2_AHP_CLK_DIVIDED_BY_2	 3) RCC_APB2_AHP_CLK_DIVIDED_BY_4
   4) RCC_APB2_AHP_CLK_DIVIDED_BY_8	 5) RCC_APB2_AHP_CLK_DIVIDED_BY_16
 */
#define RCC_APB2_CLK	(RCC_APB2_AHP_CLK)

/* Comment this line to disable security system*/
#define RCC_ENABLE_SECURITY_SYSTEM		(1)

#endif /*_RCC_CONFIG_H*/
                         
                         
                         
                        
                        
                         
                        
                         
                         
