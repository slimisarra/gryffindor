#ifndef PERSO_H
#define PERSO_H
#include <SDL/SDL.h>
#include "background.h"
#include "perso.h"		

		
typedef struct joueur
{
    int status;
    float x,y;
    float vx,vy;
    SDL_Surface* image;
    SDL_Rect position;
    int vie;
} joueur;


void init_perso(joueur *j);

void afficherjoueur(joueur *j,SDL_Surface *ecran);

void Saute(joueur* j,float impulsion);

void ControleSol(joueur* j);

void Gravite(joueur* j,float factgravite,float factsautmaintenu,Uint8* keys);

void Evolue(joueur* j,Uint8* keys);




#endif
