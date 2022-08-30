/*
 * PWM.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Hussam Hamdy
 */

#include "PWM.h"

void PWM_voidStart(TIM_HandleTypeDef *LOC_TimHandle , uint8_t tim_channel , uint8_t DutyCycle){
	if(tim_channel == 1){
	LOC_TimHandle->Instance->CCR1 = DutyCycle ;
	HAL_TIM_PWM_Start(LOC_TimHandle, TIM_CHANNEL_1);

	}
	else if(tim_channel == 2){
		LOC_TimHandle->Instance->CCR2 = DutyCycle ;
		HAL_TIM_PWM_Start(LOC_TimHandle, TIM_CHANNEL_2);
	}
	else if(tim_channel == 3){
		LOC_TimHandle->Instance->CCR3 = DutyCycle ;
		HAL_TIM_PWM_Start(LOC_TimHandle, TIM_CHANNEL_3);

		}
	else{
		LOC_TimHandle->Instance->CCR4 = DutyCycle ;
		HAL_TIM_PWM_Start(LOC_TimHandle, TIM_CHANNEL_4);
	}

}
void PWM_voidStop(TIM_HandleTypeDef *LOC_TimHandle , uint8_t tim_channel ){

		if(tim_channel == 1){
			HAL_TIM_PWM_Stop(LOC_TimHandle, TIM_CHANNEL_1);

			}
			else if(tim_channel == 2){
				HAL_TIM_PWM_Stop(LOC_TimHandle, TIM_CHANNEL_2);
			}
			else if(tim_channel == 3){
				HAL_TIM_PWM_Stop(LOC_TimHandle, TIM_CHANNEL_3);
				}
			else{
				HAL_TIM_PWM_Stop(LOC_TimHandle, TIM_CHANNEL_4);
			}
}
