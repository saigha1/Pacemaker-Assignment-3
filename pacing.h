/*Module Includes----------------------------------------------------------------------*/
#include "mbed.h"
#include "motion.h"

/*Getters and Setters------------------------------------------------------------------*/
unsigned char get_pacingstate(void);
unsigned char get_pacingmode(void);
int get_lower_rate_limit(void);
int get_upper_rate_limit(void);
int get_max_sensor_rate(void);
float get_v_pace_amp(void);
float get_v_pulse_width(void);
void set_pacingstate(unsigned char input);
void set_pacingmode(unsigned char input);
void set_lower_rate_limit(int input);
void set_upper_rate_limit(int input);
void set_max_sensor_rate(int input);
void set_v_pace_amp(float input);
void set_v_pulse_width(float input);


/*Private Functions--------------------------------------------------------------------*/
void init_pwm(void);
void deinit_pwm(void);
