#ifndef ACTIVITY_4_H_INCLUDED
#define ACTIVITY_4_H_INCLUDED

/**
 * @file Activity_4.h
 * @author (256217)Vivek Kumar Yadav
 * @brief Initialising pins and serial monitor display of temperature as set for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */

void Display(uint16_t );
void USARTInit(uint16_t );
char USARTReadChar();
void USARTWriteChar(char );

#endif // ACTIVITY_4_H_INCLUDED
