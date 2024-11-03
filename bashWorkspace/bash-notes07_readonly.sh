#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################

## readonly Keyword
readonly X=10       # Can't be assigned
echo $X             # it can be read normally
# X=5               # ERROR

# Function Definition
hi() {
    echo "Welcome"
}
hi

# Re-defining functions
hi() {
    echo "Hi"
}
hi
readonly -f hi

# Re Defintion will Pop-up ERROR
hi() {               
    echo "Welcome"
}
hi
