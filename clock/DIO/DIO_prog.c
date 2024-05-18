#include "../BitMath.h"
#include "../std_typo.h"
#include "DIO_private.h"
#include "DIO_INT.h"


void INIT(void)
{
	DDRA = PORT_INPUT;
	DDRB = PORT_INPUT;
	DDRC = PORT_INPUT;
	DDRD = PORT_INPUT;
}

ERROR_status SETPINDIrection(uint8 PORT, uint8 PIN, uint8 STATE)
{ 
	ERROR_status loc_variable = E_OK;
	if(PORT>=PORTA && PORT <=PORTD)
	{
		switch(PORT){
		
				case PORTA:
							switch(STATE)
							{
								case PIN_OUTPUT:
									set(DDRA,PIN);
									break;
								case PIN_INPUT:
									clear(DDRA,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				  
				case PORTB:
				switch(STATE)
							{
								case PIN_OUTPUT:
									set(DDRB,PIN);
									break;
								case PIN_INPUT:
									clear(DDRB,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				case PORTC:
				switch(STATE)
							{
								case PIN_OUTPUT:
									set(DDRC,PIN);
									break;
								case PIN_INPUT:
									clear(DDRC,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				case PORTD:
				switch(STATE)
							{
								case PIN_OUTPUT:
									set(DDRD,PIN);
									break;
								case PIN_INPUT:
									clear(DDRD,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				default : loc_variable = E_NOK;

		}
	}
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;
}

ERROR_status setpinvalue(uint8 PORT, uint8 PIN, uint8 value)
{
	ERROR_status loc_variable = E_OK;
	if(PORT>=PORTA && PORT <=PORTD)
	{
		switch(PORT){
		
				case PORTA:
							switch(value)
							{
								case HIGH:
									set(DIO_PORTA,PIN);
									break;
								case LOW:
									clear(DIO_PORTA,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				  
				case PORTB:
				switch(value)
							{
								case HIGH:
									set(DIO_PORTB,PIN);
									break;
								case LOW:
									clear(DIO_PORTB,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				case PORTC:
				switch(value)
							{
								case HIGH:
									set(DIO_PORTC,PIN);
									break;
								case LOW:
									clear(DIO_PORTC,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				case PORTD:
				switch(value)
							{
								case PIN_OUTPUT:
									set(DIO_PORTD,PIN);
									break;
								case PIN_INPUT:
									clear(DIO_PORTD,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				break;
				default : loc_variable = E_NOK;
		}
	}
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;

}


ERROR_status getpinvalue(uint8 PORT, uint8 PIN, uint8 *value)
{
 	ERROR_status loc_variable = E_OK;
	if(PORT>=PORTA && PORT <=PORTD)
	{
		switch(PORT){
		
				case PORTA:
						*value = getbit(PINA,PIN);
						break;
				case PORTB:
						*value = getbit(PINB,PIN);
						break;
				case PORTC:
						*value = getbit(PINC,PIN);
						break;
				case PORTD:
						*value = getbit(PIND,PIN);
						break;
				default : loc_variable = E_NOK;
		}
	}
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;
}

ERROR_status togglepinvalue(uint8 PORT, uint8 PIN)
{
	ERROR_status loc_variable = E_OK;
	if(PORT>=PORTA && PORT <=PORTD)
	{
		switch(PORT){
		
				case PORTA:
						toggle(DIO_PORTA,PIN);
						break;
				case PORTB:
						toggle(DIO_PORTB,PIN);
						break;
				case PORTC:
						  toggle(DIO_PORTC,PIN);
						break;
				case PORTD:
				  toggle(DIO_PORTC,PIN);
				break;
				default : loc_variable = E_NOK;
		}
	}
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;
}

ERROR_status ControlPortDIR(uint8 PORT, uint8 DIRECTION)
{
	ERROR_status loc_variable = E_OK;
	if(PORT>=PORTA && PORT <=PORTD)
	{
		switch(PORT){
		
				case PORTA:
						DDRA = DIRECTION;
						
						break;
				case PORTB:
			     DDRA = DIRECTION;
						
						break;
				case PORTC:
						DDRA = DIRECTION;
						
						break;
				case PORTD:
				 DDRA = DIRECTION;
						
						break;
				default : loc_variable = E_NOK;
		}
	}
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;
}
ERROR_status controlPortValue(uint8 PORT, uint8 value)
{
	ERROR_status loc_variable = E_OK;
	if(PORT>=PORTA && PORT <=PORTD)
	{
		switch(PORT){
		
				case PORTA:
						DIO_PORTA = value;
						
						break;
				case PORTB:
						DIO_PORTB = value;
						
						break;
				case PORTC:
						DIO_PORTC = value;
						
						break;
				case PORTD:
						DIO_PORTD = value;
						
						break;
				default : loc_variable = E_NOK;
		}
	}
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;
}




