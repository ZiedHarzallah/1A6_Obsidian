/**
* @file ennemi.c
* @brief Testing Program.
* @author omar nouri
* @version 1.1
* @date juin 11 2020
*
* Testing program for movement 
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"



ennemi initialisation_ennemi(ennemi e)
{
	
e.sprite=IMG_Load("ennemi_spr.png");	
	e.positionennemi.x=500 ;
	e.positionennemi.y=300 ;

e.ligne=0;
e.col=0;
e.State=WAITING;
      e.posSprite[0][0].x =0 ;
      e.posSprite[0][0].y =0 ;
      e.posSprite[0][0].w =400/4 ; 
      e.posSprite[0][0].h =400/4  ;

      e.posSprite[0][1].x =100 ;
      e.posSprite[0][1].y =0 ;
      e.posSprite[0][1].w =400/4 ; 
      e.posSprite[0][1].h =400/4  ; 


      e.posSprite[0][2].x =100*2 ;
      e.posSprite[0][2].y =0 ;
      e.posSprite[0][2].w =400/4 ; 
      e.posSprite[0][2].h =400/4  ;

      e.posSprite[0][3].x =100*3 ;
      e.posSprite[0][3].y =0 ;
      e.posSprite[0][3].w =400/4 ; 
      e.posSprite[0][3].h =400/4  ;

      e.posSprite[1][0].x =0 ;
      e.posSprite[1][0].y =100 ;
      e.posSprite[1][0].w =400/4 ; 
      e.posSprite[1][0].h =400/4  ;

      e.posSprite[1][1].x =100 ;
      e.posSprite[1][1].y =100 ;
      e.posSprite[1][1].w =400/4 ; 
      e.posSprite[1][1].h =400/4  ;

      e.posSprite[1][2].x =100*2 ;
      e.posSprite[1][2].y =100 ;
      e.posSprite[1][2].w =400/4 ; 
      e.posSprite[1][2].h =400/4  ;

      e.posSprite[1][3].x =100*3 ;
      e.posSprite[1][3].y =100 ;
      e.posSprite[1][3].w =400/4 ; 
      e.posSprite[1][3].h =400/4  ; 


      e.posSprite[2][0].x =0 ;
      e.posSprite[2][0].y =100*2 ;
      e.posSprite[2][0].w =400/4 ; 
      e.posSprite[2][0].h =400/4  ;

      e.posSprite[2][1].x =100 ;
      e.posSprite[2][1].y =100*2 ;
      e.posSprite[2][1].w =400/4 ; 
      e.posSprite[2][1].h =400/4  ;

      e.posSprite[2][2].x =100*2 ;
      e.posSprite[2][2].y =100*2 ;
      e.posSprite[2][2].w =400/4 ; 
      e.posSprite[2][2].h =400/4  ;

      e.posSprite[2][3].x =100*3 ;
      e.posSprite[2][3].y =100*2  ;
      e.posSprite[2][3].w =400/4 ; 
      e.posSprite[2][3].h =400/4  ;
	
      e.posSprite[3][0].x =0 ;
      e.posSprite[3][0].y =100*3 ;
      e.posSprite[3][0].w =400/4 ; 
      e.posSprite[3][0].h =400/4  ;

      e.posSprite[3][1].x =100 ;
      e.posSprite[3][1].y =100*3 ;
      e.posSprite[3][1].w =400/4 ; 
      e.posSprite[3][1].h =400/4  ;

      e.posSprite[3][2].x =100*2 ;
      e.posSprite[3][2].y =100*3 ;
      e.posSprite[3][2].w =400/4 ; 
      e.posSprite[3][2].h =400/4  ;

      e.posSprite[3][3].x =100*3 ;
      e.posSprite[3][3].y =100*3  ;
      e.posSprite[3][3].w =400/4 ; 
      e.posSprite[3][3].h =400/4  ;	
	

return e;
}

void afficher(ennemi e ,SDL_Surface *ecran)
{
	
SDL_BlitSurface(e.sprite,&e.posSprite[e.ligne][e.col],ecran,&e.positionennemi);
SDL_FreeSurface(&e.posSprite[e.ligne][e.col]);
	
}


void deplacement_aleatoire(ennemi *e,SDL_Rect poshero)
{

	if (poshero.x<e->positionennemi.x) 
	{
        	e->positionennemi.x = e->positionennemi.x-8; 
	}


} 

void animer_ennemi(ennemi *e ) 
{
	
	switch(e->State)
	{
			case WAITING :
			{ e->ligne = 0;
				break ;
      	}
			case FOLLOWING :
				{ e->ligne = 1;

				  break;
				}

			case ATTACKING :
				{  e->ligne = 3;
                                   break ;
					}
	}
	

	e->col ++;    
	if (e->col == 3)   
		 e->col = 0; 
		

}
 



int collision_bb(ennemi e , SDL_Rect poshero )
{
int collision ;
if (( poshero.x+poshero.w<(e.positionennemi).x) || (poshero.x>(e.positionennemi).x + (e.positionennemi).w) || (poshero.y+poshero.h<(e.positionennemi).y) || (poshero.y>(e.positionennemi).y+(e.positionennemi).h))
{
collision=0 ;
}
else collision=1 ; 
return collision ;
}

void updateEnnemiState(ennemi* e, int distEH)
{
	
   	
	
	
	switch (e->State)
      {
      case WAITING:
        if ((distEH>400)&&(distEH<=600)) {
            e->State=FOLLOWING;
            }

      case FOLLOWING:

        if ((0<distEH) && (distEH<=200)) {
             e->State=ATTACKING;
                }
      case ATTACKING:

           if (distEH<=0) {
             e->State=WAITING;
                }

      }
}

void update_ennemi(ennemi* e, SDL_Rect poshero)
{
	
	
    switch(e->State)
    	{
        	case WAITING :
        	{
            		animer_ennemi(e);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animer_ennemi(e);
            		deplacement_aleatoire(&e,poshero);
            		break;
        	}

        	case ATTACKING :
        	{
			
		    	animer_ennemi(e);
			deplacement_aleatoire(&e,poshero);
			break;
        	}       
    	}

int distEH = e->positionennemi.x - poshero.x ;
	updateEnnemiState(&e, distEH);	
}









