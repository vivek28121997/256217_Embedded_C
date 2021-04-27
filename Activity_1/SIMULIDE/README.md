# Activity_1 Project In Action

|ON|OFF|
|:--:|:--:|
|![ON](https://github.com/vivek28121997/256217_Embedded_C/blob/895443a9a9b4aca213c8213f26ca69fc81a709c5/Activity_1/SIMULIDE/ON%20(Both%20Switches%20closed).png)|![OFF](https://github.com/vivek28121997/256217_Embedded_C/blob/895443a9a9b4aca213c8213f26ca69fc81a709c5/Activity_1/SIMULIDE/OFF%20(Both%20Switches%20open).png)|
|OFF|OFF|
|![OFF](https://github.com/vivek28121997/256217_Embedded_C/blob/b7c4cac08ca5d182db38df3a118687d7dbf7c6c8/Activity_1/SIMULIDE/OFF%20(S1%20closed,%20S2%20open).png)|![OFF](https://github.com/vivek28121997/256217_Embedded_C/blob/b7c4cac08ca5d182db38df3a118687d7dbf7c6c8/Activity_1/SIMULIDE/OFF%20(S1%20open,%20S2%20closed).png)|


## Code 
```
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void led_setup(void){
	//DDRB |= (1 << DDB0);
	DDRB |=(1<<PB0); // B0=1 for led
	DDRD&=~(1<<PD0); // clear bit
	PORTD|=(1<<PD0);
	DDRD&=~(1<<PD1); // clear bit
	PORTD|=(1<<PD1);
}

void led_on(void){
	// PORTB0 is in sink config
	// Meaning when pin is ground
	// LED will turn on
	PORTB = (0 << PORTB0);
}

void led_off(void){
	// sink config
	PORTB = (1 << PORTB0);
}

void delay_ms(unsigned int delaytime){
	int i = 0;
	for(i=0; i<=delaytime; i++){
		_delay_ms(1);
	}
}

int main(void) {
	// setup the leds
	led_setup();
	
	while(1) {
		if(!(PIND&(1<<PD0))&&(!(PIND&(1<<PD1))))//switch press
	        {
	         PORTB|=(1<<PB0);
       	        }
	      else{
	           PORTB&=~(1<<PB0);}	
		  }
	return 0;
}
```
