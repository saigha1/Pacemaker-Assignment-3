/*Header File--------------------------------------------------------------------------*/
#include "motion.h"

/*Private Variables--------------------------------------------------------------------*/
char activity_threshold = 0x00;
int reaction_time = 0;
int response_factor = 0;
int recovery_time = 0;

//set up the accelerometer
FXOS8700Q_acc acc(PTE25, PTE24 , FXOS8700CQ_SLAVE_ADDR1);

/*Getters and Setters------------------------------------------------------------------*/
char get_activity_threshold()
{
	return activity_threshold;
}

int get_reaction_time()
{
	return reaction_time;
}

int get_response_factor()
{
	return response_factor;
}

int get_recovery_time()
{
	return recovery_time;
}

void set_activity_threshold(char input)
{
	activity_threshold = input;
}

void set_reaction_time(int input)
{
	reaction_time = input;
}

void set_response_factor(int input)
{
	response_factor = input;
}

void set_recovery_time(int input)
{
	recovery_time = input;
}

/*Private Functions--------------------------------------------------------------------*/
//initialize the accelerometer 
void initialize_motion () {
    acc.enable();
}

//return x magnitude
float getX(void)
{
float x = 0;
acc.getX(&x);
return x;
} 

//return y magnitude
float getY(void)
{
float y = 0;
acc.getY(&y);
return y;
} 

//return z magnitude
float getZ(void)
{
float z = 0;
acc.getZ(&z);
return z;
} 

//return the magnitude squared
float getMag(void)
{
//usually is a value between 0 and 12
return getX()*getX()+getY()*getY()+getZ()*getZ();
}
