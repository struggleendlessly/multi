#include "Tim4Init.h"

GPIO_InitTypeDef 		GPIO_InitStruct;
TIM_TimeBaseInitTypeDef TIM_BaseStruct;
NVIC_InitTypeDef        NVIC_InitStructure;
TIM_OCInitTypeDef 		TIM_OCStruct;

uint32_t tim4_motor_pulse_begin = TIM4_MOTOR_PULSE_BEGIN;

// PD12-PD15
void Tim4_LEDS_Init(void) {
	/* Clock for GPIOD */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	/* Alternating functions for pins */
	GPIO_PinAFConfig(Tim4_PORT_Part1, Tim4_CH1, GPIO_AF_TIM4);
	GPIO_PinAFConfig(Tim4_PORT_Part1, Tim4_CH2, GPIO_AF_TIM4);
	GPIO_PinAFConfig(Tim4_PORT_Part1, Tim4_CH3, GPIO_AF_TIM4);
	GPIO_PinAFConfig(Tim4_PORT_Part1, Tim4_CH4, GPIO_AF_TIM4);

	/* Set pins */
	GPIO_InitStruct.GPIO_Pin =  Tim4_CH1 |
								Tim4_CH2 |
								Tim4_CH3 |
								Tim4_CH4;

	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(Tim4_PORT_Part1, &GPIO_InitStruct);
}

void Tim4_TIMER_Init(void) {
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

void Tim4_PWM_Init(void) {
	/* PWM mode 2 = Clear on compare match */
	/* PWM mode 1 = Set on compare match */
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCStruct.TIM_Pulse = tim4_motor_pulse_begin-1;
	TIM_OC1Init(TIM4, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = tim4_motor_pulse_begin-1;
	TIM_OC2Init(TIM4, &TIM_OCStruct);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = tim4_motor_pulse_begin-1;
	TIM_OC3Init(TIM4, &TIM_OCStruct);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = tim4_motor_pulse_begin-1;
	TIM_OC4Init(TIM4, &TIM_OCStruct);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
}

void Tim4_NVIC_Init(void) {
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
uint32_t count = 0;

void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		count++;
		if(count == 50)
		{
			Tim3_Show();
			Tim4_Show();
			count = 0;
		}


		// TIM4_IRQ wait about 4 seconds for ESC init
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
	Tim4_LEDS_Init();

	/* Init timer */
	Tim4_TIMER_Init();

	/* Init PWM */
	Tim4_PWM_Init();

	/* Init NVIC */
	Tim4_NVIC_Init();

	Tim4_Show();
}
