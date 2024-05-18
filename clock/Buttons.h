/*
 * Buttons.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Owner
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "std_typo.h"
#include "BitMath.h"

#define     BUTTON0_PIN     7
#define     BUTTON1_PIN     6

#define     BUTTONS_COL_PORT     PORTD
#define     BUTTONS_ROW_PORT     PORTC

#define     ROW_BIN              5

void init_Buttons();
void Buttons_logic();
void BUTTON_CallBack(void (*ptr)(uint8), void (*ptr1)(void));

#endif /* BUTTONS_H_ */
