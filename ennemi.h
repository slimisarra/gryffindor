
#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include "perso.h"


typedef enum STATE STATE;
enum STATE {WAITING, FOLLOWING, ATTACKING};



typedef struct 
{
	int vie; 
	SDL_Surface *image ;
	SDL_Rect pos_es;
	STATE STATE;

}ennemi;






void initialiser_es (ennemi *es);
void afficher_es(ennemi *es,SDL_Surface *ecran);
void move_FB_Ennemi(ennemi* es);
void move_left_Ennemi(ennemi* es);
void move_right_Ennemi(ennemi* es);
void mvt_aleatoire_es (ennemi* es,SDL_Surface *ecran);
void UpdateEnnemi (ennemi *E, perso P,SDL_Surface* screen);
void IA (ennemi ennemi, perso P, int d1, int d2,SDL_Surface* screen);
int distance(perso p,ennemi e);





#endif // ENNEMI_H_INCLUDED
