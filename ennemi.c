/**
 *@file ennemi.c
*/
#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"ennemi.h"

/**
 *@brief  initialiser l'ennemi
 *@param e ennemi 
 *@param pos1 int 
 *@param pos2 int
 *@return Nothing
*/

void initialiser_ennemi(ennemi *e )
{
e->image=IMG_Load("ennemi.jpg");
if (e->image==NULL){printf("impossible de telecharger ennemi");};

e->pos.x=200;
e->pos.y=250;

SDL_SetColorKey(e->image,SDL_SRCCOLORKEY,SDL_MapRGB(e->image->format,255,255,255));

}

/**
 *@brief  afficher l'ennemi
 *@param e ennemi 
 *@return Nothing
*/

void afficher_ennemi(ennemi *e,SDL_Surface *ecran)
{
 SDL_BlitSurface(e->image, NULL, ecran, &e->pos);
 SDL_Flip(ecran);
}

/**
 *@brief  move left ennemi
 *@param e ennemi 
 *@return Nothing
*/

void move_left_Ennemi(ennemi* e)
{
int a; 
        			a=((rand()%4)+1);
 				switch (a)
				     {
                                       case 1:
                                         e->image = IMG_Load("ml1.png");
                                         break;
                                       case 2:
                                         e->image = IMG_Load("ml2.png");
                                         break;
                                       case 3:
                                         e->image = IMG_Load("ml3.png");
                                         break;
				       case 4:
                                         e->image = IMG_Load("ml4.png");
                                         break;
                                     }

}

/**
 *@brief  move right ennemi
 *@param e ennemi 
 *@return Nothing
*/


void move_right_Ennemi(ennemi* e)
{
                                     int a; 
       					 a=((rand()%4)+1);
					switch (a)
                                    {
                                       case 1:
                                         e->image = IMG_Load("mr1.png");
                                         break;
                                       case 2:
                                         e->image = IMG_Load("mr2.png");
                                         break;
                                       case 3:
                                         e->image = IMG_Load("mr3.png");
                                         break;
				       case 4:
                                         e->image = IMG_Load("mr4.png");
                                         break;
}
} 
/* 
 *@brief: deplacer aleatoirement
 *@param : e ennemi
 *@return : nothing
*/
void deplacement_aleatoire(ennemi *e)
{
int a; 
        a=((rand()%2)+1);

    	
        
	if (a==1)
        {
        move_right_Ennemi(e);
        e->pos.x+=10;
        }
        else if (a==2)
        {
        move_left_Ennemi(e);
	e->pos.x-=10;
        }
        
}

/* 
  *@brief : partage d'ecran
  *@param:
  *@return Nothing
*/

//void partage_ecran(SDL_Surface *ecran, BACKRGOUND back1 , BACKGROUND back2 , joueur *j1 , joueur *j2):
//{
   //init_bck1(&Back1);
   //init_bck2(Back2);

   //afficher_bk1(&ecran,&back1);
   //afficher_bk2(&ecran,&back2);

   //init_perso(&j1 , "perso1.png");
   //afficherjoueur(&j1,&ecran);

   //init_perso(&j2 , "perso2.png");
   //afficherjoueur(&j2,&ecran);

   //int keysheld[323]={0};
   //SDL_PollEvent(&event)
   //{

        //switch(event.type)
         //{ 
           //case SDL_QUIT:
             //done =1 ;
           //case SDL_KEYDOWN:
             //keysheld[event.key.keysym.sym]=1;
             //break;
           //case SDL_KEYUP:
             //keysheld[event.key.keysym.sym]=0;
             //break;
         //default :
//}

