/**
* @file time.c
* @brief Testing Program.
* @author Mohamed Zied Harzallah 
* @version 0.1
* @date Apr 11,6,2020
*
* Testing program for background scrollilng
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int  main()

{
  char chrono[16];
  SDL_Event event;
  TTF_Font *police;
  SDL_Rect pos_image;
  SDL_Surface *Backrownd=NULL;
  Uint32 t1, t2, ok = 1;
  SDL_Surface *ecran = NULL, *texte =  NULL;
  SDL_Color noir = {255,255,180,0}, rouge = {100,0,0};
 
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(920, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  Backrownd = IMG_Load("background.jpg");
  pos_image.x=0;
  pos_image.y=0;
  SDL_WM_SetCaption("Time", 0);
  TTF_Init();
  police = TTF_OpenFont("angelina.ttf", 50);
  t1 = SDL_GetTicks();
 
  while(ok){
    SDL_PollEvent(&event);
 	switch(event.type)
            {
                case SDL_QUIT:
                    ok = 0;
                case SDL_KEYUP:
                	switch(event.key.keysym.sym)
                	{
                		case SDLK_ESCAPE:
                			ok = 0;
                			break;
                	}
                                    break;
            }

    t2 = SDL_GetTicks() - t1;         
    sprintf(chrono, "%02u:%02u.%u", t2/1000/60%60, t2/1000%60, t2%1000/100);
    texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);
 
    SDL_BlitSurface(texte, NULL, ecran, 0);
    SDL_Flip(ecran);
    SDL_Delay(10);
  }
 SDL_FreeSurface(ecran) ; 
SDL_Quit() ; 


 return 0;
}

