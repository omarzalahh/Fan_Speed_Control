/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/


#include "std_types.h"

extern volatile uint16 g_adcResult;
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
/*
 * Enum for ADC channel number
 */
typedef enum
{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_channel;
/*
 * Enum for the vref
 */
typedef enum
{
	AREF,AVCC,INTERNAL= 3
}ADC_reference;


typedef enum
{
	Polling,Interrupt
}ADC_mode;
/*
 * Enum for prescaler and clocks
 */
typedef enum
{
	NO_prescaler,F_CPU_2,F_CPU_4,F_CPU_8_,F_CPU_16,F_CPU_32,F_CPU_64_,F_CPU_128
}ADC_prescaler;

typedef struct
{
	ADC_channel   channel;
	ADC_reference reference;
	ADC_mode      mode;
	ADC_prescaler Division;
}ADC_configType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(const ADC_configType * config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_readChannel(const ADC_configType * config_Ptr);


#endif /* ADC_H_ */
