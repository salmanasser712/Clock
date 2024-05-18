

#ifndef TIMMER__CONFIG_H_
#define TIMMER__CONFIG_H_


/*timer*/
#define OSC_PER_INS       (1)
#define SET_FOSC          (8000000)
#define SET_PRESCALER     (1024)

                        // Phase_Correct
                        // CTC
                        // Fast_PWM
                        // Normal
#define Timer_MODE              Normal                           //the time needed for one overflow to happen
///////////////////////////////////REGISTER   ==   WIDTH     -   (TIME GENERATED   *    TIMER FREQUENCYYYYYYYYYYYYYYYYYYYYY)
#define TIMER_TICK_adjust(TICK_MS)   ((uint8)((256 - ((u32)( (TICK_MS/1000) *  ((u32)( SET_FOSC/SET_PRESCALER)/OSC_PER_INS ))))))
#define TMR_SET_PRESCALER_1024     TCCR0|=(1<<CS02)|(1<<CS00)


#endif /* TIMMER__CONFIG_H_ */
