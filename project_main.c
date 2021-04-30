/**
 * @file main.c
 * @author (256217)Vivek Kumar Yadav
 * @brief Project to define a seat heater systems for passenger occupancy
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "Activity_1.h"
#include "Activity_2.h"
#include "Activity_3.h"
#include "Activity_4.h"

/**
 * @brief Initialize all the Peripherals and pin configurations
 *
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	//DDRB |= (1 << DDB0);
}

/**
 * @brief Main function where the code execution starts
 *
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
	    while(1)
	    {
	    int occupancy=0;
	    occupancy = Activity_1();
	    if(occupancy==1)
	    {
	        uint16_t temp=0;
	        temp=ReadADC(0);
	        Activity_3();
	        Display(temp);

    }
    }
    return 0;
	/* Initialize Peripherals
	peripheral_init();

	for(;;)
	{
        change_led_state(LED_ON);
		delay_ms(LED_ON_TIME);

        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
	}
	return 0;*/
}
