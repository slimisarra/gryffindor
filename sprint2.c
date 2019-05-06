#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "objet.h"
#include <math.h>
#include <stdbool.h>

void sauvegarde(SDL_Surface * menu2,SDL_Surface * menu22,SDL_Rect * posmenu2,SDL_Rect * posmenu22,FILE * fichier)
{  switch(event.type)
        {case SDL_QUIT :
         {continuer=0;
         menu2 =  IMG_Load("menuechap.png");
         if  ( menu2  ==  NULL )
                 {printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
                  exit ( 1 );}
         else
            {
             SDL_Flip(ecran);
             posmenu2->x =(1600/2);
             posmenu2->y =(600/2);
             SDL_BlitSurface(menu2, NULL, ecran,&posmenu2);//affichage d un png souhaitez vous quitter? au centre de l ecran
             switch (event.type)
             {case SDL_KEYDOWN:
                 if ((event.key.keysym.sym=='y')||(event.key.keysym.sym=='Y')) //si le joueur a choisi de quitter

                      {SDL_FreeSurface (menu2);
                      menu22 =  IMG_Load("menuechap2.png");
                          if  ( menu22  ==  NULL )
                             {printf ("Can not load image of tux: %s \n " , SDL_GetError ());
                             exit ( 1 );}

                          else  {
                                 SDL_Flip(ecran);
                                 posmenu22->x =(1600/2);
                                 posmenu22->y =(600/2);
                                 SDL_BlitSurface(menu22, NULL, ecran,&posmenu22);//affichage d un png souhaitez vous sauvegarder?
                                 switch(event.type)
                                 {  if ((event.key.keysym.sym=='y')||(event.key.keysym.sym=='Y'))
                                  {fichier=NULL;
                                  fichier=fopen("sauvegarde.txt","w")
                                          if (fichier!=NULL)
                                          {fprintf(fichier,"%d%d%d%d",Pposition.x,Pposition.y,vie,nbq)} //enregistrement de la position du joueur et de ses coordonnees
                                          else printf("erreur de l ouverture du fichier");}
                                    else if ((eventmenu22.key.keysym.sym=='n')||(eventmenu22.key.keysym.sym=='N'))
                                        {continuer=0;SDL_FreeSurface(menuechap2.png);
                                        SDL_Quit();}}
                                }
                        }break;


                 else if ((event.key.keysym.sym=='n')||(event.key.keysym.sym=='N')) //si le joueur a choisi de ne pas quitter/de continuer a jouer
                    continuer=1;break;
            }

        }
    }
   }
}


void reprendre(FILE * fichier,SDL_Surface image)
{SDL_Rect positionsauv;
int sauvvie,sauvnbq;
     image = IMG_Load("sousmenu1.png");
     sc_position.x=(2000/2);
     sc_position.y=(1300/2);//reprendre le jeu?
     SDL_BlitSurface(scoremoins,NULL,ecran,&sc_position);
     SDL_Flip(ecran);
     switch(event.type)
     { if(((event.key.keysym.sym=='n')||(event.key.keysym.sym=='N')))
           //entrer dans le jeu et perdre la sauvegarde
           remove("sauvegarde.txt");break;

       else if ((event.key.keysym.sym=='y')||(event.key.keysym.sym=='Y'))
           {fichier=fopen("sauvegarde.txt","w+")
            if (fichier !=NULL)
                {fscanf(fichier,"%d%d%d%d",&positionsauv.x,&posotionsauv.y,&sauvvie,&sauvnbq);
                initialiserperso(); //initialiser le personnage en utilisant les données recupérées du fichier
                remove("sauvegarde.txt");}}break;}
}


void affichage_map (SDL_Surface * perso1,SDL_Surface * perso2,SDL_Surface * fond,SDL_Surface * map,SDL_Rect * positionmap,SDL_Rect posperso1,SDL_Rect posperso2,SDL_Surface * ecran)
{//init_bckg(&b,heartofmira[]);
do
{perso1 =  IMG_Load("perso1.png");
         if  ( perso1  ==  NULL )
                 {printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
                  exit ( 1 );}
         else
            {
             SDL_Flip(fond);
             posperso1->x =joueur1.x;
             posperso1->y =joueur1.y;
             SDL_BlitSurface(perso1, NULL, fond,&posperso1);}

perso2= IMG_Load("perso2.png");
        if (perso2 ==NULL)
            {printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
                  exit ( 1 );}
         else
            {SDL_Flip(fond);
             posperso2->x =joueur2.x;
             posperso2->y =joueur2.y;
             SDL_BlitSurface(perso1, NULL, fond,&posperso2);}
map= IMG_Load (fond)
     if (map==NULL)
     {printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
                  exit ( 1 );}
         else
            {SDL_Flip(ecran);
             positionmap->x =1600/2
             positionmap->y =550;
             SDL_BlitSurface(map, NULL, ecran,&posperso2);}

SDL_FreeSurface(&perso1);
SDL_FreeSurface (&perso2);
SDL_FreeSurface (&fond);
SDL_FreeSurface (&map);}

while (continuer=1);}
