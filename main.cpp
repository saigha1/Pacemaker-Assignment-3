#include "mbed.h"
#include "pacing.h"
#include "rtos.h"
#include "egram.h"
#include "serial.h"
#include "function.h"

extern Serial pc;

int main()
{   
    pc.attach(&find_execute_Fn_Code, Serial::RxIrq);
    while(1){Thread::wait(1000);}
}