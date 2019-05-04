#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include "defs.h"
#include <stdlib.h>

#include "perso.h"

typedef struct background
{
    int stage;//numero de stage
    SDL_Rect pos;
    SDL_Rect post_background;//position du background par rapport a l ecran
    SDL_Surface *image[2];//tableau de background
   
} BACKGROUND;

void init_bck(BACKGROUND *Back);
void afficher_bk(SDL_Surface *ecran, BACKGROUND *back);

void scrolling (BACKGROUND *camera, int k,struct joueur* j,int i);
void afficher_bk(SDL_Surface *ecran, BACKGROUND *back);


#endif
