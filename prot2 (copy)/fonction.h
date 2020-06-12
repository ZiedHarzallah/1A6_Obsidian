
#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_

/**
* @enum state
* @brief enum for ennemi
*/
typedef enum STATE STATE;
enum STATE {WAITING, FOLLOWING,ATTACKING};
/**
* @struct ennemi
* @brief struct for ennemi
*/
typedef struct ennemi
{

SDL_Surface *sprite ; /*!< sprite */


SDL_Rect posSprite[4][4]; /*!< posSprite */

int ligne ; /*!< ligne  */
int col ; /*!< colomne  */

SDL_Rect positionennemi ; /*!< positionennemi */


int direction ; /*!< diretion */
STATE State; /*!< State */

}ennemi;

/**
* @struct minimap
* @brief struct for minimap
*/
typedef struct minimap
{ 
  SDL_Surface* s ; /*!< screen of minimap */
  SDL_Rect position ; /*!< pos of minimap */
}minimap ; 
/**
* @struct curseur
* @brief struct for curseur
*/
typedef struct curseur
{ 
  SDL_Surface* cu ; /*!< cursor */
  SDL_Rect position ; /*!< pos of cursor  */
}curseur ; 

               



ennemi initialisation_ennemi(ennemi e);

void afficher(ennemi e ,SDL_Surface *ecran) ;

void deplacement_aleatoire(ennemi *e,SDL_Rect poshero);

void animer_ennemi(ennemi *e ) ;

int collision_bb(ennemi e , SDL_Rect poshero ) ;

minimap initialisation_minimap (minimap m) ;

curseur initialisation_curseur (curseur c) ; 

void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran);

void mini_map(curseur * c ,ennemi *e);

void update_ennemi(ennemi* e, SDL_Rect poshero);

void updateEnnemiState(ennemi* e, int distEH);






#endif

