/*
 * 7seg.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Owner
 */

#ifndef SEG_H_
#define SEG_H_

#include "std_typo.h"
#include "DIO/DIO_INT.h"

#define seg_port          PORTB
#define seg_pin0          0
#define seg_pin1          1
#define seg_pin2          2
#define seg_pin3          4

#define seg_select_port0   PORTB
#define seg_select_pin0   6
#define seg_select_pin1   5

#define seg_select_port1   PORTA
#define seg_select_pin2   2
#define seg_select_pin3   3

#define DP_PORT           PORTD
#define DP_PIN            4

void init_7seg();
ERROR_status seg_print_val(uint8 val, uint8 id);
void Display_clock();
void inc_selected(uint8 val);
void inc_clock();
void Digits_callback(void (*ptr)(void));

#endif /* 7SEG_H_ */
