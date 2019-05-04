#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "background.h"
#include "perso.h"
#include "jeu.h"
#include "collision.h"
#include <stdio.h>
#include <stdlib.h>
int jouer(SDL_Surface * ecran)
{
	joueur j; int i=1;int a;int ju;int h;
        SDL_Rect camera;
        int numkeys;
        Uint8 * keys;
        Uint32 timer,elapsed;
        int continuer=1;
	Uint32 t_prev, dt=1; 
	
	joueur hero;
	BACKGROUND Back;
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	

	init_bck(&Back);
	init_perso(&j);

	SDL_Init(SDL_INIT_VIDEO);
	//ecran = SDL_SetVideoMode(width,hight, 32, SDL_HWSURFACE);
	ecran = SDL_SetVideoMode(SCREEN_W,SCREEN_H, 32,SDL_DOUBLEBUF|SDL_FULLSCREEN);
	const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
 
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
 
 				if (i==4){i=1;}

				if ((j.position.x )>SCREEN_W-150)
					{
						scrolling(&Back,a,&j,i);}
				if(collision_perpri(&Back,&j)){
					scrolling(&Back,2,&j,i);}
	                    //deplacementjoueur (&j,i,0,ju);


                           //if (collision_enigme(&back,&j)==1)
                           //{
                                //continuer=0;
                                 //}
                                else
                                {

					deplacementjoueur (&j,i,a);

					//afficher_es(&e,ecran);
					//mvt_aleatoire_es (&e,ecran); 
					if(collision_perpri(&Back,&j)==1)
                                               {
					deplacementjoueur (&j,i,2);
							}


                                     }


               // SDL_Delay(100);
         
                i++;
break;

}

case SDLK_LEFT:
a=2;
if (i==4){i=1;}
if (j.position.x <100)
{

	scrolling(&Back,a,&j,i);
//afficher_es(&e,ecran);
//mvt_aleatoire_es (&e,ecran); 
	deplacementjoueur (&j,i,0);
	if(collision_perpri(&Back,&j)){
	scrolling(&Back,1,&j,i);
	}
}
//if (collision_enigme(&back,&j))
//{
//continuer=0;
//}
else{

deplacementjoueur (&j,i,a);
//afficher_es(&e,ecran);
//mvt_aleatoire_es (&e,ecran); 
if(collision_perpri(&Back,&j)==1){
	deplacementjoueur (&j,i,1);
	}

}

               


          
               // SDL_Delay(100);
         
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
	scrolling(&Back,a,&j,i);
	deplacementjoueur (&j,i,0);
/*afficher_es(&e,ecran);
mvt_aleatoire_es (&e,ecran); */
}else{

deplacementjoueur (&j,i,a);
/*afficher_es(&e,ecran);
mvt_aleatoire_es (&e,ecran); */

}

               // SDL_Delay(100);

                i++;

break;

}

				
 afficher_bk(ecran,&Back);
afficherjoueur(&j,ecran);
//afficher_es(&e,ecran);
  

  SDL_Flip(ecran);					
		
		SDL_Flip(ecran);
		
		
		
	}

	                // free loaded bitmap

	SDL_FreeSurface(ecran);
	
SDL_Quit();
	return(0);
}

