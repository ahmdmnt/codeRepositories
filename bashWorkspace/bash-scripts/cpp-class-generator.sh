#! /bin/bash

## SCRIPT DESCRIPTION
# Generate CPP Class Header and CPP File
#########################################

## ACCEPT USER INPUTS ##
echo "============================================="
echo "    Welcome to CPP Class Generator Script    "
echo "============================================="

read -p "Enter Author Name: " AUTHOR
read -p "Enter Class name: " CLASSNAME
read -p "Enter Namespace name: " NAMESPACE
read -p "Do you wish to generate C++ along with Header file (y/n)? " GENERATE_CPP_FILE
echo ""

MY_DATE=$(date)
MY_DIRECTORY=~/Generated_CPP_Class
#################################################################################

## CHECK IF DIRECTORY ALREADY EXISTS ##
if [ -d "$MY_DIRECTORY" ]; then
    echo "Directory exists."
else
    echo "Directory does not exist! Generating new directory..."
    mkdir ~/Generated_CPP_Class
fi
#################################################################################

## CHECK IF SAME CLASS ALREADY EXISTS -AND- PERFORM CLEANUP IF NEEDED ##
if [ -f "$MY_DIRECTORY/$CLASSNAME.hpp" ] || [ -f "$MY_DIRECTORY/$CLASSNAME.cpp" ]; then
    echo "File exists! Performing Cleanup..."
    rm $MY_DIRECTORY/$CLASSNAME.*
fi
#################################################################################

## GENERATE HEADER FILE ##
touch ~/Generated_CPP_Class/$CLASSNAME.hpp
echo "
/**************************************************************
 *  Author      : $AUTHOR
 *  Classname   : $CLASSNAME
 *  Namespace   : $NAMESPACE
 *  Date        : $MY_DATE
 *
 *  Description : 
 *      <CLASS_DESCRIPTION_DETAILS>
**************************************************************/

#ifndef _${CLASSNAME}_HPP_
#define _${CLASSNAME}_HPP_
    
namespace $NAMESPACE {
    class $CLASSNAME {          // My Class
    public:                     // Access Specifier
        $CLASSNAME();           // Constructor
        ~$CLASSNAME();          // Destructor
    };    
}

#endif /* _${CLASSNAME}_HPP_ */
" > ~/Generated_CPP_Class/$CLASSNAME.hpp
#################################################################################

## GENERATE HEADER FILE ##
if [ $GENERATE_CPP_FILE = "Y" ] || [ $GENERATE_CPP_FILE = "y" ]; then
    touch ~/Generated_CPP_Class/$CLASSNAME.cpp
    echo "
/**************************************************************
 *  Author      : $AUTHOR
 *  Classname   : $CLASSNAME
 *  Namespace   : $NAMESPACE
 *  Date        : $MY_DATE
 *
 *  Description : 
 *      <CLASS_DESCRIPTION_DETAILS>
**************************************************************/

#include \"$CLASSNAME.hpp\"
    

$NAMESPACE::$CLASSNAME::$CLASSNAME() {          // Constructor

    /* ENTER_DESIRED_CODE_HERE */
    
}

$NAMESPACE::$CLASSNAME::~$CLASSNAME() {         // Destructor

    /* ENTER_DESIRED_CODE_HERE */
    
}
    " > ~/Generated_CPP_Class/$CLASSNAME.cpp
fi
#################################################################################

## USER PROMPT ##
echo " > file(s) for $CLASSNAME class is created successfully."
echo " > PATH: $MY_DIRECTORY"
echo " > Goodbye!"
echo ""
#################################################################################