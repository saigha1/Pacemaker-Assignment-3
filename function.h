/*Module Includes----------------------------------------------------------------------*/
#include "mbed.h"
#include "serial.h"
#include "parameters.h"
#include "egram.h"


//Getters and Setters------------------------------------------------------------------*/
unsigned char get_function_code(void);

//Private Functions--------------------------------------------------------------------*/
void find_execute_Fn_Code(void);
void execute_Fn(void);
