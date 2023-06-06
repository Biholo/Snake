#include "../include/Serpent.h"

//Permet d'initialiser le serpent
Serpent serpent_initialiser(int nb_lignes, int nb_colonnes, int taille) {
    Serpent s;
    s.direc = EST;
    Case C;
    C.x =  nb_colonnes / 2;/*mettre le serpent au centre de la fenetre*/
    C.y = nb_lignes  / 2 - 1;
    C.type = SERPENT;
    s.corp = NULL;
    while(taille) {
        insere_en_tete(C, &s.corp);
        C.x++;
        taille--;
    }
    return s;
}

//Return la prochaine case visé par la tête du serpent
Case serpent_case_visee(Serpent serp) {
    Case c = serp.corp->c;
    if(serp.direc == NORD) {
        c.y = serp.corp->c.y - 1;
    } else if(serp.direc == SUD) {
        c.y = serp.corp->c.y + 1;
    } else if(serp.direc == WEST) {
        c.x = serp.corp->c.x - 1;
    } else if(serp.direc == EST) {
        c.x = serp.corp->c.x + 1;
    }
    return c;
}
