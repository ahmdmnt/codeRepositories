## Module created for task01.py
import webbrowser

favURL = {
    "facebook": "www.facebook.com",
    "youtube" : "www.youtube.com",
    "udemy"   : "www.udemy.com",
    "coursera": "www.coursera.com",
    "udacity" : "www.udacity.com"
}

def firefox(websiteName):
    webbrowser.open(favURL[websiteName])

##########################################################