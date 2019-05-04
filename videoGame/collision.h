#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL/SDL.h>
#include "background.h"
#include "perso.h"
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y);

int collision_perpri(BACKGROUND *bg,joueur *j);

/*int collision_enigme(Background *bg,joueur *per);*/

/*int collision_ENDLevel(Background *bg,joueur *per);*/

/*int collision_sol(Background *bg,joueur *per);*/

#endif
