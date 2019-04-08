#include<stdlib.h>
#include<stdio.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL.h"
#include"Collision.h"
#include"perso.h"
#include <SDL/SDL_mixer.h>
#include<string.h>
#include <SDL/SDL_ttf.h>

SDL_Color GetPixel(SDL_Surface *pBackground, int xp, int yp)
{

    SDL_Color color, white= {255,255,255};
    Uint32 Coll = 0;
   

        char* pixelPosition = (char*)pBackground->pixels;
        pixelPosition += (pBackground->pitch * yp);
        pixelPosition += (pBackground->format->BytesPerPixel * xp);
        memcpy(&Coll, &pixelPosition, pBackground->format->BytesPerPixel);
        SDL_GetRGB(Coll, pBackground->format, &color.r, &color.g, &color.b);
        return (color);

}


void mapCollision(Perso* entity,SDL_Surface* pBackground)
{
    
    int i, xg, xd, yg, yd,test;
    int MAX_X , MAX_Y;
    SDL_Color PixelToCompare1,PixelToCompare2;
    SDL_LockSurface(pBackground);//parametre masque
    xg = entity->x + entity->dirX;
    xd = entity->x + entity->dirX + entity->w;
    yg = yd = entity->y + entity->h / 2;
    if (xg >0 && xd < MAX_X && yg >= 0 && yd < MAX_Y)
    {

        if (entity->dirX > 0)
        {

            PixelToCompare1= GetPixel(pBackground,xd,yg);
            PixelToCompare1= GetPixel(pBackground,xd,yd);
            test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) && ((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));
            if (test)
            {

                entity->x -=   entity->dirX;
                entity->dirX = 0;

            }
        }

        else if (entity->dirX < 0)
        {

            PixelToCompare1= GetPixel(pBackground,xg,yg);
            PixelToCompare1= GetPixel(pBackground,xg,yd);
            test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) && ((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));
            if (test)
            {

                entity->x -= entity->dirX;
                entity->dirX = 0;

            }
        }
    }

    xg = (entity->x)+entity->w /2;
    xd = entity->x + entity->w /2 ;
    yg = (entity->y + entity->dirY);
    yd = (entity->y + entity->dirY + entity->h);
    if (xg >= 0 && xd < MAX_X && yg >= 0 && yd < MAX_Y)
    {

        if (entity->dirY > 0)
        {

            PixelToCompare1= GetPixel(pBackground,xd,yd);
            PixelToCompare1= GetPixel(pBackground,xg,yd);
            test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) && ((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));
            if (test)
            {

                entity->y = yd;
                entity->y -= entity->h+2;
                entity->dirY = 0;
                entity->onGround = 1;

            }
        }

        else if (entity->dirY < 0)
        {

            PixelToCompare1= GetPixel(pBackground,xd,yg);
            PixelToCompare1= GetPixel(pBackground,xg,yg);
            test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) &&((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));
            if (test)
            {

                entity->y = (yg + 1);
                entity->dirY = 0;

            }
        }
    }

    entity->x += entity->dirX;
    entity->y += entity->dirY;
    if (entity->x < 0)
    {

        entity->x = 0;

    }
    else if (entity->x + entity->w >= MAX_X)
    {

        entity->x = MAX_X - entity->w - 1;

    }
    if (entity->y > MAX_Y)
    {

        entity->timerMort = 18;

    }
    SDL_UnlockSurface(pBackground);
}
