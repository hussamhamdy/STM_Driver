/*
 * Keypad.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Hussam Hamdy
 */

#include "Keypad.h"
#define NOTPRESSED  0xff

Keypadpins_OP * LOC_KeypadOUT ;
Keypadpins_IN * LOC_KeypadIN ;
extern uint8_t Keypad [4][4] ;
void Keypad_voidinit (Keypadpins_OP * KeypadOUT , Keypadpins_IN * KeypadIN ){
	LOC_KeypadOUT =KeypadOUT ;
	LOC_KeypadIN =KeypadIN ;
	HAL_GPIO_WritePin(LOC_KeypadOUT->R1_GPIO_Port, LOC_KeypadOUT->R1_Pin, GPIO_PIN_SET);  //Pull the R1 low
	HAL_GPIO_WritePin(LOC_KeypadOUT->R2_GPIO_Port,LOC_KeypadOUT-> R2_Pin, GPIO_PIN_SET);  // Pull the R2 High
	HAL_GPIO_WritePin(LOC_KeypadOUT->R3_GPIO_Port,LOC_KeypadOUT-> R3_Pin, GPIO_PIN_SET);  // Pull the R3 High
	HAL_GPIO_WritePin(LOC_KeypadOUT->R4_GPIO_Port,LOC_KeypadOUT-> R4_Pin, GPIO_PIN_SET);  // Pull the R4 High
}


uint8_t Keypad_uint8Val(void){
	uint8_t Return ;
	Return=Keypad_uint8ValRow1() ;
	if (Return != NOTPRESSED){
		return Return ;
	}
	Return=Keypad_uint8ValRow2() ;
	if (Return != NOTPRESSED){
		return Return ;
	}
	Return=Keypad_uint8ValRow3() ;
	if (Return != NOTPRESSED){
		return Return ;
	}
	Return=Keypad_uint8ValRow4() ;
	if (Return != NOTPRESSED){
		return Return ;
	}
	return NOTPRESSED ;
}
static uint8_t Keypad_uint8ValRow1(void){
		HAL_GPIO_WritePin (LOC_KeypadOUT->R1_GPIO_Port, LOC_KeypadOUT->R1_Pin, GPIO_PIN_RESET);  //Pull the R1 low
		HAL_GPIO_WritePin (LOC_KeypadOUT->R2_GPIO_Port,LOC_KeypadOUT-> R2_Pin, GPIO_PIN_SET);  // Pull the R2 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R3_GPIO_Port,LOC_KeypadOUT-> R3_Pin, GPIO_PIN_SET);  // Pull the R3 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R4_GPIO_Port,LOC_KeypadOUT-> R4_Pin, GPIO_PIN_SET);  // Pull the R4 High
		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)))   // if the Col 1 is low
		{
			while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
			return Keypad[0][0];
		}

		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)));   // wait till the button is pressed
					return Keypad[0][1];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)));   // wait till the button is pressed
					return Keypad[0][2];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
					return Keypad[0][3];
				}
		return NOTPRESSED ;

}
static uint8_t Keypad_uint8ValRow2(void){
		HAL_GPIO_WritePin (LOC_KeypadOUT->R1_GPIO_Port, LOC_KeypadOUT->R1_Pin, GPIO_PIN_SET);  //Pull the R1 low
		HAL_GPIO_WritePin (LOC_KeypadOUT->R2_GPIO_Port,LOC_KeypadOUT-> R2_Pin, GPIO_PIN_RESET);  // Pull the R2 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R3_GPIO_Port,LOC_KeypadOUT-> R3_Pin, GPIO_PIN_SET);  // Pull the R3 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R4_GPIO_Port,LOC_KeypadOUT-> R4_Pin, GPIO_PIN_SET);  // Pull the R4 High
		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)))   // if the Col 1 is low
		{
			while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
			return Keypad[1][0];
		}

		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)));   // wait till the button is pressed
					return Keypad[1][1];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)));   // wait till the button is pressed
					return Keypad[1][2];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
					return Keypad[1][3];
				}
		return NOTPRESSED ;

}

static uint8_t Keypad_uint8ValRow3(void){
		HAL_GPIO_WritePin (LOC_KeypadOUT->R1_GPIO_Port, LOC_KeypadOUT->R1_Pin, GPIO_PIN_SET);  //Pull the R1 low
		HAL_GPIO_WritePin (LOC_KeypadOUT->R2_GPIO_Port,LOC_KeypadOUT-> R2_Pin, GPIO_PIN_SET);  // Pull the R2 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R3_GPIO_Port,LOC_KeypadOUT-> R3_Pin, GPIO_PIN_RESET);  // Pull the R3 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R4_GPIO_Port,LOC_KeypadOUT-> R4_Pin, GPIO_PIN_SET);  // Pull the R4 High
		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)))   // if the Col 1 is low
		{
			while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
			return Keypad [2][0];
		}

		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)));   // wait till the button is pressed
					return Keypad [2][1];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)));   // wait till the button is pressed
					return Keypad [2][2];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
					return Keypad [2][3];
				}
		return NOTPRESSED ;

}
static uint8_t Keypad_uint8ValRow4(void){
		HAL_GPIO_WritePin (LOC_KeypadOUT->R1_GPIO_Port, LOC_KeypadOUT->R1_Pin, GPIO_PIN_SET);  //Pull the R1 low
		HAL_GPIO_WritePin (LOC_KeypadOUT->R2_GPIO_Port,LOC_KeypadOUT-> R2_Pin, GPIO_PIN_SET);  // Pull the R2 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R3_GPIO_Port,LOC_KeypadOUT-> R3_Pin, GPIO_PIN_SET);  // Pull the R3 High
		HAL_GPIO_WritePin (LOC_KeypadOUT->R4_GPIO_Port,LOC_KeypadOUT-> R4_Pin, GPIO_PIN_RESET);  // Pull the R4 High
		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)))   // if the Col 1 is low
		{
			while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
			return Keypad [3][0];
		}

		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)) )  // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C2_GPIO_Port,LOC_KeypadIN->C2_Pin)));   // wait till the button is pressed
					return Keypad [3][1];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)));   // wait till the button is pressed
					return Keypad [3][2];
				}


		if (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C3_GPIO_Port,LOC_KeypadIN->C3_Pin)))   // if the Col 1 is low
				{
					while (!(HAL_GPIO_ReadPin (LOC_KeypadIN->C1_GPIO_Port,LOC_KeypadIN->C1_Pin)));   // wait till the button is pressed
					return Keypad [3][3];
				}
		return NOTPRESSED ;

}
