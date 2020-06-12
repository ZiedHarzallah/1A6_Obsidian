/**
* @file vie.c
* @brief Testing Program.
* @author Mohamed Zied Harzallah 
* @version 0.1
* @date Apr 11,6,2020
*
* Testing program for gestion vie
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "vie.h"




/**
* @brief To initialize the vie  .
* @param *vie vie
* @return Nothing
*/
void initialiservie(vie *vie)
{

vie->position.x = 0 ;
vie->position.y = 0 ;
vie->fond1 = IMG_Load("1.png");
vie->fond2 = IMG_Load("2.png");
vie->fond3 = IMG_Load("3.png");
vie->fond4 = IMG_Load("4.png");
vie->fond5 = IMG_Load("5.png");
vie->fond6 = IMG_Load("6.jpg");

}

/**
* @brief To afficher vie .
* @param *vie vie
* @param *posj SDL_Rect
* @param posobj SDL_Rect
* @param *ecran SDL_Surface
* @param *i int
* @return Nothing
*/

void affichervie(vie *vie,SDL_Rect *posj , SDL_Rect posobj,SDL_Surface *ecran , int *i )
{
 int k;

printf("donnez le valeur de la collision k \n");
scanf("%d",&k);
  

if(k==1)
{
(*posj).x=0;
(*i)++;
}

if((*i)==0)
{

SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}

else if((*i)==1)
{

SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==2)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==3)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==4)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==5)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond6,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}

//strsep(5);


}

