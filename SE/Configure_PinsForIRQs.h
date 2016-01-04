#ifndef __CONFIGUREPINSFORIRQ_H
#define __CONFIGUREPINSFORIRQ_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"

void Configure_PinsForIRQsInit();

#define IRQ_CH0			GPIO_Pin_0
#define IRQ_CH1			GPIO_Pin_1
#define IRQ_CH2			GPIO_Pin_2
#define IRQ_CH3			GPIO_Pin_3
#define IRQ_CH4			GPIO_Pin_4

#define IRQ_CH5			GPIO_Pin_5
#define IRQ_CH6			GPIO_Pin_6
#define IRQ_CH7			GPIO_Pin_7
#define IRQ_CH8			GPIO_Pin_8
#define IRQ_CH9			GPIO_Pin_9

#define IRQ_PORT_Part1	        GPIOD
#define IRQ_EXTI_PORT_Part1	    EXTI_PortSourceGPIOD
#define IRQ_RCC_AHB_PORT_Part1	RCC_AHB1Periph_GPIOD

#endif
