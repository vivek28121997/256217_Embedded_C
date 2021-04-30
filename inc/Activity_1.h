/**
 * @file Activity_1.h
 * @author 256217 Vivek Kumar Yadav
 * @brief Project to check Button Sensor for seated, then set the LED Actuator and Heater ON connected to AVR328 MCU GPIO Pin
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define F_CPU 16000000UL 	/**< to Define the Clock Frequency as 16 MHz */
#define HIGH 	(1)			/**< GPIO state HIGH */
#define LOW 	(0)			/**< GPIO state LOW */

/**
 * Include files
 */ 
#include <avr/io.h>
#include <util/delay.h>


/**
 * Function Definitions
 */

/**
 * @brief Function to configure the IO Pins for input and output
 */
void setup_io_pins(void);

/**
 * @brief Set the gpio state
 * 
 * @param port Number of the port to which the pin belongs to
 * @param pin Number of the pin in the port
 * @param state Level of the pin, HIGH or LOW
 */
void set_gpio_state(uint8_t port, uint8_t pin, uint8_t state);

/**
 * @brief Function to generate delay in micro seconds
 * 
 * @param delaytime in micro seconds
 */
void delay_ms(unsigned int delaytime);
