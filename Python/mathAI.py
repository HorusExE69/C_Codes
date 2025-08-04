from math import *
def math(a):
    q2=input("?")
    if q2 == "as":
        print(abs(a))
        #valeur absolue
    elif q2 == "sr":
        print(sqrt(a))
        #racine carrée
    elif q2 == "ar":
        print(round(a))
        #arrondissement

def mathop(b,c):
    q3=input("?")
    if q3 == "d":
        print(b/c)
        #division
    elif q3 == ".d":
        print(c/b)
        #division inverse
    elif q3 == "dd":
        print(b//c)
        #division euclidienne
    elif q3 == ".dd":
        print(c//b)
        #division euclidienne inverse
    elif q3 == "rd":
        print(b%c)
        #reste
    elif q3 == ".rd":
        print(c%b)
        #reste inverse
    elif q3 == "x":
        print(b*c)
        #multiplication
    elif q3 == "p":
        print(b+c)
        #addition
    elif q3 == "m":
        print(b-c)
        #soustraction
    elif q3 == ".m":
        print(c-b)
        #soustraction inverse
    elif q3 == "e":
        print(b**c)
        #puissance
    elif q3 == ".e": 
        print(c**b)
        #puissance inverse