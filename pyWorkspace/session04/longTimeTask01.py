#!/usr/bin/python3

## LongTimeTask: 1.0
### Write a python code that manage a database for employees. 
### Each employee has a unique ID and has the following data:
###  - Name, Job and Salary. 
###  The system shall allow:
###      1-Add new employee
###      2-Print employee data
###      3-Remove employee from the system
###      4-Update

from pyfiglet import figlet_format



class EmployeeClass():
    sId=0
    def __init__(self, name, job="NA", salary="NA"):
        EmployeeClass.sId += 1
        self.id = EmployeeClass.sId
        self.name = name
        self.job = job
        self.salary = salary
    def __del__(self):
        pass

class EmployeeDatabase():
    sEmpDB = {}
    def __init__(self):
        pass
    
    def addNewEmployee(self, id, EmployeeData):
        EmployeeDatabase.sEmpDB[str(id)] = EmployeeData

    def removeEmployee(self, id):
        EmployeeDatabase.sEmpDB.pop(str(id))

    def updateDataEmployee(self, id, entryData, entryValue):
        entryData = entryData.lower().strip()
        if(entryData == "name"):
            EmployeeDatabase.sEmpDB[str(id)].name = entryValue
        elif(entryData == "job"):
            EmployeeDatabase.sEmpDB[str(id)].job = entryValue
        elif(entryData == "salary"):
            EmployeeDatabase.sEmpDB[str(id)].salary = entryValue
        else:
            print("Wrong Entry, Aborting!...")
    
    def printDataEmployee(self, id):
        print("----------------------------------")
        print(f"Employee ID: {EmployeeDatabase.sEmpDB[str(id)].id}")
        print(f"Employee Name: {EmployeeDatabase.sEmpDB[str(id)].name}")
        print(f"Employee Job: {EmployeeDatabase.sEmpDB[str(id)].job}")
        print(f"Employee Salary: {EmployeeDatabase.sEmpDB[str(id)].salary}")
        print("----------------------------------\n")
    
    def printDataAllEmployee(self):
        print("----------------------------------")
        for Emp in EmployeeDatabase.sEmpDB.values():
            print(f"Employee ID: {Emp.id}")
            print(f"Employee Name: {Emp.name}")
            print(f"Employee Job: {Emp.job}")
            print(f"Employee Salary: {Emp.salary}")
            print("")
        print("----------------------------------")

    def __del__(self):
        pass


print(figlet_format("Employee Database"))
print(figlet_format("---------"))

inputString = """
    1- Add New Employee.
    2- Remove, by Index, Employee.
    3- Update, by Index, Employee.
    4- Print, Employee.
    5- Print, All, Employee.
Choose desired Operation: """

EmployeeDatabaseObj = EmployeeDatabase()
while True:
    inputValue = input(inputString)
    if( int(inputValue) == 1 ):
        print("----------------------------------")
        print("Add Employee")
        eName = input("Enter Employee Name: ")
        eJob = input("Enter Employee Job: ")
        eSalary = input("Enter Employee Salary: ")
        newEmployee = EmployeeClass(eName, eJob, eSalary)
        EmployeeDatabaseObj.addNewEmployee(newEmployee.id, newEmployee)
        EmployeeDatabaseObj.printDataEmployee(newEmployee.id)

    elif( int(inputValue) == 2 ):
        print("----------------------------------")
        print("Remove Employee")
        delEmpID = input("Enter Employee ID: ")
        EmployeeDatabaseObj.removeEmployee(delEmpID)
    elif( int(inputValue) == 3 ):
        print("----------------------------------")
        print("Update Employee")
        updEmpID = input("Enter Employee ID: ")
        updEmpData = input("Enter which data to be changed [name-job-salary]: ")
        updEmpValue = input("Enter new value: ")
        EmployeeDatabaseObj.updateDataEmployee(updEmpID, updEmpData, updEmpValue)
    elif( int(inputValue) == 4 ):
        print("----------------------------------")
        print("Print Employee")
        printEmpID = input("Enter Employee ID: ")
        EmployeeDatabaseObj.printDataEmployee(printEmpID)
    elif( int(inputValue) == 5 ):
        print("----------------------------------")
        print("Print All Employees")
        EmployeeDatabaseObj.printDataAllEmployee()
    else:
        pass

    contValue = input("Do you want to continue [Y/N]: ")
    print("--------------------------------------\n")
    if(contValue.lower() != 'y'):
        break
##########################################################