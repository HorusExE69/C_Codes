#MODULES

import tkinter as tk
from tkinter import ttk
from math import *



#FN

def lst(mn,mx,ssl=1,e=0):
    lst=[i for i in range(1,e+1)]
    if ssl == 1:
        lst += [i for i in range(mn,mx+1)]
    if ssl == 2:
        lst += [[i for i in range(j,j+e)] for j in range(mn,mx+1,e)]
    return lst

def genTbl(mn,mx,ssl,e):
    y = 22
    global dico
    if e == 3:
        table["columns"]=("1","2","3")
    if e == 4:
        table["columns"]=("1","2","3","4")
        
    for j in range(1,ssl+3):
        separator = ttk.Separator(tk,orient="vertical")
        separator.place(x=200*j,y=0,relheight=1)
    
    for i in range(len(lst(mn,mx,ssl,e))):
        if e == 3 and ssl == 2 : table.insert("","end",text=dico[i],values=(str(lst(mn,mx,ssl,e)[i][0]),
                                                             str(lst(mn,mx,ssl,e)[i][1]),
                                                             str(lst(mn,mx,ssl,e)[i][2])))
        if e == 4 and ssl == 2 :table.insert("","end",text=dico[i],values=(str(lst(mn,mx,ssl,e)[i][0]),
                                                             str(lst(mn,mx,ssl,e)[i][1]),
                                                             str(lst(mn,mx,ssl,e)[i][2]),
                                                             str(lst(mn,mx,ssl,e)[i][3])))
        if i > 1:
            separator = ttk.Separator(tk,orient="horizontal")
            separator.place(x=0,y=y+18,relwidth = 1)
            y += 18
        else :
            separator = ttk.Separator(tk,orient="horizontal")
            separator.place(x=0,y=y,relwidth = 1)


def defVariable(val,var):
    var=val
            


#MAIN

dico = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mn=0
mx=19
ssl=2
e=3

tk = tk.Tk()
tk.title("TABLEUR")
tk.geometry("1000x1000")
table = ttk.Treeview(tk,columns = (),show="tree")
genTbl(mn,mx,ssl,e)
table.pack()


tk.mainloop()

