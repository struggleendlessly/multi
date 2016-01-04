#include "Tim3Init.h"

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"

GPIO_InitTypeDef 		GPIO_InitStruct;
TIM_TimeBaseInitTypeDef TIM_BaseStruct;
NVIC_InitTypeDef        NVIC_InitStructure;
TIM_OCInitTypeDef 		TIM_OCStruct;

uint32_t Motor_pulse_begin = MOTOR_PULSE_BEGIN;

// PD12-PD15
void TM_LEDS_Init(void) {
	/* Clock for GPIOD */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	/* Alternating functions for pins */
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	/* Set pins */
	GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_ |
								GPIO_Pin_13 |
								GPIO_Pin_14 |
								GPIO_Pin_15;

	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void TM_TIMER_Init(void) {
	/* Enable clock for TIM4 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	//generate 1Mz frequency
	uint16_t PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 1000000) - 1;

	/* Count up */
	TIM_BaseStruct.TIM_Prescaler = PrescalerValue;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = 20000-1; /* 50Hz PWM */
    TIM_BaseStruct.TIM_ClockDivision = 0;
    //TIM_BaseStruct.TIM_RepetitionCounter = 0;

	/* Initialize TIM4 */
    TIM_TimeBaseInit(TIM4, &TIM_BaseStruct);
	/* Start count on TIM4 */
    TIM_Cmd(TIM4, ENABLE);
}

void TM_PWM_Init(void) {
	/* PWM mode 2 = Clear on compare match */
	/* PWM mode 1 = Set on compare match */
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCStruct.TIM_Pulse = Motor_pulse_begin-1;
	TIM_OC1Init(TIM4, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = Motor_pulse_begin-1;
	TIM_OC2Init(TIM4, &TIM_OCStruct);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = Motor_pulse_begin-1;
	TIM_OC3Init(TIM4, &TIM_OCStruct);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = Motor_pulse_begin-1;
	TIM_OC4Init(TIM4, &TIM_OCStruct);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
}

void TM_NVIC_Init(void) {
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

uint32_t wait_before_start_motors_count = 0;
uint32_t wait_before_start_motors_etalon = WAIT_BEFORE_START_MOTORS_ETALON;

// TIM4_IRQ wait about 4 seconds for ESC init
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);

		if(wait_before_start_motors_count != wait_before_start_motors_etalon)
		{
			wait_before_start_motors_count ++;
		}
	}
}


// Init TIM4 for main motors
void Tim4Init()
{
	/* Init leds */
	TM_LEDS_Init();

	/* Init timer */
	TM_TIMER_Init();

	/* Init PWM */
	TM_PWM_Init();

	/* Init NVIC */
	TM_NVIC_Init();
}
