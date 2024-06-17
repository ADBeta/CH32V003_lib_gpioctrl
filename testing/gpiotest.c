/******************************************************************************
* lib_GPIOCTRL demonstation and test ground
* Provides examples of Digital Read/Write, TODO: Analog Read / Write
*
******************************************************************************/


#include "ch32v003fun.h"
#include <stdio.h>

#include "lib_GPIOCTRL.h"




int main()
{
	SystemInit();

	gpio_set_mode(GPIO_PD5, OUTPUT_10MHZ_PP); 
	gpio_set_mode(GPIO_PC0, INPUT_PULLDOWN); 

	while(1)
	{
		//uint8_t val = gpio_digital_read(GPIO_PC0);
		
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);
		gpio_digital_write(GPIO_PD5, GPIO_HIGH);
		gpio_digital_write(GPIO_PD5, GPIO_LOW);

		//Delay_Ms(250);
	}
}
