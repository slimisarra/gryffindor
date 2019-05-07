#include "jeux.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

int main(int arc, char *argv)
{
SDL_Surface *screen = NULL, *Backgr= NULL,*Newg = NULL,*Multi = NULL, *Str = NULL;
SDL_Surface *texte ;
Mix_Music *musique;
int volume=100;

TTF_Font *police=NULL;
SDL_Rect Background,Newgame,Multiplayer,Story ;
char pause;
SDL_Event event;

int continuer= 1;
int i=0;

/* positions de surface  */
Background.x = 0;
Background.y =0;
Newgame.x=293;
Newgame.y=185;
Multiplayer.x=293;
Multiplayer.y=281;
Story.x=293;
Story.y=378;
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }

	// Mix_Music *musique;
	 musique = Mix_LoadMUS("Beauty-and-the-Beast-Belle-LYRICS.mp3");
	 Mix_PlayMusic(musique, -1);
	 Mix_VolumeMusic(100);


SDL_Init(SDL_INIT_VIDEO);

screen = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE);//create new window
SDL_WM_SetCaption("menu",NULL);  /* Titre de l icone */
//SDL_WM_SetIcon(IMG_Load("icon.png"),NULL);


/* Chargement des images */
Backgr = IMG_Load("bg.jpeg");
Newg = IMG_Load("play.jpg");
Multi = IMG_Load("multi.jpg");
Str = IMG_Load("story.jpg");




/* On blitte par-dessus l'écran */
SDL_BlitSurface(Backgr,NULL,screen,&Background);

//SDL_BlitSurface(Newgame,NULL,screen,&game);


SDL_Flip(screen);

while(continuer)
{
			SDL_PollEvent(&event);
			if(event.type==SDL_MOUSEBUTTONDOWN)
					{printf("1111\n");
						if(event.button.button==SDL_BUTTON_LEFT)
				{printf("2222\n");
				if((event.motion.x>0) && (event.motion.x<=800)&&(event.motion.y>=185) && (event.motion.y <=185+Newg->h))
							{printf("3333\n");
							jeux(screen);

							}
						else if((event.motion.x>0) && (event.motion.x<=100)&&(event.motion.y>=550) && (event.motion.y <600))
							{		menuson(&volume);
									printf("4aaaaaaaaaaaaaaaaaaaaaaaaaaaa444\n");
							}
							event.button.button=SDL_BUTTON_RIGHT;
							}
					}
			switch(event.type)
					{

				case SDL_MOUSEMOTION : // mouse
				if((event.motion.x>0) && (event.motion.x<=800) && (event.motion.y>=283) && (event.motion.y <=346))
									{ i=0;

									}
			        if((event.motion.x>=0) && (event.motion.x<=800) && (event.motion.y>=349) && (event.motion.y <=412))
									{ i=1; }
				if((event.motion.x>=0) && (event.motion.x<=800) && (event.motion.y>=418) && (event.motion.y <=481))
									{ i=2; }
				break;


						case SDL_QUIT:
						continuer=0;
						break;
						case SDL_KEYDOWN:


 // keyboard

						switch(event.key.keysym.sym)
							{
								case SDLK_ESCAPE :
									continuer=0;
									break;
                         					case SDLK_DOWN:
                         					i++;
                         					break;
                         					case SDLK_UP:
                         					i--;
                         					break;





							}
					}
					switch (i)
					{
							case 0:
							SDL_BlitSurface(Backgr,NULL,screen,&Background);
							SDL_BlitSurface(Newg,NULL,screen,&Newgame);
							SDL_Flip(screen);
							break;
							case 1:
							SDL_BlitSurface(Backgr,NULL,screen,&Background);
							SDL_BlitSurface(Multi,NULL,screen,&Multiplayer);
							SDL_Flip(screen);
							break;
							case 2:
							SDL_BlitSurface(Backgr,NULL,screen,&Background);
							SDL_BlitSurface(Str,NULL,screen,&Story);
							SDL_Flip(screen);
							break;
					}
if (i==3) i=0;
if (i==-1) i=2;



}




// musique continue



//son court

//Mix_AllocateChannel(10);



// ecrire du texte


/*TTF_Init();



SDL_Color noir={0,0,0};

texte=TTF_RenderText_Solid(police,"salut",noir);

position.x= 100 ; position.y= 200;


SDL_BlitSurface(texte,NULL,screen,&position);
SDL_FLip(screen);*/



 // libération de la surface

SDL_FreeSurface(Backgr);
//SDL_FreeSurface(Newgame);


TTF_Quit();
SDL_Quit();

return EXIT_SUCCESS;

}
