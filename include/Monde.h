#ifndef __MONDE__
#define __MONDE__

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "Serpent.h"
#include "Sound.h"

typedef struct Monde {
    int lignes;
    int colonnes;
    int duree_tour;
    Serpent S;
    Liste Pommes;
    int nb_pommes;
} Monde;



/**
 * @brief  Ajoute une pomme du type T dans le monde, sur une case vide.
 * 
 * @param mon (Monde*) Monde matérialisant le jeu
 * @param T (Type_case) Liste chainée des pommes
*/
void monde_ajouter_pomme(Monde *mon, Type_case T);

/**
 * @brief  Initialise le monde avec les params prient en argument de la fonction.
 * 
 * @param nb_lignes (int) Nombre de ligne
 * @param nb_colonnes (int) Nombre de colonnes
 * @param taille_serpent (int) Taille du serpent à l'initialisation
 * @param nb_pommes (int) Nombre de pommes normal
 * @param toxic (int) Nombre de pomme toxic (meurt si mangé)
 * @param super_pomme (int) Nombre de super pomme (2 points si mangé)
 * @return Un Monde représentant le jeu.
*/
Monde monde_initialiser(int nb_lignes, int nb_colonnes, int taille_serpent, int nb_pommes, int toxic, int super_pomme);

/**
 * @brief  Vérifie si le serpent meurt au prochain déplacement.
 * 
 * @param mon (Monde) Monde représentant le jeu
 * @return 1 si le serpent meurt si non 0
*/
int monde_est_mort_serpent(Monde mon);

/**
 * @brief Déplacement et intéraction du serpent dans le jeu.
 * 
 * @param mon (Monde*) Monde représentant le jeu
 * @param sounds (Sounds) Sons initialisé.
*/
void monde_evoluer_serpent(Monde *mon, Sounds sounds);

/**
 * @brief Change la direstion du serpent en fonction des saisies de l'utilisateur.
 * 
 * @param mon (Monde*) Monde représentant le jeu
 * @param touche (int) Touche pressé.
 * @param sounds (Sounds) Sons initialisé.
*/
void interface_piloter(Monde *mon, int touche, Sounds sound);

/**
 * @brief Ajoute nb_pommes du type T dans le monde.
 * 
 * @param mon (Monde*) Monde représentant le jeu
 * @param nb_pommes (int) Nombre de pomme.
 * @param T (Type_case)  Type de pomme
*/
void ajouter_pommes(Monde *mon, int nb_pommes, Type_case T);

#endif
