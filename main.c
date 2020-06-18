#include "game.h"
void main()
{
    int volume ,i;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran=NULL;
    Mix_Music *musique;

    ecran=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("egypte",NULL);
    menu(ecran,musique,&i);
    Mix_FreeMusic(musique);
    SDL_Flip(ecran);

}
