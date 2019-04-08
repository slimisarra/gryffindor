#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include"ennemi.h"
#include"objet.h"
#include"background"
#include"perso1.h"
#include"perso2.h"
#include"enigme.h"

int main (void)
{

ennemi tab[15];
meat m[10];
bone b[10];
int i;
SDL_Init(SDL_INIT_VIDEO);


initialiser_background();
afficher_background();

for(i=0;i<20;i++)
{
initialier_objet(&m[i]);
afficher_objet(&m[i]);

initialiser_objet(&b[i]);
afficher_objet(&b[i]);
}



for(i=0;i<15;i++)
{
initialiser_afficher(&tab[i]);
deplacer_ennemi(&tab[i]);

}


initialiser_afficher(Perso * entity);
switch (case)
{
case 1 : deplacement_clavier(&entity , &background);
         break;

case 2 : deplacement_souris(&entity , &background);
         break;
}


if collisionBox(objet,perso)
{
  afficher_enigme();
  if (verifier_enigme()==1)
   {
   x=score();
   x=++;
   }
 }



SDL_Quit() ;

return EXIT_SUCCESS ;
}
