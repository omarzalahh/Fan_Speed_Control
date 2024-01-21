 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the AVR PWM mode
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                        External Variables                                   *
 *******************************************************************************/

extern volatile uint8 g_initialCount_T0;
extern volatile uint16 g_initialCount_T1;
extern volatile uint8 g_initialCount_T2;

extern volatile uint8 g_OCR0;
extern volatile uint8 g_OCR1;
extern volatile uint8 g_OCR2;

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	TIMER_0,TIMER_1,TIMER_2
}PWM_timerType;

typedef enum
{
	NORMAL_OC0_DISCONNECTED,REVERSED,CLEAR_OC0,SET_OC0
}PWM_modeType;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,EXTERNAL_CLOCK_FALLING,EXTERNAL_CLOCK_RISING
}PWM_ClockType;

typedef struct
{
	PWM_timerType whichTimer;
	PWM_modeType  mode;
	PWM_ClockType clock;
}PWM_configType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void PWM_init(const PWM_configType * config_Ptr);
void PWM_changeDuty(const PWM_configType * config_Ptr,uint8 a_duty);


#endif /* PWM_H_ */
