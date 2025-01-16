#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

uint16_t ADCRead(const int);
void USART_putstring(char* StringPtr);
void setwheel(int IN1,int IN2,int IN3,int IN4);

int main(void){

	CLKPR= 0b10000000;
	CLKPR= 0b00000000;
	DDRC = 0;
	DDRB = 0xFF;
	DDRD = 0xFF;
	
	TCCR0A = 0b10100011; // non-inverted fast PWM
	TCCR0B = 0b00000101; // p=1024
	TCCR1A = 0b10100011; // non-inverted fast PWM
	TCCR1B = 0b00000101; // p=1024
	
	ADCSRA |= (1<<ADEN);
	unsigned int BaudR = 9600;
	unsigned int ubrr = (F_CPU / (BaudR*16UL))-1;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
	UCSR0B |= (1<<TXEN0);

	while(1)
	{
		float Value1 = 0, Value2 = 0, Value3 = 0;
		
		for(int i = 0; i < 10; i++)
		{
			Value1 += (float)ADCRead(1);
			Value2 += (float)ADCRead(2);
			Value3 += (float)ADCRead(3);
		}
		Value1 /= 10; //mean of 10 readings
		Value2 /= 10; //mean of 10 readings
		Value3 /= 10; //mean of 10 readings
		
		setwheel(180,0,0,255);

		if (Value1 - Value3 > 150) //lean toward right
		{
			setwheel(180,0,0,190);
			
		}

		else if (Value3 - Value1 > 150) //lean toward left
		{
			setwheel(140,0,0,255);
		}
		else
		setwheel(180,0,0,255);
		
	}
}

uint16_t ADCRead(const int channel) {
	if(channel==1)
	ADMUX = 0b01000001;
	if(channel==2)
	ADMUX = 0b01000010;
	if(channel==3)
	ADMUX = 0b01000011;
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC) | (1<<ADIF);
	while ( (ADCSRA & (1<<ADIF)) == 0);
	ADCSRA &= ~(1<<ADSC);
	return ADC;
}


void USART_putstring(char* StringPtr){
	while(*StringPtr != 0x00){
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = *StringPtr;
		StringPtr++;
	}
}

void setwheel(int IN1,int IN2,int IN3,int IN4)
{
	OCR0A = IN1;
	OCR0B = IN2;
	OCR1A = IN3;
	OCR1B = IN4;
}

