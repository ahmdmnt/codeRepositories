#! /bin/bash

## SCRIPT DESCRIPTION
# Run any avaiable script using rofi
####################################################

## SCRIPT PREPARATIONS
SCRIPTS_DIR="/_GitHub/codeRepositories/bashWorkspace/bash-scripts"
LIST_OF_SCRIPTS="battery-notify.sh
cpp-class-generator.sh
open-directory.sh
pc-handle.sh
auto-translate.sh
check-network-devices.sh
access-file-xdot.sh
cli-text-insert.sh"
####################################################

## ACCEPT USER INPUT AND RUN DESIRED SCRIPT
SELECTED_SCRIPT=$(echo -e "$LIST_OF_SCRIPTS" | rofi -dmenu)

if [ "$SELECTED_SCRIPT" = "cli-text-insert.sh" ]; then
    $HOME/$SCRIPTS_DIR/$SELECTED_SCRIPT                                           
else
    gnome-terminal -- bash -c "$HOME/$SCRIPTS_DIR/$SELECTED_SCRIPT; exec bash"      # Open New Terminal
fi

####################################################