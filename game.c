#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "input.h"
#include <time.h>
#include <string.h>
#include <math.h>
#include "affenigme.h"
#include "game.h"

void game_one()
{
    SDL_Surface *screen = NULL, *texte=NULL, *wood=NULL;
    int running;
    hero p;
    background b;
    Input input;
    TTF_Font *police=NULL;
    SDL_Event event;
    int running=1,c=0,x=0,y=0,dir=1,i=0,c1=0;
    SDL_Rect position,positionw,positionb;

    SDL_Color couleurb = {255, 255, 255};

    int tempsActuel = 0, tempsPrecedent = 0, sec = 0, min = 4,sec=60;
    char temps[20] = "";
    positionb.x=0;
    positionb.y=0;
    position.x = 690;
    position.y =27;
    positionw.x = 680;
    positionw.y =10;


    SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(1920,960,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("OBSEDIAN",NULL);

    BG_col=IMG_Load("BG_col.png");

    intialiser_background(&b);
    inithero(&p) //init hero
    initialisation_minimap (m) ;
    initialisation_curseur (c) ;
    initialisation_ennemi(e);
    initEnigme();
    init_enigme(&e);


    tempsActuel = SDL_GetTicks();
    sprintf(temps,"time");

    texte = TTF_RenderText_Blended(police, temps, couleurb);

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);





    while(running)
    {


        if (tempsActuel - tempsPrecedent >= 1000)
        {
            sec--;

            if(sec==0)
            {
                sec=60;
                sec--;
                min--;

            }

            sprintf(temps, ":%dm :%ds",min,sec);
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended(police, temps, couleurb);
            tempsPrecedent = tempsActuel;

        }

        SDL_BlitSurface(texte, NULL, screen, &position);
        SDL_Flip(screen);


        Afficher_BG(m,screen);
        Afficher_hero(p,&screen);
        get_input(&input);

        deplacer_per(&p,input,&b,c);
        animer_personnage(&p,input,c);

        c=detectCollPP (BG_col.*BG,p.mathANIME[i][j]);
        c1=collision_bb(e ,p.mathANIME[i][j],b ) ;

        if(c1==1)
                {
                showEnigme(ed,&screen,e);
                }
        printf("collison %d \n",c);
        printf("collison bb %d \n",c1);




        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            running = 0;
        }
    }
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_FreeSurface(p.mathANIME[i][j]);
    SDL_FreeSurface(BG_col.*BG);
    SDL_FreeSurface(screen);
    SDL_Quit();

    return EXIT_SUCCESS ;

}

