def copy(filedepart, pathdest):
        
        # formatage de la commande dos pour la copie
        
    command = "copy " + filedepart + " " + pathdest # ommand
    system(command) # execution de la commande
    a = 12
    #j'ajoute
    print("je fais un ajout")