from tkinter import *
from tkinter import messagebox
from tkinter.filedialog import askopenfilename

#bouton=Button(fenetre, text="Note", command=destroy)
#bouton.pack()

fenetre = Tk()
menubar = Menu(fenetre)
fenetre.config(menu=menubar)
menufichier = Menu(menubar,tearoff=0)
menubar.add_cascade(label="Fichier", menu=menufichier)
menuedition = Menu(menubar,tearoff=0)
menubar.add_cascade(label= "Edition", menu=menufichier)

#import tkinter.filedialog

#f=tkinter.filedialog.asksaveasfile(
    #title="Enregistrer sous ... un fichier",
    #filetypes=[('CSV files','.csv')])

