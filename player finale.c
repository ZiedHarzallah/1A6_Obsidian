#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "structure.h"


//initialiser personnage
void inithero(hero *h)
{
   h->pos.x=110;
   h->pos.y=300;
   h->direction=0;
   h->j=0,h->c=0;
   h->image[0]=IMG_Load("sprite1.png");
   h->image[1]=IMG_Load("sprite2.png");
   h->image[2]=IMG_Load("sprite3.png");
   h->image[4]=IMG_Load("sprite4.png");
   h->image[3]=IMG_Load("sprite5.png");
   h->image[5]=IMG_Load("sprite6.png");
   h->image[6]=IMG_Load("sprite7.png");
   h->image[7]=IMG_Load("sprite8.png");
   h->image[8]=IMG_Load("sprite9.png");
   h->image[9]=IMG_Load("sprite10.png");
   h->image[10]=IMG_Load("sprite11.png");
   h->image[11]=IMG_Load("sprite12.png");
}


void affich_hero(hero h,SDL_Surface *screen)
{
SDL_BlitSurface(h.image[h.j],NULL,screen,&h.pos);
SDL_FreeSurface(h.image[h.j]);
}


//deplacer personnage 

void deplacer_per(hero *h,Input input,Map *m,int c)
{
   // printf(" %d %d \n",m->post.x,m->post.y);
   if(input.right==1 && input.right!=0)
	{
  
          h->direction=0;
          m->post.x=m->post.x-30;
          m->post1.x=m->post1.x+30;
          if (c==1)
		{ 
		m->post.x=m->post.x+30;
          	m->post1.x=m->post1.x-30;
		}
	}
   if(input.up==1 && input.up!=0)
	{
  
          h->direction=1;
          m->post.y=m->post.y+20;
          m->post1.y=m->post1.y-20;
          if (c==1)
		{ 
		m->post.y=m->post.y-20;
          	m->post1.y=m->post1.y+20;
		}
	}
   if(input.left==1 && input.left!=0)
	{
  
          h->direction=2;
          m->post.x=m->post.x+20;
          m->post1.x=m->post1.x-20;
          if (c==1)
		{ 
		m->post.x=m->post.x-20;
          	m->post1.x=m->post1.x+20;
		}
}
	if(input.down==1 && input.down!=0)
	{
  
          h->direction=3;
          m->post.y=m->post.y-20;
          m->post1.y=m->post1.y+20;
          if (c==1)
		{ 
		 m->post.y=m->post.y+20;
          	 m->post1.y=m->post1.y-20;
		}
	}
 
	if(input.right==1 && input.right!=0 && input.left==1 && input.left!=0  && 		input.run==1)
	{
    	  h->direction=0;
          m->post.x=m->post.x-60;
          m->post1.x=m->post1.x+60;
          	if (c==1)
		{ 
		m->post.x=m->post.x+60;
         	m->post1.x=m->post1.x-60;
		}
	}




}

//animer personnage 
void animer_personnage(hero *h,Input input,int c)
{
if(input.right==1)
{
	if(h->j<2)
	{
 		 h->j++;
	} 

else 
   h->j=0;
}


else if(input.up==1)
{
	if(h->j<5 && h->j>2)
	{
   		h->j++;
	} 
else 
h->j=3;
}

	else if(input.down==1)
	{
		if(h->j<8 && h->j>5)
		{
   			h->j++;
		} 
		else 
   		h->j=6;
}

else if(input.left==1)
	{
	if(h->j<11 && h->j>8)
		{
  		 h->j++;
		} 
		else 
   		h->j=9;
	}
else if(input.right==0)
{
  h->j=0;

}
else if(input.down==0 )
{
  h->j=0;

}
else if(input.up==0  )
{
  h->j=0;

}
else if(input.left==0  )
{
  h->j=0;

}
}

SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) surface->pixels ;

	//offset by y
	pPosition += ( surface->pitch * y ) ;

	//offset by x
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}







