#!/bin/bash
 
GPIOCHIP="gpiochip0"
LINE=17
SLEEP_TIME=1
 
# Export the line
gpioget $GPIOCHIP $LINE
 
while true; do
    # Turn the LED on
    gpioset $GPIOCHIP $LINE=1
    sleep $SLEEP_TIME
 
    # Turn the LED off
    gpioset $GPIOCHIP $LINE=0
    sleep $SLEEP_TIME
done