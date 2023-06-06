#ifndef __CASE__
#define __CASE__

#include <stdio.h>
#include <stdlib.h>

#include "Sound.h"

typedef enum {
    NORMAL,
    TOXIC,
    SUPER,
    SERPENT
} Type_case;

typedef struct {
    int x;
    int y;
    Type_case type;
} Case, Pomme;

typedef struct __case__ {
    Case c;
    struct __case__ *suivant;
} Cases, *Liste;

/**
 * @brief Génère une pomme du Type_case avec des coordonnées aléatoire.
 * 
 * @param nb_lignes (int) Coordonnée maximun du plateau
 * @param nb_colonnes (int) Coordonnée maximun du plateau
 * @param T (Type_case) type de pomme
 * @return  les coordonées d'une case
*/
Pomme pomme_aleatoire(int nb_lignes, int nb_colonnes, Type_case T);

/**
 * @brief Lorsque le serpent mange une pomme, on la retire de la liste des pommes.
 * 
 * @param C (Case) Prochaine case visé par le serpent
 * @param L (Liste*) Liste chainée des pommes
 * @param sound (Sounds) Jouer un sons lorsque le serpent mange une pomme
*/
void manger_pomme(Case C, Liste *L, Sounds sound);

/**
 * @brief Verifie que la prochaine case d'une liste L soit tu Type_case.
 * 
 * @param C (Case) Prochaine case visé par le serpent
 * @param L (Liste) Liste chainée des pommes
 * @param T (Type_case) Type_case à vérifier
 * @return  1 si prochaine case du type case si non 0;
*/
int verifier(Case C, Liste L, Type_case T);


/**
 * @brief Insere en tête de liste la case C.
 * 
 * @param C (Case) Prochaine case visé par le serpent
 * @param L (Liste*) Liste chainée des pommes
 * @return  1 si l'ajout c'est bien passé si non 0;
*/
int insere_en_tete(Case C, Liste *L);


/**
 * @brief Supprime le dernière élément de la liste L.
 * 
 * @param L (Liste*) Liste chainée
*/
void supprimer_queue(Liste *L);
#endif