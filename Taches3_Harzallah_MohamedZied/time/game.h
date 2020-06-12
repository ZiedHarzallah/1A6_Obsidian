#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct vie
{
	
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
        SDL_Surface *fond6;
}vie;

void initialiservie(vie *vie);
void affichervie(vie *vie,SDL_Rect *posj , SDL_Rect posobj,SDL_Surface *ecran , int *i);

typedef struct objet
{
	SDL_Surface *img;
	SDL_Rect pos;
	int rayon;
	float distance;
}objet;

typedef struct enigmeS
{
	SDL_Surface * back_enigme;
	SDL_Rect pos_back_enigme;
	objet obj[4];
	int running;
	int resolu;

	
}enigme;

typedef struct 
{
	SDL_Surface *BG;
	SDL_Rect posBG;
}background;


void scrolling(SDL_Surface *ecran,background bg,int continuer);
SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y);
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage);

typedef struct hero 
{
//image
SDL_Surface *imageH;
SDL_Rect mathANIME [2][5];
int jANIME;
int iANIME;
//position
SDL_Rect pos_HECRAN;
SDL_Rect pos_HBG;

int direction;
int score;

}hero;

typedef struct ennemi
{

SDL_Surface *sprite ;


SDL_Rect posSprite[2][6];

int ligne ;
int col ;

SDL_Rect positionennemi ;

int direction ;

}ennemi;

typedef struct minimap
{ 
  SDL_Surface* s ;
  SDL_Rect position ;
}minimap ; 

typedef struct curseur
{ 
  SDL_Surface* cu ;
  SDL_Rect position ;
}curseur ; 

               


ennemi initialisation_ennemi(ennemi e);

void afficher(ennemi e ,SDL_Surface *ecran) ;

void deplacement_aleatoire(ennemi *e);

void animer_ennemi(ennemi *e ) ;

void maj_ennemi (ennemi *e) ;

int collision_bb(ennemi e , SDL_Rect poshero ) ;

minimap initialisation_minimap (minimap m) ;

curseur initialisation_curseur (curseur c) ; 

void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran);

void mini_map(curseur * c ,ennemi *e);

typedef struct vie
{
	
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
        SDL_Surface *fond6;
}vie;

void initialiservie(vie *vie);
void affichervie(vie *vie,SDL_Rect *posj , SDL_Rect posobj,SDL_Surface *ecran , int *i);







#endif
