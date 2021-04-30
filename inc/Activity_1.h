#ifndef ACTIVITY_1_H_INCLUDED
#define ACTIVITY_1_H_INCLUDED

/**
 * @file Activity_1.h
 * @author (256217)Vivek Kumar Yadav
 * @brief Configuration file to define pins and ports for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

/**
 * Macro Definitions
 */

#define SetPortB (DDRB)
#define LED_Status (PORTB)  //**< LED Port Number */
#define LED_Pin ((1<<PB0))  //**< LED Pin number  */
#define SetPortD (DDRD)
#define Switch_Status (PORTD)
#define Seat_Pin ((1<<PD0))
#define Heater_Pin ((1<<PD1))
#define Seat_Occupied (!(PIND&(1<<PD0))&&(!(PIND&(1<<PD1))))
void init_port();
int Activity_1();

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


#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (1000)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (500)   /**< LED OFF time in milli seconds */

/**
 * Include files
 */
#include <avr/io.h>

/**
 * Function Definitions
 */

/**
 * @brief Change the state of the LED Pin according to the value of state
 *
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state);

#endif // ACTIVITY_1_H_INCLUDED
