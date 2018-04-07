
#define FOSC 16000000 // Clock Speed #define BAUD 9600
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <avr/io.h>
#include <util/delay.h>  // for the delay function

void USART_Transmit( unsigned char data );
unsigned char USART_receive(void);
void change (unsigned char x);
void init (void);
void sound1 (void);
void sound2 (void);
void sound3 (void);
void sound4 (void);
void sound5 (void);
void sound6 (void);
void sound7 (void);
void sound8 (void);
void sound9 (void);
void sound10 (void);
void sound11 (void);
void sound12 (void);
void sound13 (void);
void sound14 (void);
void sound15 (void);
void sound16 (void);

int main(void)
{
	int ii;
	int n;
	int count = 1;
	char freq1[] = "Freq=440";
	char freq2[] = "Freq=460";
	char freq3[] = "Freq=480";
	char freq4[] = "Freq=490";
	char b[] = " ";
	init();
	
	while (1)
	{
		if(!(PINB & (1<<PINB0)))
		{
			count = count + 1;
		}
		if (count == 4)
		{
			count = 1;
		}
			if (count = 1)
			{
				if(!(PINB & (1<<PINB1)))
				{
					USART_putstring(&freq1);
					sound1();
					n = 1;
					_delay_ms(50);
					while (n!=5)
					{
						for (ii = 0; ii < 38; ii++) 
						{
							USART_putstring(&b);
						}
						n++;
					}
					_delay_ms(5000);
				}
				if(!(PINB & (1<<PINB2)))
				{
					USART_putstring(&freq2);
					sound2();
					n = 1;
					_delay_ms(50);
					while (n!=5)
					{
						for (ii = 0; ii < 38; ii++) 
						{
							USART_putstring(&b);
						}
						n++;
					}
					_delay_ms(5000);
				}
				if(!(PINB & (1<<PINB3)))
				{
					USART_putstring(&freq3);
					sound3();
					n = 1;
					_delay_ms(50);
					while (n!=5)
					{
						for (ii = 0; ii < 38; ii++) 
						{
							USART_putstring(&b);
						}
						n++;
					}
					_delay_ms(5000);
				}
				if(!(PINB & (1<<PINB4)))
				{
					USART_putstring(&freq4);
					sound4();
					n = 1;
					_delay_ms(50);
					while (n!=5)
					{
						for (ii = 0; ii < 38; ii++) 
						{
							USART_putstring(&b);
						}
						n++;
					}
					_delay_ms(5000);
				}
			}
			if (count = 2)
			{
				if(!(PINB & (1<<PINB1)))
				{
					sound5();
				}
				if(!(PINB & (1<<PINB2)))
				{
					sound6();
				}
				if(!(PINB & (1<<PINB3)))
				{
					sound7();
				}
				if(!(PINB & (1<<PINB4)))
				{
					sound8();
				}
			}
			if (count = 3)
			{
				if(!(PINB & (1<<PINB1)))
				{
					sound9();
				}
				if(!(PINB & (1<<PINB2)))
				{
					sound10();
				}
				if(!(PINB & (1<<PINB3)))
				{
					sound11();
				}
				if(!(PINB & (1<<PINB4)))
				{
					sound12();
				}
			}
			if (count = 4)
			{
				if(!(PINB & (1<<PINB1)))
				{
					sound13();
				}
				if(!(PINB & (1<<PINB2)))
				{
					sound14();
				}
				if(!(PINB & (1<<PINB3)))
				{
					sound15();
				}
				if(!(PINB & (1<<PINB4)))
				{
					sound16();
				}
			}
	}
}
void USART_Transmit( unsigned char data )
{
	while ( !( UCSR0A & (1<<UDRE0)) ); // UDRE0 Is an Empty Flag used to compare the Status data to see if it is empty
	UDR0 = data;					   // If it is not empty it will save data there, outputting it.
}
unsigned char USART_receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}
void USART_putstring(unsigned char *SRED)
{
	int i, tmp, stop1 = 0;
	while (stop1 != 1)
	{
		if(*(SRED + i) != '\0') // String is not at a NULL
		{
			tmp = *(SRED +i);
			USART_Transmit(tmp);    //Send the String value to transmit
			_delay_ms(1000);
		}
		else
		{
			stop1 = 1;
		}
		i++;
	}
}
void init(void)
{
	UBRR0H = (MYUBRR>>8);  //Sets the Highest Bit on the USRAT
	UBRR0L = MYUBRR;		//Sets the Lowest Bit of the USRAT
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);		// Assigns Transmit and Receive functions as UCSRB functions
	UCSR0C =(0<<USBS0) | (1<<UCSZ00)|(1<<UCSZ01);	// Assigns one Stop Bit and UCSZ0 as USCRC functions
	DDRB = 0b00000000;  // DDRB as INPUT
	PORTB = 0b00011111; // 1-5 as high
	DDRC = 0b11111111; 
}
void sound1 ()
{
	int i;
	for (i =0; i < 10000; i++)
			{
				PORTB |= (1<<PORTC1);
				_delay_ms(.8);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(.8);
			}
}
void sound2 ()
{
	int i;
	for (i =0; i < 10000; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(.85);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(.85);
			}
}
void sound3 ()
{
	int i;
	for (i =0; i < 10000; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(.9);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(.9);
			}
}
void sound4 ()
{
	int i;
	for (i =0; i < 10000; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(0.95);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(0.95);
			}
}
void sound5 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.0);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.0);
			}
}
void sound6 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.05);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.05);
			}
}
void sound7 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.1);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.1);
			}
}
void sound8 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.15);
				PORTB &= ~(1<<PORTC1);
				_delay_ms(1.15);
			}
}
void sound9 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.2);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.2);
			}
}
void sound10 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.25);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.25);
			}
}
void sound11 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.30);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.30);
			}
}
void sound12 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.35);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.35);
			}
}
void sound13 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.40);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.40);
			}
}
void sound14 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.45);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.45);
			}
}
void sound15 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.50);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.50);
			}
}
void sound16 ()
{
	int i;
	for (i =0; i < 100; i++)
			{
				PORTC |= (1<<PORTC1);
				_delay_ms(1.55);
				PORTC &= ~(1<<PORTC1);
				_delay_ms(1.55);
			}
}