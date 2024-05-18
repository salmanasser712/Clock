/*
 * std_typo.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Owner
 */

#ifndef STD_TYPOS_H_
#define STD_TYPOS_H_

#include <stdint.h>

#define uint8 unsigned char
#define tWord uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define f32 float
#define f64 double

#define NULL ((void*)0)

typedef enum {
	E_OK = 1,
	E_NOK = 0
}ERROR_status;



#endif /* STD_TYPOS_H_ */
