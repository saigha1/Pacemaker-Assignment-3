/*Header File--------------------------------------------------------------------------*/
#include "egram.h"

/*Threads------------------------------------------------------------------------------*/
Thread egram_thread(egram);

/*Unions-------------------------------------------------------------------------------*/
union analogu
{
    int in;
    unsigned char by[2];
};

/*Private Variables--------------------------------------------------------------------*/
bool run_egram = false;

//create AnalogIn ain
AnalogIn ain(A0);

//create union of type analogu
analogu anUnion;

/*Getters and Setters------------------------------------------------------------------*/
bool get_run_egram(void)
{
    return run_egram;
}

void set_run_egram(bool input)
{
    run_egram = input;
}

/*Private Functions--------------------------------------------------------------------*/
void egram(void)
{
    while(true)
    {
        if(run_egram)
        {
            anUnion.in = ain.read_u16();
            write_byte(0x16);
            write_byte(0x47);
            write_byte(anUnion.by[1]);
            write_byte(anUnion.by[0]);
        }
        
        Thread::wait(200);
    }
}
