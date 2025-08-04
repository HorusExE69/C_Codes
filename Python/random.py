#aleatoire
from random import *
from Tkinter import *
#window = Tk()
#window.mainloop()
lancé_de_dé_a_6_face=randint(1,6)
lancé_de_dé_a_12_face=randint(1,12)
lancé_de_pièce=randint(1,2)
rp=input("?")
if rp == "6" :
    print(lancé_de_dé_a_6_face)
elif rp == "12" : 
    print(lancé_de_dé_a_12_face)
elif rp == "2" :
    print(lancé_de_pièce)