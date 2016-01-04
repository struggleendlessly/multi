//#ifndef __TIM3INIT_H
//#define __TIM3INIT_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "stdbool.h"

#define TIM3_MOTOR_PULSE_BEGIN (uint32_t) 1500

void Tim3Init();

#define Tim3_CH1			GPIO_Pin_4
#define Tim3_CH2			GPIO_Pin_5
#define Tim3_CH3			GPIO_Pin_8
#define Tim3_CH4			GPIO_Pin_9

#define Tim4_PORT_Part1			   GPIOB
#define Tim4_PORT_Part2			   GPIOC

//#endif
