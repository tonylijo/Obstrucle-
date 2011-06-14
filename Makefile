robo.hex: robo
	avr-objcopy -j .text -j .data -O ihex robo robo.hex
robo: robo.o motor.o
	avr-gcc -mmcu=atmega16 robo.o motor.o -o robo
robo.o:	robo.c 
	avr-gcc -mmcu=atmega16 -c robo.c
motor.o: motor.c
	avr-gcc -mmcu=atmega16 -c motor.c
