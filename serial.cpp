/*Header File--------------------------------------------------------------------------*/
#include "serial.h"

/*Private Variables--------------------------------------------------------------------*/
Serial pc(USBTX,USBRX);

//Private Functions--------------------------------------------------------------------*/
//Reads the next byte in readable serial
unsigned char read_byte(void)
{
	DigitalOut(LED_BLUE,1);
	DigitalOut(LED_RED,0);
	return pc.getc();
}

void write_byte(unsigned char byte)
{
	pc.putc(byte);
}

//Flushes all readable serial
void flush_serial(void)
{
	while(pc.readable())
	{
		pc.getc();
	}
	return;
}
