#include "background.h"
#include <SDL/SDL_image.h>
#include "perso.h"


void init_bck(BACKGROUND *Back)
{
    Back->stage = 0;

    Back->image[0] = SDL_LoadBMP("background.bmp");
    Back->image[1] = SDL_LoadBMP("backgroundCol.bmp");


    Back->pos.x =0;
    Back->pos.y =0;

    Back->pos.h = Back->image[0]->h;
    Back->pos.w = Back->image[0]->w;

    Back->post_background.x = 0;
    Back->post_background.y = 0;
    Back->post_background.h = SCREEN_H;
    Back->post_background.w = SCREEN_W;

}

void afficher_bk(SDL_Surface *ecran, BACKGROUND *back)
{
 
SDL_BlitSurface(back->image[0],&back->post_background, ecran, NULL);
SDL_Flip(ecran);
}


void scrolling (BACKGROUND *camera, int k, struct joueur* j,int i)
{


if (k==4){
(*camera).post_background.y+=10;
       switch (i)
                                    {
                                       case 1:
                                         j->image= IMG_Load("perso1.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9.png");
                                         break;
                            }}
if (k==1){

(*camera).post_background.x+=10;
switch (i)
                                    {
                                       case 1:
                                         j->image= IMG_Load("perso1.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9.png");
                                         break;
                                     }
}
if(k==3){
(*camera).post_background.y-=10;
     switch(i)
                {
                                       case 1:
                                         j->image= IMG_Load("perso1.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9.png");
                                         break;
                                     }}
if(k==2){
(*camera).post_background.x-=10;
 switch (i)
                 {
                                       case 1:
                                         j->image= IMG_Load("perso1.png");
                                         break;
                                       case 2:
                                         j->image= IMG_Load("perso2.png");
                                         break;
                                       case 3:
                                         j->image= IMG_Load("perso3.png");
                                         break;
                       			case 4:
                                         j->image= IMG_Load("perso4.png");
                                         break;
                                        case 5:
                                         j->image= IMG_Load("perso5.png");
                                         break;
                                       case 6:
                                         j->image= IMG_Load("perso6.png");
                                         break;
                                       case 7:
                                         j->image= IMG_Load("perso7.png");
                                         break;
                       			case 8:
                                         j->image= IMG_Load("perso8.png");
                                         break;
                                        case 9:
                                         j->image= IMG_Load("perso9.png");
                                         break;
                                  }}


}



