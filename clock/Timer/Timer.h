#ifndef __TIMER_H__
#define __TIMER_H__
#include "Timmer_Privates.h"
#include "../std_typo.h"
#include "../BitMath.h"

#define TMR_TICK_MS				(10)
#define min_ms                  60000

#define TMR_ENABLE_CLOCK              (TCCR0 = 0x05)
#define TMR_DISABLE_CLOCK             (TCCR0=0X00)
#define TMR_WAVE_GENERATOR            (FOC0=1)
#define TMR_CLEAR_OVFLAG              (TIFR|=1<<TOV0)
#define TMR_GET_OVFLAG                (TOV0)
#define TMR_INTRUPT_ENABLE            (TIMSK|=(1<<TOIE0))
#define GLOBAL_INTERRUPT_ENABLE       (SREG |=(1<<7))
#define Value_after_delay(Tim_s) (Tim_s * 300 * 2);


void Start_clock();
void Plincking_delay();
void TMR_Init(void);
void delay_int(tWord time_ms);
void TMR_Start(void);
uint8 TMR_CheckOverFlow(void);
void TMR_Stop(void);
void Timer_callback(void(*ptr)(void));

#endif
