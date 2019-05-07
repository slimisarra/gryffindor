#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeux.h"

void init(bouton b[7][2])
{
b[0][0].image = IMG_Load("volumeon.png");
b[0][1].image = IMG_Load("volumeoff.png");
b[1][0].image = IMG_Load("fullscreen.png");
b[1][1].image = IMG_Load("fullscreen2.png");
b[2][0].image = IMG_Load("save.png");
b[2][1].image = IMG_Load("save2.png");
b[3][0].image = IMG_Load("quit.png");
b[3][1].image = IMG_Load("quit2.png");
b[4][0].image = IMG_Load("help.png");
b[4][1].image = IMG_Load("help2.png");
b[5][0].image = IMG_Load("moins1.png");
b[5][1].image = IMG_Load("moins2.png");
b[6][0].image = IMG_Load("plus1.png");
b[6][1].image = IMG_Load("plus2.png");

b[0][1].pos.x = 300;
b[0][0].pos.x = 300;
b[5][1].pos.x = 250;
b[5][0].pos.x = 250;
b[6][1].pos.x = 520;
b[6][0].pos.x = 520;

b[2][1].pos.x = 300;
b[2][0].pos.x = 300;

b[1][1].pos.x = 300;
b[1][0].pos.x = 300;
b[3][1].pos.x = 300;
b[3][0].pos.x = 300;
b[4][0].pos.x = 780;
b[4][1].pos.x = 780;

b[0][1].pos.y = 100;
b[0][0].pos.y = 100;
b[5][1].pos.y = 105;
b[5][0].pos.y = 105;
b[6][1].pos.y = 105;
b[6][0].pos.y = 105;




b[1][1].pos.y = 200;
b[1][0].pos.y = 200;
b[3][1].pos.y = 400;
b[2][0].pos.y = 300;
b[2][1].pos.y = 300;
b[3][0].pos.y = 400;
b[4][0].pos.y = 10;
b[4][1].pos.y = 10;

}

int menuson(int *volume)

