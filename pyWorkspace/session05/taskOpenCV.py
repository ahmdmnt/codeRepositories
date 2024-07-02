#!/usr/bin/python3

## Task: OpenCV
### Capture and save a Photo

import cv2

def main():
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error, accessing the Camera!")
        return
    
    window_name = "Camera View"
    while True:
        ret, frame = cap.read()
        
        if not ret:
            print("Error, accessing the Camera!")
            break

        cv2.imshow(window_name, frame)
        
        key = cv2.waitKey(1)
        if key == ord('q'):         # Quit Application
            break
        
        elif key == ord('c'):       # Capture a Photo
            cv2.imwrite('preview.jpg', frame)
    
    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
##########################################################