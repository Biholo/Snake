#include "../include/Config.h"

//Lis le fichier de configuration et fixe les paramètres
void lire_config(char *config_file, Config *conf) {
    FILE *f;
    f = fopen(config_file, "r");
    char param[32];
    char value[32];

    if(f == NULL) {
        printf("Error lors de l'ouverture du fichier d'initialisation\n");
        exit(EXIT_FAILURE);
    }
    //Parcours des lignes du fichier de paramétrage
    while(fscanf(f, "%s = %s", param, value) == 2){
        if(strcmp(param, "largeur") == 0) {
            conf->largeur = atoi(value);
        }else if (strcmp(param, "hauteur") == 0) {
            conf->hauteur = atoi(value);
        } else if (strcmp(param, "nombre_pommes_normal") == 0) {
            conf->nombre_pommes = atoi(value);
        } else if (strcmp(param, "nombre_pommes_super") == 0) {
            conf->nombre_p_super = atoi(value);
        } else if (strcmp(param, "nombre_pommes_toxic") == 0) {
            conf->nombre_p_toxic = atoi(value);
        } else if (strcmp(param, "taille_serpent") == 0) {
            conf->taille_serpent = atoi(value);
        } else if (strcmp(param, "duree_tour") == 0) {
            conf->duree_tour = atoi(value);
        }
    }

    fclose(f);
}
