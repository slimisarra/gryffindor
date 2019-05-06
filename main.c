
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"bg.h"
/**
* @file main.c
* @brief Testing Program.
* @author gryffindor
* @version 0.1
* @date mai 05, 2019
*
* Testing program for background scrollilng
*
*/



int main(int argc, char *argv[])

{ background b;
SDL_Event event;
SDL_Surface*ecran;

if(SDL_Init(SDL_INIT_VIDEO)==-1)// Démarrage de la SDL. Si erreur :
 
 { printf("can't init SDL:%s\n", SDL_GetError() );
   return EXIT_FAILURE;}
 
ecran=SDL_SetVideoMode(CAMERA_W,CAMERA_H,32,SDL_HWSURFACE | SDL_DOUBLEBUF);// On tente d'ouvrir une fenêtre


init_bckg (&b,"heartofmira.png");

afficher_bckg (ecran,b);
SDL_Flip(ecran);

int continuer=0;

SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
 while (!continuer)
  {while (SDL_PollEvent(&event))
    { switch(event.type)
      { case SDL_QUIT :
        continuer=1;
       break;
      case SDL_KEYDOWN:
       switch(event.key.keysym.sym)
         { case SDLK_RIGHT:
           scrolldroite (&b);
            break;}
      break;}}

 afficher_bckg(ecran,&b);
 SDL_Flip(ecran);
}
 SDL_FreeSurface(ecran);
 SDL_FreeSurface(b.img);/* On libère la surface */
    SDL_Quit();
}
     
