#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "Monde.h"

/**
 * @brief Initialisation des couleurs utilisé au cours du programme. 
*/
void initialisation_colors();

/**
 * @brief Affiche le quadrillage du jeu.
 * 
 * @param mon (Monde) 
*/
void interface_afficher_quadrillage(Monde mon);

/**
 * @brief Affiche le serpent.
 * 
 * @param ser (Serpent) 
*/
void interface_afficher_serpent(Serpent ser);

/**
 * @brief Affiche les pommes
 * 
 * @param pom (Pomme) 
*/
void interface_afficher_pomme(Pomme pom);

/**
 * @brief Affiche le monde danse sa globalité.
 * 
 * @param mon (Monde) 
*/
void interface_afficher_monde(Monde mon);

/**
 * @brief Affiche la fin de partie
 * 
 * @param mon (Monde) 
*/
void game_over(Monde mon);
#endif