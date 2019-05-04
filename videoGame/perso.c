#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "perso.h"
#include "background.h"
#include <stdio.h>
#include <stdlib.h>





void init_perso(joueur *j)
{
    int choix;
     
    j->position.x=(int)SCREEN_W/2;
   
    j->position.y=(int)SCREEN_H/2;

    j->vie=3;
    
    j->x = 150.0f;

    j->y = 250.0f;

    j->status = STAT_SOL;

    j->vx = j->vy = 0.0f;

    j->image=IMG_Load("perso1.png");// sprite sheet deplacement


}

void afficherjoueur(joueur *j,SDL_Surface *ecran)
{
 SDL_BlitSurface(j->image, NULL, ecran, &j->position);

 SDL_Flip(ecran);
}

void Render(joueur* j,SDL_Surface* ecran)
{
    SDL_Rect R;

    R.x = (Sint16)j->x;

    R.y = (Sint16)j->y;

    R.w = 20;

    R.h = 40;

    SDL_FillRect(ecran,&R,SDL_MapRGB(ecran->format,255,255,255));

    SDL_BlitSurface(j->image, NULL, ecran, &j->position);

    SDL_Flip(ecran);
}

  
void Saute(joueur* j,float impulsion)
{
    j->vy = -impulsion;

    j->status = STAT_AIR;
}


void ControleSol(joueur* j)
{
    if (j->y>250.0f)
    {
        j->y = 250.0f;
        
        if (j->vy>0)
          
              j->vy = 0.0f;
        
        j->status = STAT_SOL;
    }
}


void Gravite(joueur* j,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (j->status == STAT_AIR && keys[SDLK_UP])

        factgravite/=factsautmaintenu;

    j->vy += factgravite;
}

void Evolue(joueur* j,Uint8* keys)
{
    float lateralspeed = 0.5f;
    float airlateralspeedfacteur = 0.5f;
    float maxhspeed = 3.0f;
    float adherance = 1.5f;
    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
// controle lateral
    if (j->status == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (keys[SDLK_LEFT]) // (*1)
        j->vx-=lateralspeed;
    if (keys[SDLK_RIGHT])
        j->vx+=lateralspeed;
    if (j->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
        j->vx/=adherance;
// limite vitesse
    if (j->vx>maxhspeed) // (*4)
        j->vx = maxhspeed;
    if (j->vx<-maxhspeed)
        j->vx = -maxhspeed;
// saut
    if (keys[SDLK_UP] && j->status == STAT_SOL)
        Saute(j,impulsion);
    Gravite(j,factgravite,factsautmaintenu,keys);
    ControleSol(j);
// application du vecteur à la position.
    j->x +=j->vx;
    j->y +=j->vy;
}








void deplacementjoueur (joueur *j,int i, int a)
{



 if (a==1)//right
            {
                

		j->position.x -=10;
                j->position.y +=5;
                                  switch (i)
                                    {
                                       case 1:
                                         j->image= IMG_Load("perso1L.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2L.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3L.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4L.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5L.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6L.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7L.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8L.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9L.png");
                                         break;
                                     }
            
}

 if (a==2)//left
            {
       
                j->position.x-=10;
                j->position.y +=5;
                                  switch (i)
                 {
                                       case 1:
                                         j->image= IMG_Load("perso1L.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2L.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3L.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4L.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5L.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6L.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7L.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8L.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9L.png");
                                         break;
                                  }
                        }

   if (a==3)//up
            {
               
                  switch(i)
                {
                         
                                         case 1:
                                         j->image= IMG_Load("perso1L.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2L.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3L.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4L.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5L.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6L.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7L.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8L.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9L.png");
                                         break;
                                     }
                        }
  if (a==4)//acceleration
            {
           
                j->position.x +=10;
                j->position.y +=5;
                j->position.x-=10;
                j->position.y +=5;
                                  switch (i)
                                    {
                                       case 1:
                                         j->image= IMG_Load("perso1L.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2L.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3L.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4L.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5L.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6L.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7L.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8L.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9L.png");
                                         break;
                            }         }
 
}



















