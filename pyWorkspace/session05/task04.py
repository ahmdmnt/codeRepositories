#!/usr/bin/python3

## Task: 4.0
### Program using Tk ,,, Toggle a LED

import tkinter as tk

class LEDToggleApp:
    def __init__(self, root):
        self.root = root
        self.root.title("LED GUI")
        self.root.geometry("250x350")

        # Canvas for drawing the LED
        self.canvas = tk.Canvas(root, width=200, height=200)
        self.canvas.pack(pady=20)

        # Button to toggle the LED state
        self.toggle_button = tk.Button(root, text="Switch LED", command=self.toggle_led)
        self.toggle_button.pack(pady=20)

        # Initial LED state
        self.led_on = False
        self.draw_led()

    def draw_led(self):
        # Clear the canvas
        self.canvas.delete("all")
        
        # Draw the LED shape
        led_color = "green" if self.led_on else "red"
        self.canvas.create_oval(50, 50, 150, 150, fill=led_color, outline="black", width=2)
        
        # Draw the LED label
        led_state = "ON" if self.led_on else "OFF"
        self.canvas.create_text(100, 180, text=f"LED is {led_state}", font=("Helvetica", 16), fill="black")

    def toggle_led(self):
        # Toggle the LED state
        self.led_on = not self.led_on
        self.draw_led()

# Create the main window
root = tk.Tk()
app = LEDToggleApp(root)

# Start the Tkinter event loop
root.mainloop()
##########################################################