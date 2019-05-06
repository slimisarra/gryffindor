#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "background.h"
#include "perso.h"
#include "jeu.h"
#include "collision.h"
#include <stdio.h>
#include <stdlib.h>
#include "ennemi.h"
#include "enigme_jeu.h"


int jouer(SDL_Surface * ecran)
{
system("stty -F /dev/ttyACM0 9600 -parenb cs8 -cstopb");
	joueur j; int i=1;int a;int ju;int h;
        SDL_Rect camera;
        int numkeys;
        Uint8 * keys;
        Uint32 timer,elapsed;
        int continuer=1;
	Uint32 t_prev, dt=1;
        char nom=IMG_Load("perso1.png"); 
	
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	
        

	SDL_Init(SDL_INIT_VIDEO);
	//ecran = SDL_SetVideoMode(width,hight, 32, SDL_HWSURFACE);
	ecran = SDL_SetVideoMode(SCREEN_W,SCREEN_H, 32,SDL_DOUBLEBUF|SDL_FULLSCREEN);
        //SDL_WM_SetCaption("Heart of mira",NULL);
	const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
        
        //background
        BACKGROUND b;
        init_bckg(&b);
        afficher_bckg(ecran,&b);
        //perso
        joueur hero;
	init_perso(&j,nom);

        // ennemi
        ennemi * e;
        e=malloc(sizeof(ennemi));
        initialiser_ennemi(&e);
 
// Configure le mode vidéo


while(continuer)
    {

     SDL_PollEvent(&event);
 
     switch (event.type)
{
		case SDL_QUIT:
 		continuer = 0;
		break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{

				case SDLK_RIGHT :
				a=1;
 
 				if (i==4)
                                {i=1;}

				if ((j.position.x )>SCREEN_W-150)
					{

						scrolling(&b,a,&j,i);
                                                }
				if(collision_perpri(&b,&j)){
                                        
					scrolling(&b,2,&j,i);
                                }
	                    deplacementjoueur (&j,i,0,ju);


                           if (collision_enigme(&b,&j)==1)
                           {
                                enigme();
                                continuer=0;
                                 }
                                else
                                {

					deplacementjoueur (&j,i,a);
                                         afficher_ennemi(&e,ecran);
					deplacement_aleatoire(e); 

							


                                     }


               SDL_Delay(100);
         
                i++;
break;

}

case SDLK_LEFT:
a=2;
if (i==4){i=1;}
if (j.position.x <100)
{
        
	scrolling(&b,a,&j,i);
afficher_ennemi(&e,ecran);
deplacement_aleatoire(&e); 
	deplacementjoueur (&j,i,0);
	if(collision_perpri(&b,&j)){
        
	scrolling(&b,1,&j,i);
	}
}
if (collision_enigme(&b,&j))
{
continuer=0;
}
else{

deplacementjoueur (&j,i,a);
afficher_ennemi(&e,ecran);
deplacement_aleatoire (&e); 

}

               


          
                SDL_Delay(100);
         
                i++;

break;




case SDLK_UP:
a=3;
timer = SDL_GetTicks();
        				SDL_FillRect(ecran,NULL,0);
        				SDL_PumpEvents();
        				keys = SDL_GetKeyState(&numkeys);
        				Evolue(&j,keys);
        				Render(&j,ecran);
        				SDL_Flip(ecran);
        				elapsed = SDL_GetTicks() - timer;
        				if (elapsed<20)
           				 SDL_Delay(20-elapsed);

break;




case SDLK_SPACE :


if (i==4){i=1;}
                if (j.position.x ==1)
{
	scrolling(&b,a,&j,i);
	deplacementjoueur (&j,i,0);
afficher_ennemi(&e,ecran);
deplacement_aleatoire(&e); 
}else{

deplacementjoueur (&j,i,a);
afficher_ennemi(&e,ecran);
deplacement_aleatoire(&e,ecran); 

}

                SDL_Delay(100);

                i++;

break;

}

				
 afficher_bk(ecran,&b);
afficherjoueur(&j,ecran);
afficher_ennemi(&e,ecran);
  

  SDL_Flip(ecran);					
		
		SDL_Flip(ecran);
		
		
		
	}

int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}	                 

	SDL_FreeSurface(ecran);
	
SDL_Quit();

	return(0);
}

