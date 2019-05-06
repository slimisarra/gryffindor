#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_gfx>
#include <math.h>
 
#define W   500
#define H   500
 
#define CHECK(cond, fun)                                                       \
    do{                                                                        \
        if (!(cond))                                                           \
            fprintf(stderr, "%s line : %u\n %s\n", __FILE__, __LINE__, fun()), \
            exit(EXIT_FAILURE);                                                \
    }while(0);
 
 
 
void initSDL(int w, int h)
{
    CHECK(SDL_Init(SDL_INIT_VIDEO) >= 0, SDL_GetError);
    CHECK((SDL_SetVideoMode(w, h, 32, SDL_SWSURFACE)), SDL_GetError);
}
 
 
 
void run(void)
{
    SDL_Surface* scr = SDL_GetVideoSurface();
    SDL_Surface *srfSquare;
    SDL_Surface *srfTriangle;
 
    SDL_Rect rctSquare;
 
    int done = 0;
    double angle = 0.;
 
    CHECK((srfSquare = IMG_Load("square.png")), SDL_GetError);
    CHECK((srfTriangle = IMG_Load("triangle.png")), SDL_GetError);
 
    rctSquare.x = (scr->w - srfSquare->w) / 2;
    rctSquare.y = (scr->h - srfSquare->h) / 2;
 
    while(!done)
    {
        SDL_Surface *srfTmp;
        SDL_Rect rctTmp;
 
        SDL_Event ev;
        int x, y;
        while(SDL_PollEvent(&ev))
        {
            if(ev.type == SDL_QUIT)
            done = 1;
        }
 
        SDL_GetMouseState(&x, &y);
        angle = atan2(-(x - scr->w / 2), -(y - scr->h / 2)) / M_PI * 180;
        srfTmp = rotozoomSurface(srfTriangle, angle, 1, 1);
        rctTmp.x = (scr->w - srfTmp->w) / 2;
        rctTmp.y = (scr->h - srfTmp->h) / 2;
 
        SDL_FillRect(scr, NULL, 0xffffff);
        SDL_BlitSurface(srfSquare, NULL, scr, &rctSquare);
        SDL_BlitSurface(srfTmp, NULL, scr, &rctTmp);
        SDL_FreeSurface(srfTmp), srfTmp = NULL;
 
        SDL_Flip(scr);
    }
 
    SDL_FreeSurface(srfSquare), srfSquare = NULL;
    SDL_FreeSurface(srfTriangle), srfTriangle = NULL;
}
 
 
 
int main(int argc, char *argv[])
{
    initSDL(W, H);
 
    run();
 
    SDL_Quit();
 
    return 0;
}

