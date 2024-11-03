#! /bin/bash

# Check if figlet is Installed
if ! command -v figlet &> /dev/null; then
    echo "figlet is not installed. RECOMMENDED: Please install it by running:"
    echo "sudo apt install figlet"
    echo -e "--------------------------------------\n"
    # exit 1
else
    figlet "Embedded Python in Bash"
fi

# Print a greeting - Line of Python
python3 -c "print(\"Hello World!\")"

# Run embedded Section of Python code
python3 << EOF
# Simple addition
a = 5
b = 3
result = a + b
print(f"The result of {a} + {b} is {result}")

# Define a function to square a number
def square(number):
    return number * number

# Use the function and print the result
num = 4
print(f"The square of {num} is {square(num)}")

# Loop through a list and print each element
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(f"I like {fruit}")
EOF
