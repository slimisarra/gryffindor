#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>

/**
 *@struct ennemi 
 *@brief struct for ennemi
*/
struct ennemi
{
SDL_Rect pos; /*!<rectangle*/
SDL_Surface *image ; /*!<surface*/
};typedef struct ennemi ennemi;


void initialiser_ennemi(ennemi *e);
void afficher_ennemi(ennemi *e,SDL_Surface *ecran);
void move_left_Ennemi(ennemi* e);
void move_right_Ennemi(ennemi* e);
void deplacemant_aleatoire(ennemi *e);


#endif
