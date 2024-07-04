#!/usr/bin/python3

from pytube import YouTube 

def youtubetDownload(link):
    print("Open Youtube link and get high resolution video.")
    youtubeObject = YouTube(link)
    title = youtubeObject.title
    youtubeObject = youtubeObject.streams.get_highest_resolution()
    try:
        print(f"Downloading Video ... {title}")
        youtubeObject.download()
    except:
        print("An error has occurred")
    print("Download is completed successfully")


if __name__ == "__main__":
    with open('yt_file.txt', 'r') as yt_file:
        youtubeLinks = yt_file.readlines()
    
    count = 0
    for link in youtubeLinks:
        count +=1
        youtubetDownload(link)
