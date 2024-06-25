#!/usr/bin/python3

## QuickTask: 3.0
### Program to write a “list” to a file.
import os.path

FILE_NAME = "my_file.txt"

currentWorkingDirectory = os.getcwd()
filePath = f'{currentWorkingDirectory}/{FILE_NAME}'

myList = ["Hello", "this", "is", "Linux", "OS.", "How", "can", "I", "help", "you?"]
myString = " ".join(myList)             # Join and Add newline at end of text

for itr, letter in enumerate(myString): # add newline at each end of line "." or "?"
    if(letter == "." or letter == "?"):
        myString = f"{myString[:itr+1]}\n{myString[itr+2:]}"


if (os.path.isfile(filePath)):         # Append of file exists
    with open(filePath, "a") as myFile:
        myFile.write(myString)
else:                                   # Create new file
    with open(filePath, "x") as myFile:
        myFile.write(myString)

##########################################################