# Remora Nucleo H723

repo for development of the STM32H7 boards using a NucleoH723, using a static config. 

Progress so far:
- Firmware loads
- Serial Output good
- Blink kinda works (most likely issue to the static blink module)
- DMAMUX i dont think is working, no connection to linuxcnc
- dont know how to debug the H7

  # To compile for Nucleo H723

  - need to remove a compile limitation is using ARM6, Remove this section here in the mbedlib targets list
    https://github.com/ARMmbed/mbed-os/blob/baf6a3022a328b91713e03fd88f65126a9a53f01/targets/targets.json#L3333-L3339

# Remora

The full documentation is at <https://remora-docs.readthedocs.io/en/latest/>

Remora is a free, opensource LinuxCNC component and Programmable Realtime Unit (PRU) firmware to allow LPC17xx and STM32F4 base controller boards to be used in conjuction with a Raspberry Pi to implement a LinuxCNC based CNC controller.

Having a low cost and accessable hardware platform for LinuxCNC is important if we want to use LinuxCNC for 3D printing for example. Having a controller box the size of the printer itself makes no sense in this applicatoin. A SoC based single board computer is ideal in this application. Although developed for 3D Printing, Remora (and LinuxCNC) is highly flexible and configurable for other CNC applications.

Remora has been in use amd development since 2017. Starting on Raspberry Pi 3B and 3B+ eventhough at the time it was percieved that the Raspberry Pi was not a viable hardware for LinuxCNC.

With the release of the RPi 4 the LinuxCNC community now supports the hardware, with LinuxCNC and Preempt-RT Kernel packages now available from the LinuxCNC repository. This now greatly simplifies the build of a Raspberry Pi based CNC controller.
