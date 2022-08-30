/*
 * Servo.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Hussam Hamdy
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include"stm32f1xx_hal.h"

/*
 * 1-set clock to 8 MHZ
 * 2-set prescalar to 16-1----> timFreq = 8Mhz / 16 = 500Khz
 * 3-set counter period to 10000-1-----> timFreq/100000 = 50 hz
 * */
void Servo_voidStart(TIM_HandleTypeDef *LOC_TimHandle , uint8_t tim_channel , uint8_t Servo_Angel);

void Servo_voidStop(TIM_HandleTypeDef *LOC_TimHandle , uint8_t tim_channel );


#endif /* INC_SERVO_H_ */
