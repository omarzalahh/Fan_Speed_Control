 /******************************************************************************
 *
 * File Name: Application.c
 *
 * Description: Source file for the Application
 *
 * Author: Omar Salah
 *
 * Date: 9/10/2021
 */
#include "lm35_sensor.h"
#include "lcd.h"
#include"motor.h"
int main(void)
{
	/*
	 * Varaiable for the adc read temperature
	 */
	uint8 temp;
	/* -initialize LCD driver
	 * -initialize Motor */
	LCD_init();
	DcMotor_Init();
	/*
	 * LCD layout initialization
	 * FAN IS ... at the first row & at the mid of the screen
	 * Temp = ...C at the second row & at the mid of the screen
	 * */
	LCD_moveCursor(0, 2);
	LCD_displayString("Fan iS ");
	LCD_moveCursor(1, 2);
	LCD_displayString("Temp =    C");

	while(1)
	{
		temp=LM35_getTemperature();//get the temperature from lm35 driver
		LCD_moveCursor(1,9);//move cursor to display the temperature value on LCD
		if(temp>=100)//condition to display the current temperature on LCD
		{
			LCD_intgerToString(temp);
		}else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(0,9);
		if(temp >= 120 )//condition to control the fan and control DC Motor speed according to given temperature
		{
			DcMotor_Rotate(cw,100);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}else if(temp >= 90)
		{
			DcMotor_Rotate(cw,75);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}else if(temp >= 60)
		{
			DcMotor_Rotate(cw,50);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}else if(temp >= 30)
		{
			DcMotor_Rotate(cw,25);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}else
		{
			DcMotor_Rotate(stop,0);
			LCD_displayString("OFF");
			LCD_displayCharacter(' ');
		}
	}

}

