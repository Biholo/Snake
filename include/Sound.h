#ifndef __SOUND__
#define __SOUND__

#include <MLV/MLV_all.h>

typedef struct {
    MLV_Sound* death;
    MLV_Sound* eat;
    MLV_Sound* turn;
} Sounds;

/**
 * @brief Initialise les sons nécessaire.
 * 
 * @return Les sons initialisé dans la struct Sounds
*/
Sounds init_sounds();

/**
 * @brief Joue le son prit en paramètre, permet de ne pas
 * include la lib MLV dans tout les modules.
 * 
 * @param s (MLV_Sound*) Type son de la lib MLV
*/
void play_sound(MLV_Sound* s);

/**
 * @brief Ferme les sons initialisé au debut du programme.
 * 
 * @param s (MLV_Sound*) Type son de la lib MLV
*/
void close_sounds(Sounds *s);

#endif