 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#include "lm35_sensor.h"

#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* ADC config ->
		 * - choose channel 2
		 * - choose INTERNAL in micro-controller
		 * - choose polling not interrupt because it takes only 3 cycle
		 * - F_CPU / 8 = 1MHZ / 8 = 125KHZ (50 : 200 KHZ)
		 */
	ADC_configType ADC_config = {ADC2,INTERNAL,Polling,F_CPU_8_};
	ADC_init(&ADC_config); /* initialize ADC driver */
	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(&ADC_config);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

