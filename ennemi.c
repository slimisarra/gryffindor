#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ennemi.h" 
#include "perso.h"
#include <time.h>
#include <math.h>





void initialiser_es (ennemi *es)
{
es->pos_es.x=500;
es->pos_es.y=380;
es->image=IMG_Load("m.png");
}


void afficher_es(ennemi *es,SDL_Surface *ecran)
{
 SDL_BlitSurface(es->image, NULL, ecran, &es->pos_es);
 SDL_Flip(ecran);
}



void move_left_Ennemi(ennemi* es)
{
int a; 
        			a=((rand()%4)+1);
 				switch (a)
				     {
                                       case 1:
                                         es->image = IMG_Load("ml1.png");
                                         break;
                                       case 2:
                                         es->image = IMG_Load("ml2.png");
                                         break;
                                       case 3:
                                         es->image = IMG_Load("ml3.png");
                                         break;
				       case 4:
                                         es->image = IMG_Load("ml4.png");
                                         break;
                                     }

}






void move_right_Ennemi(ennemi* es)
{
                                     int a; 
       					 a=((rand()%4)+1);
					switch (a)
                                    {
                                       case 1:
                                         es->image = IMG_Load("mr1.png");
                                         break;
                                       case 2:
                                         es->image = IMG_Load("mr2.png");
                                         break;
                                       case 3:
                                         es->image = IMG_Load("mr3.png");
                                         break;
				       case 4:
                                         es->image = IMG_Load("mr4.png");
                                         break;
}
}





void move_FB_Ennemi(ennemi* es)
{
es->image= IMG_Load("m.png");
}






void mvt_aleatoire_es (ennemi* es,SDL_Surface *ecran)
{
   
        srand(time(NULL));
     
	int a; 
        a=((rand()%4)+1);

    	
        
	if (a==1)
        {
        move_right_Ennemi(es);
        es->pos_es.x+=10;
	es->pos_es.y+=10;
        }
        else if (a==2)
        {
        move_left_Ennemi(es);
	es->pos_es.x-=10;
	es->pos_es.y-=10;
        }


	else if (a==3)
        {
        move_FB_Ennemi(es); //forward
        es->pos_es.x+=10;
	es->pos_es.y-=10;
        }
        else 
        {
        move_FB_Ennemi(es); //back
	es->pos_es.x-=10;
	es->pos_es.y+=10;
        }
        
}


int distance(perso p,ennemi e)
{
int a,b,c,d,k,l;
a= p.position.x;
b= p.position.y;
c= p.position.x;
d= p.position.y;
k=(a-c)*(a-c);
l=(b-d)*(b-d);
return sqrt(k+l);
}









void UpdateEnnemi (ennemi *E, perso P,SDL_Surface* screen)
{
	switch (E->STATE)
	{
	case WAITING : 
				mvt_aleatoire_es(E,screen);
				break; 
	case FOLLOWING : 


if       ((P.position.x<E->pos_es.x)&&(P.position.y<E->pos_es.y))
         {E->pos_es.x -=10;
	 E->pos_es.y -=10; 
	 move_left_Ennemi(E);}

else if  ((P.position.x>E->pos_es.x)&&(P.position.y>E->pos_es.y))
         {E->pos_es.x +=10;
	 E->pos_es.y +=10; 
	 move_right_Ennemi(E);}

else if  ((P.position.x>E->pos_es.x)&&(P.position.y<E->pos_es.y))
         {E->pos_es.x +=10;
	 E->pos_es.y -=10;
	 move_FB_Ennemi(E);} 

else if  ((P.position.x<E->pos_es.x)&&(P.position.y>E->pos_es.y))
         {E->pos_es.x -=10;
	 E->pos_es.y +=10; 
         move_FB_Ennemi(E); }  
				break;
	

	case ATTACKING :

if       ((P.position.x<E->pos_es.x)&&(P.position.y<E->pos_es.y))

	 move_left_Ennemi(E);

else if  ((P.position.x>E->pos_es.x)&&(P.position.y>E->pos_es.y))

	 move_right_Ennemi(E);

else if  ((P.position.x>E->pos_es.x)&&(P.position.y<E->pos_es.y))

	 move_FB_Ennemi(E); 

else if  ((P.position.x<E->pos_es.x)&&(P.position.y>E->pos_es.y))

         move_FB_Ennemi(E);   
				break;
					

}
}



void IA (ennemi ennemi, perso p, int d1, int d2,SDL_Surface* screen)
{
if ((distance(p,ennemi)<d1)&&(ennemi.STATE==WAITING))
		{
			ennemi.STATE=FOLLOWING;
			
		}
		else if ((distance(p,ennemi)>d1)&&(ennemi.STATE==FOLLOWING))
		{
			ennemi.STATE=WAITING;
			
		}
		else if ((distance(p,ennemi)<d2)&&(ennemi.STATE==FOLLOWING))
		{
			ennemi.STATE=ATTACKING;
			p.vie--;
			
		}
		else if ((distance(p,ennemi)<d2)&&(p.vie==0)&&(ennemi.STATE==ATTACKING))
		{	
			ennemi.STATE=WAITING;
			
		}
		else if ((distance(p,ennemi)<d1)&&(distance(p,ennemi)>d2)&&(ennemi.STATE==ATTACKING))
		{	
			ennemi.STATE=FOLLOWING;
			
		}
		UpdateEnnemi(&ennemi,p,screen);

}











