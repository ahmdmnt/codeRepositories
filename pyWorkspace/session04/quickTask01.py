#!/usr/bin/python3

## QuickTask: 1.0
### Program to count the number of lines in a text file

def file_LineCount(fname):
    with open(fname) as tmpFile:
        fileLines = tmpFile.readlines()
        print(f"Count of Lines: {len(fileLines)}")


FILE_PATH = "temp_file.txt"
file_LineCount(FILE_PATH)

##########################################################