/*
 * Usart.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Hussam Hamdy
 */

#include "Usart.h"
void (*LOC_PtrFun1)(void);
void (*LOC_PtrFun2)(void);
void (*LOC_PtrFun3)(void);

void Uart_voidTrans(UART_HandleTypeDef * Uart_handle,uint8_t*data , uint16_t Size){
	HAL_UART_Transmit (Uart_handle, data, Size, 10);
}

void Uart_voidReceive(UART_HandleTypeDef * Uart_handle,uint8_t*data , uint16_t Size){
	HAL_UART_Receive(Uart_handle, data, Size, 100);
}



void Uart_voidReceiveIT(UART_HandleTypeDef * Uart_handle,uint8_t*data , uint16_t Size,  void (*fun)(void) ){
	HAL_UART_Receive_IT(Uart_handle, data, Size);
	 if(Uart_handle->Instance==USART1)
		  {
			   LOC_PtrFun1=fun;

		  }
		  else   if(Uart_handle->Instance==USART2)
		  {
			  LOC_PtrFun2=fun;

		  }
		  else   if(Uart_handle->Instance==USART3)
		  {
			  LOC_PtrFun3=fun;
		  }
}




void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	  if(huart->Instance==USART1)
	  {
		   (*LOC_PtrFun1)();

	  }
	  else   if(huart->Instance==USART2)
	  {
		   (*LOC_PtrFun2)();

	  }
	  else   if(huart->Instance==USART3)
	  {
		   (*LOC_PtrFun3)();
	  }
}
