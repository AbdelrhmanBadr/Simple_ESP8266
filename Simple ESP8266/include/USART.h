/*
 * USART.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Abdelrhman Badr
 *  This peripheral in STM is suppourt : Asynchronous mode,Hardware Flow Control,Multibuffer Communication (DMA),
 *  Multiprocessor Communication,Synchronous,Smartcard,Half-Duplex (Single-Wire mode),IrDA,LIN
 *
 *  This driver is support Asynchronous mode only and the other modes will be updated soon
 */

#ifndef USART_H_
#define USART_H_

/*
 * USART pins:
   ===========
   USART3_TX_B10_RX_B11
   USART2_TX_A2_RX_A3
   USART1_TX_A9_RX_A10 --> Default pins
   USART1_TX_B6_RX_B7  --> Use re-map function to use these pins
*/

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
#define  USART_ENABLE_TX					(1)
#define  USART_DISABLE_TX					(0)
#define  USART_ENABLE_RX					(1)
#define  USART_DISABLE_RX					(0)

typedef struct
{
	__IO__  uint32t USART_SR;
	__IO__  uint32t USART_DR;
	__IO__  uint32t USART_BRR;
	__IO__  uint32t USART_CR1;
	__IO__  uint32t USART_CR2;
	__IO__  uint32t USART_CR3;
	__IO__  uint32t	USART_GTPR;
}USART_Registers_t;

typedef enum
{
	USART_NoError,
	USART_ORE,
	USART_NE,
	USART_FE,
	USART_PE,
	USART_TimeOut,
}USART_Errors_t;

/*Define USARt register pointers*/
#define USART1    ((__IO__ USART_Registers_t *)(0x40013800))
#define USART2    ((__IO__ USART_Registers_t *)(0x40004400))
#define USART3    ((__IO__ USART_Registers_t *)(0x40004800))
/**
  * @brief  USART Init Structure definition
  */
typedef struct
{
	uint32t USART_BaudRate;	     /*!< This member configures the USART communication baud rate. */

	uint8t USART_WordLength; /*!< Specifies the number of data bits transmitted or received in a frame.
                                      This parameter can be:
                                      * USART_8_DATA_BIT
                                      * USART_9_DATA_BIT
                                  */

	uint8t USART_ParityMode;  /*!< Specifies the parity mode.
                                       This parameter can be a value of the following:
                                       * USART_ENABLE_EVEN_PARITY_MODE
			                           * USART_ENABLE_ODD_PARITY_MODE
			                           * USART_DISABLE_PARITY_MODE
			                       */

	uint8t USART_StopBit;  /*!< Specifies the number of stop bits transmitted.
                                       This parameter can be a value of:
                                       * USART_2_STOP_BIT
                                       * USART_1_STOP_BIT
                                   */

    uint8t USART_TransmitterEnable; /*!< Specifies the mode of the transmitter
	                                         This parameter can be a value of:
	                                         * USART_ENABLE_TX
	                                         * USART_DISABLE_TX
	                                      */

	uint8t USART_RecieverEnable; /*!< Specifies the mode of the reciever
	                                          This parameter can be a value of:
	                                          * USART_ENABLE_RX
	                                          * USART_DISABLE_RX
	                                      */

}USART_Config_t;


/*
 * @brief: initiate USARt with selected configurations in CONFIG file
 * @para : 1) USARTn -->USART1, USART2, USART3 where n = 1:3
 * 		   2) variable from USART_Config_t <MUST BE INITIALIZED>
 * @ret  : void
 */
void USART_Initiate(volatile USART_Registers_t *USARTn , USART_Config_t *USART_Config);
void USART_SendDataAsynch(volatile USART_Registers_t *USARTn , uint16t Data);
uint16t USART_RecieveData(volatile USART_Registers_t *USARTn ,uint8t *ReturnedError);
void USART1_ReMap(void);

#endif /* USART_H_ */
