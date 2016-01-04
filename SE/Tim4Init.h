#ifndef __TIM4INIT_H
#define __TIM4INIT_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"

#define TIM4_MOTOR_PULSE_BEGIN (uint32_t) 900
#define WAIT_BEFORE_START_MOTORS_ETALON (uint32_t) 250

void Tim4Init();

#define Tim4_CH1			GPIO_Pin_6
#define Tim4_CH2			GPIO_Pin_7
#define Tim4_CH3			GPIO_Pin_8
#define Tim4_CH4			GPIO_Pin_9

#define Tim4_PORT_Part1		 GPIOB

#endif
