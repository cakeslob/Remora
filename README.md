# Remora Nucleo CNC shield v3.0
This repo is for a setup using a STM Nucleo64 STM32F446 with classic CNC shield v3.0 
The configuration is for 4 axis and 3 endstops. It is a basic configuration for the time being, using the static config from Flexi-hal.
- SPI2 for connection to RPI4, with pins PB1, PB13, PB14 and PB15, and pin PB2 for reset
- the pinout configuration is loacted in /Firmware/FirmwareSource/Remora-OS6/TARGET_NUCLEO_F446RE/board_config.h
- if you wish to change the pinout, you must configure it in this file, and them recompile 

# Remora

The full documentation is at <https://remora-docs.readthedocs.io/en/latest/>

Remora is a free, opensource LinuxCNC component and Programmable Realtime Unit (PRU) firmware to allow LPC17xx and STM32F4 base controller boards to be used in conjuction with a Raspberry Pi to implement a LinuxCNC based CNC controller.

Having a low cost and accessable hardware platform for LinuxCNC is important if we want to use LinuxCNC for 3D printing for example. Having a controller box the size of the printer itself makes no sense in this applicatoin. A SoC based single board computer is ideal in this application. Although developed for 3D Printing, Remora (and LinuxCNC) is highly flexible and configurable for other CNC applications.

Remora has been in use amd development since 2017. Starting on Raspberry Pi 3B and 3B+ eventhough at the time it was percieved that the Raspberry Pi was not a viable hardware for LinuxCNC.

With the release of the RPi 4 the LinuxCNC community now supports the hardware, with LinuxCNC and Preempt-RT Kernel packages now available from the LinuxCNC repository. This now greatly simplifies the build of a Raspberry Pi based CNC controller.
