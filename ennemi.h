#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>


struct ennemi
{
SDL_Rect pos;
SDL_Surface *image ;
SDL_Rect frame ;
};typedef struct ennemi ennemi;


void initialiser_afficher(ennemi *e);
void deplacer_ennemi(ennemi *e);
void initialiser_joueur(ennemi *e);
void animate_right(ennemi *e);
void animate_left(ennemi *e);
void animate_up(ennemi *e);
void animate_down(ennemi *e);
void animate_jump (ennemi *e);



#endif
