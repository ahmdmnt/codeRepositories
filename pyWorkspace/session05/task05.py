#!/usr/bin/python3

## Task: 5.0
### Program in Python that displays a window to the user that asks them to enter an integer N and displays its factorial

import tkinter as tk

def factorial(n):
    fact = 1
    for i in range(1, n+1):
        fact = fact * i
    return fact

def on_button_click():
    print(f"Input Value: {inputVal.get()}")
    fact = factorial(inputVal.get())
    outputVal.set(fact)
    print(f"Output Value: {outputVal.get()}")
#######################################

root = tk.Tk()
root.title("Factorial Calculator")

inputVal = tk.IntVar()
outputVal = tk.IntVar()

tk.Label(root, text="Enter a Value", font=("Arial", 12)).grid(row=0, column=0, padx=10, pady=10)

stringEntry = tk.Entry(root, width=30, borderwidth=2, textvariable=inputVal)
stringEntry.grid(row=0, column=1, padx=10, pady=10)

reverseButton = tk.Button(root, text="Generate Factorial", width=27, command=on_button_click)
reverseButton.grid(row=1, column=1, padx=10, pady=10)

tk.Label(root, text="Factorial Result =", font=("Arial", 12)).grid(row=2, column=0, padx=10, pady=10)

stringOutput = tk.Entry(root, width=30, borderwidth=2, textvariable=outputVal)
stringOutput.grid(row=2, column=1, padx=10, pady=10)


# Start the Tkinter event loop
root.mainloop()
##########################################################