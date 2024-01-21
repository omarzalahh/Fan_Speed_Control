/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the ADC Registers */
volatile uint16 g_adcResult = 0;

ISR(ADC_vect)
{
	g_adcResult = ADC;
}

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * arguments: pointer to access the structure
 * return:void
 */
void ADC_init(const ADC_configType * config_Ptr)
{

	ADMUX = ((config_Ptr->reference)<<6);/*V ref mode*/
	SET_BIT(ADCSRA,ADEN);/*set enable bit */
	ADCSRA |= ((config_Ptr->mode)<<ADIE);/* Choose the mode between interrupt or pooling */
	ADCSRA = (ADCSRA & 0xF8) | ((config_Ptr->Division) & 0x07);/*change the pre scaler  */
}
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * arguments: pointer to access the structure
 * return:void
 */
uint16 ADC_readChannel(const ADC_configType * config_Ptr)
{
	ADMUX = (ADMUX & 0xE0) | ((config_Ptr->channel) & 0x07);/*Change the channel of the adc*/
	SET_BIT(ADCSRA,ADSC);
	if((config_Ptr->mode) == Polling)
	{
		while(BIT_IS_CLEAR(ADCSRA,ADIF));/*Pooling wait for end the reading*/
		SET_BIT(ADCSRA,ADIF);/*Clear the flag by sit it*/
	}
	return ADC;
}
