#ifndef _GPIO_H
#define _GPIO_H

/*This struct is for GPIO registers*/
typedef struct
{
	__IO__ uint32t GPIOx_CRL;
	__IO__ uint32t GPIOx_CRH;
	__IO__ uint32t GPIOx_IDR;
	__IO__ uint32t GPIOx_ODR;
	__IO__ uint32t GPIOx_BSRR;
	__IO__ uint32t GPIOx_BRR;
	__IO__ uint32t GPIOx_LCKR;
}GPIO_Register_t;

#define GPIOA    ((__IO__ GPIO_Register_t *)(0x40010800))
#define GPIOB    ((__IO__ GPIO_Register_t *)(0x40010C00))
#define GPIOC    ((__IO__ GPIO_Register_t *)(0x40011000))

/*pin mode configuration*/
#define GPIO_INPUT_ANALOG		               (0)
#define GPIO_INPUT_FLOATING		               (4)
#define GPIO_INPUT_PULLUP		               (8)
#define GPIO_INPUT_PULLDOWN		               (20)

#define GPIO_OUTPUT_10MHZ_PUSH_PULL		       (1)
#define GPIO_OUTPUT_10MHZ_OPEN_DRAIN		   (5)
#define GPIO_OUTPUT_10MHZ_AF_PUSH_PULL	       (9)
#define GPIO_OUTPUT_10MHZ_AF_OPEN_DRAIN        (13)

#define GPIO_OUTPUT_2MHZ_PUSH_PULL		       (2)
#define GPIO_OUTPUT_2MHZ_OPEN_DRAIN	      	   (6)
#define GPIO_OUTPUT_2MHZ_AF_PUSH_PULL	       (10)
#define GPIO_OUTPUT_2MHZ_AF_OPEN_DRAIN         (14)

#define GPIO_OUTPUT_50MHZ_PUSH_PULL		       (3)
#define GPIO_OUTPUT_50MHZ_OPEN_DRAIN	       (7)
#define GPIO_OUTPUT_50MHZ_AF_PUSH_PULL	       (11)
#define GPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN        (15)

/*Define digital pin*/
#define GPIO_HIGH								(1)
#define GPIO_LOW								(0)


void GPIO_SetPinDirection(volatile GPIO_Register_t * GPIOx, uint8t PinNumber, uint8t PinMode);
void GPIO_WritePin(volatile GPIO_Register_t * GPIOx,uint8t PinNumber, uint8t DigitalVal);
void GPIO_ReadPin(volatile GPIO_Register_t * GPIOx,uint8t PinNumber, uint8t * ReturnedDigitalValue);


#endif /*_GPIO_H*/
