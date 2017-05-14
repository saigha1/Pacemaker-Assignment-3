/*Header File--------------------------------------------------------------------------*/
#include "parameters.h"

/*Structures---------------------------------------------------------------------------*/
//Structure that holds programmable values
struct prog
{
    char pacingstate;
    char pacingmode;
    int lower_rate_limit;
    int upper_rate_limit;
    int max_sensor_rate;
    float v_pace_amp;
    float v_pulse_width;
    char activity_threshold;
    int reaction_time;
    int response_factor;
    int recovery_time;
};

/*Unions-------------------------------------------------------------------------------*/
union intu
{
	int in;
	unsigned char by[2];
};

union floatu
{
	float fl;
	unsigned char by[4];
};

/*Private Variables--------------------------------------------------------------------*/
const unsigned char MODE_OFF = 0x00;
const unsigned char MODE_AAT = 0x11;
const unsigned char MODE_AOO = 0x12;
const unsigned char MODE_AAI = 0x13;
const unsigned char MODE_AOOR = 0x14;
const unsigned char MODE_AAIR = 0x15;
const unsigned char MODE_VVT = 0x21;
const unsigned char MODE_VOO = 0x22;
const unsigned char MODE_VVI = 0x23;
const unsigned char MODE_VDD = 0x24;
const unsigned char MODE_VOOR = 0x25;
const unsigned char MODE_VVIR = 0x26;
const unsigned char MODE_VDDR = 0x27;
const unsigned char MODE_DOO = 0x31;
const unsigned char MODE_DDI = 0x32;
const unsigned char MODE_DDD = 0x33;
const unsigned char MODE_DOOR = 0x34;
const unsigned char MODE_DDIR = 0x35;
const unsigned char MODE_DDDR = 0x36;

//create sructure of type prog named progStruct
prog progStruct;

//create unions of type ufloat and uint
intu intUnion;
floatu floatUnion;

/*Getters and Setters------------------------------------------------------------------*/

//Private Functions--------------------------------------------------------------------*/

//builds a structure of type prog and sets the instance variables
void build_struct(void)
{
    //read pacing mode
    progStruct.pacingmode = read_byte();
	
	//switch case
    switch(progStruct.pacingmode) {
    
    case(MODE_OFF):
    	//assign all parameters to zero
    	break;
    	
	case(MODE_AAT):
		//Mode AAT
		break;
	
	case(MODE_AOO):
		//Mode AOO
		break;
	
	case(MODE_AAI):
		//Mode AAI
		break;
		
	case(MODE_AOOR):
		//Mode AOOR
		break;
		
	case(MODE_AAIR):
		//Mode AAIR
		break;
		
	case(MODE_VVT):
		//Mode VVT
		break;
	
	case(MODE_VOO):
		//Mode VOO
		break;
	
	case(MODE_VVI):
		//Mode VVI
		break;
	
	case(MODE_VDD):
		//Mode VDD
		break;
	
    case(MODE_VOOR):
        //read next 2 bytes, store in lower_rate_limit
        intUnion.by[1] = read_byte();
        intUnion.by[0] = read_byte();
        progStruct.lower_rate_limit = intUnion.in;
        //read next 2 bytes, store in upper_rate_limit
        intUnion.by[1] = read_byte();
        intUnion.by[0] = read_byte();
        progStruct.upper_rate_limit = intUnion.in;
        //read next 2 bytes, store in max_sensor_rate
        intUnion.by[1] = read_byte();
        intUnion.by[0] = read_byte();
        progStruct.max_sensor_rate = intUnion.in;
        //read next 4 bytes, store in v_pace_amp
        floatUnion.by[3] = read_byte();
        floatUnion.by[2] = read_byte();
        floatUnion.by[1] = read_byte();
        floatUnion.by[0] = read_byte();
        progStruct.v_pace_amp = floatUnion.fl;
        //read next 4 bytes divides int result by 1000, stores as float
        floatUnion.by[3] = read_byte();
        floatUnion.by[2] = read_byte();
        floatUnion.by[1] = read_byte();
        floatUnion.by[0] = read_byte();
        progStruct.v_pulse_width = floatUnion.fl;
        //read next byte, store in activity_threshold
        progStruct.activity_threshold = read_byte();
        //read next 2 bytes, store in reaction_time
        intUnion.by[1] = read_byte();
        intUnion.by[0] = read_byte();
        progStruct.reaction_time = intUnion.in;
        //read next 2 bytes, store in response_factor
        intUnion.by[1] = read_byte();
        intUnion.by[0] = read_byte();
        progStruct.response_factor = intUnion.in;
        //read next 2 bytes, store in recovery_time
        intUnion.by[1] = read_byte();
        intUnion.by[0] = read_byte();
        progStruct.recovery_time = intUnion.in;
		break;
	
	case(MODE_VVIR):
		//Mode VVIR
		break;
		
	case(MODE_VDDR):
		//Mode VDDR	
		break;
		
	case(MODE_DOO):
		//Mode DOO
		break;
		
	case(MODE_DDI):
		//Mode DDI
		break;
		
	case(MODE_DDD):
		//Mode DDD
		break;
		
	case(MODE_DOOR):
		//Mode DOOR
		break;
		
	case(MODE_DDIR):
		//Mode DDIR
		break;
		
	case(MODE_DDDR):
		//Mode DDDR
		break;
	
	default:
		//Default
		break;
	}
}

