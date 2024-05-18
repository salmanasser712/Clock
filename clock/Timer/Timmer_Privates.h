
#ifndef TIMMER_PRIVATES_H_
#define TIMMER_PRIVATES_H_

#define TIMSK        (*((volatile uint8*) 0x59))
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE   5
#define TOIE2   6
#define OCIE2   7

#define TIFR         (*((volatile uint8*) 0x58))
#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF     5
#define TOV2    6
#define OCF2    7

#define TCCR0        (*((volatile uint8*) 0x53))
#define WGM00   6
#define WGM01   3
#define COM00   4
#define COM01   5
#define CS00    0
#define CS01    1
#define CS02    2
#define FOC0    7

#define TCNT0       (*((volatile uint8*) 0x52))
#define OCR0        (*((volatile uint8*) 0x5C))


void __vector_11(void) __attribute__((signal));

#endif /* TIMMER_PRIVATES_H_ */
