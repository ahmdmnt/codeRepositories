#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################

## Functions in BASH
function sayHello {
    echo "Hello, $1!"   # Argument from function call
}
sayHello "$1"           # Function Call -- Argument from Script

concatFunction() {
    echo "$1+$2"
    return 120
}
concatFunction 1 2
retValue=$?
echo "retValue = $retValue"
echo

## Variables and Scopes
VAR="GlobalVariable"
function fu() {
    VAR="LocalVariable"     # global also however it is in function
    echo $VAR
}
echo $VAR
fu
echo $VAR

echo

VAR="GlobalVariable"
function fu() {
    local VAR="LocalVariable"     # global also however it is in function
    echo $VAR
}
echo $VAR
fu
echo $VAR