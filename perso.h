#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#ifndef PERSO_H_
#define PERSO_H_

#define COLLISION_H_

typedef struct Perso
{
  int x;
  int y;
  int w;
  int h;
  int dirX;
  int dirY;
  int onGround;
  int timerMort;
}Perso;



void initialiser_afficher(Perso *entity);
void deplacement_clavier(Perso* entity,SDL_Surface* background);



#endif 
