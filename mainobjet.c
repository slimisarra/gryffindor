#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
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
//affichage des objets meat et bone; //taille de l ecran choisie 2000 x 1300 mais a verifier selon background
SDL_Surface* init_affich_objet(*image ,Meat[1].position1,800,1000,"meat.png");
SDL_Surface* init_affich_objet(*image ,Meat[2].position1,1800,400,"meat.png");
SDL_Surface* init_affich_objet(*image ,Bone[1].position1,1200,1000,"bone.png");
SDL_Surface* init_affich_objet(*image ,Bone[2].position1,1900,400,"bone.png");
SDL_Surface* init_affich_objet(*image ,Bone[3].position1,400,1000,"meat.png");

     //**************NIVEAU 2******************
 //affichage des objets restants de meat et bone
SDL_Surface* init_affich_objet(*image ,Meat[2].position1,400,500,"meat.png");
SDL_Surface* init_affich_objet(*image ,Meat[4].position1,1880,1000,"meat.png");
SDL_Surface* init_affich_objet(*image ,Bone[4].position1,700,500,"bone.png");
SDL_Surface* init_affich_objet(*image ,Bone[5].position1,1500,500,"bone.png");
SDL_Surface* init_affich_objet(*image ,Bone[6].position1,1000,1000,"meat.p
 
 //collisions avec les objets soit + soit -
int modifscore(*Player,Pposition,scoreplus,scoremoins,vie,sc_position);

return 0;
}
