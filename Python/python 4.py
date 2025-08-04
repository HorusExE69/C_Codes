import turtle

LARGEUR, HAUTEUR = 256, 256

if __name__ == "__main__":
    pos_y = -HAUTEUR/2  #On initialise la position en hauteur initiale
    turtle.setup(LARGEUR, HAUTEUR)  #On initialise la fenêtre
    turtle.speed(0)  #On met la vitesse de traçage la plus rapide
    #Pour val allant de 255 à 0 (couleur)
    for val in range(255, -1, -1):
        #On se déplace au début de la ligne à tracer
        turtle.up(); turtle.goto(-LARGEUR, pos_y); turtle.down()
        turtle.pencolor((val/255, 0, val/255)) #On prépare la couleur
        turtle.forward(LARGEUR)  #On trace la ligne
        pos_y += 1  #On remonte de 1px à chaque fois
    turtle.exitonclick()
