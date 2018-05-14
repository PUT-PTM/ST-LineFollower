#include <avr/io.h>
#include <util/delay.h>

int a = 1;
void onof(void){
	
	switch(a)
	{
		case 1:
		{
			if(OCR1A !=255)
			{
				PORTD |= _BV(PD2);
				PORTD &=~ _BV(PD3);
				OCR1A++;
				OCR1B++;
				_delay_ms(10);
			}
			else
			{
				PORTD &=~_BV(PD2);
				PORTD &=~ _BV(PD3);
				OCR1A=0;
				OCR1B=0;
				a++;
				_delay_ms(500);
			}
			break;
		}
		case 2:
		{
			if(OCR1A !=255)
			{
				PORTD |= _BV(PD3);
				PORTD &=~ _BV(PD2);
				OCR1A++;
				OCR1B++;
				_delay_ms(10);
			}
			else
			{
				PORTD &=~_BV(PD2);
				PORTD &=~ _BV(PD3);
				OCR1A=0;
				OCR1B=0;
				a=1;
				_delay_ms(500);
			}
			break;
			
		}
		
	}
	
}

int main(void)
{
	DDRB |= (1<<PB1) | (1<<PB2);
	TCCR1A |= (1<<WGM10);
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);
	//TCCR1A |= (1<<COM1A0) | (1<<COM1B0);
	TCCR1B |= (1<<CS10) | (1<<CS11);
	OCR1A = 0;
	OCR1B = 0;
	
	DDRD = 0b00001111;
	//PORTC = 0b00010000;
	
	PORTD |= _BV(PD3);
	PORTD &=~ _BV(PD2);
	PORTD |= _BV(PD0);
	PORTD &=~ _BV(PD1);
	
	

	while (1)
	{
		 if (bit_is_clear(PIND, 6) || bit_is_clear(PIND, 5))
		 {
			 OCR1A = 255;
			 OCR1B = 255;
		 }
		 else
		 {
			 OCR1A = 0;
			 OCR1B = 0;
			 
		 }
		
		
	}
	return 0;
}
