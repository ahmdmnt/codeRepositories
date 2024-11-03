#! /bin/bash


## dmenu (suckless-tools)
## dmenu --> above taskbar for Options
selectedColor=$(echo -e "red\ngreen\nblue" | dmenu)

if [ $selectedColor = "red" ]; then
    echo -e "it is \e[31mred\e[0m"
elif [ $selectedColor = "green" ]; then
    echo -e "it is \e[32mgreen\e[0m"
elif [ $selectedColor = "blue" ]; then
    echo -e "it is \e[34mblue\e[0m"
else
    echo "other color"
fi

## dmenu (suckless-tools)
## rofi --> in a GUI window for Options
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

## For Extra Information on Bash: https://devhints.io/bash
###########################################################