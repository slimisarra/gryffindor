
#include<SDL/SDL.h>
#define CAMERA_W 1600
#define CAMERA_H 600
/**
* @struct Background
* @brief struct for backround
*/



struct background
 { SDL_Rect bckg;
   SDL_Surface*img;}; typedef struct background background;

void init_bckg(background*b,char heratofmira[]);
void afficher_bckg(SDL_Surface*ecran,background*b);
void scrolldroite(background*b);


