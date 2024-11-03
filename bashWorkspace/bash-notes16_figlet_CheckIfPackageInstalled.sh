#! /bin/bash

# Check if figlet is Installed
if ! command -v figlet &> /dev/null; then
    echo "figlet is not installed. RECOMMENDED: Please install it by running:"
    echo "sudo apt install figlet"
    echo -e "--------------------------------------\n"
    # exit 1
else
    # Execut Script Normally
    figlet "Embedded Python in Bash"
fi
