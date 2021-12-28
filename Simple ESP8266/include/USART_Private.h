/*
 * USART_Private.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/*Define word lenght config*/
 #define  USART_8_DATA_BIT 		 (0)
 #define  USART_9_DATA_BIT  	 (1)

/*Define number of stop bits*/
#define  USART_2_STOP_BIT		(0)
#define  USART_1_STOP_BIT		(2)

/*Define parity modes*/
#define	  USART_ENABLE_PARITY_MODE		(1)
#define	  USART_DISABLE_PARITY_MODE		(0)
#define   USART_EVEN_PARITY				(0)
#define   USART_ODD_PARITY				(1)

/*Define enable modes*/
#define  USART_ENABLE					(1)
#define  USART_DISABLE					(0)

/*Define polarity modes*/
#define USART_LOW_POLARITY				(0)
#define USART_HIGH_POLARITY				(1)










/*Define AIFO pointer*/
#define USART_AIFO	 (*(__IO__ uint32t *)(0x40010000 + 0x04))

/*Define registers bits*/
#define CR1_UE_BIT			(13)
#define CR1_M_BIT			(12)
#define CR2_STOP_BIT		(12)
#define CR2_RE_BIT			(2)
#define CR2_TE_BIT			(3)
#define SR_TC_BIT			(6)
#define SR_RXNE_BIT			(5)
#define SR_PE_BIT			(0)
#define SR_FE_BIT			(1)
#define SR_NE_BIT			(2)
#define SR_ORE_BIT			(3)
/*Define bit masks*/
#define USART_WORD_LENGTH_BIT_MASK	(0xFFFF6FFF)
#define USART_STOP_BIT_MASK			(0xFFFFCFFF)
#define USART_TX_RX_ENABLE_BIT_MASK	(0xFFFFFFF3)

#endif /* USART_PRIVATE_H_ */
