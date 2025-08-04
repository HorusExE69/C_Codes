from turtle import *

# BASE : fondation du programme et excution

player = Turtle()
player.speed(5)

running = True

# FONCTION(1) : utilitaire

def q(variable):
    variable = False

# FONCTION(2) : deplacement

def up_move(t,d):
    t.setheading(0)
    t.forward(d)

def down_move(t,d):
    t.setheading(180)
    t.forward(d)

def right_move(t,d):
    t.setheading(90)
    t.forward(d)

def left_move(t,d):
    t.setheading(-90)
    t.forward(d)
    

# BOUCLE : boucle du jeu

while running:
    onkeypress(up_move(player,10),'Up')
    onkeypress(down_move(player,10),'Down')
    onkeypress(right_move(player,10),'Right')
    onkeypress(left_move(player,10),'Left')
    onkeypress(q(running),'Q')

    



listen()
mainloop()
