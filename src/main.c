#include "stm8l101f2.h"

#include <stdint.h>
#include <stdio.h>


int putchar(int c) {
	while(!(USART->SR & (0x1 << 7)));

	USART->DR = c;

	return(c);
}

void main(void) {

	sim(); // enable interrupts

	CLK->CKDIVR = 0x00; // set frequency to 16mhz
	CLK->PCKENR = 0xff; // enable all peripherals

	// configure tx pin
	GPIOC->DDR = 0x08; 
	GPIOC->CR1 = 0x08;

	USART->CR2 = (0x1 << 3); // enable usart transmitter
	USART->CR3 &= ~(0x3 << 4); // 1 stop bit

	// 9600 baud
	USART->BRR2 = 0x03; 
	USART->BRR1 = 0x68; 

	rim(); // disable interrupts

	printf("Hello World!\n");

	while(1) {
	}
}

