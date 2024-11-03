#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################
 
 
## unset keyword - TO REMOVE a Variable
VAR="10"
echo $VAR
unset VAR
echo $VAR
 
## trap Keyword
sayHello() {
    echo "Hello"
}
trap 'sayHello' SIGINT      # If Ctrl+C Pressed ... sayHello() will be called __OR__ kill -SIGINT pidof(BASH.sh)
while true; do
    val=10
done