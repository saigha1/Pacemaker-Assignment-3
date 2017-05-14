/*Module Includes----------------------------------------------------------------------*/
#include "serial.h"
#include "pacing.h"
#include "motion.h"

//Private Functions--------------------------------------------------------------------*/
void build_struct(void);
int verify_struct(void);
int isValid(double value, double lower_limit, double upper_limit, double increment);
void assign_values(void);
void echo_values(void);
