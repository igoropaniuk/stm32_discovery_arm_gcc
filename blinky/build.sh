#!/bin/bash

export PATH=$PATH:~/toradex/toolchain/gcc-arm-none-eabi-8-2019-q3-update/bin/
export STM_COMMON=~/stm32/reps/stm32_discovery_arm_gcc/STM32F4-Discovery_FW_V1.1.0/

make

# For flashing create udev rule /etc/udev/rules.d/45-usb-stlink-v2.rules:
# SUBSYSTEM=="usb", ATTR{idVendor}=="0483", ATTR{idProduct}=="3748", MODE="0666"
# and do:
# sudo udevadm control --reload
#
# Additional details are:
# http://www.wolinlabs.com/blog/linux.stm32.discovery.gcc.html
