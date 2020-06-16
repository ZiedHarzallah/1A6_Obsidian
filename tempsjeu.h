#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>


typedef struct 
{
int sec;
int min;
int ticker;
}timer;


SDL_Surface * gameTime (timer *t) ;

#endif
