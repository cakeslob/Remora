# Remora Nucleo CNC shield v3.0
This repo is for a setup using a STM Nucleo64 with classic CNC shield v3.0 

Main focus for this project is based around STM32F446RE, but other supported Nucleo boards include STM32F103RC, STM32F401RE, STM32F411RE and STM32F446ZE
The configuration is for 4 stepgen, 4 encoders, 7 input, 2 output and 1 pwm. It is a basic configuration for the time being, using the static config from Flexi-hal.
- SPI2 for connection to RPI4, with pins PB1, PB13, PB14 and PB15, and pin PB2 for reset
- the pinout configuration is loacted in /Firmware/FirmwareSource/Remora-OS6/TARGET_NUCLEO_F446RE/board_config.h
- if you wish to change the pinout, you must configure it in this file, and them recompile 
- Firmware premade bin file is located in /Firmware/FirmwareBin/firmware.bin


Documentation here 
https://github.com/cakeslob/Remora-docs/blob/nucleo/docs/source/hardware/nucleo446.rst

<img src="/nucleo446_pi.png" >

# Remora

The full documentation is at <https://remora-docs.readthedocs.io/en/latest/>

Remora is a free, opensource LinuxCNC component and Programmable Realtime Unit (PRU) firmware to allow LPC17xx and STM32F4 base controller boards to be used in conjuction with a Raspberry Pi to implement a LinuxCNC based CNC controller.

Having a low cost and accessable hardware platform for LinuxCNC is important if we want to use LinuxCNC for 3D printing for example. Having a controller box the size of the printer itself makes no sense in this applicatoin. A SoC based single board computer is ideal in this application. Although developed for 3D Printing, Remora (and LinuxCNC) is highly flexible and configurable for other CNC applications.

Remora has been in use amd development since 2017. Starting on Raspberry Pi 3B and 3B+ eventhough at the time it was percieved that the Raspberry Pi was not a viable hardware for LinuxCNC.

With the release of the RPi 4 the LinuxCNC community now supports the hardware, with LinuxCNC and Preempt-RT Kernel packages now available from the LinuxCNC repository. This now greatly simplifies the build of a Raspberry Pi based CNC controller.
