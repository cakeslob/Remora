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

#define BOARD "NUCLEO_F446ZE CNC SHIELD"

// Base thread frequency
uint32_t base_freq_config = 80000;

//Base thread objects - Stepgens, encoders, and RC servos supported here
//Comment, joint number, step pin, dir pin, 
 
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PF_15", "PE_11"}, // D2,D5
                                    {"Y-Axis", 1, "PE_13", "PE_9"}, // D3,D6
                                    {"Z-Axis", 2, "PF_14", "PF_13"}, // D4,D7
                                    {"A-Axis", 3, "PA_6", "PA_5"}}; // D12,D13

EncoderConfig EncoderConfigs[] = {{"X-axis", "PC_10", "PC_12", PULLNONE},
                                  {"Y-axis", "PC_11", "PD_2", PULLNONE},
                                  {"Z-axis", "PC_2", "PC_3", PULLNONE}};
//EncoderConfig EncoderConfigs[] = {};

//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI

//Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {{"STEP_ENA", "PF_12", PULLUP, true, 0}, // D8
                                {"AUX0", "PC_9", PULLNONE, false, 1},
                                {"AUX1", "PC_8", PULLNONE, false, 2}};
//Comment, pin, modifier, invert, data bit
DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PD_15", PULLUP, false, 0}, // D9
                                {"Y_LIMIT", "PD_14", PULLUP, false, 1}, // D10
                                {"Z_LIMIT", "PA_7", PULLUP, false, 2}, // D11
                                {"ABORT", "PA_3", PULLUP, false, 3}, // A0
                                {"HOLD", "PC_0", PULLUP, false, 4}, // A1
                                {"RESUME", "PC_3", PULLUP, false, 5}, // A2
                                {"COOLANT", "PF_3", PULLUP, false, 6}};  // A3



//PWMPinConfig PWMConfigs[] = {};        
PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PC_6"}};

BlinkPinConfig BlinkConfigs[] = {};    

const char* PRU_Reset_Pin = "PB_2";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif
