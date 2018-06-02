#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1<<PB1) | (1<<PB2);  //wyjœcia pwm
	TCCR1A |= (1<<WGM10);         //tryb PWM, Phase Correct, 8-bit
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);  //Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM 
	TCCR1B |= (1<<CS10) | (1<<CS11);  //Preksaler = 64
	OCR1A = 0;  //kana³ a
	OCR1B = 0;   //kana³ b
	
	DDRD = 0b00001111; //port d, piny 0,1,2,3 - out, 4,5,6,7 - in
	
	PORTD |= _BV(PD3);
	PORTD &=~ _BV(PD2);
	
	PORTD |= _BV(PD0);
	PORTD &=~ _BV(PD1);

	while (1)
	{
		if(bit_is_clear(PIND, 5) && bit_is_clear(PIND, 4))
		{
			 PORTD |= _BV(PD3);
			 PORTD &=~ _BV(PD2);
			 
			 PORTD |= _BV(PD0);
			 PORTD &=~ _BV(PD1);
			OCR1A = 255;
			OCR1B = 126;
			
		}
		else if(bit_is_clear(PIND, 5) && bit_is_clear(PIND, 6))
		{
			 PORTD |= _BV(PD3);
			 PORTD &=~ _BV(PD2);
			 
			 PORTD |= _BV(PD0);
			 PORTD &=~ _BV(PD1);
			OCR1B = 255;
			OCR1A = 126;
			
		}
		 else if (bit_is_clear(PIND, 5))
		 {
			  PORTD |= _BV(PD3);
			  PORTD &=~ _BV(PD2);
			  
			  PORTD |= _BV(PD0);
			  PORTD &=~ _BV(PD1);
			 OCR1A = 255;
			 OCR1B = 255;
			
		 }
		 else if(bit_is_clear(PIND, 4))
		 {
			 PORTD |= _BV(PD3);
			 PORTD &=~ _BV(PD2);
			 
			 PORTD |= _BV(PD1);
			 PORTD &=~ _BV(PD0);
			 
			 
			 OCR1A = 200;
			 OCR1B = 255;
			 
		 }
		 else if(bit_is_clear(PIND, 6))
		 {
			PORTD |= _BV(PD2);
			PORTD &=~ _BV(PD3);
			
			PORTD |= _BV(PD0);
			PORTD &=~ _BV(PD1);
			 
			  OCR1A = 255;
			  OCR1B = 200;
			 
		 }
		 
		 
		
		
	}
	return 0;
}
