#!/usr/bin/python3

## Task: 2.0
### Program that asks the user to enter two integers and displays their sum/sub

import tkinter as tk

def on_button_click():
    print(f"Input A: {inputA.get()}")
    print(f"Input B: {inputB.get()}\n")
    if(inOperator.get() == 1):
        opResult.set((inputA.get()+inputB.get()))
    else:
        opResult.set((inputA.get()-inputB.get()))
    print(f"opResult: {opResult.get()}")
    print(f"--------------------------")
#######################################

root = tk.Tk()
root.title("Reverse String")

inputA = tk.IntVar()
inputB = tk.IntVar()
opResult = tk.IntVar()
inOperator = tk.IntVar()

tk.Label(root, text="Enter Value A").grid(row=0, column=0, padx=10, pady=10)
valEntryA = tk.Entry(root, width=10, borderwidth=2, textvariable=inputA)
valEntryA.grid(row=0, column=1, padx=10, pady=10)

tk.Label(root, text="Enter Value B").grid(row=1, column=0, padx=10, pady=10)
valEntryB = tk.Entry(root, width=10, borderwidth=2, textvariable=inputB)
valEntryB.grid(row=1, column=1, padx=10, pady=10)

tk.Radiobutton(root, text="Sum", variable=inOperator, value=1).grid(row=2, column=0)
tk.Radiobutton(root, text="Sub", variable=inOperator, value=2).grid(row=2, column=1)

reverseButton = tk.Button(root, text="Result", width=10, command=on_button_click)
reverseButton.grid(row=3, column=0, padx=10, pady=10)

valOutput = tk.Entry(root, width=10, borderwidth=2, textvariable=opResult)
valOutput.grid(row=3, column=1, padx=10, pady=10)

root.mainloop()

##########################################################