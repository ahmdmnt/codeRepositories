#! /bin/bash

 
# SCRIPT Description:
# Add, Remove and Select from a file - Common used sentences
##############################################################

MY_FILE=$(cat "$HOME"/.notes.txt)
 
SELECTED_VALUE=$(echo -e "$MY_FILE" | rofi -dmenu -p "add/rm/select")      # -- "$VALUES[@]"
 
case "$SELECTED_VALUE" in
ADD | add | Add)
    # Add to File
    TEXT_TO_ADD=$(rofi -dmenu -p "Add Request")
    if [ -n "$TEXT_TO_ADD" ]; then
        echo "$TEXT_TO_ADD is added to file successfully!"
        echo "$TEXT_TO_ADD" >> "$HOME"/.notes.txt
    fi
    ;;
RM | rm | Rm)
    # Remove from File
    TEXT_TO_REMOVE=$(rofi -dmenu -p "Remove Request")
    code "$HOME"/.notes.txt       # Remove Manually to avoid remove un desired lines
    # sed -i "/$TEXT_TO_REMOVE/d" "$HOME"/.notes.txt
    # grep -vo "$TEXT_TO_REMOVE" "$MY_FILE" > "$HOME"/.notes.txt
    ;;
*)
    # Select from File
    if [ -n "$SELECTED_VALUE" ]; then
        xdotool type --delay 10 "$SELECTED_VALUE"
    fi
    ;;
esac
