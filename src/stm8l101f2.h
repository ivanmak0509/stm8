#ifndef STM8L101F2_H
#define STM8L101F2_H

#include "stdint.h"

#define __IO volatile

typedef struct {
  __IO uint8_t ODR;
  __IO uint8_t IDR;
  __IO uint8_t DDR;
  __IO uint8_t CR1;
  __IO uint8_t CR2;
} gpio_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t PUKR;
  __IO uint8_t DUKR;
  __IO uint8_t IAPSR;
} flash_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t CR3;
  __IO uint8_t SR1;
  __IO uint8_t SR2;
  __IO uint8_t CONF;
} exti_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
} wfe_t;

typedef struct {
  __IO uint8_t CR;
  __IO uint8_t SR;
} rst_t;

typedef struct {
  __IO uint8_t CKDIVR;
  __IO uint8_t reserved[2];
  __IO uint8_t PCKENR;
  __IO uint8_t reserved1;
  __IO uint8_t CCOR;
} clk_t;

typedef struct {
  __IO uint8_t KR;
  __IO uint8_t PR;
  __IO uint8_t RLR;
} iwdg_t;

typedef struct {
  __IO uint8_t CSR;
  __IO uint8_t APR;
  __IO uint8_t TBR;
} awu_t;

typedef struct {
  __IO uint8_t CSR;
} beep_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t ICR;
  __IO uint8_t SR;
  __IO uint8_t DR;
} spi_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t FREQR;
  __IO uint8_t OARL;
  __IO uint8_t OARH;
  __IO uint8_t reserved;
  __IO uint8_t DR;
  __IO uint8_t SR1;
  __IO uint8_t SR2;
  __IO uint8_t SR3;
  __IO uint8_t ITR;
  __IO uint8_t CCRL;
  __IO uint8_t CCRH;
  __IO uint8_t TRISER;
} i2c_t;

typedef struct {
  __IO uint8_t SR;
  __IO uint8_t DR;
  __IO uint8_t BRR1;
  __IO uint8_t BRR2;
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t CR3;
  __IO uint8_t CR4;
} usart_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t SMCR;
  __IO uint8_t ETR;
  __IO uint8_t IER;
  __IO uint8_t SR1;
  __IO uint8_t SR2;
  __IO uint8_t EGR;
  __IO uint8_t CCMR1;
  __IO uint8_t CCMR2;
  __IO uint8_t CCER1;
  __IO uint8_t CNTRH;
  __IO uint8_t CNTRL;
  __IO uint8_t PSCR;
  __IO uint8_t ARRH;
  __IO uint8_t ARRL;
  __IO uint8_t CCR1H;
  __IO uint8_t CCR1L;
  __IO uint8_t CCR2H;
  __IO uint8_t CCR2L;
  __IO uint8_t BKR;
  __IO uint8_t OISR;
} tim_general_t;

typedef struct {
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t SMCR;
  __IO uint8_t IER;
  __IO uint8_t SR1;
  __IO uint8_t EGR;
  __IO uint8_t CNTR;
  __IO uint8_t PSCR;
  __IO uint8_t ARR;
} tim_basic_t;

typedef struct {
  __IO uint8_t CR;
} irtim_t;

typedef struct {
  __IO uint8_t CR;
  __IO uint8_t CSR;
  __IO uint8_t CCS;
} comp_t;

typedef struct {
  __IO uint8_t A;
  __IO uint8_t PCE;
  __IO uint8_t PCH;
  __IO uint8_t PCL;
  __IO uint8_t XH;
  __IO uint8_t XL;
  __IO uint8_t YH;
  __IO uint8_t YL;
  __IO uint8_t SPH;
  __IO uint8_t SPL;
  __IO uint8_t CC;
} cpu_t;

typedef struct {
  __IO uint8_t GCR;
} cfg_t;

typedef struct {
  __IO uint8_t SPR1;
  __IO uint8_t SPR2;
  __IO uint8_t SPR3;
  __IO uint8_t SPR4;
  __IO uint8_t SPR5;
  __IO uint8_t SPR6;
  __IO uint8_t SPR7;
  __IO uint8_t SPR8;
} spr_t;

typedef struct {
  __IO uint8_t CSR;
} swim_t;

typedef struct {
  __IO uint8_t BK1RE;
  __IO uint8_t BK1RH;
  __IO uint8_t BK1RL;
  __IO uint8_t BK2RE;
  __IO uint8_t BK2RH;
  __IO uint8_t BK2RL;
  __IO uint8_t CR1;
  __IO uint8_t CR2;
  __IO uint8_t CSR1;
  __IO uint8_t CSR2;
  __IO uint8_t ENFCTR;
} dm_t;

#define GPIOA  ((gpio_t*)0x005000)
#define GPIOB  ((gpio_t*)0x005005)
#define GPIOC  ((gpio_t*)0x00500A)
#define GPIOD  ((gpio_t*)0x00500F)
#define FLASH  ((flash_t*)0x005050)
#define EXTI   ((exti_t*)0x0050A0)
#define WFE    ((wfe_t*)0x0050A6)
#define RST    ((rst_t*)0x0050B0)
#define CLK    ((clk_t*)0x0050C0)
#define IWDG   ((iwdg_t*)0x0050E0)
#define AWU    ((awu_t*)0x0050F0)
#define BEEP   ((beep_t*)0x0050F3)
#define SPI    ((spi_t*)0x005200)
#define I2C    ((i2c_t*)0x005210)
#define USART  ((usart_t*)0x005230)
#define TIM2   ((tim_general_t*)0x005250)
#define TIM3   ((tim_general_t*)0x005280)
#define TIM4   ((tim_basic_t*)0x0052E0)
#define IRTIM  ((irtim_t*)0x0052FF)
#define COMP   ((comp_t*)0x005300)
#define CPU    ((cpu_t*)0x007F00)
#define CFG    ((cfg_t*)0x007F60)
#define SPR    ((spr_t*)0x007F70)
#define SWIM   ((swim_t*)0x007F80)
#define DM     ((dm_t*)0x007F90)


#define rim()   {__asm__("rim\n");}  /* set main interrupt level to min (enable interrupts) */
#define sim()   {__asm__("sim\n");}  /* set main interrupt level to max (disable interrupts) */
#define nop()   {__asm__("nop\n");}  /* does nothing (literally) */
#define trap()  {__asm__("trap\n");} /* calls the trap interrupt handler (as if there was an exception) */
#define wfi()   {__asm__("wfi\n");}  /* Wait For Interrupt */
#define halt()  {__asm__("halt\n");} /* Halt */


#endif