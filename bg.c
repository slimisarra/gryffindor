

/**
* @file background.c
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"bg.h"



/**
* @brief To initialize the background b .
* @param b the background
* @param url the url of the image
* @return Nothing
*/

void init_bckg(background*b,char heratofmira[])

{  
 b->img= IMG_Load (heartofmira);
 b->bckg.X = 0;
 b->bckg.Y = 0;
 b->bckg.W = b->img->W;
 b->bckg.H = b->img->H;}

/**
* @brief To show the background b .
* @param scren the screen
* @param b the background
* @return Nothing
*/


void afficher_bckg(SDL_Surface*ecran,background*b)

{ SDL_BlitSurface(b.img,&(b.bckg),eran,NULL);}

/**
* @brief To scroll the background to the right .
* @param b the background
* @return Nothing
*/


void scrolldroite(background*b)

{ if (b->bckg.w - b->bckg.X !=CAMERA_w)
  b->bckg.X++;}
