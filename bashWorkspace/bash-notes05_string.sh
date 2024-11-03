#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################

## Strings
name="Ahmed Montasser Ramadan"
# Count # of Characters
echo "the Word-Count of name: ${#name}"
count=$(echo -n "$name" | wc -c)
echo "the Word-Count of name: $count"
# Cut the Second name
echo "Second name: ${name:6:9}"                 # Total Characters: 9, after Index: 6 -- ${<VARIABLE_NAME>:<START_INDEX>:<CHARACTERS_COUNT>}
second_name=$(echo $name | cut -f 2 -d " ")
echo "Second name: ${second_name}"
second_name=$(echo $name | cut -c 7-15)
echo "Second name: ${second_name}"
second_name=$(echo $name | awk '{print $2}')
echo "Second name: ${second_name}"


## String Manpulation
# Delete Part of String [FROM the END]
str="/path/to/foo.cpp"
echo "1- ${str%.cpp}"    # Delete ".cpp" -- Result: /path/to/foo
echo "2- ${str%.cpp}.o"  # Delete ".cpp" -- Result: /path/to/foo.o -- Adding ".o"
echo "3- ${str%/*}"      # Delete "/" and after -- Result: /path/to

# Delete Part of String [FROM the BEGINNING]
echo "4- ${str#*.}"      # Delete "." and before -- Result: cpp
echo "5- ${str##*/}"     # foo.cpp 
echo "6- ${str#*/}"      # Delete "/" and before -- Result: path/to/foo.cpp
echo "7- ${str##*/}"     # Delete from 3rd "/" and before -- Result: foo.cpp

# String Replacement
echo "8- ${str/foo/bar}" # Replace "foo" with "bar" -- Result: /path/to/bar.cpp