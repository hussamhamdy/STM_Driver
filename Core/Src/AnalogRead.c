/*
 * AnalogRead.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Hussam Hamdy
 */


#include "AnalogRead.h"

void (*LOC_PtrFun1)(void);
void (*LOC_PtrFun2)(void);

void AnalogRead(ADC_HandleTypeDef * ADC_LocHandle , uint32_t adc_val){
	HAL_ADC_Start(ADC_LocHandle); // start the adc

	HAL_ADC_PollForConversion(ADC_LocHandle, 100); // poll for conversion

	adc_val = HAL_ADC_GetValue(ADC_LocHandle); // get the adc value

	HAL_ADC_Stop(ADC_LocHandle); // stop adc


}

void AnalogReadIT(ADC_HandleTypeDef * ADC_LocHandle, void(*fun)(void)){
	 if(ADC_LocHandle->Instance==ADC1)
			  {
				   LOC_PtrFun1=fun;

			  }
			  else   if(ADC_LocHandle->Instance==ADC2)
			  {
				  LOC_PtrFun2=fun;

			  }
}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	 if(hadc->Instance==ADC1)
				  {
					   (*LOC_PtrFun1)();

				  }
				  else   if(hadc->Instance==ADC2)
				  {
					  (*LOC_PtrFun2)();

				  }
}
