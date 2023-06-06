#include <time.h>


#include "../include/Config.h"
#include "../include/Graphique.h"
#include "../include/Sound.h"

int main() {
    srand(time(NULL));
    Config conf;
    Sounds sounds; 
    int touche;
    struct timespec sleep_time;
    sleep_time.tv_sec = 0; // seconds
        
    lire_config("./src/Serpent.ini", &conf);
    if( MLV_init_audio() ){
        fprintf(stderr, "L'infrasctructure audio de la librairie MLV ne s'est pas \
        correctement initialisé.");
        exit(1);
    }
    
    sounds = init_sounds();
    initscr();
    start_color();
    initialisation_colors();

    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);/*getch() without block*/
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    sleep_time.tv_nsec = conf.duree_tour * 100000; // nanoseconds (0.5 seconds)

    Monde mon = monde_initialiser(conf.hauteur, conf.largeur, conf.taille_serpent, conf.nombre_pommes, conf.nombre_p_toxic, conf.nombre_p_super);
    interface_afficher_monde(mon);/*afficher le monde initiale*/
    refresh();

    while (1) {
        touche = getch();
        if(touche != ERR){/*une touce par clavier pour commencer*/
            while(!monde_est_mort_serpent(mon)){
                sleep_time.tv_nsec =  (conf.duree_tour * 100000) / (1 + (mon.nb_pommes / 2)); //On augmente la vitesse du serpent en fonction du score

                touche = getch();/*enregister une touche de la clavier, s'il y en a*/
                interface_piloter(&mon, touche, sounds);/*changer la direction*/
                monde_evoluer_serpent(&mon, sounds);/*serpent bouge*/
                interface_afficher_monde(mon);/*afficher le monde apres le sepent bouge*/
                nanosleep(&sleep_time, NULL);/*la vitesse de déplacement du serpent*/
                refresh();    
            }
            break;
        }
    }
    sleep_time.tv_sec = 5; // seconds
    play_sound(sounds.death);
    game_over(mon);
    nanosleep(&sleep_time, NULL);/*pause fin*/

    endwin();
    close_sounds(&sounds);
    return 0;
}