#! /bin/bash

## SCRIPT DESCRIPTION
# Run any avaiable script using rofi
####################################################

## SCRIPT PREPARATIONS
SCRIPTS_DIR="/home/ahmedmont/_GitHub/codeRepositories/bashWorkspace/bash-scripts"
LIST_OF_SCRIPTS="battery-notify.sh
cpp-class-generator.sh
open-directory.sh
pc-handle.sh
auto-translate.sh"
####################################################

## ACCEPT USER INPUT AND RUN DESIRED SCRIPT
SELECTED_SCRIPT=$(echo -e "$LIST_OF_SCRIPTS" | rofi -dmenu)
$SCRIPTS_DIR/$SELECTED_SCRIPT
####################################################