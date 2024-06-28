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

#define BOARD "BLUEPILL"

// Base thread frequency
uint32_t base_freq_config = 30000;

//Base thread objects - Stepgens, encoders, and RC servos supported here

StepgenConfig StepgenConfigs[] = {{"X-Axis", 0, "PB_11", "PB_10"} //Comment, joint number, step pin, dir pin, enable pin
                                 };

EncoderConfig EncoderConfigs[] = {};
//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI



DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PA_11", PULLNONE, true, 0}}; //Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {};             
PWMPinConfig PWMConfigs[] = {};        

BlinkPinConfig BlinkConfigs[] = {};    


const char* PRU_Reset_Pin = "PA_3";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif