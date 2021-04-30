#include <avr/io.h>
#include "Activity_1.h"

/**
 * @file Activity_1.c
 * @author (256217)Vivek Kumar Yadav
 * @brief Project to check Button Sensor for seated, then set the LED Actuator and Heater ON connected to AVR328 MCU GPIO Pin
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

void setup_io_pins(void)
{
    SetPortB |=LED_Pin;   // set B0=1 for led(output pin high)
    SetPortD&=~Seat_Pin;   // clear bit pin D0
    PORTD|=Seat_Pin;       //set bit high for Seat pin D0
    SetPortD&=~Heater_Pin; // clear bit pin D1
    PORTD|=Heater_Pin;     //set bit high for Heater pin D1
}

void set_gpio_state(uint8_t port, uint8_t pin, uint8_t state)
{
	port = (HIGH << pin);
}


/**
 * @brief Main Function where the Code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int Activity_1(void)
{
	// setup the leds
	setup_io_pins();

	while (1)
	{	
	      if(Seat_Occupied) //both seat and heater switch press when seat occupied
	        {
	        LED_Status|=LED_Pin;
	      }
	      else{
	        LED_Status&=~LED_Pin;}
		/*set_gpio_state(LED_Status, LED_Pin, HIGH);

		set_gpio_state(LED_Status, LED_Pin, LOW);*/
	}
	return 0;
}
