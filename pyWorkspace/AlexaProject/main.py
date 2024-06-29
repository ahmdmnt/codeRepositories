#!/usr/bin/python3
    
import alexa as a

if __name__ == "__main__":
    voiceCommandDuration = 5 # Duration in seconds
    voiceCommandFile = "voiceCommandRecord.wav"  # Output file name

    # alexaInstance = a.Alexa(username="Ahmed", lang="en")
    alexaInstance = a.Alexa(username="أحمد", lang="ar")
    
    while True:    
        requestRecognized = False
        while not(requestRecognized):
            alexaInstance.Listen(voiceCommandDuration, voiceCommandFile)
            requestRecognized = alexaInstance.RecognizeRequest(voiceCommandFile)
            if requestRecognized:
                alexaInstance.Speak("requestOK")
            else:
                alexaInstance.Speak("requestNOK")

        alexaInstance.Respond()
        alexaInstance.CleanVoiceRecord(voiceCommandFile)
        
        exitApp = alexaInstance.PerformAnotherRequest()
        if(exitApp):
            alexaInstance.Speak("bye")
            break
        

    

