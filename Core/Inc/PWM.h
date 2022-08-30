/*
 * PWM.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Hussam Hamdy
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "stm32f1xx_hal.h"
/*
 * PWM.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Hussam Hamdy
 */
/*
 *
 * To Use
 * 1-clock time = (ABP2 clock / (prescalar+1))
 * 2- set ARR to 99 to get dutycycle as fraction of 100
 * 3-PWM freq = clock time /(counter period(ARR)+1)
 *
 * */
#include "PWM.h"

void PWM_voidStart(TIM_HandleTypeDef *LOC_TimHandle , uint8_t tim_channel , uint8_t DutyCycle);
void PWM_voidStop(TIM_HandleTypeDef *LOC_TimHandle , uint8_t tim_channel );


#endif /* INC_PWM_H_ */
