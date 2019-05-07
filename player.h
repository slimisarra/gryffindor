#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct vie
{
  int nbr;
  SDL_Rect position;
  SDL_Surface *image;
}vie;
typedef struct Player
{
  SDL_Surface *image[2][5];
  SDL_Surface *imageActuel;
  int fram;
  SDL_Rect position;
  int score;
  vie vie;

}Player;

void gestion_vie(vie *v,int i);
Player InitPlayer(Player Hero);
void AfficherPlayer(Player Hero,SDL_Surface *screen);
Player AnimatePlayer(Player Hero,int direction,int Hit);
Player MovePlayer(Player Hero,int direction,int x);
void  afficher_vie(vie v,SDL_Surface *screen);
