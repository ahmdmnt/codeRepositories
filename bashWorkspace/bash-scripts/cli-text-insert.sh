#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################
  
## Text Insert in CLI Script
TEXT_INSERT_KEY=("red" "yellow" "green" "blue" "magenta" "cyan" "white" "bold" "unknown" "italic" "underline" "reset")
declare -A TEXT_INSERT=(
    [red]="\e[31m"
    [yellow]="\e[32m"
    [green]="\e[33m"
    [blue]="\e[34m"
    [magenta]="\e[35m"
    [cyan]="\e[36m"
    [white]="\e[37m"
    [bold]="\e[1m"
    [unknown]="\e[2m"
    [italic]="\e[3m"
    [underline]="\e[4m"
    [reset]="\e[0m"
)

# Select using rofi tool
SELECTED_KEY=$(printf "%s\n" "${TEXT_INSERT_KEY[@]}" | rofi -dmenu -p "Select Desired Manipulation")
# Select Cli Text
xdotool type -delay 30 "${TEXT_INSERT[$SELECTED_KEY]}"

#PS1='\e[36m\e[1m\u@legion: \e[0m\e[32m\W\e[0m $ '
