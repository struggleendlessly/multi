#include "IRQHandlers.h"

extern uint32_t wait_before_start_motors_count;
extern uint32_t wait_before_start_motors_etalon;

float_t resiver_pulse = RESIVER_PULSE;

// BEGIN Main motors
uint32_t motor_1;
uint32_t motor_2;
uint32_t motor_3;
uint32_t motor_4;

uint32_t motor_begin = 0;
float_t motor_koef = 1.0;
float_t motor_etalon_koef = 0;
float_t motor_etalon= MOTOR_ETALON;

float_t motor_1_koef = MOTOR_1_KOEF;
float_t motor_2_koef = MOTOR_2_KOEF;
float_t motor_3_koef = MOTOR_3_KOEF;
float_t motor_4_koef = MOTOR_4_KOEF;
// END Main motors

// BEGIN Servo back and forth
uint32_t servoBackForth_1;
uint32_t servoBackForth_2;
uint32_t servoBackForth_3;
uint32_t servoBackForth_4;

uint32_t servoBackForth_begin = 0;
uint32_t servoBackForth_difference = 1500;
uint32_t servoBackForth_difference_temp = 1500;
float_t servoBackForth_koef = 1.0;
float_t servoBackForth_etalon_koef = 0;
float_t servoBackForth_etalon= SERVO_BACK_FORTH_ETALON;

float_t servoBackForth_1_koef = SERVO_BACK_FORTH_1_KOEF;
float_t servoBackForth_2_koef = SERVO_BACK_FORTH_2_KOEF;
float_t servoBackForth_3_koef = SERVO_BACK_FORTH_3_KOEF;
float_t servoBackForth_4_koef = SERVO_BACK_FORTH_4_KOEF;
// END Servo back and forth


// Channel 1 Left/Right (Big) (Right joystick)
void EXTI0_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line0) != RESET)
    {

    	/* Clear interrupt flag */
    	EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

// Channel 2 Up/Down (Big) (Right joystick)
void EXTI1_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line1) != RESET)
    {
    	/* Clear interrupt flag */
    	EXTI_ClearITPendingBit(EXTI_Line1);

    	servoBackForth_difference_temp = TIM3->CNT - servoBackForth_begin;

    	if(servoBackForth_difference_temp < 2000)
    	{
            /*
    		if(abs(servoBackForth_difference_temp - servoBackForth_difference) > servoBackForth_difference/10){
    			if(servoBackForth_difference_temp - servoBackForth_difference > 0 )
    			{
    				servoBackForth_difference = servoBackForth_difference + servoBackForth_difference/10;
    			}
    			else {
    				servoBackForth_difference = servoBackForth_difference - servoBackForth_difference/10;
				}
    		}
    		else {
    			servoBackForth_difference = servoBackForth_difference_temp;
			}*/
    		servoBackForth_difference = servoBackForth_difference_temp;
    		servoBackForth_koef = servoBackForth_difference / resiver_pulse;
    		servoBackForth_etalon_koef = servoBackForth_koef * servoBackForth_etalon;

    		servoBackForth_1 = servoBackForth_etalon_koef + servoBackForth_1_koef;
    		servoBackForth_2 = servoBackForth_etalon_koef + servoBackForth_2_koef;
    		servoBackForth_3 = servoBackForth_etalon_koef + servoBackForth_3_koef;
    		servoBackForth_4 = servoBackForth_etalon_koef + servoBackForth_4_koef;
    	}

		TIM3->CCR1 = servoBackForth_1;
		TIM3->CCR2 = servoBackForth_2;
		TIM3->CCR3 = servoBackForth_3;
		TIM3->CCR4 = servoBackForth_4;

		servoBackForth_begin = TIM3->CNT;
    }
}

// Channel 3 Up/Down (Big) (Left joystick)
void EXTI2_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line2) != RESET)
    {
    	if((TIM4->CNT - motor_begin) < 2000)
    	{
    		motor_koef = (TIM4->CNT - motor_begin) / resiver_pulse;
    		motor_etalon_koef = motor_koef * motor_etalon;

    		motor_1 = motor_etalon_koef + motor_1_koef;
    		motor_2 = motor_etalon_koef + motor_2_koef;
    		motor_3 = motor_etalon_koef + motor_3_koef;
    		motor_4 = motor_etalon_koef + motor_4_koef;
    	}

		// wait about 4 sec for ESC init
		if(wait_before_start_motors_count == wait_before_start_motors_etalon)
		{
			SSD1289_CleanTextFont(0, 60, "wait_before_start_motors_count", Green, SYSTEM_8x16);

			TIM4->CCR1 = motor_1;
			TIM4->CCR2 = motor_2;
			TIM4->CCR3 = motor_3;
			TIM4->CCR4 = motor_4;
		}

    	motor_begin = TIM4->CNT;
    	/* Clear interrupt flag */
    	EXTI_ClearITPendingBit(EXTI_Line2);
    }
}

// Channel 4 Left/Right (Big) (Left joystick)
void EXTI3_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line3) != RESET)
    {

    	/* Clear interrupt flag */
    	EXTI_ClearITPendingBit(EXTI_Line3);
    }
}

// Channel 5 switch C PD4
// Position UP		945
// Position MID		1500
// Position DOWN	2055
void EXTI4_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line4) != RESET)
    {

    	/* Clear interrupt flag */
    	EXTI_ClearITPendingBit(EXTI_Line4);
    }
}

// Channels 6-10
void EXTI9_5_IRQHandler(void) {
	// Channel 6 VR(A) PD5
	// Round control
	// Position LEFT	945
	// Position RIGHT	2055
	if (EXTI_GetITStatus(EXTI_Line5) != RESET) {


		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line5);
	}

	// Channel 7 VR(C) PD6
	// Round control
	// Position LEFT	945
	// Position RIGHT	2055
	if (EXTI_GetITStatus(EXTI_Line6) != RESET) {


		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line6);
	}

	// Channel 8 VR(B) PD7
	// Round control
	// Position LEFT	945
	// Position RIGHT	2055
	if (EXTI_GetITStatus(EXTI_Line7) != RESET) {


		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line7);
	}

	// Channel 9 switch B PD8
	// Position UP		1004
	// Position DOWN	2005
	if (EXTI_GetITStatus(EXTI_Line8) != RESET) {


		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line8);
	}

	// Channel 10 switch A PD9
	// Position UP		1005
	// Position DOWN	2010
	if (EXTI_GetITStatus(EXTI_Line9) != RESET) {


		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line9);
	}

	uint16_t hc_sr04_begin = 0;
	uint16_t hc_sr04_dif = 0;
	// HC-SR04
	if (EXTI_GetITStatus(EXTI_Line10) != RESET) {

		if(TIM3->CNT < hc_sr04_begin){
			hc_sr04_dif = (65535 - hc_sr04_begin) + TIM3->CNT;
		}
		else {
			hc_sr04_dif = TIM3->CNT - 0;
		}

		hc_sr04_begin = TIM3->CNT;
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}
