
#include "Timer.h"
#include "Timmer__Config.h"

u32 target = 0, count = 0;
uint8 TCNT0_value = TIMER_TICK_adjust(TMR_TICK_MS);
tWord Delay_min = Value_after_delay(60);
uint8 Plinck_ms  = 20;
static void(*inc_clock)(void) = NULL;
extern uint8 delay_flag;
extern uint8 blincking;
extern uint8 first;

void TMR_Init(void)
{
	TCCR0 = 0;
	TIFR = 0;
	TIMSK = 0;
	/* Add your code here! */
	//SET MODE
#if Timer_MODE == Normal
	clear(TCCR0, WGM01);
	clear(TCCR0, WGM00);
	set(TCCR0, FOC0);
#elif Timer_MODE == Phase_Correct
	clear(TCCR0, WGM01);
	set(TCCR0, WGM00);
#elif Timer_MODE == CTC
	set(TCCR0, WGM01);
	clear(TCCR0, WGM00);
#elif Timer_MODE == Fast_PWM
	set(TCCR0, WGM01);
	set(TCCR0, WGM00);
#endif

	//TMR_CLEAR_OVFLAG
	set( TIMSK, TOIE0);
	/* End of your code!*/
}
void TMR_Start(void)
{
	/* Add your code here! */
	//TMR_CLEAR_OVFLAG
	set(TIFR, TOV0);
	//TIMER_TICK_adjust
	TCNT0 = TCNT0_value;
	//TMR_ENABLE_CLOCK
	#if SET_PRESCALER == 1024
		set(TCCR0, CS02);
		clear(TCCR0, CS01);
		set(TCCR0, CS00);
	#endif

	/* End of your code!*/
}

uint8 TMR_CheckOverFlow(void)
{
	/* Add your code here! */
	// TMR_GET_OVFLAG
	uint8 ov = getbit( TIFR, TOV0);
	return ov;
	/* End of your code!*/
}
void TMR_Stop(void)
{
	/* Add your code here! */
	//TMR_DISABLE_CLOCK
	clear( TCCR0, CS02);
	clear( TCCR0, CS01);
	clear( TCCR0, CS00);
	/* End of your code!*/
}


void delay_int(tWord time_ms){
	TMR_Init();
	TMR_Stop();
	count = 0;
	target = (time_ms / TMR_TICK_MS);
	TMR_Start();
}
void __vector_11(void){
	count++;
	if(count < target) {
		TMR_Start();
		return;
	}
	else {
		TMR_Stop();
		delay_flag = 1;
		return;
	}
}


// counting minutes
void Start_clock(){
	if(delay_flag && !blincking){
		delay_int((tWord)Delay_min);
		delay_flag = 0;
		if(!first) inc_clock();
		first = 0;
	}
}

// delaying for the blincking
void Plincking_delay(){
	if(blincking && delay_flag){
		delay_int(Plinck_ms);
		delay_flag = 0;
	}
}

void Timer_callback(void(*ptr)(void)){
	inc_clock = ptr;
}


