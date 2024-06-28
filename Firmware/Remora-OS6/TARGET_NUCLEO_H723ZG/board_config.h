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
    const char* Pin;
    const int Freq;
};

//Module config

#define BOARD "NUCLEO_H7 CNC SHIELD"

// Base thread frequency
uint32_t base_freq_config = 80000;

//Base thread objects - Stepgens, encoders, and RC servos supported here
//Comment, joint number, step pin, dir pin, 
 
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4"}};// D12,D13


EncoderConfig EncoderConfigs[] = {};

//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI

//Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {};
 //Comment, pin, modifier, invert, data bit
DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PC_13", PULLUP, false, 0}};  // A3



PWMPinConfig PWMConfigs[] = {};        
//PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PC_6"}};

BlinkPinConfig BlinkConfigs[] = { "PE_1", 4};    
//BlinkPinConfig BlinkConfigs[] = {};    


const char* PRU_Reset_Pin = "PB_12";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif