/*
 * Delayus.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Hussam Hamdy
 */

#ifndef INC_DELAYUS_H_
#define INC_DELAYUS_H_

#include "stm32f1xx_hal.h"
/*
 * Set clock to 8Mhz
 * Set prescalar to 8-1
 * set ARR 0xffff-1
 */
void Delayus_voidInit(TIM_HandleTypeDef *TimHandle);
void Delayus (uint16_t us);
#endif /* INC_DELAYUS_H_ */
