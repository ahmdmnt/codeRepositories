#! /bin/bash
# shebang --> Comment to identify the interperter that will be used to run this Script

### BASH Scripting Content ###
 # Basics
    ## variables
    ## echo
    ## read
    ## mathematical operations
    ## test
    ## [ EXPRESSION ]
 # Conditions
    ## if
    ## case
    ## select
 # Iterations
    ## for loop
    ## while
    ## until
 # Along with using:
 # Whole available Linux Commands of shell
################################

## Multiple Line Comment
<<COMMENT
 This is a Multiple line comment.
 <COMMENT+BODY>
COMMENT
#################################################################

## Variables
name="Ahmed"    # Variable does not have any spaces between name and = sign
grade='90'
job=enineer
address="19, Street 1, Cairo"       # "..." allows words with spaces and special characters
value=1000
declare -i salary=1000              # Integer Variable
#################################################################

## using "echo" Keyword
echo "TEXT_SENTENCE"
echo "Hello $name"
echo "$grade%"
echo $job
#################################################################

## using Linux Commands in Bash scripts 
cmd_op=$(date)
# cmd_op=`date`       # Legacy Format
echo "Date today is: $cmd_op"
pwd        # Can accept any linux command
#################################################################

## using read keyword
# read -p "Enter your name: " new_name        # -p to Prompt echo in reading
[ "$new_name" = "$name" ] && echo "Hello Same user :):)"

## read mulitple args (Array)
# read -a array
echo ${array[0]}
echo "${array[1]}"
#################################################################

## Mathematical Operations
num1=10
num2=20
let sum=$num1+$num2                 # Bash only... not in shell
sum1=$(echo "$num1+$num2" | bc)     # Bc tool
sum2=$(expr $num1 + $num2)          # expr Keyword,, spaces are mandatory in expr between the sign
sum3=$(($num1+$num1))               # Sub-Shell
echo "Sum=$sum -- Sum1=$sum1 -- Sum2=$sum2 -- Sum3=$sum3"
##################################################################

## using test keyword
[ $value -eq 1000 ] && echo "Value=1000" || echo "Value!=1000"       # After && "True Condition" -- After || "False Condition"
[ -z "" ] && echo "Empty Text" || echo "Text Available"
##################################################################

## using [ EXPRESSION ]
## It consists of Domain ... ex: checking string is not similar to checking integers or files
[ $salary -gt 999 ] && echo "Good Salary" || echo "Low Salary"
[ -z $job ] && echo "Empty Job Description" || echo $job
#################################################################

## For Loop
# for i in 1 2 3 4 5 6 7 8 9 10; do
# for i in $(seq 1 10); do
for i in {1..10}; do
    echo -n "$i "
done
echo ""
myName="Ahmed Montasser Ramadan"
for i in $myName; do
    echo $i
done
#################################################################

## For Loop with linux Command
lsCommandOutput=$(ls)
for filename in $lsCommandOutput; do
    wc -l $filename
    cat $filename | grep -i "bash"
done
#################################################################

## while loop
count=0
while [ $count -lt 5 ]; do
    echo $count
    ((++count))
done
count1=0
count2=5
while [[ $count1 -lt 5 && $count2 -gt 0 ]]; do
    echo "$count1 - $count2"
    ((++count1))
    ((--count2))
done
#################################################################

## Until Loop
i=1
until [ $i -gt 3 ];do
    echo $i
    ((++i))
done
#################################################################