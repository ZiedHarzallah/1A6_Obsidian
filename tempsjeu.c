#include "tempsjeu.h"

SDL_Surface * gameTime (timer *t) 
    {
		char tim[8];
		SDL_Surface *timetext;
		SDL_Delay(1000);
		if (t->sec==60) 
			{
				t->min++;
				t->sec =0;
			}
			else
				{
					t->sec++;
				}
				if (TTF_Init() < 0) 
					{
					printf("error\n");
					}
					else
						{
						TTF_Font * police = NULL;
						SDL_Color noir = {255, 255, 255};
						police = TTF_OpenFont("angelina.ttf", 32);
						if (police == NULL) 
							{
								printf("error in font time\n");
							}
							else
								{
									sprintf(tim, "0%d : %d", t->min, t->sec);
									timetext = TTF_RenderText_Solid(police, tim, noir);
									TTF_CloseFont(police);
									TTF_Quit();
								}
						}
    return timetext;
    }
