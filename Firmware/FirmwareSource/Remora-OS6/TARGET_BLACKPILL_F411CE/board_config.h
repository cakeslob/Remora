#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H

#include "pin.h"


struct StepgenConfig {
    const char* Comment;
    const int JointNumber;
    const char* StepPin;
    const char* DirectionPin;
}; 

struct EncoderConfig {
    const char* Comment;
    const char* PinA;
    const char* PinB;
    const int Modifier; // OPENDRAIN, PULLUP, PULLDOWN, PULLNONE, NONE
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

#define BOARD "BLACKPILL F411"

// Base thread frequency
uint32_t base_freq_config = 40000;

//Base thread objects - Stepgens, encoders, and RC servos supported here

StepgenConfig StepgenConfigs[] = {{"X-Axis", 0, "PA_1", "PA_2"}, 
                                  {"Y-Axis", 1, "PA_3", "PA_4"},
                                  {"Z-Axis", 2, "PA_5", "PA_6"} //Comment, joint number, step pin, dir pin, enable pin
                                 };

EncoderConfig EncoderConfigs[] = {};
//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI



DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PB_6", PULLUP, false, 0},
                                {"Y_LIMIT", "PB_5", PULLUP, false, 1},
                                {"Z_LIMIT", "PB_4", PULLUP, false, 2}, 
                                {"AUX0", "PB_3", PULLUP, false, 3},
                                {"AUX1", "PA_15", PULLUP, false, 4}, 
                                {"USR_BUTTON", "PA_0", PULLNONE, true, 5}}; //Comment, pin, modifier, invert, data bit

//Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {{"STEP_ENA", "PA_7", PULLNONE, false, 0}, // D8
                                {"AUX0", "PB_1", PULLNONE, false, 1},
                                {"AUX1", "PB_2", PULLNONE, false, 2}};
        
PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PB_0"}};      

BlinkPinConfig BlinkConfigs[] = {};    


const char* PRU_Reset_Pin = "PA_8";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif