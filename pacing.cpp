/*Header File--------------------------------------------------------------------------*/
#include "pacing.h"

/*PWM----------------------------------------------------------------------------------*/
PwmOut v_pwm(D3);
PwmOut a_pwm(D5);

/*Private Variables--------------------------------------------------------------------*/
unsigned char pacingstate = 0x00;
unsigned char pacingmode = 0x00;
int lower_rate_limit = 60;
int upper_rate_limit = 120;
int max_sensor_rate = 0;
float v_pace_amp = 1.0;
float v_pulse_width = 0.2;


/*Getters and Setters------------------------------------------------------------------*/
unsigned char get_pacingstate(void)
{
	return pacingstate;
}

unsigned char get_pacingmode(void)
{
	return pacingmode;
}

int get_lower_rate_limit(void)
{
	return lower_rate_limit;
}

int get_upper_rate_limit(void)
{
	return upper_rate_limit;
}

int get_max_sensor_rate(void)
{
	return max_sensor_rate;
}

float get_v_pace_amp(void)
{
	return v_pace_amp;
}

float get_v_pulse_width(void)
{
	return v_pulse_width;
}

void set_pacingstate(unsigned char input)
{
	pacingstate = input;
}

void set_pacingmode(unsigned char input)
{
	pacingmode = input;
}

void set_lower_rate_limit(int input)
{
	lower_rate_limit = input;
}

void set_upper_rate_limit(int input)
{
	upper_rate_limit = input;
}

void set_max_sensor_rate(int input)
{
	max_sensor_rate = input;
}

void set_v_pace_amp(float input)
{
	v_pace_amp = input;
}

void set_v_pulse_width(float input)
{
	v_pulse_width = input;
}

/*Private Functions--------------------------------------------------------------------*/
void init_pwm(void)
{
	//assign values for pwm
	v_pwm.period(lower_rate_limit/60);
	v_pwm.pulsewidth(v_pulse_width);
	v_pwm.write(v_pace_amp/5);
}

void deinit_pwm(void)
{
	//delete &v_pwm;
	//PwmOut *v_pwm = new PwmOut(D3);
}
