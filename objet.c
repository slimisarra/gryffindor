/**
 *@file objet.c
 */

#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "objet.h"
#include <math.h>
#include <stdbool.h>

/**
 *@brief to initialize/show objects
 *@param image for the object
 *@param Oposition for object position (initial NULL position)
 *@param x for the position chosen
 *@param y for the position chosen
 *@return image
 *
*/

//Initialisation+affichage Objet avec x et y les positions selon background et obstacles

SDL_Surface* init_affich_objet( SDL_Surface *image ,SDL_Rect *Oposition,  int x , int y , char nom_obj[])
{   image =  IMG_Load((nom_obj)->image1);
     if  ( image  ==  NULL )  {
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
         exit ( 1 );
     }
     else  { SDL_BlitSurface(image, NULL, ecran,&Oposition);
             SDL_Flip(ecran);
             Oposition->x =x;
             Oposition->y =y;}
return image ;
   //SDL_FreeSurface(image);
    //SDL_Quit();}

/**
 *@brief detect trigonometric collision
 *@param Player for player
 *@param C_Object for object
 *@param Pposition for player position
 *@param Oposition for object position
 *@return true/false (depends on collision)
 *
*/

//Collision trigo

 bool CollisionTrigoInsc ( SDL_Surface *Player , SDL_Surface *C_Object , SDL_Rect Pposition , SDL_Rect Oposition ) //Insc
{ //Pposition=position du personnage, Pposition=Position de l'objet
if ( (((Oposition.x+(Oposition.w/2))-(Pposition.x+(Pposition.w/2))) <= ((Pposition.w/2)+(Oposition.w/2))) && (Pposition.x <= (Oposition.x+Oposition.w)) && ((Pposition.y+Pposition.h) > Oposition.y ) )
     return true ; //Collision faite

else return false ;}

/**
 *@brief detect circular collision
 *@param Player for player
 *@param C_Object for object
 *@param Pposition for player position
 *@param Oposition for object position
 *@return true/false (depends on collision)
 *
*/

bool CollisionTrigoCir ( SDL_Surface *Player , SDL_Surface *C_Object , SDL_Rect Pposition , SDL_Rect Oposition ) //Circ
 {
	 int r1,r2 ; //Rayons du cercle
           r1=(sqrt(pow(Pposition.h,2)+pow(Pposition.w,2)))/2 ;
           r2=(sqrt(pow(Oposition.h,2)+pow(Oposition.w,2)))/2 ;

 if  ( ((Oposition.x)+(Oposition.w/2))-((Pposition.x)+(Pposition.w/2))) <= r1 + r2 && (Pposition.x <= Oposition.x+(Oposition.w/2)+r2 ) && (Pposition.y+Pposition.h > ((Oposition.y+(Oposition.h/2)) - r2 ) ) )
     return true ; //Collision faite

else return false ;}

/**
 *@brief to modify score depending on collisions
 *@param Player for player 
 *@param Pposition for player position
 *@param scoreplus for score update (+1)
 *@param scoremoins for score update (-1)
 *@param vie for score (number)
 *@param sc_position for position of update
 *@return vie
 *
*/

int modifscore(SDL_Surface *Player,SDL_Rect Pposition,SDL_Surface scoreplus,SDL_Surface scoremoins,int vie,SDL_Rect sc_position)
{int i;SDL_Surface * image;
for (i=0;i++;i<20)
{if (CollisionTrigoInsc(&Player,Meat[i].image1,Pposition,Meat[i].position1)||(CollisionTrigoCir(&Player,Meat[i].image1,Pposition,Meat[i].position1)))
    vie=vie+1;
    image = IMG_Load("scoreplus.png");
     sc_position.x=(2000/2);
     sc_position.y=(1300/2);
     SDL_BlitSurface(scoreplus,NULL,ecran,&sc_position);
     SDL_Flip(ecran); SDL_FreeSurface (Meat[i].image1);
     SDL_FreeSurface(&image);

if ((CollisionTrigoInsc(&Player,Bone[i].image2,Pposition,Bone[i].position2))||(CollisionTrigoCir(&Player,Bone[i].image2,Pposition,Bone[i].position2))
    vie=vie-1;
    image = IMG_Load("scoremoins.png");
     sc_position.x=(2000/2);
     sc_position.y=(1300/2);
     SDL_BlitSurface(scoremoins,NULL,ecran,&sc_position);
     SDL_Flip(ecran);SDL_FreeSurface (Bone[i].image2);
     SDL_FreeSurface (&image);};
return vie;
}
