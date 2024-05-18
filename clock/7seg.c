
#include "std_typo.h"
#include "7seg.h"
#include <util/delay.h>

extern uint8 blincking;
extern uint8 delay_flag;
extern uint8 digits[4];
static void (*Plincking_delay)(void) = NULL;

void set_high(){
	setpinvalue(seg_select_port0, seg_select_pin0, HIGH);
	setpinvalue(seg_select_port0, seg_select_pin1, HIGH);
	setpinvalue(seg_select_port1, seg_select_pin2, HIGH);
	setpinvalue(seg_select_port1, seg_select_pin3, HIGH);
}

void init_7seg(){
	SETPINDIrection(seg_port, seg_pin0, PIN_OUTPUT);
	SETPINDIrection(seg_port, seg_pin1, PIN_OUTPUT);
	SETPINDIrection(seg_port, seg_pin2, PIN_OUTPUT);
	SETPINDIrection(seg_port, seg_pin3, PIN_OUTPUT);

	SETPINDIrection(seg_select_port0, seg_select_pin0, PIN_OUTPUT);
	SETPINDIrection(seg_select_port0, seg_select_pin1, PIN_OUTPUT);
	SETPINDIrection(seg_select_port1, seg_select_pin2, PIN_OUTPUT);
	SETPINDIrection(seg_select_port1, seg_select_pin3, PIN_OUTPUT);

	SETPINDIrection(DP_PORT, DP_PIN, PIN_OUTPUT);

	set_high();
}

void light_number(uint8 b0, uint8 b1, uint8 b2, uint8 b3, uint8 sb0, uint8 sb1, uint8 sb2, uint8 sb3){

	setpinvalue(seg_select_port0, seg_select_pin0, sb0);
	setpinvalue(seg_select_port0, seg_select_pin1, sb1);
	setpinvalue(seg_select_port1, seg_select_pin2, sb2);
	setpinvalue(seg_select_port1, seg_select_pin3, sb3);

	setpinvalue(seg_port, seg_pin0, b0);
	setpinvalue(seg_port, seg_pin1, b1);
	setpinvalue(seg_port, seg_pin2, b2);
	setpinvalue(seg_port, seg_pin3, b3);
}

void set_val(uint8 b0, uint8 b1, uint8 b2, uint8 b3, uint8 sb0, uint8 sb1, uint8 sb2, uint8 sb3){

	// checking if i'm printing on a segment that is supposed to be plincking, if so did the delay end, so i can print the number
	if(blincking == 1 && !(sb0 && sb1) && delay_flag){
		light_number(b0, b1, b2, b3, sb0, sb1, sb2, sb3);
	}

	else if(blincking == 2 && !(sb2 && sb3) && delay_flag){
		light_number(b0, b1, b2, b3, sb0, sb1, sb2, sb3);
	}

	else if (blincking == 1 && (sb0 && sb1)){
		light_number(b0, b1, b2, b3, sb0, sb1, sb2, sb3);
	}
	else if(blincking == 2 && (sb2 && sb3)){
		light_number(b0, b1, b2, b3, sb0, sb1, sb2, sb3);
	}
	else if(blincking == 0){
		light_number(b0, b1, b2, b3, sb0, sb1, sb2, sb3);
	}
}

ERROR_status seg_print_val(uint8 val, uint8 id){
	ERROR_status er = E_OK;
	uint8 b0 = 0, b1 = 0, b2 = 0, b3 = 0, sb0 = 1, sb1 = 1, sb2 = 1, sb3 = 1;
	switch (val){
	case 0:
		break;
	case 1:
		b0 = 1;
		break;
	case 2:
		b1 = 1;
		break;
	case 3:
		b1 = b0 = 1;
		break;
	case 4:
		b2 = 1;
		break;
	case 5:
		b2 = b0 = 1;
		break;
	case 6:
		b2 = b1 = 1;
		break;
	case 7:
		b2 = b1 = b0 = 1;
		break;
	case 8:
		b3 = 1;
		break;
	case 9:
		b3 = b0 = 1;
		break;
	default: er = E_NOK;
	}

	switch(id){
	case 0:
		sb0 = 0;
		break;
	case 1:
		sb1 = 0;
		break;
	case 2:
		sb2 = 0;
		break;
	case 3:
		sb3 = 0;
		break;
	default: er = E_NOK;
	}
	if(er == E_OK){
		set_val(b0, b1, b2, b3, sb0, sb1, sb2, sb3);
	}
	return er;
}

void Display_clock(){
	init_7seg();
	Plincking_delay();
	if(blincking == 1){
		for(uint8 i = 3; i >= 0; i--){
			seg_print_val(digits[i], i);
			_delay_ms(2);
			set_high();
			if(i == 0) break;
		}
	}
	else{
		for(uint8 i = 0; i < 4; i++){
			seg_print_val(digits[i], i);
			_delay_ms(2);
			set_high();
		}
	}
}

void inc_mins(){
	if(digits[2] == 5 && digits[3] == 9){
		digits[2] = digits[3] = 0;
	}
	else if(digits[3] == 9){
		digits[2]++;
		digits[3] = 0;
	}
	else{
		digits[3]++;
	}
}
//                  0  1  2  3
//uint8 digits[] = {2, 3, 5, 9};
void inc_clock(){
	if(digits[2] == 5 && digits[3] == 9){
		if(digits[0] == 2 && digits[1] == 3){
			digits[0] = digits[1] = digits[2] = digits[3] = 0;
		}
		else if(digits[0] == 2){
			digits[1]++;
			digits[2] = digits[3] = 0;
		}
		else if(digits[1] == 9){
			digits[0]++;
			digits[2] = digits[1] = digits[3] = 0;
		}
		else{
			digits[1]++;
			digits[2] = digits[3] = 0;
		}
	}
	else if(digits[3] == 9){
		digits[2]++;
		digits[3] = 0;
	}
	else{
		digits[3]++;
	}
}

void inc_hours(){
	if(digits[0] == 2 && digits[1] == 3){
		digits[0] = digits[1] = 0;
	}
	else if(digits[1] == 9){
		digits[0]++;
		digits[1] = 0;
	}
	else{
		digits[1]++;
	}
}

void inc_selected(uint8 val){
	init_7seg();
	if(val == 2){
		inc_mins();
	}
	else{
		inc_hours();
	}
}

void Digits_callback(void (*ptr)(void)){
	Plincking_delay = ptr;
}
