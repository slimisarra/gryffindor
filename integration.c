#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include"ennemi.h"

int main (void)
{

ennemi tab[15];
int i;
SDL_Init(SDL_INIT_VIDEO);

for(i=0;i<15;i++)
{
initialiser_afficher(&tab[i]);
deplacer_ennemi(&tab[i]);
}

SDL_Quit() ;

return EXIT_SUCCESS ;
}
