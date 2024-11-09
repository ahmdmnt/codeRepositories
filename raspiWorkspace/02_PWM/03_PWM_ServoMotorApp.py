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
SERVOMOTOR_PIN = 12

SERVOMOTOR_FREQUENCY = 50

SERVOMOTOR_DC_OFF = 0



# Application Setup
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(SERVOMOTOR_PIN, GPIO.OUT)
ServoMotorPWM = GPIO.PWM(SERVOMOTOR_PIN, SERVOMOTOR_FREQUENCY)  # Create a PWM Instance with desired Frequency
ServoMotorPWM.start(SERVOMOTOR_DC_OFF)                          # Start PWM of Required DutyCycle (DC=0:  OFF MODE)


# Application Run: Move Servo Motor Arm 0 > 90 > 180
def set_angle(angle):
    """ Sets the servo angle (0 to 180 degrees). """
    duty = (angle / 18) + 2                 # Convert angle to duty cycle
    GPIO.output(SERVOMOTOR_PIN, True)       # used to send a HIGH signal to the servo control wire for a brief period to create the PWM pulse.
    ServoMotorPWM.ChangeDutyCycle(duty)
    sleep(1)
    GPIO.output(SERVOMOTOR_PIN, False)
    ServoMotorPWM.ChangeDutyCycle(0)

for itr in range(0, 5):
    # Move the servo to different angles
    set_angle(0)    # 0 degrees
    sleep(2)
    set_angle(90)   # 90 degrees
    sleep(2)
    set_angle(180)  # 180 degrees
    sleep(2)

ServoMotorPWM.stop()


# SERVOMOTOR_DC_0_DEG = 2
# SERVOMOTOR_DC_90_DEG = 7
# SERVOMOTOR_DC_180_DEG = 12s
    # ServoMotorPWM.ChangeDutyCycle(SERVOMOTOR_DC_0_DEG)
    # sleep(0.5)

    # ServoMotorPWM.ChangeDutyCycle(SERVOMOTOR_DC_90_DEG)
    # sleep(0.5)

    # ServoMotorPWM.ChangeDutyCycle(SERVOMOTOR_DC_180_DEG)
    # sleep(0.5)

# Another Task: Potentiometer controls a Servo Motor