/**
	\file
	\brief
		This is a starter file to implement a function able to produce an accurate delay
		using the PIT module.

	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	17/09/2018
 */


#include "MK64F12.h"
#include "PIT.h"
#include "NVIC.h"
#include "GPIO.h"
#include "Bits.h"
#include "rgb.h"

#define SYSTEM_CLOCK (21000000U)
#define DELAY (2.5F)


int main(void)
{
	uint8_t pit_inter_status = FALSE;

	 init_rgb();

	 set_PIT_timer_with_interrupt(PIT_1,SYSTEM_CLOCK , DELAY,
			 	 	 	 	 	 	 PIT_CH1_IRQ, PRIORITY_11);
	 //for more info about the ISR check PIT1_IRQHandler() on pit.c file
	for(;;) {
		pit_inter_status= PIT_get_interrupt_flag_status(PIT_1);
		if(TRUE == pit_inter_status)
		{
			rgb_color(YELLOW , TOOGLE);
			PIT_clear_interrupt_flag(PIT_1);
		}




	}

	return 0;
}
