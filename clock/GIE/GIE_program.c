#include "../std_typo.h"
#include "../BitMath.h"

#include "GIE_interface.h"
#include "GIE_private.h"
//#include "GIE_config.h"

void GIE_voidEnable(void){
	set(SREG, 7);
}

void GIE_voidDisable(void){
	clear(SREG, 7);
}
