from tkinter import *
from string import *
from random import *
from pickle import *

gui = Tk()

alph = list(ascii_letters)
chiffres = list(digits)
all_c = chiffres + alph

lbl = Label(gui,text="Quelle longueure voulez vous ?")
lbl.pack()

myEntry = Entry(gui,width = 40)
myEntry.pack()

def getEntry():
    res = myEntry.get()
    mdp_S = ""
    for i in range(0,int(res)):
        mdp_S += all_c[randint(0,len(all_c)-1)]
    with open('mypicklefile', 'wb') as f1:
        dump(mdp_S, f1)
    with open('mypicklefile', 'rb') as f1:
        mdp_save = load(f1)
    print(mdp_save)
    mdp = Label(gui,text = mdp_S)
    mdp.pack()
    return mdp_save


btn = Button(gui, height=1, width=10, text="GENERATE", command=getEntry)
btn.pack()

mdp_save = getEntry()

gui.mainloop()
