#!/usr/bin/python3

import speech_recognition as sr
from playsound import playsound
from datetime import datetime
from gtts import gTTS
import webbrowser
import pyaudio
import wave
import json
import os

with open("alexaRespDatabase.json", 'r') as file:
        alexaResponds = json.load(file)

with open("alexaWordsDatabase.json", 'r') as file:
        alexaRecogWords = json.load(file)

class Alexa:
    username = 0
    lang = 0

    textData = 0
    timeData = 0
    dayData = 0

    def __init__(self, username, lang):
        self.username = username
        self.lang = lang
        
        self.Speak("welcome")
        ################################################################

    def Listen(self, duration, audio_file):
        # Set parameters for recording
        chunk = 1024  # Record in chunks of 1024 samples
        sample_format = pyaudio.paInt16  # 16 bits per sample
        channels = 1  # Mono audio
        fs = 44100  # Record at 44100 samples per second

        p = pyaudio.PyAudio()  # Create an interface to PortAudio

        print('Listening...')

        # Open a new stream for recording
        stream = p.open(format=sample_format, channels=channels,
                        rate=fs, frames_per_buffer=chunk, input=True)

        frames = []  # Initialize array to store frames

        # Store data in chunks for the specified duration
        for i in range(0, int(fs / chunk * duration)):
            data = stream.read(chunk)
            frames.append(data)

        # Stop and close the stream
        stream.stop_stream()
        stream.close()
        # Terminate the PortAudio interface
        p.terminate()

        print('Finished recording')

        # Save the recorded data as a WAV file
        wf = wave.open(audio_file, 'wb')
        wf.setnchannels(channels)
        wf.setsampwidth(p.get_sample_size(sample_format))
        wf.setframerate(fs)
        wf.writeframes(b''.join(frames))
        wf.close()
        return audio_file
        ################################################################

    def RecognizeRequest(self, audio_file):
        # Initialize recognizer class (for recognizing the speech)
        recognizer = sr.Recognizer()

        # Reading Audio file as source
        # Listening the audio file and store in audio_text variable
        with sr.AudioFile(audio_file) as source:
            audio_text = recognizer.record(source)

        if self.lang == "ar":
            lang = "ar-SA"
        else:
            lang = "en"

        # Recognize speech using Google Web Speech API
        try:
            # Using google speech recognition
            self.textData = recognizer.recognize_google(audio_text, language=lang)
            print(f'User >>> {self.textData}')
            result = True

        except Exception as e:
            print(f"Error: {e} Recognizing Request!")
            result = False

        return result
        ################################################################

    def Speak(self, respondCommand):
        if(respondCommand == "welcome"):
            alexaText = self.username+" "+alexaResponds[self.lang][respondCommand]
        elif(respondCommand == "time"):
            alexaText = alexaResponds[self.lang][respondCommand] + self.timeData
        elif(respondCommand == "day"):
            alexaText = alexaResponds[self.lang][respondCommand] + self.dayData
        else:
            alexaText = alexaResponds[self.lang][respondCommand]

        print(f"Alexa >> {alexaText}")
        # Convert text to speech
        tts = gTTS(text=alexaText, lang=self.lang)
        output_file = "output.mp3"
        tts.save(output_file)
        # Play the converted file
        playsound(output_file)
        # Remove the file after playing
        os.remove(output_file)
        ################################################################

    def Respond(self):
        for word in alexaRecogWords[self.lang]["clock"]:
            if word in self.textData:
                self.timeData = datetime.now().strftime("%H:%M:%S")
                self.Speak("time")
                return
        for word in alexaRecogWords[self.lang]["day"]:
            if word in self.textData:
                self.dayData = alexaResponds[self.lang]["days"][datetime.now().weekday()]
                self.Speak("day")
                return
        for word in alexaRecogWords[self.lang]["google"]:
            if word in self.textData:
                self.Speak("requestOK")
                webbrowser.open("www.google.com")
                return
        for word in alexaRecogWords[self.lang]["facebook"]:
            if word in self.textData:
                self.Speak("requestOK")
                webbrowser.open("www.facebook.com")
                return
        for word in alexaRecogWords[self.lang]["vscode"]:
            if word in self.textData:
                self.Speak("requestOK")
                os.system("code &")
                return
        for word in alexaRecogWords[self.lang]["youtube"]:
            if word in self.textData:
                self.Speak("requestOK")
                webbrowser.open("www.youtube.com")
                return
        ################################################################
    
    def PerformAnotherRequest(self):
        voiceCommandFile = "voiceCommandRecord.wav"
        self.Speak("anotherRequest")
        self.Listen(3, voiceCommandFile)
        requestRecognized = self.RecognizeRequest(voiceCommandFile)
        if requestRecognized:
            for word in alexaRecogWords[self.lang]["yes"]:
                if word in self.textData:
                    self.CleanVoiceRecord(voiceCommandFile)
                    self.Speak("request")
                    return False
            for word in alexaRecogWords[self.lang]["no"]:
                if word in self.textData:
                    self.CleanVoiceRecord(voiceCommandFile)
                    return True
        else:
            return True
        ################################################################

    def CleanVoiceRecord(self, audio_file):
        os.remove(audio_file)
        ################################################################

    def __del__(self):
        pass
        ################################################################


if __name__ == "__main__":
    voiceCommandDuration = 5 # Duration in seconds
    voiceCommandFile = "voiceCommandRecord.wav"  # Output file name

    alexaInstance = Alexa(username="Ahmed")
    alexaInstance.Listen(voiceCommandDuration, voiceCommandFile)
    alexaInstance.RecognizeRequest(voiceCommandFile)
    alexaInstance.Speak("Hello, Ahmed, Yes sure, Request is under processing!")
    alexaInstance.CleanVoiceRecord(voiceCommandFile)
