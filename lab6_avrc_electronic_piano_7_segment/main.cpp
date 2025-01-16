/*
 * GccApplication12.cpp
 *
 * Created: 2021/4/26 下午 02:21:21
 * Author : VivoBook
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	CLKPR = (1<<CLKPCE);
	CLKPR = 0b00000000;
	
	DDRB = 0b01111111; //7 segment
	DDRD = 0b00000000; //switch 1~8
	DDRC = 0b00100000; //buzzer
	
	PORTC = 0; //default buzzer
	
	PORTD = 0xFF;
	
	while(1){
		
		PIND = 0b00000000;
		PORTB=0b01111111;
		
		if(~PIND&0b00000001)    //c
		{
			PORTB = 0b01111001;
			
			
			while (1){
				
				TCNT0 = 50 ;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
		if(~PIND&0b00000010)		//d
		{
			PORTB = 0b10100100;
			
			
			while (1){
				
				TCNT0 =  150;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
		if(~PIND&0b00000100)      //e
		{
			PORTB = 0b10110000;
			
			
			while (1){
				
				TCNT0 = 200 ;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
		if(~PIND&0b00001000)			//f
		{
			PORTB = 0b10011001;
			
			
			while (1){
				
				TCNT0 = 206 ;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
		if(~PIND&0b00010000)				//g
		{
			PORTB = 0b10010010;
			
			
			while (1){
				
				TCNT0 = 212 ;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
		if(~PIND&0b00100000)				//a
		{
			PORTB = 0b10000010;
			
			
			while (1){
				
				TCNT0 = 222;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b11011000;
				break;
			}
		}
		if(~PIND&0b01000000)				//b
		{
			PORTB = 0b11011000;
			
			
			while (1){
				
				TCNT0 = 232 ;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
		if(~PIND&0b10000000)			//c
		{
			PORTB = 0b10000000;
			
			
			while (1){
				
				TCNT0 = 238 ;
				TCCR0A = 0;
				TCCR0B = 0b00000101;
				
				while ((TIFR0 & (1<<TOV0)) == 0);
				TCCR0B = 0;
				TIFR0 = TIFR0 | (1<<TOV0);
				PORTC = PORTC^0b00100000;
				
				_delay_ms(30);
				PORTC = 0b00000000;
				break;
			}
		}
	}
	}
