#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################

MY_FILE=$(cat "$HOME/system_on_log.txt")    # Read file contents
echo "$MY_FILE"
echo ""

MYFILE=$(<"$HOME/system_on_log.txt")        # Read file contents
echo "$MYFILE"
echo ""
echo "${MYFILE[@]}"                           # Read as a Whole File
echo ""

# Read file Line by line -- Into ARRAY
declare -a FILE_ARRAY
FILE_IDX=0
while read LINE; do
    echo "-- $LINE"
    FILE_ARRAY[FILE_IDX]=$LINE
    ((FILE_IDX++))
done < "$HOME/system_on_log.txt"
echo "New Array Elements Count= ${#FILE_ARRAY[@]}"
echo "New Array Idx 1 = ${FILE_ARRAY[1]}"
echo ""

# Read file by WORDS -- Into ARRAY
declare -a FILE_ARRAY
WORD_IDX=0
for WORD in $MYFILE; do
    FILE_ARRAY[WORD_IDX]=$WORD
    ((WORD_IDX++))
done
echo "New Array Elements Count= ${#FILE_ARRAY[@]}"
echo "New Array Idx 11 = ${FILE_ARRAY[11]}"
echo ""

# Check if file exists
if [ -f  "$HOME/system_on_log.txt" ]; then
    echo "File Exists!"
fi

# OverWrite in file
# echo "-- START OF FILE - `date`" > "$HOME/system_on_log.txt"

# Append in file
# echo "-- END OF FILE" >> "$HOME/system_on_log.txt"


declare -A database=(           # RECOMMENDED TO USE: declare -A when using Map
    ["report1"]="$HOME/system_on_log.txt"
    ["report2"]="$HOME/system_on_log.txt"
    ["report3"]="$HOME/system_on_log.txt"
)

echo "${database["report1"]}"   # Print content of first Key
echo "${!database[@]}"          # Print All Keys