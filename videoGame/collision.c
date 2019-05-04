#include <stdlib.h>
#include <stdio.h>
#include "collision.h"
#include "perso.h"
#include "background.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
	SDL_Color color;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) pSurface->pixels ;

	//offset by y
	pPosition += ( pSurface->pitch * y ) ;

	//offset by x
	pPosition += ( pSurface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}



int collision_perpri(BACKGROUND *bg,joueur *j) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	int x=bg->post_background.x + j->position.x;
	int y=bg->post_background.y + j->position.y;
	SDL_Color couleur[4];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->image[0],x,y+j->position.h ); //foot left 1/3 x
	couleur[1] = GetPixel (bg->image[0],x + j->position.w ,y+j->position.h ); //head 2/3 x
	couleur[2] = GetPixel (bg->image[0],x,y+(int)j->position.h*3/4 ); //hand right
	couleur[3] = GetPixel (bg->image[0],x + (int)j->position.w ,y+(int)j->position.h*3/4 );// hand left
	
	
	for(i=0;i<4;i++)
	{
		if((couleur[i].r != 133) && ((couleur[i].g != 87) && (couleur[i].b != 34))) // a changer
		{
			verif=1;
			break;
		}
	}
	if (verif==1)
		return 1;
	else return 0;
}


// fin collision



/*int collision_enigme(BACKGROUND *bg,joueur *per) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	int x=bg->post_background.x + per->positionexplo.x;
	int y=bg->post_background.y + per->positionexplo.y;
	SDL_Color couleur[4];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->image[0],x,y+per->positionexplo.h ); //foot left 1/3 x
	couleur[1] = GetPixel (bg->image[0],x + per->positionexplo.w ,y+per->positionexplo.h ); //head 2/3 x
	couleur[2] = GetPixel (bg->image[0],x,y+(int)per->positionexplo.h*3/4 ); //hand right
	couleur[3] = GetPixel (bg->image[0],x + (int)per->positionexplo.w ,y+(int)per->positionexplo.h*3/4 );// hand left
	
	
	for(i=0;i<4;i++)
	{
		if((couleur[i].r != 252) && ((couleur[i].g != 63) && (couleur[i].b != 16))) // a changer
		{
			verif=1;
			break;
		}
else if ((couleur[i].r != 133) && ((couleur[i].g != 87) && (couleur[i].b != 34)))
{
verif=0;
break;


}
	}
	if (verif==1)
		return 1;
	else return 0;
}
*/ 

//fin collision2
