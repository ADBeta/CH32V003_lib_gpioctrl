/******************************************************************************
* lib_gpioctrl demonstation and test ground
* Provides examples of Digital Read/Write, and Analog Read
*
* ADBeta (c)    02 Aug 2024
******************************************************************************/
#include "ch32v003fun.h"
#include <stdio.h>

#include "lib_gpioctrl.h"

int main()
{
	SystemInit();
	
	// PD6 is digital input
	// PD5 is digital output
	// PD4 (A7) is analog input
	gpio_set_mode(GPIO_PD6, INPUT_FLOATING);
	gpio_set_mode(GPIO_PD5, OUTPUT_10MHZ_PP); 
	gpio_set_mode(GPIO_PD4, INPUT_ANALOG);
	// or gpio_set_mode(GPIO_A7, INPUT_ANALOG);

	// Initiliase the ADC to use 24MHz clock, and Sample for 73 Clock Cycles
	gpio_init_adc(ADC_CLOCK_DIV_2, ADC_SAMPLE_CYCLES_73);
	
	// Read PD6's state, Toggle the state of PD5, and analog read PD4
	uint8_t d5_state = 1;
	while(1)
	{
		// Read PD6
		uint8_t d6_state = gpio_digital_read(GPIO_PD6);
	
		// Set PD5 output state
		gpio_digital_write(GPIO_PD5, d5_state);
		d5_state = !d5_state;
	
		// Read A7 pin, aka PD4
		uint16_t d4_analog = gpio_analog_read(GPIO_ADC_A7);
		
		// Print the state values
		printf("pd6: %d\tpd5:%d\tpd4: %d\n", d6_state, d5_state, d4_analog);
		
		// Wait for next loop
		Delay_Ms(250);
	}
}
