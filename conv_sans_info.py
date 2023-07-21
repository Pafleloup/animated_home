from PIL import Image
from tkinter.filedialog import askopenfilename


chemin=askopenfilename(file='Selectionner une image', filetypes=[('PNG files','.png'),('all files','.*')])


def conv(chemin,palette):
    i=Image.open(chemin)
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

    largeur,hauteur=320,240
    A=""
    l=palette
    t_1="reemigration"
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
    print(l)
    return A
    print('char * liste1="'+A+'";')

pal=[(255, 255, 255), (167, 220, 243), (102, 159, 229), (62, 184, 242), (105, 223, 247), (210, 253, 252), (0, 0, 0), (163, 251, 252), (184, 255, 250), (71, 247, 249), (31, 143, 243), (16, 99, 204), (44, 122, 247), (15, 72, 202), (11, 45, 194), (7, 16, 184)]
conv(chemin,pal)