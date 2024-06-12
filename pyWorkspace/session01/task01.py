#!/usr/bin/python3

## Task: 1.1
### Count the number 4 in a given list
import random
 
randomList=[]; n=20
for i in range(n):
    randomList.append(random.randint(2, 8))

print("List = ", randomList)
print("Count of number 4 in list= ", randomList.count(4), "\n\n")
##########################################################


## Task: 1.2
### Check Vowel letters
import string

randomLetter = random.choice(string.ascii_letters)
print("Letter = ", randomLetter)

vowelList:list = ['a', 'e', 'i', 'u', 'o']
if randomLetter.lower() in vowelList:
    print("The letter is Vowel.", "\n\n")
else:
    print("The letter is Consonant.", "\n\n")
##########################################################


## Task: 1.3
### Access the environment variable; PATH and SHELL
import os

envVar_PATH = os.environ['PATH']
print("PATH=", envVar_PATH)

envVar_SHELL = os.environ['SHELL']
print("SHELL=", envVar_SHELL, "\n\n")
##########################################################