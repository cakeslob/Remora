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

#define BOARD "NUCLEO_F401RE CNC SHIELD"
// Base thread frequency
uint32_t base_freq_config = 40000;

//Base thread objects - Stepgens, encoders, and RC servos supported here
//Comment, joint number, step pin, dir pin, 
 
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4"}, // D2,D5
                                    {"Y-Axis", 1, "PB_3", "PB_10"},// D3,D6
                                    {"Z-Axis", 2, "PB_5", "PA_8"},// D4,D7
                                    {"A-Axis", 3, "PA_6", "PA_5"}};// D12,D13

EncoderConfig EncoderConfigs[] = {{"X-axis", "PC_10", "PC_12", PULLNONE},
                                  {"Y-axis", "PC_11", "PD_2", PULLNONE},
                                  {"Z-axis", "PC_2", "PC_3", PULLNONE}};
                                  
//EncoderConfig EncoderConfigs[] = {};

//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI

//Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {{"STEP_ENA", "PA_9", PULLUP, true, 0}, // D8
                                {"AUX0", "PC_9", PULLNONE, false, 1},
                                {"AUX1", "PC_8", PULLNONE, false, 2}};
 //Comment, pin, modifier, invert, data bit
DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PC_7", PULLUP, false, 0}, // D9
                                {"Y_LIMIT", "PB_6", PULLUP, false, 1}, // D10
                                {"Z_LIMIT", "PA_7", PULLUP, false, 2}, // D11
                                {"ABORT", "PA_0", PULLUP, false, 3}, // A0
                                {"HOLD", "PA_1", PULLUP, false, 4}, // A1
                                {"RESUME", "PA_4", PULLUP, false, 5}, // A2
                                {"COOLANT", "PB_0", PULLUP, false, 6}};  // A3



//PWMPinConfig PWMConfigs[] = {};        
PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PC_6"}};

BlinkPinConfig BlinkConfigs[] = {};    

const char* PRU_Reset_Pin = "PB_2";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif