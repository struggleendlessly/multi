#ifndef __IRQHANDLERS_H
#define __IRQHANDLERS_H

#include "Tim4Init.h"

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "misc.h"
#include "math.h"
#include "stdbool.h"
#include "stdlib.h"
#include "SSD1289.h"

#define RESIVER_PULSE 					(float_t) 1497.0

// BEGIN Main motors
#define MOTOR_ETALON 					(float_t) 1650.0
#define MOTOR_1_KOEF					(float_t) 0.0
#define MOTOR_2_KOEF 					(float_t) 13.0
#define MOTOR_3_KOEF				    (float_t) 24.5
#define MOTOR_4_KOEF 					(float_t) 31.0

// BEGIN Servo back and forth
#define SERVO_BACK_FORTH_ETALON 		(float_t) 1500.0
#define SERVO_BACK_FORTH_1_KOEF			(float_t) 0.0
#define SERVO_BACK_FORTH_2_KOEF 		(float_t) 0.0
#define SERVO_BACK_FORTH_3_KOEF		    (float_t) 0.0
#define SERVO_BACK_FORTH_4_KOEF 	    (float_t) 0.0

#endif
