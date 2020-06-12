#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_


/**
* @struct ennemi
* @brief struct for ennemi
*/

typedef struct ennemi
{

SDL_Surface *sprite ; /*!< sprite*/


SDL_Rect posSprite[2][6]; /*!< posSprite*/

int ligne ; /*!< ligne*/
int col ; /*!< col*/

SDL_Rect positionennemi ; /*!< positionennemi*/

int direction ; /*!< direction*/

}ennemi;
/**
* @struct minimap
* @brief struct for minimap
*/
typedef struct minimap
{ 
  SDL_Surface* s ; /*!<s*/
  SDL_Rect position ; /*!< position*/
}minimap ; 
/**
* @struct curseur
* @brief struct for curseur
*/
typedef struct curseur
{ 
  SDL_Surface* cu ; /*!< cu*/
  SDL_Rect position ; /*!< position*/
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






#endif

