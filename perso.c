#include<stdlib.h>
#include<stdio.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL.h"
#include "perso.h"
#include"Collision.h"
#include <SDL/SDL_ttf.h>

void initialiser_afficher(Perso* entity)

{


SDL_Event event;

SDL_Surface* ecran=NULL;
SDL_Surface* background=NULL;
entity=NULL;


SDL_Rect positionecran;

ecran=SDL_SetVideoMode(800,600,24,SDL_HWSURFACE | SDL_DOUBLEBUF);

background=IMG_Load("background2.png");

entity=IMG_Load("Java.png");

SDL_Rect box={350,100,100,100};


//position absolue(position dans la fenetre)
SDL_Rect posPersoAbs;
posPersoAbs.x = 200;
posPersoAbs.y = 300-(entity->h);
 
//position relative (position dans le nouveau repere)
SDL_Rect posPersoRel;
posPersoRel.x = -50;
posPersoRel.y = 0;

}



void deplacement_clavier(Perso* entity,SDL_Surface* background)
{

SDL_Rect positionecran;
SDL_Surface* ecran=NULL;
background=NULL;
entity=NULL;
int continuer=0;
SDL_Rect box;
SDL_Rect pBackground;
SDL_Event event;
SDL_Rect posPersoRel;
SDL_Rect posPersoAbs;


while(continuer)

{

int Coll=0;

SDL_BlitSurface(background,NULL,ecran,&positionecran);

{
while(SDL_PollEvent(&event))
{
switch(event.type) 
{
//quand on ferme la fenetre
case SDL_QUIT :

continuer=0;

break;

//quand on appuie sur une touche
case SDL_KEYDOWN :

    if(event.key.keysym.sym==SDLK_RIGHT)
          posPersoRel.x +=20;

    if(event.key.keysym.sym==SDLK_LEFT)
          posPersoRel.x -=20;

    if(event.key.keysym.sym==SDLK_UP)
          posPersoRel.y +=20;

    if(event.key.keysym.sym==SDLK_DOWN)
          posPersoRel.y -=20;
break;
}
}
}

            posPersoAbs.x = 200;
            posPersoAbs.y = 300-(entity->h);

            //On calcule la valeur relative de y:
            posPersoRel.y=(-0.04*(posPersoRel.x*posPersoRel.x)+100);

            //On calcule maintenant les valeurs abs
            posPersoAbs.x = posPersoAbs.x + posPersoRel.x+50;
            posPersoAbs.y = posPersoAbs.y - posPersoRel.y;

        //Intervalle de 10ms
        SDL_Delay(10);

        // FIN EVOLUTION

        // DESSIN

        // On vide l'ecran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        SDL_BlitSurface(entity, NULL, ecran, &posPersoAbs);
        SDL_FillRect(ecran,&box,SDL_MapRGB(ecran->format,255,255,0));

       mapCollision(entity,pBackground);
        if (Coll==1)
	{
            printf("Il y a une collision\n");
	}

        // FIN DESSIN

        // Et on oublie pas de rafraichir l'image !
        SDL_Flip(ecran);
    }

    // Soulageons la memoire !
    SDL_FreeSurface(background);
    SDL_FreeSurface(entity);
   
}



