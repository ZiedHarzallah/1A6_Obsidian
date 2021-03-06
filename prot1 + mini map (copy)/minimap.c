/**
* @file minimap.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#include <SDL/SDL_mixer.h>



minimap initialisation_minimap (minimap m) 
{
	
m.s=IMG_Load("mini_map.png");	
	m.position.x=0 ;
	m.position.y=0 ;
return m ;
/**
* @brief to inistalize minimap .
* @param m to minimap
* @return minimap
*/
}
curseur initialisation_curseur(curseur c)
{
c.cu=IMG_Load("curseur.png");
	c.position.x=0;
	c.position.y=5;
return c ;
/**
* @brief to initialize curseur .
* @param c to curseur
* @return curseur
*/
}
 
void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran)
{
SDL_BlitSurface(m.s,NULL,ecran,&m.position);
 
SDL_BlitSurface(c.cu,NULL,ecran,&c.position);
SDL_FreeSurface(&m.position);
SDL_FreeSurface(&c.position);
/**
* @brief to blit minimap .
* @param m to minimap
* @param c to curseur
* @param ecran to the screen
* @return Nothing
*/
}

void mini_map(curseur * c ,ennemi *e)
{
	c->position.x=(float)0.32*(e->positionennemi.x);
	c->position.y=(float)0.32*(e->positionennemi.y);
/**
* @brief to run the minimap .
* @param c to curseur
* @param e to ennemi
* @return Nothing
*/

}


 