{
SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *ecran = NULL, *bg = NULL;
bouton b[7][2];
SDL_Rect pos;
int i;

pos.x=0;
pos.y=0;


ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("SETTINGS", NULL);

init(b);
bg = IMG_Load("menu.png");
SDL_BlitSurface(bg,NULL,ecran,&pos);
for (i=0;i<7;i++)
SDL_BlitSurface(b[i][0].image, NULL, ecran, &(b[i][0].pos));
SDL_Flip(ecran);

int continuer = 1;
SDL_Event event;


while(continuer)
{
   SDL_PollEvent(&event);

     if (event.type == SDL_QUIT)
     {
       continuer = 0;

     }
     else if( event.type == SDL_MOUSEBUTTONDOWN )
     {

        if( event.button.button == SDL_BUTTON_LEFT )
        {
   //VOLUME ON OFF
          if ((event.button.x > b[0][0].pos.x) && (event.button.x < b[0][0].pos.x + b[0][0].pos.w) && (event.button.y > b[0][0].pos.y) && (event.button.y < b[0][0].pos.y + b[0][0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][0].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                        SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
                    }
                    else
                    {
                        Mix_PauseMusic(); //Mettre en pause la musique
                        SDL_BlitSurface(b[0][1].image, NULL, ecran, &(b[0][1].pos));
                    }
              SDL_Flip(ecran);
            }
// Fullscreen
else if ((event.button.x > b[1][0].pos.x) && (event.button.x < b[1][0].pos.x + b[1][0].pos.w) && (event.button.y > b[1][0].pos.y) && (event.button.y < b[1][0].pos.y + b[1][0].pos.h))
            {
              SDL_WM_ToggleFullScreen(ecran);
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
              SDL_BlitSurface(b[1][1].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][0].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              SDL_Flip(ecran);
            }
//save
else if ((event.button.x > b[2][0].pos.x) && (event.button.x < b[2][0].pos.x + b[2][0].pos.w) && (event.button.y > b[2][0].pos.y) && (event.button.y < b[2][0].pos.y + b[2][0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][1].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][0].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              SDL_Flip(ecran);
            }
//QUIT
else if ((event.button.x > b[3][0].pos.x) && (event.button.x < b[3][0].pos.x + b[3][0].pos.w) && (event.button.y > b[3][0].pos.y) && (event.button.y < b[3][0].pos.y + b[3][0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][1].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][0].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              SDL_Flip(ecran);
              continuer =0;
            }
//HELP
else if ((event.button.x > b[4][0].pos.x) && (event.button.x < b[4][0].pos.x + b[4][0].pos.w) && (event.button.y > b[4][0].pos.y) && (event.button.y < b[4][0].pos.y + b[4][0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][1].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              SDL_Flip(ecran);
              //help();
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][1].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              SDL_Flip(ecran);
            }

else if ((event.button.x > b[5][0].pos.x) && (event.button.x < b[5][0].pos.x + b[5][0].pos.w) && (event.button.y > b[5][0].pos.y) && (event.button.y < b[5][0].pos.y + b[5][0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][0].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][1].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              if (*volume == 40)
              { Mix_VolumeMusic(20); *volume =20;}
              else if (*volume == 60)
              { Mix_VolumeMusic(40); *volume =40;}
              else if (*volume == 80)
              { Mix_VolumeMusic(60); *volume =60;}
              else if (*volume == 100)
              { Mix_VolumeMusic(80); *volume =80;}


              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));


              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_Flip(ecran);
            }

else if ((event.button.x > b[6][0].pos.x) && (event.button.x < b[6][0].pos.x + b[6][0].pos.w) && (event.button.y > b[6][0].pos.y) && (event.button.y < b[6][0].pos.y + b[6][0].pos.h))
            {
              SDL_BlitSurface(bg,NULL,ecran,&pos);
              SDL_BlitSurface(b[0][0].image, NULL, ecran, &(b[0][0].pos));
              SDL_BlitSurface(b[1][0].image, NULL, ecran, &(b[1][0].pos));
              SDL_BlitSurface(b[2][0].image, NULL, ecran, &(b[2][0].pos));
              SDL_BlitSurface(b[3][0].image, NULL, ecran, &(b[3][0].pos));
              SDL_BlitSurface(b[4][0].image, NULL, ecran, &(b[4][0].pos));
              SDL_BlitSurface(b[5][0].image, NULL, ecran, &(b[5][0].pos));
              SDL_BlitSurface(b[6][1].image, NULL, ecran, &(b[6][0].pos));


              if (*volume == 80)
              { Mix_VolumeMusic(100); *volume =100;}
              else if (*volume == 60)
              { Mix_VolumeMusic(80); *volume =80;}
              else if (*volume == 40)
              { Mix_VolumeMusic(60); *volume =60;}
              else if (*volume == 20)
              { Mix_VolumeMusic(40); *volume =40;}


              SDL_BlitSurface(b[6][0].image, NULL, ecran, &(b[6][0].pos));

              SDL_Flip(ecran);
            }


        }}}}





Extras initialisation_extra(Extras e)
{

         e.barre[0] = IMG_Load("1.png");
         e.barre[1] = IMG_Load("2.png");
         e.barre[2] = IMG_Load("3.png");
         e.barre[3] = IMG_Load("4.png");
         e.barre[4] = IMG_Load("5.png");
         e.barre[5] = IMG_Load("6.png");
         e.barre[6] = IMG_Load("7.png");
e.Img_barre = e.barre[0];

e.pos_barre.x = 5;
e.pos_barre.y =5;
         e.life[0] = IMG_Load("6vies.png");
         e.life[1] = IMG_Load("5vies.png");
         e.life[2] = IMG_Load("4vies.png");
         e.life[3] = IMG_Load("3vies.png");
         e.life[4] = IMG_Load("2vies.png");
         e.life[5] = IMG_Load("1vie.png");
         e.life[6] = IMG_Load("0vies.png");
         e.life[7] = IMG_Load("novie.png");
e.pos_life.x = 220;
e.pos_life.y= 5;
e.Img_life = e.life[0];
         e.bonus[0] = IMG_Load("bonus.png");
         e.bonus[1] = IMG_Load("artefact.png");
         e.pos_bonus.x = 800;
         e.pos_bonus.y = 80;
         e.Img_bonus = e.bonus[0];

return e;
}
