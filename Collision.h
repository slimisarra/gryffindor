#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

#ifndef COLLISION_H_
#define COLLISION_H_

#define PERSO_H_

SDL_Color GetPixel(pbackground,int xp,int yp);
/*renvoie l'adresse d'un pixel, x et y sont les coordonnées de ce pixel */
void mapCollision(Perso *entity,SDL_Surface* pBackground);








#endif 
