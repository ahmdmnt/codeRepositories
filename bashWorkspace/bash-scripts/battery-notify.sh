#! /bin/bash

## SCRIPT DESCRIPTION
# Notify the User of the Current battery Precentage
####################################################

BAT_PERCENT=$(cat /sys/class/power_supply/BAT0/capacity)

if [ $BAT_PERCENT -lt 10 ]; then
    MESSAGE="CAUTION: Very Low Battery, PC might log off!"
    notify-send "Battery Notification [$BAT_PERCENT%]" "$MESSAGE"
elif [ $BAT_PERCENT -lt 20 ]; then
    MESSAGE="CAUTION: Low Battery!"
    notify-send "Battery Notification [$BAT_PERCENT%]" "$MESSAGE"
elif [ $BAT_PERCENT -lt 50 ]; then
    MESSAGE="It is recommended to connect the Charger!"
    notify-send "Battery Notification [$BAT_PERCENT%]" "$MESSAGE"
fi