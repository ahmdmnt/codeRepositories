#! /bin/bash

## dmenu (suckless-tools)
## in a GUI window for Options
selectedColor=$(echo -e "red\ngreen\nyellow" | rofi -dmenu)

if [ $selectedColor = "red" ]; then
    echo -e "it is \e[31mred\e[0m"
elif [ $selectedColor = "green" ]; then
    echo -e "it is \e[32mgreen\e[0m"
elif [ $selectedColor = "yellow" ]; then
    echo -e "it is \e[33myellow\e[0m"
else
    echo "other color"
fi