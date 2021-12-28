#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H


/*Define configurations of RCC_SYSTEM_CLK*/
#define RCC_EXTERNAL_SYSTEM_CLK        (1)
#define RCC_INTERNAL_SYSTEM_CLK        (0)
#define RCC_PLL_SYSTEM_CLK             (2)

/*Define external modes*/
#define RCC_CRYSTAL						(0x01)
#define RCC_RC							(0x05)

/*Define Bit MASK*/
#define RCC_CFGR_HSE_MASK       (0xFFFFFFFC)
#define RCC_CFGR_HSI_MASK       (0xFFFFFFFC)
#define RCC_CR_HSE_MASK         (0xFFF8FFFF)
#define RCC_CR_HSI_MASK         (0xFFFFFFFC)
#define RCC_CFGR_PLL_MASK       (0xFF30FFFC)
#define RCC_CFGR_BUS_CLK_MASK	(0xFFFFC00F)
#define RCC_CFGR_MCO_MASK		(0xF8FFFFFF)
#define RCC_CR_HSITRIM_MASK		(0xF8FFFFF7)

/*Define PLL sources*/
#define RCC_PLL_INTERNAL_SOURCE               (0x00)
#define RCC_PLL_EXTERNAL_SOURCE               (0x01)
#define RCC_PLL_EXTERNAL_SOURCE_DIVEDED_BY_2  (0x03)

/*Define clock turning on*/
#define RCC_CRYSTAL_TURN_ON                (0x01) /*Turn on external crystal*/
#define RCC_RC_TURN_ON                     (0x05) /*Turn on external RC*/

/*Define PLL factors*/
#define RCC_PLL_FACTOR_x2    (0) 
#define RCC_PLL_FACTOR_x3    (1)   
#define RCC_PLL_FACTOR_x4    (2)
#define RCC_PLL_FACTOR_x5    (3)
#define RCC_PLL_FACTOR_x6    (4)
#define RCC_PLL_FACTOR_x7    (5)
#define RCC_PLL_FACTOR_x8    (6)
#define RCC_PLL_FACTOR_x9    (7)
#define RCC_PLL_FACTOR_x10   (8)
#define RCC_PLL_FACTOR_x11   (9)
#define RCC_PLL_FACTOR_x12   (10)
#define RCC_PLL_FACTOR_x13   (11)
#define RCC_PLL_FACTOR_x14   (12)
#define RCC_PLL_FACTOR_x15   (13)
#define RCC_PLL_FACTOR_x16   (14)

/*Define AHB clock*/
#define RCC_AHP_SYSTEM_CLK					(0)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_2		(8)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_4		(9)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_8		(10)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_16	(11)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_64	(12)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_128	(13)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_512	(14)
#define RCC_AHP_SYSTEM_CLK_DIVIDED_BY_256	(15)

/*Define APB1 clock*/
#define RCC_APB1_AHP_CLK					(0)
#define RCC_APB1_AHP_CLK_DIVIDED_BY_2		(4)
#define RCC_APB1_AHP_CLK_DIVIDED_BY_4		(5)
#define RCC_APB1_AHP_CLK_DIVIDED_BY_8		(6)
#define RCC_APB1_AHP_CLK_DIVIDED_BY_16	    (7)

/*Define APB2 clock*/
#define RCC_APB2_AHP_CLK					(0)
#define RCC_APB2_AHP_CLK_DIVIDED_BY_2		(4)
#define RCC_APB2_AHP_CLK_DIVIDED_BY_4		(5)
#define RCC_APB2_AHP_CLK_DIVIDED_BY_8		(6)
#define RCC_APB2_AHP_CLK_DIVIDED_BY_16	    (7)

/*Define APB2 peripherals*/
#define RCC_APB2_AFIO         (0)
#define RCC_APB2_IOPA         (2)
#define RCC_APB2_IOPB         (3)
#define RCC_APB2_IOPC         (4)
#define RCC_APB2_IOPD         (5)
#define RCC_APB2_IOPE         (6)
#define RCC_APB2_IOPF         (7)
#define RCC_APB2_IOPG         (8)
#define RCC_APB2_ADC1         (9)
#define RCC_APB2_ADC2         (10)
#define RCC_APB2_TIM1         (11)
#define RCC_APB2_SPI1         (12)
#define RCC_APB2_TIM8         (13)
#define RCC_APB2_USART1       (14)
#define RCC_APB2_ADC3         (15)
#define RCC_APB2_TIM9         (19)
#define RCC_APB2_TIM10        (20)
#define RCC_APB2_TIM11        (21)

/*Define APB1 peripherals*/
#define RCC_APB1_TIM2         (0)
#define RCC_APB1_TIM3         (1)
#define RCC_APB1_TIM4         (2)
#define RCC_APB1_TIM5         (3)
#define RCC_APB1_TIM6         (4)
#define RCC_APB1_TIM7         (5)
#define RCC_APB1_TIM12        (6)
#define RCC_APB1_TIM13        (7)
#define RCC_APB1_TIM14        (8)
#define RCC_APB1_WWDG         (11)
#define RCC_APB1_SPI2         (14)
#define RCC_APB1_SPI3         (15)
#define RCC_APB1_USART2       (17)
#define RCC_APB1_USART3       (18)
#define RCC_APB1_UART4        (19)
#define RCC_APB1_UART5        (20)
#define RCC_APB1_I2C1         (21)
#define RCC_APB1_I2C2         (22)
#define RCC_APB1_USB		  (23)
#define RCC_APB1_CAN		  (25)
#define RCC_APB1_BKP		  (27)
#define RCC_APB1_PWR		  (28)
#define RCC_APB1_DAC		  (29)

