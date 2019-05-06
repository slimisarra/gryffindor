/** 
*@file main.c
*@brief Testing Program (object)
*@author Gryffindor
*@version 0.1
*@date May 05,2019
*
*Testing object
*
*/


#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "objet.h"
#include <math.h>
#include <stdbool.h>

int main()
{Meat Meat[4];
Bone Bone[6];
SDL_Surface *image,*Player,*C_Object,scoreplus,scoremoins ;
SDL_Rect *position,Pposition,Oposition,sc_position;
int x,y,vie;
char nom_obj[];
      //**************NIVEAU 1*****************
//affichage des objets meat et bone; //taille de l ecran choisie 1600 x 600
SDL_Surface* init_affich_objet(&image ,Meat[1].position1,800,200,"meat.png");
SDL_Surface* init_affich_objet(&image ,Meat[2].position1,1500,400,"meat.png");
SDL_Surface* init_affich_objet(&image ,Bone[1].position1,1200,200,"bone.png");
SDL_Surface* init_affich_objet(&image ,Bone[2].position1,950,400,"bone.png");
SDL_Surface* init_affich_objet(&image ,Bone[3].position1,400,200,"meat.png");

//collisions avec les objets soit + soit -
int modifscore(&Player,Pposition,scoreplus,scoremoins,vie,sc_position);


return 0;
}
