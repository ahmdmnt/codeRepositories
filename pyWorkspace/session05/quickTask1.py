#!/usr/bin/python3

## quickTask: 1.0
### Make this template and each button display different name

import tkinter as tk

def on_button_click(button_text):
    print(f"{button_text} clicked")
#######################################

root = tk.Tk()
root.title("3x3 Grid with 4 Buttons")

button1 = tk.Button(root, text="Button 1", command=lambda text="Button 1": on_button_click(text))
button1.grid(row=0, column=1, padx=0, pady=0)

button2 = tk.Button(root, text="Button 2", command=lambda text="Button 2": on_button_click(text))
button2.grid(row=1, column=0, padx=0, pady=0)

button3 = tk.Button(root, text="Button 3", command=lambda text="Button 3": on_button_click(text))
button3.grid(row=1, column=2, padx=0, pady=0)

button4 = tk.Button(root, text="Button 4", command=lambda text="Button 4": on_button_click(text))
button4.grid(row=2, column=1, padx=0, pady=0)

root.mainloop()

##########################################################