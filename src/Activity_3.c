#include <avr/io.h>
#include <util/delay.h>
#include "Activity_3.h"

/**
 * @file Activity_3.c
 * @author (256217)Vivek Kumar Yadav
 * @brief Initialising pins and channel to generate PWM as per assigned ADC value under conditions for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */

int Activity_3(void)
{
    unsigned volatile int ADC_value;
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);//
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10); //64 pre-scalar
    DDRB|=(1<<PB1);

    while(1)
    {
        ADC_value=ReadADC(0);
        if(ADC_value>0 && ADC_value<=200)
        {
            OCR1A=20;
        }
        else if(ADC_value>210 && ADC_value<=500)
        {
            OCR1A=40;
        }
        else if(ADC_value>510 && ADC_value<=700)
        {
            OCR1A=70;
        }
        else if(ADC_value>710 && ADC_value<=1024)
        {
            OCR1A=95;
        }
        else
        {
            OCR1A=0;
        }
    }

    return 0;
}
