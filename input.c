#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "player.h"
#include "input.h"
#include "map.h"


//mettre a jour les evenements


void get_input(Input *input){

 SDL_Event event;

   
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    /*case SDLK_ESCAPE:
                        exit(0);
                    break;*/

                    case SDLK_DELETE:
                        input->erase = 1;
                    break;

                    case SDLK_ESCAPE:
                        input->esp = 1;
                    break;
                      
                   case SDLK_r:
                        input->run = 1;
                    break;

                      case SDLK_v:
                        input->attack = 1;
                    break;

                    case SDLK_LEFT:

                        input->left = 1;
                    break;

                    case SDLK_RIGHT:

                        input->right = 1;
                    break;

                    case SDLK_DOWN:

                        input->down = 1;
                    break;

                    case SDLK_UP:

                        input->up = 1;
                    break;

                    case SDLK_RETURN:
                        input->enter = 1;
                    break;

                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_DELETE:
                        input->erase = 0;
                    break;

                    case SDLK_c:
                        input->jump = 0;
                    break;

                    case SDLK_r:
                        input->run = 0;
                    break;


                    case SDLK_LEFT:
                        input->left = 0;
                    break;

                    case SDLK_RIGHT:
                        input->right = 0;
                    break;

                    case SDLK_DOWN:
                        input->down = 0;
                    break;

                    case SDLK_UP:
                        input->up = 0;
                    break;

                    case SDLK_RETURN:
                        input->enter = 0;
                    break;

                    default:
                    break;
                }
            break;

      /* case SDL_MOUSEBUTTONUP: 
            switch(event.button.button){

                    case SDL_BUTTON_LEFT:
                        input->left = 0;
                    break;

                    case SDL_BUTTON_RIGHT:
                        input->right = 0;
                    break;


}
break;*/
      /* case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button){
                    case SDL_BUTTON_LEFT:
                        input->left = 1;
                    break;

                    case SDL_BUTTON_RIGHT:
                        input->right = 1;
                    break;



}
     break;*/
  
}
 
        }




}
