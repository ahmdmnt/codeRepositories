#!/usr/bin/python3

## Task: 1.0
### program that asks the user to type a word and return him its reverse

import tkinter as tk

def on_button_click():
    print(f"Input String: {inputString.get()}")
    outputString.set(inputString.get()[::-1])
    print(f"Output String: {outputString.get()}")
#######################################

root = tk.Tk()
root.title("Reverse String")

inputString = tk.StringVar()
outputString = tk.StringVar()

tk.Label(root, text="Enter String").grid(row=0, column=0, padx=10, pady=10)

stringEntry = tk.Entry(root, width=50, borderwidth=2, textvariable=inputString)
stringEntry.grid(row=0, column=1, padx=10, pady=10)

stringOutput = tk.Entry(root, width=50, borderwidth=2, textvariable=outputString)
stringOutput.grid(row=1, column=1, padx=10, pady=10)

reverseButton = tk.Button(root, text="Reverse", command=on_button_click)
reverseButton.grid(row=2, column=1, padx=10, pady=10)

root.mainloop()

##########################################################