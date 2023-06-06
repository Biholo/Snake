#include "../include/Sound.h"
#include "../include/Case.h"

/*Génère une pomme aléatoire du type_case*/
Pomme pomme_aleatoire(int nb_lignes, int nb_colonnes, Type_case T) {
    Pomme P;   
    P.x = rand() % (nb_colonnes-1);
    P.y = rand() % nb_lignes;
    P.type = T;
    return P;
}

/*Génère une pomme aléatoire du type_case*/
void manger_pomme(Case C, Liste *L, Sounds sound) {
    Liste courant = *L;
    Liste precedent = NULL;
    //Parcours de la liste chainée
    while (courant != NULL) {
        if (courant->c.x == C.x && courant->c.y == C.y) { 
            if (precedent == NULL) {
                *L = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            play_sound(sound.eat);
            free(courant);
            return;
        }
        precedent = courant;
        courant = courant->suivant;
    }
}

/*verifier le case est dans la liste ou pas*/
int verifier(Case C, Liste L, Type_case T) {
    for(; L; L = L->suivant) {
        if(L->c.x == C.x && L->c.y == C.y && L->c.type == T) 
            return 1;/*si case est dans la liste, on return 1*/
    }
    return 0;/*sinon on return 0*/
}

/*Insere en tete de liste l'élément C*/
int insere_en_tete(Case C, Liste *L) {
    Liste tmp = (Cases *)malloc(sizeof(Cases));
    if(tmp != NULL) {
        tmp->c = C;
        tmp->suivant = *L;
        *L = tmp;/*inserer en tete de la liste de pommes*/
        return 1;
    }
    else {
        printf("Eurrer allouer la zone pour pomme !\n");
        return 0;/*allouer la zone avec eurrer*/
    }
}

//Supprime le dernière élément de la liste
void supprimer_queue(Liste *L) {
    for(; (*L)->suivant; L = &((*L)->suivant));
    free(*L);
    *L = NULL;
}