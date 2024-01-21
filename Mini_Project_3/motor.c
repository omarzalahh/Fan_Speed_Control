 /******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: motor.c
 *
 * Description: source file for the Motor
 *
 * Author: Omar Salah
 *
 *******************************************************************************/
#include"motor.h"
#include"common_macros.h"
#include"gpio.h"
#include"pwm.h"
PWM_configType config={TIMER_0,CLEAR_OC0,F_CPU_8};
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTA_MOTOR, PINA_MOTOR,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_MOTOR, PINB_MOTOR,PIN_OUTPUT);

	GPIO_writePin(PORTA_MOTOR, PINA_MOTOR, stop);
	GPIO_writePin(PORTA_MOTOR, PINB_MOTOR, stop);

	PWM_init(&config);
}
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	if(state == stop)//condition to determine the direction of rotation of the motor
		{
			GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
			GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		}else if(state == A_CW)
		{
			GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
			GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		}else if(state == cw)
		{
			GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
			GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		}
	PWM_changeDuty(&config,(speed*2.55));
}
