/*
 * Delayus.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Hussam Hamdy
 */
#include "Delayus.h"


TIM_HandleTypeDef *LOC_TimHandle ;
void Delayus_voidInit(TIM_HandleTypeDef *TimHandle){
	LOC_TimHandle = TimHandle ;
	HAL_TIM_Base_Start(LOC_TimHandle);

}
void Delayus (uint16_t us){
	LOC_TimHandle->Instance->CNT =0 ;
	while(LOC_TimHandle->Instance->CNT < us );
}
