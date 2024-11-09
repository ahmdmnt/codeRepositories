#!/bin/bash


# Export PWM0
echo 0 > /sys/class/pwm/pwmchip0/export

# Set PWM Period in nanoseconds (500 Hz frequency)
echo 2000000 > /sys/class/pwm/pwmchip0/pwm0/period
# echo 1000 > /sys/class/pwm/pwmchip0/pwm0/period

# Set the PWM duty cycle (e.g., 50% duty cycle)
echo 1000000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
# echo 500 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle

# Enable the PWM
echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable

# Disable the PWM
echo 0 > /sys/class/pwm/pwmchip0/pwm0/enable

# Unexport PWM0 to release the pin
echo 0 > /sys/class/pwm/pwmchip0/unexport

# NOTE:
# Configuration available in below file, 
# if "CONFIG_DEBUG_KERNEL=y" enabled in "/lib/modules/<VER>/build/.config".
#   $ cat /sys/kernel/debug/pwm