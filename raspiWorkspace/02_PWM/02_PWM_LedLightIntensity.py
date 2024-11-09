#!/bin/python3

import RPi.GPIO as GPIO
from time import sleep


# Raspberry Pi PWM Pins
# PWM0: GPIO12/GPIO18
# PWM0: GPIO13/GPIO19

## IMPORTANT:: Config RaspberryPi Pins for PWM (ALT-4)
# vi /boot/config
# Edit below line:
#   dtoverlay=pwm-2chan,pin=12,func=4


# Application Configuration
LED = 12


# Application Setup
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(LED, GPIO.OUT)
LedPWM = GPIO.PWM(LED, 1000)    # Create a PWM Instance with desired Frequency
LedPWM.start(0)                 # Start PWM of Required DutyCycle (DC=0:  OFF MODE)


# Application Run: LED Changes Light Intensity from 0 to 100 DutyCycle
while(True):
    for DutyCycleValue in range(0,100):
        print(DutyCycleValue)
        LedPWM.ChangeDutyCycle(DutyCycleValue)
        sleep(0.01)
    sleep(0.5)
    for DutyCycleValue in range(100, 0, -1):
        print(DutyCycleValue)
        LedPWM.ChangeDutyCycle(DutyCycleValue)
        sleep(0.01)
    sleep(0.5)  