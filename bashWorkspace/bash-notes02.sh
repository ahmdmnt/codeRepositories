#! /bin/bash
# shebang --> Comment to identify the interperter that will be used to run this Script

### BASH Scripting Content ###
    ## Default Variable(s)
    ## Process ID
################################

echo "Filename = $0"
echo "First Arg = $1"
echo "Second Arg = $2"
echo "Number of Args = $#"
echo "Process ID = $$"
echo "All Arguments = $*"           # "1st Arg 2nd Arg"   :: One content
echo "All Agruments =" "$@"         # "1st Arg" "2nd Arg" :: Array
echo "last command result = $?"     # above: line 15
################################

## Array in Bash
arrayValues=($@)            # fill with passed args 
arrayValues+=("Ramadan")    # Concatenate
arrayValues+=("Mohamed")
echo "Array Values: ${arrayValues[@]}"
for i in ${arrayValues[@]}; do
    echo $i
done
################################

## shift keyword: pop and shift the array values or Arguments
echo "-------- Loop on the Arguments using shift keyword"
for i in $(seq 1 $#); do
    echo $1
    shift
done
################################