/*
 * GccApplication5.cpp
 *
 * Created: 2021/4/16 上午 11:34:09
 * Author : VivoBook
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0b11111111;		//7-segment
	
	DDRD = 0b00000000;		//switch 7~9, 0
	DDRC = 0b00000000;		//switch 1~6
	
	PORTD = 0xFF;
	PORTC = 0xFF;
	while(1)
	{
		
		
		PINC = 0b00000000;
		PIND = 0b00000000;
		
		if (PIND&0b00000001)	//1
		{
			PORTB = 0b11111001;
		}
		if (~PIND&0b00000010)	//2
		{
			PORTB = 0b10100100;
		}
		if (~PIND&0b00000100)	//3
		{
			PORTB = 0b10110000;
		}
		if (~PIND&0b00001000)	//4
		{
			PORTB = 0b10011001;
		}
		if (~PIND&0b00010000)	//5
		{
			PORTB = 0b10010010;
		}
	    if (~PIND&0b00100000)	//6
		{
			PORTB = 0b10000010;
		}
		
		if (~PIND&0b01000000)//7
		{
			PORTB = 0b11011000;
		}
		 if (~PINC&0b00100000)//8
		{
			PORTB = 0b10000000;
		}
		 if (~PINC&0b00010000)//9
		{
			PORTB = 0b10011000;
		}
		 if(~PINC&0b00001000)//0
		{
			PORTB = 0b11000000;
		}
		else
		    PORTB = 0b11111111;

}
}




