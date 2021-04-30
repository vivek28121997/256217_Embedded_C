#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

/**
 * @file Activity_4.c
 * @author (256217)Vivek Kumar Yadav
 * @brief Initialising pins and serial monitor display of temperature as set for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */

/**
 * @brief USART port initializtions 
 * 
 * @param ubrr_value 
 */
void USARTInit(uint16_t ubrr_value)
{
    //set Baud rate
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)&0x00ff;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //Enable the receiver and transmitter
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

/**
 * @brief to read data from Serial monitor 
 */
char USARTReadChar()
{
    //Wait until a data is available
    while(!(UCSR0A & (1<<RXC0)))
    {
        //Do nothing
    }
    return UDR0;
}

/**
 * @brief for output display in Serial monitor 
 * 
 * @param data 
 */
void USARTWriteChar(char data)
{
    //Wait until the transmitter is ready
    while(!(UCSR0A & (1<<UDRE0)))
    {
        //Do nothing
    }
    //Now write the data to USART buffer
    UDR0=data;
}

/**
 * @brief Display Temperature as per the set value
 * 
 * @param data 
 */
void Display(uint16_t data)
{
    char data;
    DDRB|=(1<<PB0);
    USARTInit(103);

    while(1)
    {
        data=USARTReadChar();
        if (data>=0 && data<=200)
        {
            USARTWriteChar('Temperature: 20 degree Celcius')
        }
        else if (data>=210 && data<=500)
        {
            USARTWriteChar('Temperature: 25 degree Celcius')
        }
                else if (data>=510 && data<=700)
        {
            USARTWriteChar('Temperature: 29 degree Celcius')
        }
                else if (data>=710 && data<=1024)
        {
            USARTWriteChar('Temperature: 33 degree Celcius')
        }

    }

    return 0;
}
