#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "enigmes.h"

int main()
	{ 
		int done=1;
		int y ;
		int z ;
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Surface*screen;
		screen=SDL_SetVideoMode(700,500,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
		SDL_Flip(screen);
		SDL_Delay(1000);
		SDL_Event event ;

		enigme e ;
		enigmeData ed;

		e=initEnigme();
		if (e.back==NULL)
			printf("vide");
		
		while (done)
			{
			SDL_BlitSurface(e.back,NULL,screen,NULL);
			ed= generateEnigme( e);

			z= randomize();
			y=resolutionEnigme(ed,event);
			showEnigme(ed, screen, e);
			}
	SDL_Quit() ;
	return EXIT_SUCCESS ;
	}
