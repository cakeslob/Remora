# Remora Static Config

This is a test branch to try out target based static configs, ported from Expatria-Technologies/remora-flexi-hal  <https://github.com/Expatria-Technologies/remora-flexi-hal>

My intentions with this is to be able to merge this with the rest of remora, but that is a work in progress. I am currently using this to test things that have no SD card slot, or targets that I cannot get to work the SD card slot to work properly. 

# Remora Static Config Example

This example is using the Fystec Spider as a test unit. 
Configuring the board_config.h is similar to a standard config file.

The board configuration under the TARGET_SPIDER folder in the firmware source located here [< 
/Firmware/FirmwareSource/Remora-OS5/TARGET_SPIDER/board_config.h>](https://github.com/cakeslob/Remora/blob/static_config/Firmware/FirmwareSource/Remora-OS5/TARGET_SPIDER/board_config.h)

- Define your board name
```
#define BOARD "Expatria Flexi-HAL"
```

- Define your base thread objects - Stepgens, encoders, and RC servos supported here. Here is an example of simple stepgen. I have not tested out encoders or rc servo.

```
//Comment, joint number, step pin, dir pin, enable pin
StepgenConfig StepgenConfigs[] = {{"X-Axis", 0, "PC_11", "PC_10","PC_9" }, 
                                    {"Y-Axis", 1, "PD_8", "PB_12","PD_9" },
                                    {"Z-Axis", 2, "PD_14", "PD_13","PD_15" },
                                    {"A-Axis", 3, "PD_5", "PD_6","PD_4" },
                                    {"B-Axis", 4, "PE_6", "PC_13", "PE_5"}};
```

- Define your servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI
Sample configuration from FlexiHAL of inputs, outputs, and soft pwm. I have not yet tested the rest.


```
//Comment, pin, modifier, invert, data bit
DigitalPinConfig DOConfigs[] = {{"AUX2", "PA_4", PULLNONE, false, 0}, 
                                {"AUX3", "PA_6", PULLNONE, false, 1},
                                {"MIST", "PA_7", PULLNONE, false, 2},
                                {"AUX1", "PB_0", PULLNONE, false, 3},
                                {"SPINDLE_EN", "PB_2", PULLNONE, false, 4},
                                {"AUX0", "PB_13", PULLNONE, false, 5},
                                {"COOLANT", "PC_9", PULLNONE, false, 6},
                                {"STEP_EN", "PA_13", PULLNONE, false, 7},
                                {"STEP_EN_Z", "PA_14", PULLNONE, false, 8},
                                {"SPINDLE_DIR", "PB_1", PULLNONE, true, 9}};

//Comment, pin, modifier, invert, data bit
DigitalPinConfig DIConfigs[] = {{"X_LIMIT", "PA_5", PULLNONE, true, 0}, 
                                {"A_LIMIT", "PB_6", PULLNONE, true, 1},
                                {"PROBE", "PB_7", PULLNONE, true, 2},
                                {"Y_LIMIT", "PB_9", PULLNONE, true, 3},
                                {"KPSTR", "PB_10", PULLNONE, true, 4},
                                {"DOOR", "PC_4", PULLNONE, true, 5},
                                {"HALT", "PB_12", PULLNONE, true, 6},
                                {"FD_HLD", "PC_8", PULLNONE, true, 7},
                                {"CYC_START", "PC_11", PULLNONE, true, 8},
                                {"Z_LIMIT", "PC_13", PULLNONE, true, 9},
                                {"B_LIMIT", "PC_14", PULLNONE, true, 10}}; 

PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PA_8"}};

```

- Define your PRU reset pin, this is the pin connected to the Rpi
```
const char* PRU_Reset_Pin = "PC_7";
```

>"On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here."

For these and the rest of the modules missing in the config, they will need to be added to the top before they can be configured




# Remora Flexi-HAL

This is a port of the excellent Remora firmware for the Flexi-HAL.  
https://github.com/Expatria-Technologies/Flexi-HAL

Different in this fork from the 'standard' Remora is the lack of a config file. The board has a well defined set of inputs and outputs, typically with a single function. Within the LinuxCNC component the 'pins' are named intuitively to attempt to make HAL configuration easier. Pins are defined in board_config.h and the modules loaded in main.cpp in an attempt to keep the modules unmodified for easier maintenance as they are developed upstream.

# Remora

The full documentation is at <https://remora-docs.readthedocs.io/en/latest/>

Remora is a free, opensource LinuxCNC component and Programmable Realtime Unit (PRU) firmware to allow LPC17xx and STM32F4 base controller boards to be used in conjuction with a Raspberry Pi to implement a LinuxCNC based CNC controller.

Having a low cost and accessable hardware platform for LinuxCNC is important if we want to use LinuxCNC for 3D printing for example. Having a controller box the size of the printer itself makes no sense in this applicatoin. A SoC based single board computer is ideal in this application. Although developed for 3D Printing, Remora (and LinuxCNC) is highly flexible and configurable for other CNC applications.

Remora has been in use amd development since 2017. Starting on Raspberry Pi 3B and 3B+ eventhough at the time it was percieved that the Raspberry Pi was not a viable hardware for LinuxCNC.

With the release of the RPi 4 the LinuxCNC community now supports the hardware, with LinuxCNC and Preempt-RT Kernel packages now available from the LinuxCNC repository. This now greatly simplifies the build of a Raspberry Pi based CNC controller.
