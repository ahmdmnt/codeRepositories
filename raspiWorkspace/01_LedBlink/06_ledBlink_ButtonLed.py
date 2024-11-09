#!/bin/python3

import tkinter as gui
import RPi.GPIO as GPIO


# Application Configuration
BUTTON = 2
LED = 2


# Application Setup
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUTTON, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED, GPIO.OUT)


# Application Run
while(True):
    LedValue = GPIO.input(BUTTON)
    GPIO.output(LED, (not LedValue))