#include "player.h"
Player InitPlayer(Player Hero)
{
  Hero.image[0][0]=IMG_Load("graphique/Abeille sprite/Bee_0000_Capa-1.png");
  Hero.image[0][1]=IMG_Load("graphique/Abeille sprite/Bee_0001_Capa-2.png");
  Hero.image[0][2]=IMG_Load("graphique/Abeille sprite/Bee_0002_Capa-3.png");
  Hero.image[0][3]=IMG_Load("graphique/Abeille sprite/Bee_0003_Capa-4.png");
  Hero.image[0][4]=IMG_Load("graphique/Abeille sprite/Bee_0004_Capa-5.png");
  Hero.image[1][0]=IMG_Load("graphique/Abeille sprite/HIT/Bee_0005_Capa-6.png");
  Hero.image[1][1]=IMG_Load("graphique/Abeille sprite/HIT/Bee_0006_Capa-7.png");
  Hero.image[1][2]=IMG_Load("graphique/Abeille sprite/HIT/Bee_0007_Capa-8.png");
  Hero.image[1][3]=IMG_Load("graphique/Abeille sprite/HIT/Bee_0008_Capa-9.png");
  Hero.image[1][4]=IMG_Load("graphique/Abeille sprite/HIT/Bee_0009_Capa-0.png");
  Hero.imageActuel=Hero.image[0][0];
  Hero.position.x=450;
  Hero.position.y=342- Hero.imageActuel->h;
  Hero.fram=0;
  Hero.vie.image=IMG_Load("coeur.png");
  Hero.score=0;
  Hero.vie.nbr=4;

  Hero.vie.position.x=20;
  Hero.vie.position.y=20;
  return Hero;
}
void AfficherPlayer(Player Hero , SDL_Surface *screen)
{
  SDL_BlitSurface(Hero.imageActuel,NULL,screen,&Hero.position);
}
Player AnimatePlayer(Player Hero,int direction,int Hit)
{
  if(Hero.fram==4)
  {
    Hero.fram=0;
  }
  else
  {
    Hero.fram++;
  }

  Hero.imageActuel=Hero.image[Hit][Hero.fram];
  return Hero;
}
Player MovePlayer(Player Hero,int direction,int x)
{
  if(direction==0)
  {printf("%d    %d\n",x,Hero.position.x );

    if((Hero.position.x<450))
      Hero.position.x+=20;
    else if((x>6000)&&(Hero.position.x<920))
      Hero.position.x+=20;
  }
  else if(direction==1)
  {
    if((x==0)&&(Hero.position.x>0))
      Hero.position.x-=20;
    else if(Hero.position.x>450)
      Hero.position.x-=20;
  }
  if(direction==2)
    Hero.position.y-=20;
  /*else if(direction==3)
    Hero.position.y+=20;*/
  return Hero;
}
void gestion_vie(vie *v,int i)
{
  if(i==1)
   v->nbr--;

  // printf("||||||||||||||||||||||||%d\n", v->nbr);
}
void  afficher_vie(vie v,SDL_Surface *screen)
{
  int i;
  SDL_Rect position;
  for(i=0;i<v.nbr;i++)
  {
    position.x=v.position.x+(v.image->w*i);
    position.y=20;
    SDL_BlitSurface(v.image,NULL,screen,&position);
  }
}
