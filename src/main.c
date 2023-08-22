#include "main.h"
#include "stm8l101f2.h"


/* Interrupt example */
// void tim4_handler(void) __interrupt(25) {
// 	tim4_ovf_cnt ++;
// 	TIM4->SR1 &= ~(0x1);
// }


int main(void) {

	sim(); // disable interrupts
	rim(); // enable interrupts

	while(1) {
	}
}
