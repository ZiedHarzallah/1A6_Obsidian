#include "enigmes.h"
#include "tempsjeu.h"

enigme initEnigme ()
	{
  		 enigme e;
 		 e.f = fopen("lesenigmes.txt","r");
 		 e.back = IMG_Load("pyramid.jpg");
 		return e;
	}

void showEnigme (enigmeData ed, SDL_Surface *screen, enigme e)
	{

  	typedef struct
	{
    		SDL_Rect back;
    		SDL_Rect quest;
    		SDL_Rect c1;
    		SDL_Rect c2;
    		SDL_Rect c3;
  	}posenigme;

	posenigme pe;

	SDL_Surface *questsurf;
	SDL_Surface *c1surf;
	SDL_Surface *c2surf;
	SDL_Surface *c3surf;

	TTF_Font * police;
	SDL_Color red = {255,0,0};
	SDL_Color white = {0,0,0};

		if (TTF_Init() < 0)
		{
			printf("error\n");
		}
			else
			{
				police = TTF_OpenFont("angelina.TTF", 24);
				if (police == NULL)
				 {
		  		printf("error dans open font enigma\n");
				}
					else
					{
		  			questsurf = TTF_RenderText_Solid(police, ed.quest, red);
		  			c1surf = TTF_RenderText_Solid(police, ed.c1, red);
		  			c2surf = TTF_RenderText_Solid(police, ed.c2, red);
		  			c3surf = TTF_RenderText_Solid(police, ed.c3, red);
		  			pe.back.x = 0;
		  			pe.back.y = 0;
		  			pe.quest.x = 50;
					pe.quest.y = 50;
					pe.c1.x= 100;
					pe.c1.y= 300;
					pe.c2.x= 100;
					pe.c2.y= 200;
					pe.c3.x= 100;
					pe.c3.y= 100;
					SDL_BlitSurface(e.back, NULL, screen, &pe.back);
					SDL_BlitSurface(questsurf, NULL, screen, &pe.quest);
					SDL_BlitSurface(c1surf, NULL, screen, &pe.c1);
					SDL_BlitSurface(c2surf, NULL, screen, &pe.c2);
					SDL_BlitSurface(c3surf, NULL, screen, &pe.c3);
					SDL_Flip(screen);
					SDL_Delay(1000);
					TTF_CloseFont(police);
					TTF_Quit();
					}
			}
	}

int randomize()
	{
	int pos;
	srand(time(NULL));
	pos=rand()%(8-0+1)+0;
	return pos;
	}

enigmeData generateEnigme(enigme e)
	{
	enigmeData ed [10];
	enigmeData edata;
	int i;
	int pos = randomize();
	for (i = 0; i < 10; i++)
		{
			fgets(ed[i].quest, 400, e.f);
			fscanf(e.f,"1)%s 2)%s 3)%s -%s\n",ed[i].c1, ed[i].c2, ed[i].c3, ed[i].x);
		}
		strcpy(edata.quest,ed[pos].quest);
		strcpy (edata.c1 ,ed[pos].c1);
		strcpy(edata.c2 ,ed[pos].c2);
		strcpy(edata.c3 ,ed[pos].c3);
		strcpy(edata.x ,ed[pos].x);
	return edata;
	}

int resolutionEnigme(enigmeData ed, SDL_Event event)
		{
		switch(event.type)
		{
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_1)
				{
					if (strcmp (ed.c1, ed.x) == 0)
					{
						return 1;
					}
				}
					else
					{
						if(event.key.keysym.sym == SDLK_2)
						{
							if (strcmp (ed.c2, ed.x) == 0)
							{
								return 1;
							}
						}
						else
							{
							if(event.key.keysym.sym == SDLK_3)
							{
								if (strcmp (ed.c3, ed.x) == 0)
								{
									return 1;
								}
							}
                            }
                    }
        }
	return 0;
	}
