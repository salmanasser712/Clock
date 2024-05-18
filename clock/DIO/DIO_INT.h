#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "../std_typo.h"
#define F_CPU    16000000UL

#define PIN_OUTPUT 0x1 
#define PIN_INPUT  0x0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT 0x00

#define T1 (0.00539875f)
#define TM (0.634125f)

#define LOW  0 
#define HIGH 1 

typedef enum
{
PIN0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7
}PINS;

typedef enum {
	PORTA = 1,
	PORTB,
	PORTC,
	PORTD
}PORTS;

//prototypes
void INIT(void); // ddrx input 
ERROR_status SETPINDIrection(uint8 PORT, uint8 PIN, uint8 STATE);
ERROR_status setpinvalue(uint8 _port, uint8 _pin, uint8 value);
ERROR_status getpinvalue(uint8 _port, uint8 _pin,uint8 *value);
ERROR_status togglepinvalue(uint8 _port, uint8 _pin);
ERROR_status ControlPortDIR(uint8 _PORT, uint8 DIRECTION);
ERROR_status controlPortValue(uint8 _PORT, uint8 Value);

#endif
