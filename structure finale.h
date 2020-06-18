#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
typedef struct hero
{
SDL_Surface* image [12];
SDL_Rect pos;
SDL_Rect position;
int vie,c;
int score,j;
int direction;
}hero;



void inithero (hero *h);
void affich_hero(hero h,SDL_Surface *screen);
void deplacer_per(hero *h,Input input,Map *m,int c);
void animer_personnage(hero *h,Input input,int c);




