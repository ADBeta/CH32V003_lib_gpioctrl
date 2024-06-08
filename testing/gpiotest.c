#include "ch32v003fun.h"
#include <stdio.h>

#include "lib_GPIOCTRL.h"




int main()
{
	SystemInit();

	gpio_set_mode(GPIO_PD6, OUTPUT_10MHZ_PP); 


	while(1)
	{
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
