/**
 *
 *@struct Meat
 *@brief struct for object 1
 *@struct Bone
 *@brief struct for object 2
 *
*/





#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <SDL/SDL_image.h>
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include "objet.h"
#include <math.h>
#include <stdbool.h>

typedef struct
{ SDL_Surface *image1 = NULL; /*!<Surface. */
  SDL_Rect position1; /*!<Rectangle*/
}Meat;

typedef struct
{ SDL_Surface *image2 = NULL; /*!<Surface. */
  SDL_Rect position2; /*!<Rectangle*/
}Bone;

SDL_Surface* init_affich_objet(*image ,*position,x,y,nom_obj[]);
//initialisation affichage objet

bool CollisionTrigoInsc (&Player,&C_Object,Pposition,Oposition);
//collision trigo

bool CollisionTrigoCir (&Player,&C_Object,Pposition,Oposition);
//collision circ

int modifscore(&Player,obj1,obj2,Pposition,scoreplus,scoremoins,score,sc_position);
//modification score

#endif // OBJET_H_INCLUDED
