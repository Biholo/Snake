#ifndef __CONFIG__
#define __CONFIG__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int largeur;
    int hauteur;
    int nombre_pommes;
    int nombre_p_toxic;
    int nombre_p_super;
    int taille_serpent;
    int duree_tour;
} Config;

/**
 * @brief Lit un fichier et récupère les informations paramétrant une partie.
 * 
 * @param config_file (Config*) Adresse de struct de configuration
 * @param conf (char*) Nom du fichier
 * @return  1 si l'ajout c'est bien passé si non 0;
 **/
void lire_config(char *config_file, Config *conf);

#endif