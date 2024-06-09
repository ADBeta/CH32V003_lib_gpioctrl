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

	gpio_set_mode(GPIO_PD6, OUTPUT_10MHZ_PP); 


	while(1)
	{
		/*
		uint8_t val = (uint8_t)gpio_digital_read(GPIO_PD6);
		printf("%d val\n", val);

		Delay_Ms(250);
		*/



		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);

		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);

		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);

		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);

		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);

		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);

		gpio_digital_write(GPIO_PD6, GPIO_HIGH);
		gpio_digital_write(GPIO_PD6, GPIO_LOW);


	}
}
