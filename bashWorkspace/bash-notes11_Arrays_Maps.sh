#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################
 
## Arrays
array1=("Ahmed" "Montasser" "Ramadan" "Mohamed" "Ahmed")
declare -a array2=("Windows" "MacOS" "Ubuntu")
 
echo "${array1[@]}"         # Print all Array
array1[0]="Mohamed"         # Update Value at Array Index
echo "${array1[0]}"         # Print a Element
for i in 1 2 3; do
    echo "${array1[$i]}"    # Print Elements
done
for i in "${array1[@]}"; do
    echo "$i"               # Print Elements
done
array2+=("CentOS")          # Append to array
echo "${array2[@]}"
echo "${#array2[@]}"        # Print length of Array
 
unset "array2[0]"           # Remove index 0 .... ARRAY STRUCTURE::   <NULL>-"MacOS"-"Ubuntu"-"CentOS"
echo "${#array2[@]}"        # Decreased by one
echo "${array2[0]}"         # NULL
 
echo "${array1[@]:2:3}"     # Array slicing 3 elements starts from index:2


## Maps
declare -A map1=(
    ["Name"]="Ahmed"
    ["Age"]="31"
    ["Job"]="Engineer"
)
map1+=(["Salary"]="500")                  # Append Key and Value to Map

echo "---- ECHO MAP Section ----"
echo "Element:  ${map1["Name"]}"          # Print Element @ Keyvalue
echo "   Keys:  ${!map1[@]}"              # Print ALL Element Keys
echo "  Value:  ${map1[@]}"               # Print ALL Elements Values
echo "  Count:  ${#map1[@]}"              # Print ALL Elements Count
 