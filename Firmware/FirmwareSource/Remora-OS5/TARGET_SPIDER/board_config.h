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

};


//Module config

#define BOARD "Expatria Flexi-HAL"

//Base thread objects - Stepgens, encoders, and RC servos supported here

StepgenConfig StepgenConfigs[] = {{"X-Axis", 0, "PC_11", "PC_10","PC_9" }, //Comment, joint number, step pin, dir pin, enable pin
                                    {"Y-Axis", 1, "PD_8", "PB_12","PD_9" },
                                    {"Z-Axis", 2, "PD_14", "PD_13","PD_15" },
                                    {"A-Axis", 3, "PD_5", "PD_6","PD_4" },
                                    {"B-Axis", 4, "PE_6", "PC_13", "PE_5"}};


//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI



DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PA_1", PULLNONE, true, 0}}; //Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {};             
PWMPinConfig PWMConfigs[] = {};        



const char* PRU_Reset_Pin = "PC_7";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif