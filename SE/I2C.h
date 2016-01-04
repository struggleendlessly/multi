#ifndef __I2C_H
#define __I2C_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_rcc.h"

#define GYRO_SDA 				GPIO_Pin_7
#define GYRO_SCL				GPIO_Pin_6

#define GYRO_CTRL_PORT			GPIOB

#endif
