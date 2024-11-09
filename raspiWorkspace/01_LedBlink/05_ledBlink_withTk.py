#!/bin/python3

import tkinter as gui
import RPi.GPIO as GPIO


LED = 2

# GPIO Setup
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED, GPIO.OUT)


# Application Function
LedOutputValue=0
def APP_LedToggle():
    global LedOutputValue
    x^=1
    GPIO.output(LED, LedOutputValue)


# Main Window
MainWindow=gui.Tk()
MainWindow.title("Led Toggle Application")
MainWindow.geometry("400x200+500+300")
MainWindow.resizable(False, False)
MainWindow.configure(background="black")

# Window Widgets
ButtonToggle = gui.Button(MainWindow, text="LED Toggle", command=APP_LedToggle, bg="white")
ButtonToggle.place(x=50, y=50)

# Start Main Window
MainWindow.mainloop()