#include <avr/io.h>
#include <util/delay.h>
#include "Activity_2.h"
/**
 * @file Activity_2.c
 * @author (256217)Vivek Kumar Yadav
 * @brief Initialising pins and channel to ADC conversions for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 *
 */

void InitADC()
{
    ADMUX=(1<<REFS0); //for Aref=AVcc(REFS0 for 1024 resolution)
    ADCSRA=(1<<ADEN)|(7<<ADPS0);// enabling ADC|128 FCPU prescalar value
}
uint16_t ReadADC(uint8_t ch)
{
    InitADC();
    //select ADC channel ch must be 0-7
    ADMUX&=0xf8;//clear last 3 bits
    ch=ch&0b00000111; // set channel number
    ADMUX|=ch; //assign mux value based on channel
    //Start Single conversion
    ADCSRA|=(1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA&(1<<ADIF)));
    //clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF); //set flag
    return(ADC);
}