//returns 1 if the progStruct has valid instance variables
int verify_struct(void)
{
    if ( isValid(progStruct.lower_rate_limit , 50, 90, 1) == 0) //lower rate limit verification
    {
        return 0;
    }

    if ( isValid(progStruct.upper_rate_limit, 50, 175, 5) == 0) //upper rate limit verification
    {
        return 0;
    }

    if ( isValid(progStruct.max_sensor_rate, 50, 175, 5) == 0) //max sensor rate verification
    { 
        return 0;
    }

    if ( isValid(progStruct.v_pace_amp, 3.5, 7.0, 0.5) == 0) //pace applitude verification
    {
        return 0;
    }

    if ( isValid(progStruct.v_pulse_width,0.1, 1.9, 0.1) == 0) //pulse width verification
    {
        return 0;
    }

    if ( isValid(progStruct.reaction_time, 10, 50, 10) == 0) //reaction time verification
    {
        return 0;
    }

    if ( isValid(progStruct.response_factor, 1, 16, 1) == 0) //response factor verification
    {
        return 0;
    }

    if ( isValid(progStruct.recovery_time, 2, 16, 1) == 0) //recovery time verification
    {
        return 0;
    }
    
    return 1;
}

//function used in verift_struct (ignore)
int isValid(double value, double lower_limit, double upper_limit, double increment)
{
    double div = value/increment; //divides value by increment. if div has decimals, value is not following incrementation
    if (lower_limit <= value && value <= upper_limit && (div == (int)div) ) {
        return 1;
    }
    else {
        return 0;
    }
}

//assigns progStruct values to programmables
void assign_values(void)
{
	build_struct();
	if (verify_struct())
	{
		//Tranfers struct to parameters
		set_pacingmode(progStruct.pacingmode);
		set_lower_rate_limit(progStruct.lower_rate_limit);
		set_upper_rate_limit(progStruct.upper_rate_limit);
		set_max_sensor_rate(progStruct.max_sensor_rate);
		set_v_pace_amp(progStruct.v_pace_amp);
		set_v_pulse_width(progStruct.v_pulse_width);
		set_activity_threshold(progStruct.activity_threshold);
		set_reaction_time(progStruct.reaction_time);
		set_response_factor(progStruct.response_factor);
		set_recovery_time(progStruct.recovery_time);
	}
	else
	{
		//Keep parameters the same
	}
}

//echos programmables
void echo_values(void)
{
	//Send sync and function
	write_byte(0x16); //K_SYNC
	write_byte(0x49); //K_ECHO
	//Send pacing mode
	write_byte(get_pacingmode()); 
	//Send lower rate limit
	intUnion.in = get_lower_rate_limit();
	write_byte(intUnion.by[1]);
	write_byte(intUnion.by[0]);
	//Send upper rate limit
	intUnion.in = get_upper_rate_limit();
	write_byte(intUnion.by[1]);
	write_byte(intUnion.by[0]);
	//Send max sensor rate
	intUnion.in = get_max_sensor_rate();
	write_byte(intUnion.by[1]);
	write_byte(intUnion.by[0]);
	//Send v pace amplitude
	intUnion.in = get_v_pace_amp();
	write_byte(floatUnion.by[3]);
	write_byte(floatUnion.by[2]);
	write_byte(floatUnion.by[1]);
	write_byte(floatUnion.by[0]);
	//Send v pulse width
	intUnion.in = get_v_pulse_width();
	write_byte(floatUnion.by[3]);
	write_byte(floatUnion.by[2]);
	write_byte(floatUnion.by[1]);
	write_byte(floatUnion.by[0]);
	//Send activity threshold
	write_byte(get_activity_threshold());
	//Send reaction time
	intUnion.in = get_reaction_time();
	write_byte(intUnion.by[1]);
	write_byte(intUnion.by[0]);
	//Send response factor
	intUnion.in = get_response_factor();
	write_byte(intUnion.by[1]);
	write_byte(intUnion.by[0]);
	//Send recovery time
	intUnion.in = get_recovery_time();
	write_byte(intUnion.by[1]);
	write_byte(intUnion.by[0]);
}
