#include<avr/io.h>

void init_motors(void)
{
		PORTB |= 0x0F;
}

void move_forward(void)
{
		PORTB |= ( 1 << PB0 );
		PORTB &= ( ~( 1 << PB1 ));
		PORTB &= ( ~(1 << PB2 ) );
		PORTB |= (	1 << PB3 );
}

void move_backwards(void)
{
		PORTB &= ( ~( 1 << PB0 ) );
		PORTB |= ( 1 << PB1 );
		PORTB |= ( 1 << PB2 );
		PORTB &= ( ~( 1  << PB3 ) );
}

void turn_left(void)
{
		PORTB &= ( ~( 1 << PB0 ) );
		PORTB &= ( ~( 1 << PB1 ) );
		PORTB &= ( ~( 1 << PB2 ) );
		PORTB |= ( 1 << PB3 );
}

void turn_right(void)
{
		PORTB |= (1 << PB0);
		PORTB &= ( ~(1 << PB1));
		PORTB &= ( ~(1 << PB2));
		PORTB &= ( ~(1 << PB3));
}

void robo_stop(void)
{
		PORTB &= ( ~( 1 << PB0 ) );
		PORTB &= ( ~( 1 << PB1 ) );
		PORTB &= ( ~( 1 << PB2 ) );
		PORTB &= ( ~( 1 << PB3 ) );
}
