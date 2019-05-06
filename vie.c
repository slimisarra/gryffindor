
/**
* @file vie.c
*/

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"bg.h"
#include<SDL/SDL_ttf.h>


/**
* @brief gestion de vie  .
*  @param scren the screen
* @param  vieactuelle life of character 
* @return Nothing
*/

 gestion_vie(SDL_Surface*ecran,int NBQ,int vieactuelle)
    
  
    TTF_Init();
if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILUR);}
    SDL_Surface *texte = NULL
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int vieactuelle = 3;
    int NBQ=0;
    char vie[20] = ""; /* Tableau de char suffisamment grand */

     TTF_Init()

    /* Chargement de la police */
    police = TTF_OpenFont("angelina.ttf", 65);

    sprintf(vie, "vie : %d", vieactuelle);
    texte = TTF_RenderText_solid(police, vie, couleurNoire);
    
   if(enigme>0)
     {do 
       vieactuelle=vieactuelle+1;
       NBQ=NBQ+1;
       sprintf(vie,vie:%d,vieactuelle);
            SDL_FreeSurface(texte); /* On supprime la surface précédente */
            texte = TTF_RenderText_Shaded(police,vie, couleurNoire); /* On écrit la chaîne vie  dans la SDL_Surface */ 
             b->bckg.x = 180;
             b->bckg.y = 210;
             SDL_BlitSurface(texte, NULL, ecran, &(b.bckg)); /* Blit du texte */
             SDL_Flip(ecran);

       while((vieactuelle>0) || (NBQ<5))
        }
   if (enigme<0)
     {do
        vieactuelle=vieactuelle-1;
       sprintf(vie,viie:%d,vieactuelle);
         SDL_FreeSurface(texte); /* On supprime la surface précédente */
            texte = TTF_RenderText_Shaded(police,vie, couleurNoire); 
        b->bckg.x = 0;
        b->bckg.y = 590;
        SDL_BlitSurface(texte, NULL, ecran, &(b.bckg)); /* Blit du texte */
        SDL_Flip(ecran);
    while((vieactuelle>0) || (NBQ<5))    }



    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);

    return
}


/**
* @brief end of the game .
* @parm  vieactuelle  vie
* @param NBQ question number 
* @return Nothing
*/

void continuer(int vieactuelle,int NBQ)
int  continuer=1;
 
if(vieactuelle=0 )
 {  SDL_FreeSurface(b.img);/* On libère la surface */


    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
    /* Chargement d'une image Bitmap dans une surface */
    b->img = IMG_Load("gameover");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(b.img,&(b.bckg),eran,NULL);}
    SDL_Flip(ecran);

if((NBQ=5)&&(vieactuelle>0))
 {
   SDL_FreeSurface(b.img);/* On libère la surface */
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
    /* Chargement d'une image Bitmap dans une surface */
    b->img = IMG_Load("bravo");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(b.img,&(b.bckg),eran,NULL);
   SDL_Flip(ecran);}



