from PyQt5.QtCore import QTimer


def initFils(gv):
    gv.nbFilConnecte = len(gv.ordreFils) #Nbr de fils à connecter
    indexFilsConnecte = []  # ex, si 2 fils connecté, on peux avoir le 2ème fils sur le 4ème trou. On aurait alors indexFilsConnecte[1] = 3
    nbFilsCouleur = [0, 0, 0, 0, 0, 0]  # 0 Bleu, 1 Jaune, 2 Blanc, 3 Rouge, 4 Noir, 5 Vert

    indexTroue = 0
    for cable in gv.ordreFils:
        fils = cable[1]
        print(cable)
        if fils != "":
            indexFilsConnecte.append(indexTroue)
            print(indexFilsConnecte)
            if "b" in fils:
                nbFilsCouleur[0] += 1
            if "j" in fils:
                nbFilsCouleur[1] += 1
            if "w" in fils:
                nbFilsCouleur[2] += 1
            if "r" in fils:
                nbFilsCouleur[3] += 1
            if "n" in fils:
                nbFilsCouleur[4] += 1
            if "v" in fils:
                nbFilsCouleur[5] += 1
        indexTroue += 1

    print("nbFilsCouleur : " + str(nbFilsCouleur))
    print("indexFilsConnecte : " + str(indexFilsConnecte))
    print(indexFilsConnecte[-1])


    if gv.nbFilConnecte == 2:
        print("2 câbles")
        if nbFilsCouleur[3] == 0:
            gv.logiqueMsg = "Si il n'y a pas de fil rouge, débranchez le deuxième câble"
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[1]

        elif "w" in gv.ordreFils[indexFilsConnecte[-1]][1]:
            gv.logiqueMsg ="Sinon, si le dernier câble à un fil blanc, débranchez le dernier câble."
            print(gv.logiqueMsg)

            gv.filADeco = indexFilsConnecte[-1]

        elif nbFilsCouleur[0] == 1:
            gv.logiqueMsg ="Sinon, s'il y a plus d'un fil bleu, débranchez le dernier câble ayant un fil bleu."
            print(gv.logiqueMsg)

            compteurBleu = -1
            for cable in gv.ordreFils:
                fils= cable[1]
                if "b" in fils:
                    compteurBleu += 1
            gv.filADeco = indexFilsConnecte[compteurBleu]

        else:
            gv.logiqueMsg ="Sinon,débranchez le dernier câble"
            print(gv.logiqueMsg)

            gv.filADeco = indexFilsConnecte[1]


    if gv.nbFilConnecte == 3:
        print("3 câbles")
        if nbFilsCouleur[3] > 1 and isNumSerieImpair(gv):
            gv.logiqueMsg = "S'il y a plus d'un fil rouge et si le dernier chiffre du numéro de série est impair, débranchez le dernier câble ayant un fil rouge."
            print(gv.logiqueMsg)
            compteurRouge = -1
            for cable in gv.ordreFils:
                fils= cable[1]

                if "r" in fils:
                    compteurRouge += 1
            gv.filADeco = indexFilsConnecte[compteurRouge]

        elif "j" in gv.ordreFils[-1][1] and nbFilsCouleur[4] == 0:
            gv.logiqueMsg ="Sinon, si le dernier câble a un fil jaune et qu'il n'y a pas de fil noir, débranchez le premier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[0]

        elif nbFilsCouleur[0] == 2:
            gv.logiqueMsg ="Sinon, s'il y a exactement deux fil bleu, débranchez le deuxième câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[1]

        elif nbFilsCouleur[1] > 1:
            gv.logiqueMsg ="Sinon, s'il y a plus d'un fil jaune, débranchez le dernier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[-1]

        else:
            gv.logiqueMsg ="Sinon,débranchez le dernier câble"
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[1]


    if gv.nbFilConnecte == 4:
        print("4 câbles")

        if nbFilsCouleur[3] > 1 and isNumSerieImpair(gv):  # Rouge > 1 et numéro impair
            gv.logiqueMsg = "S'il y a plus d'un fil rouge et si le dernier chiffre du numéro de série est impair, débranchez le dernier câble ayant un fil rouge."
            print(gv.logiqueMsg)
            compteurRouge = -1
            for cable in gv.ordreFils:
                fils = cable[1]
                if "r" in fils:
                    compteurRouge += 1
            gv.filADeco = indexFilsConnecte[compteurRouge]

        elif "j" in gv.ordreFils[indexFilsConnecte[-1]][1] and nbFilsCouleur[3] == 0:  # dernier est jaune et pas de rouge
            gv.logiqueMsg = "Sinon, si le dernier câble est jaune et qu'il n'y a pas de fil rouge, débranchez le premier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[0]

        elif nbFilsCouleur[0] == 1:  # 1 bleu
            gv.logiqueMsg = "Sinon, s'il y a exactement un fil bleu, débranchez le premier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[0]

        elif nbFilsCouleur[1] > 1:  # jaune > 1
            gv.logiqueMsg = "Sinon, s'il y a plus d'un fil jaune, débranchez le dernier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[-1]

        else:
            gv.logiqueMsg = "Sinon, débranchez le deuxième câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[1]

    if gv.nbFilConnecte == 5:
        print("5 câbles")

        if "n" in gv.ordreFils[indexFilsConnecte[-1]][1] and isNumSerieImpair(gv):  # dernier est noir + impair
            gv.logiqueMsg = "Si le dernier câble est noir et si le dernier chiffre du numéro de série est impair, débranchez le quatrième câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[3]

        elif nbFilsCouleur[3] == 1 and nbFilsCouleur[1] > 1:  # un rouge + plusieurs jaunes
            gv.logiqueMsg = "Sinon, s'il y a exactement un fil rouge et plus d'un fil jaune, débranchez le premier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[0]

        elif nbFilsCouleur[4] == 0:  # aucun noir
            gv.logiqueMsg = "Sinon, s'il n'y a pas de fil noir, débranchez le deuxième câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[1]

        else:
            gv.logiqueMsg = "Sinon, débranchez le premier câble."
            print(gv.logiqueMsg)
            gv.filADeco = indexFilsConnecte[0]

    else:
        gv.logiqueMsg =  "Sinon, débrancher le quatrième cable"
        print(gv.logiqueMsg)
        gv.filADeco = indexFilsConnecte[3]
    gv.indexFilsConnecte = indexFilsConnecte

    print("index position filADeco : " + str(gv.filADeco))


def checkFils(self):
    gv = self.gameVar
    if gv.filADeco == -1 or gv.moduleWin[2] == 1:
        return
    if gv.etatFils[str(gv.filADeco + 1)] == 1 :
        QTimer().singleShot(200, lambda: winFils(gv))
        return

    for kfil, fil in gv.etatFils.items() :
        if fil == 1 and kfil not in gv.filDeco and int(kfil)-1 in gv.indexFilsConnecte:
            gv.filDeco.append(kfil)
            QTimer().singleShot(200, lambda: errFils(self))

def errFils(self):
    self.gameVar.filErreur = 1
    self.erreurGlobal(2)
    QTimer().singleShot(3000, lambda: shutdownErrorLed(self.gameVar))


def winFils(gv):
    gv.moduleWin[2] = 1


def shutdownErrorLed(gv):
    gv.filErreur = 0


def isNumSerieImpair(gv):
    num = [int(i) for i in list(gv.serialNumber) if i.isdigit()]
    print(num)
    return int(num[-1]) % 2 != 0
