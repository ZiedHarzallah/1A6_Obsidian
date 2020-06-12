/**
* @file Main.c
* @brief Testing Program.
* @author C omar NOURI
* @version 1.1
* @date  juin 2020
*
* Testing program for main.c
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int main (void)

{

    int continuee=1;

    SDL_Surface *ecran =NULL;

    SDL_Surface *image=NULL;
	
    SDL_Surface *hero=NULL;
	
    SDL_Rect posimage,poshero;

	SDL_Event event ; 
    SDL_Init(SDL_INIT_VIDEO);

    ennemi e ;
    minimap m ;
    curseur c;


    ecran = SDL_SetVideoMode(700,490,32, SDL_HWSURFACE | SDL_DOUBLEBUF);




    image=IMG_Load("m.jpeg");
    posimage.x=0;
    posimage.y=0;

	hero=IMG_Load("zack.png");
	poshero.x=10;
	poshero.y=300;
	

    if (ecran==NULL)

    {

        printf("error: %s ",SDL_GetError());

        exit(EXIT_FAILURE);

    }




	e=initialisation_ennemi(e);
printf("init ennemi") ; 
	c=initialisation_curseur(c);
printf("init curseur") ; 
	m=initialisation_minimap(m);
printf("init mini") ; 	
	

    while (continuee)
    {
      SDL_PollEvent(&event) ; 
 switch  ( event.type )  
	{ 
             case  SDL_QUIT : 
                 continuee  =  0 ; 
break;
	}

        SDL_BlitSurface(image, NULL, ecran, &posimage);
	afficher_minimap(m,c,ecran);
printf("aff minimap") ; 
	
        afficher(e,ecran);
printf("aff ecran ") ; 
	
       update_ennemi(&e,poshero) ;
printf("update ennemi") ; 
	mini_map(&c ,&e) ;
printf("mini map");
        SDL_Flip(ecran);




    }










    SDL_FreeSurface(ecran);
	
    SDL_Quit();

    return EXIT_SUCCESS;
}


