#!/usr/bin/python3

## QuickTask: 2.0
### Program to count the Number of words in a file.

def file_LineCount(fname):
    with open(fname) as tmpFile:
        fileWords = tmpFile.read().split()
        print(f"Count of Words: {len(fileWords)}")


FILE_PATH = "/home/ahmedmont/codeRepositories/pyWorkspace/session04/temp_file.txt"
file_LineCount(FILE_PATH)

##########################################################