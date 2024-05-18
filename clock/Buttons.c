
#include "DIO/DIO_INT.h"
#include "Buttons.h"
#include "util/delay.h"

static void (*inc)(uint8) = NULL;
static void (*init_7seg)(void) = NULL;
extern uint8 blincking;
extern uint8 delay_flag;
extern uint8 first;

void init_Buttons(){
	SETPINDIrection(BUTTONS_COL_PORT, BUTTON0_PIN, PIN_INPUT);
	SETPINDIrection(BUTTONS_COL_PORT, BUTTON1_PIN, PIN_INPUT);

	SETPINDIrection(BUTTONS_ROW_PORT, ROW_BIN, PIN_OUTPUT);
}

void Buttons_logic(){
	uint8 pushed1 = 1, pushed2 = 1, push1 = 0, push2 = 0;
	init_7seg();
	getpinvalue(BUTTONS_COL_PORT, BUTTON0_PIN, &pushed1);
	while(!pushed1){
		push1 = 1;
		getpinvalue(BUTTONS_COL_PORT, BUTTON0_PIN, &pushed1);
	}
	getpinvalue(BUTTONS_COL_PORT, BUTTON1_PIN, &pushed2);
	while(!pushed2){
		push2 = 1;
		getpinvalue(BUTTONS_COL_PORT, BUTTON1_PIN, &pushed2);

	}
	if(push1){
		if(blincking == 2){
			blincking = 0;
		}
		else{
			blincking++;
		}
		delay_flag = 1;
		first = 1;
	}


	if(push2){
		if(blincking > 0){
			inc(blincking);
		}
		delay_flag = 1;
		first = 1;
	}
}

void BUTTON_CallBack(void (*ptr)(uint8), void (*ptr1)(void))
{
	inc = ptr;
	init_7seg = ptr1;
}
