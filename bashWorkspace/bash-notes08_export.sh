#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################

## EXPORT
export VAR=10

# Give the previlage to any Child bash to see the VAR ... 
# known issue ... if you do export from a Child, Parent can see export
# and if it was killed it will be no longer available.

# To Solve ISSUE
# type command// $ . Script.sh (Run the script in my Bash not child)
# OR
# type command// $ source Script.sh (Run the script in my Bash not child)


#! /bin/bash
 
## BASH CHEAT-SHEET: https://devhints.io/bash :-
################################################