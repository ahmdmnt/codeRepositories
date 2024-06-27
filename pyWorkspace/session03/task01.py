#!/usr/bin/python3

## Task: 1.0
### pyAutoGUI - VSCODE Extension Installation
###    > install clangd from extension
import pyautogui
from time import sleep


pyautogui.hotkey("win")
sleep(2)

pyautogui.hotkey("v")
pyautogui.hotkey("s")
pyautogui.hotkey("c")
sleep(1)

pyautogui.moveTo(980, 180, duration=0.5)
pyautogui.click()
sleep(1)

try:
    imgLocation = None
    while imgLocation is None:
        imgLocation = pyautogui.locateOnScreen("extension_icon.png")
        sleep(1)
except pyautogui.ImageNotFoundException:
    print("Image Not Found")
    exit()

pyautogui.moveTo(imgLocation.left+15, imgLocation.top+15, duration=0.5)
sleep(1)
pyautogui.click()

pyautogui.hotkey("c")
pyautogui.hotkey("l")
pyautogui.hotkey("a")
pyautogui.hotkey("n")
pyautogui.hotkey("g")
pyautogui.hotkey("d")
sleep(1)

pyautogui.moveTo(200, 200, duration=0.5)
sleep(3)
pyautogui.click()

try:
    imgLocation = None
    while imgLocation is None:
        imgLocation = pyautogui.locateOnScreen("install_icon.png")
        sleep(1)
except pyautogui.ImageNotFoundException:
    print("Image Not Found")
    exit()
pyautogui.moveTo(imgLocation.left+15, imgLocation.top+15, duration=0.5)
sleep(1)
pyautogui.click()
##########################################################

