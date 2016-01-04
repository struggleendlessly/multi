#include "Tim3Init.h"

GPIO_InitTypeDef 		GPIO_InitStruct;
TIM_TimeBaseInitTypeDef TIM_BaseStruct;
NVIC_InitTypeDef        NVIC_InitStructure;
TIM_OCInitTypeDef 		TIM_OCStruct;

uint32_t tim3_motor_pulse_begin = TIM3_MOTOR_PULSE_BEGIN;

// PB4, PB5
void Tim3_PB_Init(void) {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_PinAFConfig(GPIOB, GPIO_Pin_4, GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOB, GPIO_Pin_5, GPIO_AF_TIM3);

	GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_4 |
			GPIO_Pin_5;

	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
}

// PC8, PC9
void Tim3_PC_Init(void) {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_PinAFConfig(GPIOC, GPIO_Pin_8, GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOC, GPIO_Pin_9, GPIO_AF_TIM3);

	GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_8 |
			GPIO_Pin_9;

	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void Tim3_TIMER_Init(void) {
	/* Enable clock for TIM3 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	//generate 1Mz frequency
	uint16_t PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 1000000) - 1;

	/* Count up */
	TIM_BaseStruct.TIM_Prescaler = PrescalerValue;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = 20000-1; /* 50Hz PWM */
    TIM_BaseStruct.TIM_ClockDivision = 0;
    //TIM_BaseStruct.TIM_RepetitionCounter = 0;

	/* Initialize TIM3 */
    TIM_TimeBaseInit(TIM3, &TIM_BaseStruct);
	/* Start count on TIM3 */
    TIM_Cmd(TIM3, ENABLE);
}

void Tim3_PWM_Init(void) {
	/* PWM mode 2 = Clear on compare match */
	/* PWM mode 1 = Set on compare match */
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OCStruct.TIM_Pulse = tim3_motor_pulse_begin-1;
	TIM_OC1Init(TIM3, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = tim3_motor_pulse_begin-1;
	TIM_OC2Init(TIM3, &TIM_OCStruct);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = tim3_motor_pulse_begin-1;
	TIM_OC3Init(TIM3, &TIM_OCStruct);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OCStruct.TIM_Pulse = tim3_motor_pulse_begin-1;
	TIM_OC4Init(TIM3, &TIM_OCStruct);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
}

void Tim3_NVIC_Init(void) {
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

// TIM3_IRQ
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

	}
}


// Init TIM3 for main motors
void Tim3Init()
{
	Tim3_PB_Init();
	Tim3_PC_Init();
	/* Init timer */
	Tim3_TIMER_Init();

	/* Init PWM */
	Tim3_PWM_Init();

	/* Init NVIC */
	Tim3_NVIC_Init();

}
