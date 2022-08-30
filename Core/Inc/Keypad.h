/*
 * Keypad.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Hussam Hamdy
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include "stm32f1xx_hal.h"

typedef struct {
	GPIO_TypeDef *R1_GPIO_Port ;
	GPIO_TypeDef *R2_GPIO_Port ;
	GPIO_TypeDef *R3_GPIO_Port ;
	GPIO_TypeDef *R4_GPIO_Port ;
	uint8_t R1_Pin;
	uint8_t R2_Pin;
	uint8_t R3_Pin;
	uint8_t R4_Pin;

}Keypadpins_OP;

typedef struct {
	GPIO_TypeDef *C1_GPIO_Port ;
	GPIO_TypeDef *C2_GPIO_Port ;
	GPIO_TypeDef *C3_GPIO_Port ;
	GPIO_TypeDef *C4_GPIO_Port ;
	uint8_t C1_Pin;
	uint8_t C2_Pin;
	uint8_t C3_Pin;
	uint8_t C4_Pin;

}Keypadpins_IN;
//uint8_t Keypad [4][4] = { {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A', '0','=','+'}};
uint8_t Keypad [4][4] = { {'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*', '0','#','D'}};

void Keypad_voidinit (Keypadpins_OP * KeypadOUT , Keypadpins_IN * KeypadIN );


uint8_t Keypad_uint8Val(void);

static uint8_t Keypad_uint8ValRow1(void);
static uint8_t Keypad_uint8ValRow2(void);
static uint8_t Keypad_uint8ValRow3(void);
static uint8_t Keypad_uint8ValRow4(void);

#endif /* INC_KEYPAD_H_ */
