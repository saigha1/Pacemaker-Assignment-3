/*Header File--------------------------------------------------------------------------*/
#include "function.h"

/*Private Variables--------------------------------------------------------------------*/
//sync byte
const unsigned char K_SYNC = 0x16;

//function byte
const unsigned char K_PPARAMS = 0x55;
const unsigned char K_EGRAM = 0x47;
const unsigned char K_ECHO = 0x49;
const unsigned char K_ESTOP = 0x62;

//function code
unsigned char Fn_Code;

/*Private Functions--------------------------------------------------------------------*/

void find_execute_Fn_Code(void)
{
	DigitalOut(LED_BLUE,0);	
		
	//if first byte is sync byte
	if (read_byte() == K_SYNC)
	{
		DigitalOut(LED_RED,0);
		Fn_Code = read_byte();
		execute_Fn();
	}
	
	//if first byte is not sync byte
	else
	{
		DigitalOut(LED_GREEN,0);
		//flush serial
		flush_serial();
	}
}

void execute_Fn(void)
{
	switch(Fn_Code) {
		case K_PPARAMS:
			//assign values to programmables
			assign_values();
			break;
			
		case K_EGRAM:
			//send out egram
			//set_run_egram(true);
			break;
			
		case K_ECHO:
			//echo programmables
			echo_values();
			break;
			
		case K_ESTOP:
			//set_run_egram(false);
			break;
			
		default:
			//default
			break;
	}
}
