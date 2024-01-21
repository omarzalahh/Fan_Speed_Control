 /******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: motor.h
 *
 * Description: source file for the Motor
 *
 * Author: Omar Salah
 *
 *******************************************************************************/
#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#define PORTA_MOTOR     PORTB_ID
#define PINA_MOTOR      PIN0_ID
#define PORTB_MOTOR     PORTB_ID
#define PINB_MOTOR      PIN1_ID

typedef enum{
	stop=0X00,cw=0X01,A_CW=0X10
}DcMotor_State;
void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif /* MOTOR_H_ */
