#!/usr/bin/python3

## Task: 1.0
### Generate C++ Project and Create Class files
import os
from datetime import date

## CLASS DEFINITION
class CppClass():
    username= ""
    classname= ""
    namespace= ""
    createCppFileStatus = ""

    def __init__(self, name, classname, namespace, createCppFileStatus):
        self.name = name
        self.classname = classname
        self.namespace = namespace
        self.createCppFileStatus = createCppFileStatus.lower()
    
    def createClassDirectory(self):
        if (not(os.path.exists(self.classname))):
            print("Creating new directory...")
            os.system(f"mkdir {self.classname}")
            os.system(f"touch {self.classname}/{self.classname}.hpp")
            if(self.createCppFileStatus == "y"):
                os.system(f"touch {classnameInput}/{classnameInput}.cpp")
        else:
            print("Modifiying Already existing directory...")

    def generateCppFileContent(self):
        string = "/******************************************************\n"+\
        f" *               Copyright {self.username}\n"+\
        " *\n"+\
        f" *  Author: {self.username}\n"+\
        f" *    Date: {date.today().strftime("%B %d, %Y")}\n"+\
        " *   Brief:\n"+\
        " *****************************************************/\n"+\
        "\n\n"+\
        f"#include \"{self.classname}.hpp\""+\
        "\n\n"+\
        f"namespace {self.namespace} "+"{\n"+\
        f"\t{self.classname}::{self.classname}() {{\n\n\t}}\n"+\
        f"\t{self.classname}::~{self.classname}() {{\n\n\t}}\n"+\
        "}"
        return string
    
    def generateHppFileContent(self):
        string = "/******************************************************\n"+\
        f" *               Copyright {self.username}\n"+\
        " *\n"+\
        f" *  Author: {self.username}\n"+\
        f" *    Date: {date.today().strftime("%B %d, %Y")}\n"+\
        " *   Brief:\n"+\
        " *****************************************************/\n"+\
        "\n\n"+\
        "#pragma once"+\
        "\n\n"+\
        f"namespace {self.namespace} "+"{\n"+\
        f"\tclass {self.classname} "+"{\n"+\
        "\t\tpublic:\n"+\
        f"\t\t\t{self.classname}();\n"+\
        f"\t\t\t~{self.classname}();\n"+\
        "\t\tprivate:\n"+\
        "\t}\n"+\
        "}"
        return string
    
    def fillCppClassFilesContent(self):
        hppString = self.generateHppFileContent()
        with open(f"{self.classname}/{self.classname}.hpp", "w") as hppFile:
            hppFile.write(hppString)

        if(self.createCppFileStatus == "y"):
            cppString = self.generateCppFileContent()    
            with open(f"{self.classname}/{self.classname}.cpp", "w") as cppFile:
                cppFile.write(cppString)     

    def printClassFilesContent(self):
        print("\n\n> HPP FILE CONTENT >>>\n")
        with open(f"{self.classname}/{self.classname}.hpp", "r") as hppFile:
            print(hppFile.read())
        print("\n\n> CPP FILE CONTENT >>>\n")
        with open(f"{self.classname}/{self.classname}.cpp", "r") as cppFile:
            print(cppFile.read())

    def __del__(self):
        print("CppClass is deleted")
## END OF CLASS


usernameInput = input("Please, Enter your Name: ").title()
print(f"Hello, Mr {usernameInput}")
classnameInput = input("Please, Enter desired Class: ")
namespaceInput = input("Please, Enter desired Namespace: ")
print(f"Class Name = {classnameInput}, Namespace = {namespaceInput}")
createCppFileInput = input("Do you want to create CPP file [Y/N]: ")

CppObj = CppClass(usernameInput, classnameInput, namespaceInput, createCppFileInput)

CppObj.createClassDirectory()
CppObj.fillCppClassFilesContent()
CppObj.printClassFilesContent()

##########################################################