/*
 * LCD_I2C.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Hussam Hamdy
 */

#include "LCD_I2C.h"


I2C_HandleTypeDef *LOC_i2c_Handle ;

void LCD_voidInit(I2C_HandleTypeDef *I2C_Handle){
	LOC_i2c_Handle = I2C_Handle ;
	HAL_Delay(50);  // wait for >40ms
	LCD_voidSendCmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	LCD_voidSendCmd (0x30);
	HAL_Delay(1);  // wait for >100us
	LCD_voidSendCmd (0x30);
	HAL_Delay(10);
	LCD_voidSendCmd (0x20);  // 4bit mode
	HAL_Delay(10);

	LCD_voidSendCmd (LCD_Function_4BIT_2Lines); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	LCD_voidSendCmd (LCD_DISP_OFF_CURSOR_OFF); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	LCD_voidSendCmd (LCD_CLEAR_SCREEN);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	LCD_voidSendCmd (LCD_ENTRY_INC); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	LCD_voidSendCmd (LCD_DISP_ON_CURSOR_OFF); //Display on/off control --> D =
}

void LCD_voidSendCmd(char Loc_Cmd){
	char data_u , data_l ;
	uint8_t data_t[4] ;
	data_u = (Loc_Cmd&0xf0);
	data_l = ((Loc_Cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (LOC_i2c_Handle, LCD_ADDRESS,(uint8_t *)data_t, 4, 100);
}
void LCD_voidSendChar(char Loc_Char){
	char data_u , data_l ;
	uint8_t data_t[4] ;
	data_u = (Loc_Char&0xf0);
	data_l = ((Loc_Char<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (LOC_i2c_Handle, LCD_ADDRESS,(uint8_t *)data_t, 4, 100);
}

void LCD_voidClear (void)
{
	LCD_voidSendCmd (LCD_CLEAR_SCREEN);
}
void LCD_voidMoveCursor(uint8_t row, uint8_t col)
{
    switch (row)
    {
        case 0:
            col |= LCD_BEGIN_AT_FIRST_RAW;
            break;
        case 1:
            col |= LCD_BEGIN_AT_SECOND_RAW;
            break;
    }
    LCD_voidSendCmd(col);
}

void LCD_voidSendStr (char *str)
{
	while(*str)LCD_voidSendChar(*str++);
}

