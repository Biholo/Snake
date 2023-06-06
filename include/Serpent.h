#ifndef __SERPENT__
#define __SERPENT__

#include <stdio.h>
#include <stdlib.h>

#include "Case.h"

//Directions du serpent
typedef enum {
    NORD,
    SUD,
    WEST,
    EST
} Direction;

typedef struct Serpent {
    Direction direc;
    Liste corp;
} Serpent;

/**
 * @brief Permet d'initialiser le serpent.
 * 
 * @param nb_lignes (int) Dimenssion maximun en y
 * @param nb_colonnes (int) Dimenssion maximun en x
 * @param taille (int) Taille du serpent à l'initialisation
 * @return Un serpent initialisé de la bonne taille
*/
Serpent serpent_initialiser(int nb_lignes, int nb_colonnes, int taille);

/**
 * @brief La prochaine case visé par la tête du serpent.
 * 
 * @param serp (Serpent) Serpent
 * @return La prochaine case vise par le serpent
*/
Case serpent_case_visee(Serpent serp);

#endif