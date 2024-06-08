#ifndef LIB_GPIOCTRL_H
#define LIB_GPIOCTRL_H

#include <stdint.h>
#include <stddef.h>

/*** GPIO Pin Enumeration ****************************************************/
// This enum is used as binary data for pin and port addressing. 
// 0x[PIN][PORT] - 0x 0603 6th pin of port 4 (PORTD)
// NOTE: Little-Endian Architecture means value in memory is [PORT][PIN] order
typedef enum {
	GPIO_PA0      = 0x0000,
	GPIO_PA1      = 0x0100, 
	GPIO_PA2      = 0x0200, 
	GPIO_PA3      = 0x0300,
	GPIO_PA4      = 0x0400,
	GPIO_PA5      = 0x0500,
	GPIO_PA6      = 0x0600,
	GPIO_PA7      = 0x0700,

	GPIO_PB0      = 0x0001,
	GPIO_PB1      = 0x0101, 
	GPIO_PB2      = 0x0201, 
	GPIO_PB3      = 0x0301,
	GPIO_PB4      = 0x0401,
	GPIO_PB5      = 0x0501,
	GPIO_PB6      = 0x0601,
	GPIO_PB7      = 0x0701,

	GPIO_PC0      = 0x0002,
	GPIO_PC1      = 0x0102, 
	GPIO_PC2      = 0x0202, 
	GPIO_PC3      = 0x0302,
	GPIO_PC4      = 0x0402,
	GPIO_PC5      = 0x0502,
	GPIO_PC6      = 0x0602,
	GPIO_PC7      = 0x0702,

	GPIO_PD0      = 0x0003,
	GPIO_PD1      = 0x0103, 
	GPIO_PD2      = 0x0203, 
	GPIO_PD3      = 0x0303,
	GPIO_PD4      = 0x0403,
	GPIO_PD5      = 0x0503,
	GPIO_PD6      = 0x0603,
	GPIO_PD7      = 0x0703,
} gpio_pin_t;


/*** GPIO Pin Mode Enumeration ***********************************************/
typedef enum {
	INPUT_ANALOG       = 0b0000,
	INPUT_FLOATING     = 0b0100,
	INPUT_PP           = 0b1000,
	//
	OUTPUT_10MHZ_PP    = 0b0001,
	OUTPUT_10MHZ_OD    = 0b0101,
	//
	OUTPUT_2MHZ_PP     = 0b0010,
	OUTPUT_2MHZ_OD     = 0b0110,

} gpio_mode_t;


/*** GPIO Output State Enumerations ******************************************/
typedef enum {
	GPIO_LOW     = 0x00,
	GPIO_HIGH    = 0x01,
} gpio_state_t;


/*** Registers for GPIO Port *************************************************/
typedef struct {
	volatile uint32_t CFGLR;  // Configuration Register (lower)
	volatile uint32_t CFGHR;  // Configuration Register (upper)
	volatile uint32_t INDR;   // Input Data Register
	volatile uint32_t OUTDR;  // Output Data Register
	volatile uint32_t BSHR;   // Set/Reset Register
	volatile uint32_t BCR;    // Port Reset Register
	volatile uint32_t LCKR;   // Lock Register
} gpio_port_reg_t;


/*** Register Address Definitions ********************************************/
#define RCC_APB2PCENR ((volatile uint32_t *)0x40021018)

#define PORTA_GPIO_REGISTER_BASE 0x40010800
// NOTE: PORTB is not available for the CH32V003.
#define PORTB_GPIO_REGISTER_BASE 0x40010C00
#define PORTC_GPIO_REGISTER_BASE 0x40011000
#define PORTD_GPIO_REGISTER_BASE 0x40011400

#define GPIO_PORTA ((gpio_port_reg_t *)PORTA_GPIO_REGISTER_BASE)
// NOTE: PORTB is not available for the CH32V003.
#define GPIO_PORTB ((gpio_port_reg_t *)PORTB_GPIO_REGISTER_BASE)
#define GPIO_PORTC ((gpio_port_reg_t *)PORTC_GPIO_REGISTER_BASE)
#define GPIO_PORTD ((gpio_port_reg_t *)PORTD_GPIO_REGISTER_BASE)


// GPIO Port Array for easy addressing
// NOTE: Only 3 PORTs are usable in the CH32V003, 4 for other MCUs
extern gpio_port_reg_t *gpio_port_reg[4]; 

// Sets the GPIO Mode TODO:
static inline void gpio_set_mode(gpio_pin_t pin, gpio_mode_t mode)
{
	// TODO: Any pin over 8 needs to change CFGHR
	
	// Make array of uint8_t from [pin] enum. See definition for details
	uint8_t *byte = (uint8_t *)&pin;
	
	// Set the RCC Register to enable clock on the specified port
	//                 AFIO    IOPxEN
	*RCC_APB2PCENR |= (0x01 | (0x04 << byte[0]));

	// Clear then set the GPIO Config Register
	gpio_port_reg[ byte[0] ]->CFGLR &=        ~(0x0F << (4 * byte[1]));
	gpio_port_reg[ byte[0] ]->CFGLR |= (uint8_t)mode << (4 * byte[1]);
}

// NOTE: This is the fastest code possible I've found. branch-free is slower
__attribute__((always_inline)) static void inline gpio_digital_write(gpio_pin_t pin, gpio_state_t state)
{
	// Make array of uint8_t from [pin] enum. See definition for details
	uint8_t *byte = (uint8_t *)&pin;

	if(state == GPIO_HIGH)
		gpio_port_reg[ byte[0] ]->OUTDR |=  (0x01 << (byte[1]));
	if(state == GPIO_LOW)
		gpio_port_reg[ byte[0] ]->OUTDR &= ~(0x01 << (byte[1]));
}



#endif
