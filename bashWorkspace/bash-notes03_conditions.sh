#! /bin/bash

## If Condition
if [ -z "$address" ]; then
    echo "Unfortunately, no Address recorded!"
elif [ "$address" = "no User" ]; then
    echo "No User recorded"
else
    echo "Addres is $address"
fi
#################################################################

## If Condition - Complex Expression
# if [ -z "$address" ] && [ -z "$name" ] ; then
# if [[ -z "$address" && -z "$name" ]] ; then
if [ -z "$address" -a -z "$name" ] ; then
    echo "Unfortunately, no Address recorded!"
else
    echo "OK"
fi
if [ 10 -eq 10 ] && [ 10 -lt 11 ] && [ 3 -ne 4 ] || [ 11 -gt 10 ] ; then
    echo "Correct!"
fi
#################################################################

## Case Condition
# case can hold any type (int, files, string ..), unlike C
read -p "Enter a letter: " LETTER

case $LETTER in
"A" | "a")
    echo "A Letter"
    ;;
"B" | "b")
    echo "B Letter"
    ;;
"C" | "c")
    echo "C Letter"
    ;;
*)
    echo "Any Letter"
    ;;
esac
#################################################################

## Select Condition
# it will loop on condition infinitly until u break
select word in write read insert append erase; do
    echo "$word is chosen..."
    # useful when using with case
    case $word in
    write)
        echo "1"
        ;;
    read)
        echo "2"
        ;;
    insert)
        echo "3"
        ;;
    append)
        echo "4"
        ;;
    erase)
        echo "5"
        break       ## break the "select" looping 
        ;;
    esac
done
#################################################################