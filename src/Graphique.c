#include "../include/Graphique.h"

//Initialisation des couleurs
void initialisation_colors(){
    init_pair(1, COLOR_BLACK, COLOR_GREEN );
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
}

/*affiche le quadrillage*/
void interface_afficher_quadrillage(Monde mon) {
    attron(COLOR_PAIR(1));
    for(int i = 0; i < mon.colonnes; i++) {
        for(int j = 0; j < mon.lignes; j++) {
            mvprintw(j, i*2, "|_|");
        }
    }
    attroff(COLOR_PAIR(1));
}

/* Affiche les pommes*/
void interface_afficher_pomme(Pomme pom) {
    if(pom.type == NORMAL) {  //Pomme normal
        attron(COLOR_PAIR(2));
        mvprintw( pom.y, pom.x * 2, "  ");
        attroff(COLOR_PAIR(2));
    } else if (pom.type == SUPER) { //Super pomme
        attron(COLOR_PAIR(5));
        mvprintw( pom.y, pom.x * 2, "  ");
        attroff(COLOR_PAIR(5));
    } else if(pom.type == TOXIC){ //Pomme toxic
        attron(COLOR_PAIR(6));
        mvprintw( pom.y, pom.x * 2, "  ");
        attroff(COLOR_PAIR(6));
    }
}

/* Affiche le serpent*/
void interface_afficher_serpent(Serpent ser) {
    Liste ser_corp = ser.corp;
    attron(COLOR_PAIR(4)); //Affiche la tête du serpent
    mvprintw(ser_corp->c.y, ser_corp->c.x * 2 + 1, "|_");
    attroff(COLOR_PAIR(4));

    attron(COLOR_PAIR(3)); 
    if(ser_corp->suivant != NULL) {
        ser_corp = ser_corp->suivant;
    }
    while(ser_corp != NULL){//Affiche le corp du serpent
        mvprintw(ser_corp->c.y, ser_corp->c.x * 2 + 1, "|_");
        ser_corp = ser_corp->suivant;
        if(ser_corp->suivant == NULL)
            break;
    }
    attroff(COLOR_PAIR(3));
}

/* Affiche le monde dans la globalité*/
void interface_afficher_monde(Monde mon) {
    clear();
    interface_afficher_quadrillage(mon);
    interface_afficher_serpent(mon.S);
    while(mon.Pommes != NULL){
        interface_afficher_pomme(mon.Pommes->c);
        mon.Pommes = mon.Pommes->suivant;
    }
}

//Affiche la fin de partie
void game_over(Monde mon) {
    clear();
    mvprintw(mon.lignes/2, mon.colonnes / 2 - 5, "Game Over!");
    mvprintw(mon.lignes/2 + 1, mon.colonnes / 2 - 11, "Votre score est de %d", mon.nb_pommes);
    refresh();
}