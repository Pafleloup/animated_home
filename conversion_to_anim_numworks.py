from tkinter import *
from tkinter import filedialog
import os
from PIL import Image,ImageTk as iim

root=Tk()
root.geometry("800x800")


liste_image=[]
def keykey(x):
    x=x.split(".")[0]
    return int(x)

def upload_image():
    global liste_image
    dir = filedialog.askdirectory()
    liste=os.listdir(dir)
    liste.sort(key=keykey)
    print(liste)
    for i in liste:
        liste_image.append(Image.open(dir+"/"+i))
def conv(chemin):
    i=Image.open(chemin)
    l=[]
    (largeur, hauteur)= i.size
    if largeur>320:
        largeur=320
    if hauteur>240:
        hauteur=240
    if i.mode == "P":
        i=i.convert('RGB')
        print("converti")

    def truc(x):
        x1=hex(x[0])
        x2=hex(x[1])
        x3=hex(x[2])
        return(x1,x2,x3)

    def to_b62(x):
        A=""
        while x>62:
            A+=t_b62(x//62)
            x=x%62
        A+=t_b62(x)
        return A
    def t_b62(x):
        if x<10:
            return str(x)
        elif x<35:
            return chr(x+55)
        else:
            return chr(x+61)
    def b62(x):
        A=0
        for t,i in enumerate(x):
            n=len(x)-t-1
            if ord(i)<58:
                A+=(int(i))*62**n
            elif ord(i)<91:
                A+=(ord(i)-55)*62**n
            else:
                A+=(ord(i)-61)*62**n
        return A


    def chn_():
        if chn<5:
            return(chn*to_b62(l.index(t_1)))
        A=to_b62(chn)
        while len(A)<3:
            A="0"+A
        return("*"+A+to_b62(l.index(t_1)))

    A=""
    t_1="sus"
    chn=0
    s=False
    for y in range(hauteur):
        for x in range(largeur):
            t=i.getpixel((x,y))
            if t in l:
                if x<largeur-1 and t==i.getpixel((x+1,y)):
                    chn+=1
                else:
                    if chn!=0:
                        A+=chn_()
                    A+=t_b62(l.index(t))
                    chn=0
            else:
                if chn!=0:
                    A+=chn_()
                l.append(t)
                A+=t_b62(l.index(t))
                chn=0
            t_1,s=t,True
        if chn!=0:
            A+=chn_()
    """
    for i in l:
        print("KDColor::RGB24(0x"+str(hex(i[0]))[2:]+str(hex(i[1]))[2:]+str(hex(i[2]))[2:]+"),")


    """
    B=to_b62(len(l))
    print(len(l))
    for i in l :
        a,b,c=hex(i[0]),hex(i[1]),hex(i[2])
        a,b,c=str(a)[2:],str(b)[2:],str(c)[2:]
        print(a,b,c,end="|")
        B+=(2-len(a))*"0"+a+(2-len(b))*"0"+b+(2-len(c))*"0"+c
    return B+A

def export():
    dir= filedialog.askdirectory()
    with open(dir+'/bg2.cpp','w') as b :
        b.write("int s=1;\nint sleep=40 ;\nint len_tab="+str(len(liste_converti))+";\nchar* liste["+str(len(liste_converti))+"]={")
    for n,i in enumerate(liste_converti):
        i.save(dir+"/"+str(n)+"_conv.png")
        with open(dir+'/bg2.cpp','a') as b:
            b.write('"'+conv(dir+"/"+str(n)+"_conv.png")+'",')
    with open(dir+'/bg2.cpp','a') as b :
        b.write("};")


def conv_palette():
    global liste_image,liste_converti
    global imag,palette
    dither=False
    liste_converti=[]
    imag=[]
    groot=Frame(root)
    groot.pack()
    for n,i in enumerate(liste_image):

        img=i.convert("P",0, palette=Image.ADAPTIVE,colors=16)
        if img.size[0]<320:
            img=img.resize((320,round((320*img.size[1])/img.size[0])))
        liste_converti.append(img)

        imag.append(iim.PhotoImage(liste_converti[-1].resize((160, 120))))
        Label(groot,image=imag[-1]).grid(column=n%5,row=n//5)

B=Button(root,text="upload image",command=upload_image)
B.pack()
B=Button(root,text="converti image",command=conv_palette)
B.pack()
B=Button(root,text="export",command=export)
B.pack()
root.mainloop()