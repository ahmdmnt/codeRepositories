#!/usr/bin/python3

## Task: 3.0
### Program to make Humidity Gauge like pic

import tkinter as tk
import math

def update_humidity_gauge(value):
    humidity_value = int(value)
    angle = 180 + (humidity_value * 1.8)  # Calculate the angle for the needle
    
    # Clear the canvas
    canvas.delete("all")
    
    # Draw the semi-circular gauge background
    canvas.create_arc(50, 50, 250, 250, start=180, extent=-180, style=tk.ARC, outline="gray", width=20)
    
    # Draw the filled part of the gauge
    extent = humidity_value * 1.8  # 180 degrees / 100 percent
    canvas.create_arc(50, 50, 250, 250, start=180, extent=-extent, style=tk.ARC, outline="blue", width=20)
    
    # Draw the gauge labels
    canvas.create_text(150, 130, text=f"{humidity_value}%", font=("Helvetica", 24), fill="black")
    
    # Draw min and max labels
    canvas.create_text(50, 180, text="0%", font=("Helvetica", 12), fill="gray")
    canvas.create_text(250, 180, text="100%", font=("Helvetica", 12), fill="gray")
    
    # Calculate needle end position
    needle_length = 80
    center_x = 150
    center_y = 150
    needle_x = center_x + needle_length * math.cos(math.radians(angle))
    needle_y = center_y + needle_length * math.sin(math.radians(angle))
    
    # Draw the needle
    canvas.create_line(center_x, center_y, needle_x, needle_y, fill="red", width=2)
    canvas.create_oval(center_x-5, center_y-5, center_x+5, center_y+5, fill="black")  # Needle pivot

# Create the main window
root = tk.Tk()
root.title("Humidity Gauge with Needle")
root.geometry("500x450")

# Create a Canvas to draw the gauge
canvas = tk.Canvas(root, width=300, height=300)
canvas.pack(pady=20)

# Initial drawing of the gauge
update_humidity_gauge(0)

# Create a Scrollbar for adjusting the humidity value
humidity_scrollbar = tk.Scale(root, from_=0, to=100, orient=tk.HORIZONTAL, command=update_humidity_gauge)
humidity_scrollbar.pack(pady=20)

# Start the Tkinter event loop
root.mainloop()
##########################################################