#include "../include/Monde.h"
#include "../include/Case.h"
#include "../include/Sound.h"

//Ajoute une pomme du type T dans le monde, sur une case vide.
void monde_ajouter_pomme(Monde *mon, Type_case T) {
    Pomme p;
    p = pomme_aleatoire(mon->lignes, mon->colonnes, T);
    //Tant que la pomme est superposé avec une pomme existante
    while (verifier(p, mon->Pommes, TOXIC) || verifier(p, mon->S.corp, SERPENT) || verifier(p, mon->Pommes, NORMAL) || verifier(p, mon->Pommes, SUPER))/*si la case est dans le corp de serpent ou dans la pommmes deja existe, on reinitialise la position de nouvelle pomme*/
    {
        p = pomme_aleatoire(mon->lignes, mon->colonnes, T);
    }

    insere_en_tete(p, &(mon->Pommes));
}

// Ajoute nb_pommes du type T dans le monde.
void ajouter_pommes(Monde *mon, int nb_pommes, Type_case T) {
    while (nb_pommes > 0) {
        monde_ajouter_pomme(mon, T);
        nb_pommes--;
    }
}

//Initialise le monde avec les params prient en argument de la fonction.
Monde monde_initialiser(int nb_lignes, int nb_colonnes, int taille_serpent, int nb_pommes, int toxic, int super_pomme) {
    Monde mon;
    mon.lignes = nb_lignes;
    mon.colonnes = nb_colonnes;
    mon.S = serpent_initialiser(nb_lignes, nb_colonnes/2, taille_serpent);
    mon.Pommes = NULL;
    //Tant
    while(nb_pommes) {
        monde_ajouter_pomme(&mon, NORMAL);
        nb_pommes--;
    }
    ajouter_pommes(&mon, nb_pommes, NORMAL);
    ajouter_pommes(&mon, toxic, TOXIC);
    ajouter_pommes(&mon, super_pomme, SUPER);
    mon.nb_pommes = 0;/*au debut le serpent manger 0 pommes*/
    return mon;
}

//Vérifie si le serpent meurt au prochain déplacement.
int monde_est_mort_serpent(Monde mon) {
    Case C = serpent_case_visee(mon.S);
    if(verifier(C, (mon.S).corp, SERPENT)) /*il vise une case à une case de son corps*/
        return 1;
    if(verifier(C, mon.Pommes, TOXIC))/*si il vise une case empoisonné*/
        return 1;
    else if (C.x > mon.colonnes || C.y > mon.lignes || C.x < -1 || C.y < -1) /*il vise une case à l’extérieur du quadrillage */
        return 1;
    return 0;/*il n'est pas mort*/
}

//Déplacement et intéraction du serpent dans le jeu.
void monde_evoluer_serpent(Monde *mon, Sounds sounds) {
    Case C_prochaine = serpent_case_visee(mon->S);

    /*verifier si ce case il y en a pomme ou pas*/
    if(verifier(C_prochaine, mon->Pommes, NORMAL) || verifier(C_prochaine, mon->Pommes, SUPER)) {

        if(verifier(C_prochaine, mon->Pommes, SUPER)) {
            monde_ajouter_pomme(mon, SUPER);  /*ajoute une nouvelle pomme normal*/
            mon->nb_pommes += 2; /*On augmente le score*/
        } else {
            monde_ajouter_pomme(mon, NORMAL);  /*ajoute une nouvelle pomme normal*/
            mon->nb_pommes++; /*On augmente le score*/
        }
        manger_pomme(C_prochaine, &(mon->Pommes), sounds);/*supprimer la pomme dans la liste*/

        insere_en_tete(C_prochaine, &(mon->S.corp)); /*inserer la nouvelle case dans la tete*/
    }
    else{    
        insere_en_tete(C_prochaine, &(mon->S.corp)); /*inserer la nouvelle case dans la tete*/

        supprimer_queue(&(mon->S.corp));
        /*supprimer la queue*/
    }

}

//Change la direstion du serpent en fonction des saisies de l'utilisateur.
void interface_piloter(Monde *mon, int touche, Sounds sound) {
    switch (touche) {
        case ' ':
            while(1){
                if(getch() == ' ')
                    break;
            }/*espace pour pause, espace encore pour commencer*/
            break;
            
        case KEY_UP:
            if(mon->S.direc == EST || mon->S.direc == WEST) {
                mon->S.direc = NORD;/*sinon on changer la direction*/
                play_sound(sound.turn);
            }
            break;

        case KEY_DOWN:
            if(mon->S.direc == EST || mon->S.direc == WEST) {
                mon->S.direc = SUD;
                play_sound(sound.turn);
            }    
            break;

        case KEY_LEFT:
            if(mon->S.direc == NORD || mon->S.direc == SUD) {
                mon->S.direc = WEST;
                play_sound(sound.turn);
            }              
            break;

        case KEY_RIGHT:
            if(mon->S.direc == NORD || mon->S.direc == SUD) {
                mon->S.direc = EST;
                play_sound(sound.turn);
            }     
            break;
        
        default:
            break;
    }
}

