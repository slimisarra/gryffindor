#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"ennemi.h"


void initialiser_afficher(ennemi *e)
{

 SDL_Surface *ecran= NULL , *imagefond=NULL , *ennemi=NULL ;
SDL_Rect positionfond ;


imagefond = SDL_LoadBMP("imagefond.bmp");
e->image=SDL_LoadBMP("imageennemi.bmp");

positionfond.x=0;
positionfond.y=0;
positionfond.w=imagefond->w;

e->pos.x=200;
e->pos.y=100 ;

SDL_SetColorKey(ennemi,SDL_SRCCOLORKEY,SDL_MapRGB(ennemi->format,255,255,255));

SDL_Init(SDL_INIT_VIDEO);

ecran=SDL_SetVideoMode(600,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("ennemi",NULL);
}


void deplacer_ennemi(ennemi *e)
{
int continuer = 1;
SDL_Event event ;
SDL_Rect positionfond ;
SDL_Surface *ecran , *imagefond;
SDL_Rect position , pos;
imagefond = SDL_LoadBMP("imagefond.bmp");
while (continuer=1)
{
   SDL_PollEvent(&event);
    if(event.type = SDL_QUIT)
     continuer = 0;
     else
    {
      position.x=abs(10+rand()%(30-10));
      position.y=0;
      e->pos.x+=pos.x;
      e->pos.y+=pos.y;

    }


SDL_BlitSurface(imagefond ,NULL,ecran,&positionfond);
SDL_BlitSurface(e,NULL,ecran,&e->pos);

SDL_Flip(ecran);
}
}


void initialiser_ennemi(ennemi *e)
{
	p->frame.y = 0;
	p->frame.x = 0;
	p->frame.w = 80;
	p->frame.h = 117;
	
	
}


void animate_right(ennemi *e)
{
				e->frame.y=0;
				e->frame.x +=80;
				if (e->frame.x == 400 ){
						e->frame.x = 0;
						}
				SDL_Delay(28);	
			}	
					
void animate_left(ennemi *e)
{
				e->frame.y=351;
				e->frame.x +=80;
				if (e->frame.x == 400 ){
						e->frame.x = 0;
						}
					SDL_Delay(28);
}

void animate_up(ennemi *e)
{
				e->frame.y=117;
				e->frame.x+=80;
				if (e->frame.x == 400 ){
						e->frame.x = 0;
						}
							    	 
				    

			SDL_Delay(28);	
			}	
void animate_down(ennemi *e)
{
				e->frame.y=234;
				e->frame.x +=80;
				if (e->frame.x == 400 ){
						e->frame.x = 0;
						}
					SDL_Delay(28);
}
	
void animate_jump (ennemi *e)
{
	int i ;
	
    
    if (e->frame.x == 0 )
    {
	    e->frame.x = 72;
	}	
	SDL_Delay(28);
} 

	void Display_perso (ennemi e,SDL_Rect position,SDL_Surface *screen)
{
	
		
		SDL_BlitSurface(e.image, &e.frame, screen, &position);
		SDL_Flip( screen );
	    
}



