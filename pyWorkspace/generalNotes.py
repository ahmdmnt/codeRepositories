#!/usr/bin/python3

# Break tuples
# Create 3 different variables assign values from fruits tuple,, *Red is the rest of tuple elements == List type

fruits = ("Watermelon", "Banana", "Cherry", "Apple", "Grapes")
(Green, Yellow, *Red) = fruits

print(f"Green = {Green}")
print(f"Yellow = {Yellow}")
print(f"Red = {Red}")

fruits = ("Watermelon", "Cherry", "Apple", "Grapes", "Banana")
(Green, *Red, Yellow) = fruits

print(f"Green = {Green}")
print(f"Red = {Red}")
print(f"Yellow = {Yellow}")


class Animal():
    name = "animal"
    __id = 1
    def __init__(self, _name):      #constructor
        self.name = _name
    def speak(self):
        print("I am Animal")
        print("Animal ID: ", self.__id)
    def __del__(self):      # destructor
        print("Animal is deleted")

    @staticmethod   # Member related to Class itself not an object
    def myType():
        print("This is animal Class")

cat = Animal("cat")
print(cat.name)
# print(cat.__id) Error Private Member
print(cat._Animal__id)  # workaround to access private member
print(Animal.myType())  


# Operator Overloading
class Point():
    xCoord=0
    yCoord=0
    def __init__(self, x=0, y=0):
        self.xCoord = x
        self.yCoord = y
    def __add__(self, point2):      # Operator Overloading
        return Point(self.xCoord+point2.xCoord, self.yCoord+point2.yCoord)
    
p1 = Point(1, 1)
p2 = Point(2, 2)

p3 = p1+p2      # p1.__add__(p2)
print(p3.xCoord)
print(p3.yCoord)  