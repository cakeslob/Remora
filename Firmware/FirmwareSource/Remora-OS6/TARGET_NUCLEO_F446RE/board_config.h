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

#define BOARD "NUCLEO GRBL SHIELD"

//Base thread objects - Stepgens, encoders, and RC servos supported here
//Comment, joint number, step pin, dir pin, 
 
 //446
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4"}, 
                                    {"Y-Axis", 1, "PB_3", "PB_10"},
                                    {"Z-Axis", 2, "PB_5", "PA_8"},
                                    {"A-Axis", 3, "PA_6", "PA_5"}};
                                    
/*
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4","PA_9" }, 
                                    {"Y-Axis", 1, "PB_3", "PB_10","PA_9" },
                                    {"Z-Axis", 2, "PB_5", "PA_8","PA_9" },
                                    {"A-Axis", 3, "PA_6", "PA_5","PA_9"  }};
/*
 401
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PB_4", "PC_10","PA_9" }, 
                                    {"Y-Axis", 1, "PB_10", "PB_12","PA_9" },
                                    {"Z-Axis", 2, "PA_8", "PD_13","PA_9" },
                                    {"A-Axis", 3, "PA_6", "PA_5","PA_9" }};
*/


//EncoderConfig EncoderConfigs[] = {{"X-axis", 0, "PA_13", "PA_14", PULLNONE}};
EncoderConfig EncoderConfigs[] = {{"X-axis", "PC_10", "PC_12", PULLNONE},
                                  {"Y-axis", "PC_11", "PD_2", PULLNONE},
                                  {"Z-axis", "PC_2", "PC_3", PULLNONE}};
//EncoderConfig EncoderConfigs[] = {};

//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI

DigitalPinConfig DOConfigs[] = {{"STEP_ENA", "PA_9", PULLNONE, false, 0}, //Comment, pin, modifier, invert, data bit
                                {"AUX0", "PC_9", PULLNONE, false, 1},
                                {"AUX1", "PC_8", PULLNONE, false, 2}};

DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PC_7", PULLUP, false, 0},
                                {"Y_LIMIT", "PB_6", PULLUP, false, 1},
                                {"Z_LIMIT", "PA_7", PULLUP, false, 2},
                                {"COOLANT", "PB_0", PULLUP, false, 3},
                                {"ABORT", "PA_0", PULLUP, false, 4},
                                {"HOLD", "PA_1", PULLUP, false, 5},
                                {"RESUME", "PA_4", PULLUP, false, 6}};  //Comment, pin, modifier, invert, data bit




//PWMPinConfig PWMConfigs[] = {};        
PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PC_6"}};

BlinkPinConfig BlinkConfigs[] = {};    


const char* PRU_Reset_Pin = "PB_2";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif