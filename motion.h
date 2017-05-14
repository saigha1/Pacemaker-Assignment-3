/*Library Includes---------------------------------------------------------------------*/
#include "mbed.h"
#include "FXOS8700Q.h"

/*Getters and Setters------------------------------------------------------------------*/
char get_activity_threshold(void);
int get_reaction_time(void);
int get_response_factor(void);
int get_recovery_time(void);
void set_activity_threshold(char input);
void set_reaction_time(int input);
void set_response_factor(int input);
void set_recovery_time(int input);

/*Private Functions--------------------------------------------------------------------*/
void initialize_motion(void) ;
float getX();
float getY();
float getZ();
float getMag();
