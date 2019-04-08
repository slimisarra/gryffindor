#include<stdlib.h>
#include<stdio.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL.h"
#include"perso.h"
#include"Collision.h"
#include <SDL/SDL_ttf.h>

int main(int argc,char* args[])
{

SDL_Rect pBackground;
SDL_Surface entity;
SDL_Surface background;

SDL_Init(SDL_INIT_VIDEO);//initialisation de la SDL

initialiser_afficher(&entity);
deplacement_clavier(&entity,&background);
GetPixel(2,3,4);
mapCollision(entity,&pBackground);


//Quit SDL
SDL_Quit();
printf("Au revoir \n");
return 0;
}
