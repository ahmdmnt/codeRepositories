#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################
 
## getopts Keyword
 
available_opt=false
while getopts "a:bcd:" opt; do
    case $opt in
    a)
        echo "input in a opt is: ${OPTARG}"
        available_opt=true
        ;;
    b)
        echo "Welcome b"
        available_opt=true
        ;;
    c)
        echo "Welcome c"
        available_opt=true
        ;;
    d)
        echo "input in d opt is: ${OPTARG}"
        available_opt=true
        ;;
    *)
        echo "unknown option, available opts: (a b c d)"
        available_opt=true
        ;;
    esac
done
shift $((OPTIND -1))                    # Shift ALL the Opts after it is handled -- te fetch extra args without opt
echo "$*"                               # Print rest of args without opts
 
if [ $available_opt != true ]; then      # Check if there was no opt sent
    echo "no option!!"
    exit 1
fi