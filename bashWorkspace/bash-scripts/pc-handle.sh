#! /bin/bash

## SCRIPT DESCRIPTION
# PC Handling Script: Logout, Shudtown & Reboot
################################################

echo "====================================="
echo "    Welcome to PC Handling Script    "
echo "====================================="
choice=$(echo -e "Logout\nReboot\nShutdown" | rofi -dmenu -p "Select an Option")

if [ "$choice" = "Logout" ]; then
    echo "Selected: Logout"
    notify-send "log out"
    #logout
elif [ "$choice" = "Shutdown" ]; then
    echo "Selected: Shutdown"
    notify-send "shutdown"
    #shutdown -h now
elif [ "$choice" = "Reboot" ]; then
    echo "Selected: Reboot"
    notify-send "reboot"
    #sudo reboot
else
    notify-send "unknown option!"
fi