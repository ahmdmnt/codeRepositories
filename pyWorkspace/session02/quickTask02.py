#!/usr/bin/python3

## QuickTask: 2.0
### Find largest item from a given list using Loop
import random
 
randomList=[]; n=20
for i in range(n):
    randomList.append(random.randint(0, 200))
print("List: ".rjust(16), randomList)

randomList.sort()
print("Sorted: ".rjust(16), randomList)

randomList.sort(reverse=True)
print("Reverse Sorted: ", randomList)
##########################################################