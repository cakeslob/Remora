#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H

#include "pin.h"


struct StepgenConfig {
    const char* Comment;
    const int JointNumber;
    const char* StepPin;
    const char* DirectionPin;
    const char* EnablePin;
}; 

struct DigitalPinConfig {
    const char* Comment;
    const char* Pin;
    const int Modifier; // OPENDRAIN, PULLUP, PULLDOWN, PULLNONE, NONE
    const bool Invert;
    const int DataBit;
};

struct PWMPinConfig {
    const char* Comment;
    const char* Pin;
    const int Peroid_sp;

};

struct BlinkPinConfig {
    const char* Comment;
    const char* Pin;
    const int Freq;
};

//Module config

#define BOARD "NUCLEO GRBL SHIELD"

//Base thread objects - Stepgens, encoders, and RC servos supported here
//Comment, joint number, step pin, dir pin, enable pin
//446
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4","PA_9" }, 
                                    {"Y-Axis", 1, "PB_3", "PB_10","PA_9" },
                                    {"Z-Axis", 2, "PB_5", "PA_8","PA_9" },
                                    {"A-Axis", 3, "PA_6", "PA_5","PA_9" }};

 /*  401
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PB_4", "PC_10","PA_9" }, 
                                    {"Y-Axis", 1, "PB_10", "PB_12","PA_9" },
                                    {"Z-Axis", 2, "PA_8", "PD_13","PA_9" },
                                    {"A-Axis", 3, "PA_6", "PA_5","PA_9" }};
*/


//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI



DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PC_7", PULLNONE, true, 0},
                                {"Y_LIMIT", "PB_6", PULLNONE, true, 1},
                                {"Z_LIMIT", "PA_7", PULLNONE, true, 2}}; //Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {};             
PWMPinConfig PWMConfigs[] = {};        
BlinkPinConfig BlinkConfigs[] = {};    


const char* PRU_Reset_Pin = "PB_2";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif