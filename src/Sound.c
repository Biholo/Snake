#include "../include/Sound.h"

//Initialise les sons nécessaire.
Sounds init_sounds(){
    Sounds s;
    //Initialisation des sons
    s.eat = MLV_load_sound( "./src/Sound/eat.ogg" );
    s.death = MLV_load_sound( "./src/Sound/gameover.ogg" );
    s.turn = MLV_load_sound( "./src/Sound/clavier.ogg" );
    return s;

}

//Joue le son prit en paramètre.
void play_sound(MLV_Sound* s){
    MLV_play_sound( s, 1.0 );
}

//Ferme les sons initialisé.
void close_sounds(Sounds * s){
    MLV_stop_all_sounds();
    //Libération de la mémoire utilisé par les sons
    MLV_free_sound(s->death);
    MLV_free_sound(s->eat);
    MLV_free_sound(s->turn);
    MLV_free_audio();
}