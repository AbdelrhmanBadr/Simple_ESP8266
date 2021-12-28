#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

/*Define ports*/
#define GPIO_PORTA		(1)
#define GPIO_PORTB		(2)
#define GPIO_PORTC		(3)

#define INPUT_PULLDOWN_MODE	(8)

typedef enum
{
	GPIO_Output_10MHZ,
	GPIO_Output_2MHZ,
	GPIO_Output_50MHZ,
}GPIO_OutputSpeed_t;



#endif /*_GPIO_PRIVATE_H*/
