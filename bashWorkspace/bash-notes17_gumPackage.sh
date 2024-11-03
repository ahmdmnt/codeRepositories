#! /bin/bash

# Check if gum is Installed
if ! command -v gum &> /dev/null; then
    echo "gum is not installed. RECOMMENDED: Please install it by running:"
    echo "sudo snap install gum"
    exit 1
else
    # EXAMPLE CODE FOR: GUM Package
    SELECTED_OPT=$(gum choose "Option1" "Option2" "Option3")
    echo "Selection is $SELECTED_OPT"
fi
