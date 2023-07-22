import cv2
from tkinter import *
from tkinter import filedialog
import os

root=Tk()
root.geometry("800x800")

nb_frame_passe=1#1 frame sur 2
nb_frame_passe+=1
def upload_image():
    global dir
    dir = filedialog.askopenfilename()

def convert():
    dest=filedialog.askdirectory()
    cam = cv2.VideoCapture(dir)
    cr_frame=0
    while(True):

        # reading from frame
        ret,frame = cam.read()

        if ret:
            if cr_frame%nb_frame_passe:
                # if video is still left continue creating images
                name = dest+'/' + str(cr_frame) + '.png'
                print ('Creating...' + name)

                # writing the extracted images
                cv2.imwrite(name, frame)

                # increasing counter so that it will
                # show how many frames are created
            cr_frame += 1
        elif not(ret):
            print("ended")
            break

B=Button(root,text="upload video",command=upload_image)
B.pack()
B=Button(root,text="convert to image",command=convert)
B.pack()


root.mainloop()
