/*
 * LCD_I2C.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Hussam Hamdy
 */
#include "stm32f1xx_hal.h"

#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_

// OPTIONS 0 for 8BIT
//		   1 for 4bit

#define LCD_MODE 1

#define LCD_Function_4BIT_2Lines 0x28
#define LCD_Function_8BIT_2Lines 0x38

//===============LCD Commands===============//
#define LCD_MOVE_DISP_RIGHT		 					0X1C
#define LCD_MOVE_DISP_LIFT		 					0X18
#define LCD_MOVE_CURSOR_RIGHT	 					0X14
#define LCD_MOVE_CURSOR_LIFT	 					0X10
#define LCD_DISP_OFF_CURSOR_OFF					    0X08
#define LCD_DISP_ON_CURSOR_OFF						0X0C
#define LCD_DISP_ON_CURSOR_ON						0X0E
#define LCD_DISP_ON_CURSOR_BLINK		 			0X0F
#define LCD_ENTRY_MODE		 				    	0X06
#define LCD_ENTRY_DEC	 						    0X04
#define LCD_ENTRY_DEC_SHIFT		 					0X05
#define LCD_ENTRY_INC		 					    0X06
#define LCD_ENTRY_INC_SHIFT	 					    0X07
#define LCD_BEGIN_AT_FIRST_RAW	 					0X80
#define LCD_BEGIN_AT_SECOND_RAW	 					0XC0
#define LCD_CLEAR_SCREEN		 					0X01
#define LCD_RETURN_HOME	 							0X02
//========================================================//
#define   Four_bit 0
#define   Eight_bit 1

#define LCD_ADDRESS 0x4E



void LCD_voidInit(I2C_HandleTypeDef *I2C_Handle);

void LCD_voidSendCmd(char Loc_Cmd);
void LCD_voidSendChar(char Loc_Char);

void LCD_voidClear (void);

void LCD_voidMoveCursor(uint8_t row, uint8_t col);

void LCD_voidSendStr (char *str);


#endif /* INC_LCD_I2C_H_ */
