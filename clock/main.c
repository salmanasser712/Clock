#include "DIO/DIO_INT.h"
#include "Timer/Timer.h"
#include "GIE/GIE_interface.h"
#include "util/delay.h"
#include "7seg.h"
#include "Buttons.h"

uint8 digits[4] = {2, 3, 5, 5};

// delay_flag tells me if the isr got executed and first tells me when to increment the clock
uint8 delay_flag = 1, first = 1;

// Global variable used to specify the mode i'm currently in, because i'm using the same timer for both delaying the blincking of the selected segments and incrementing the clock normally
// blincking = 0 - > normal clock mode
// blincking = 1 - > plinking the hours
// blincking = 2 - > blincking minutes

uint8 blincking = 0;

int main(){
	INIT();
	TMR_Init();
	init_7seg();
	init_Buttons();
	GIE_voidEnable();
	Digits_callback(&Plincking_delay);
	BUTTON_CallBack(&inc_selected, &init_7seg);
	Timer_callback(&inc_clock);

	while(1){
		Start_clock();
		Display_clock();
		Buttons_logic();
	}


	return 0;
}