/*Define AHB peripherals*/
#define RCC_AHB_DMA1			(0)
#define RCC_AHB_DMA2			(1)
#define RCC_AHB_SRAM			(2)
#define RCC_AHB_FLITF			(4)
#define RCC_AHB_CRCE			(6)
#define RCC_AHB_FSMC			(8)
#define RCC_AHB_SDIO			(10)

/*
*@Brief: This struct is used for RCC registers
*/
typedef struct
{
  __IO__ uint32t RCC_CR;
  __IO__ uint32t RCC_CFGR;
  __IO__ uint32t RCC_CIR;
  __IO__ uint32t RCC_APB2RSTR;
  __IO__ uint32t RCC_APB1RSTR;
  __IO__ uint32t RCC_AHBENR;
  __IO__ uint32t RCC_APB2ENR;
  __IO__ uint32t RCC_APB1ENR;
  __IO__ uint32t RCC_BDCR;
  __IO__ uint32t RCC_CSR;
}RCC_Registers_t;



/*Define registers bits*/
#define RCC_CR_HSERDY           (17)
#define RCC_CR_HSIRDY           (1)
#define RCC_CR_PLLRDY           (25)
#define RCC_CFGR_PLLSRC         (16)
#define RCC_CR_HSEON            (16)
#define RCC_CFGR_PLLSRC         (16)
#define RCC_CFGR_PLLMUL         (18)
#define RCC_CR_HSION            (0)
#define RCC_CR_PLLON            (24)
#define RCC_CR_PLLRDY           (25)
#define RCC_CR_CSSON			(19)
/*Define a pointer to RCC_Registers_t*/
#define RCC_REGISTER    ((__IO__ RCC_Registers_t *)(0x40021000))

/*Ready flags*/
#define RCC_HSE_READY   (1)
#define RCC_HSI_READY   (1)
#define RCC_PLL_READY   (1)

/*Error handling*/
#define IS_RCC_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x1F)  /*To avoid overflow*/
#define IS_RCC_APB2Periphral_VALUE(VALUE)		((VALUE == RCC_APB2_AFIO) ||\
                                                (VALUE == RCC_APB2_IOPA) ||\
                                                (VALUE == RCC_APB2_IOPB) ||\
                                                (VALUE == RCC_APB2_IOPC) ||\
                                                (VALUE == RCC_APB2_IOPD) ||\
                                                (VALUE == RCC_APB2_IOPE) ||\
                                                (VALUE == RCC_APB2_IOPF) ||\
                                                (VALUE == RCC_APB2_IOPG) ||\
                                                (VALUE == RCC_APB2_ADC1) ||\
                                                (VALUE == RCC_APB2_ADC2) ||\
                                                (VALUE == RCC_APB2_TIM1) ||\
                                                (VALUE == RCC_APB2_SPI1) ||\
                                                (VALUE == RCC_APB2_TIM8) ||\
                                                (VALUE == RCC_APB2_USART1) ||\
                                                (VALUE == RCC_APB2_ADC3) ||\
                                                (VALUE == RCC_APB2_TIM9) ||\
                                                (VALUE == RCC_APB2_TIM10) ||\
                                                (VALUE == RCC_APB2_TIM11))

#define IS_RCC_APB1Periphral_VALUE(VALUE)		((VALUE ==RCC_APB1_TIM2) ||\
                                                (VALUE == RCC_APB1_TIM3) ||\
                                                (VALUE == RCC_APB1_TIM4) ||\
                                                (VALUE == RCC_APB1_TIM5) ||\
                                                (VALUE == RCC_APB1_TIM6) ||\
                                                (VALUE == RCC_APB1_TIM7) ||\
                                                (VALUE == RCC_APB1_TIM12) ||\
                                                (VALUE == RCC_APB1_TIM13) ||\
                                                (VALUE == RCC_APB1_TIM14) ||\
                                                (VALUE == RCC_APB1_WWDG) ||\
                                                (VALUE == RCC_APB1_SPI2) ||\
                                                (VALUE == RCC_APB1_SPI3) ||\
                                                (VALUE == RCC_APB1_USART2) ||\
                                                (VALUE == RCC_APB1_USART3) ||\
                                                (VALUE == RCC_APB1_UART4) ||\
                                                (VALUE == RCC_APB1_UART5) ||\
                                                (VALUE == RCC_APB1_I2C1) ||\
                                                (VALUE == RCC_APB1_I2C2) ||\
                                                (VALUE == RCC_APB1_USB) ||\
												(VALUE == RCC_APB1_CAN) ||\
                                                (VALUE == RCC_APB1_BKP) ||\
                                                (VALUE == RCC_APB1_PWR) ||\
                                                (VALUE == RCC_APB1_DAC))


#define IS_RCC_AHBPeriphral_VALUE(VALUE)		((VALUE ==RCC_AHB_DMA1)	 ||\
                                                (VALUE == RCC_AHB_DMA2)	 ||\
                                                (VALUE == RCC_AHB_SRAM)	 ||\
                                                (VALUE == RCC_AHB_FLITF) ||\
                                                (VALUE == RCC_AHB_CRCE)	 ||\
                                                (VALUE == RCC_AHB_FSMC)	 ||\
                                                (VALUE == RCC_AHB_SDIO))

#endif /*_RCC_PRIVATE_H*/
