#include<avr/io.h>
#define TRUE 1
#define CENTER_SENSER ((ch & (1 << PA0))>>PA0)
#define RIGHT_SENSER ((ch & (1 << PA1))>>PA1)
#define LEFT_SENSER ((ch & (1 << PA2))>>PA2)
unsigned char ch;
void right_module(void);
void left_module(void);
void center_module()
{
		robo_stop();
		if(RIGHT_SENSER && LEFT_SENSER) {
				while(!RIGHT_SENSER||!LEFT_SENSER) {
						move_backwards();
						ch = PINA;
				}
				if(!RIGHT_SENSER) {
						turn_right();
				} else {
						turn_left();
				}
				move_forward();
		}
		else {
				if(RIGHT_SENSER) {
						right_module();
				}
				if(LEFT_SENSER) {
						left_module();
				}
		}
}

void right_module()
{
		robo_stop();
		while(!RIGHT_SENSER) {
				turn_left();
				ch = PINA;
		}
		move_forward();
}

void left_module()
{
		robo_stop();
		while(!LEFT_SENSER) {
				turn_left();
				ch = PINA;
		}
		move_forward();
}

int main(void)
{
		//DDRA = 0x00;
		//DDRB = 0xFF;
		DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3);
		DDRA &= ~((1 << DDA0) | (1 << DDA1) | (1 << DDA2) | (1 << DDA3));

		PORTB = 0x00;
		init_motors();
		
		while(TRUE) {
				ch = 0x00;
				ch = PINA;
				move_forward();
				if(CENTER_SENSER) {
						center_module();
				}
				if(RIGHT_SENSER) {
						right_module();
				}
				if(LEFT_SENSER) {
						left_module();
				}
		}
}
