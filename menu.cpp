#include "SDL/SDL_rotozoom.h"

#include "menu.hpp"
#include "globals.hpp"
#include "functions.hpp"

menu::menu()
{
  m_choice=true;
  choice=1;
  menu1=loadimg("menu/menu.png");
  animate=loadimg("menu/marker.png");
  cursor[0].h=20;
  cursor[0].w=20;
  cursor[0].x=0;
  cursor[0].y=0;
  menuan[0].h=1024;
  menuan[0].w=768;
  menuan[0].x=0;
  menuan[0].y=0;
  frame=0;
  cur_x=280;
  cur_y=290;
}
menu::~menu()
{
  SDL_FreeSurface(menu1);
  SDL_FreeSurface(animate);
}

void menu::paintmenu()
{
  int tick=SDL_GetTicks();
  if(tick<=gLastTick)
    {
      SDL_Delay(1);
      return;
    }
  while (gLastTick < tick)
    {
      while(SDL_PollEvent(&event))
	move_curs();
      gLastTick += 1000 / 4;
    }
  if(SDL_MUSTLOCK(gScreen))
    if(SDL_LockSurface(gScreen) < 0) 
      return;
  //if(frame>1)frame=0;
  apply_surface(0,0,menu1,gScreen/*,&menuan[0]*/); 
  show_curs();
  //frame++;
  if (SDL_MUSTLOCK(gScreen)) 
    SDL_UnlockSurface(gScreen);
  SDL_Flip(gScreen);
}

void menu::move_curs()
{
  switch(event.type)
    {
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{
	case SDLK_UP:
	  cur_y-=70*RATIO;
	  choice--;
	  break;
	case SDLK_DOWN:
	  cur_y+=70*RATIO;
	  choice++;
	  break;
	case SDLK_RETURN:
	  m_choice=false;
	  break;
	  /*	case SDLK_F1:
	  changeres(1);
	  break;
	case SDLK_F2:
	  changeres(2);
	  break;
	case SDLK_F3:
	  changeres(3);
	  break;*/
	}
      break;
    }
}

void menu::show_curs()
{
  if(cur_y<290*RATIO)
    {
      choice=1;
      cur_y=290*RATIO;
    }
  if(cur_y>570*RATIO)
    {
      choice=5;
      cur_y=570*RATIO;
    }
  apply_surface(cur_x,cur_y,animate,gScreen);
}

int menu::get_choice()
{
  return choice;
}

bool menu::getbchoice()
{
  return m_choice;
}

/*void menu::changeres(int res)
{
  if(res==1)			// 640x480
    {
      WIDTH=640;
      HEIGHT=480;
      RATIO=0.5;
      gScreen = SDL_SetVideoMode(WIDTH,HEIGHT, 32, SDL_SWSURFACE);
    }
  if(res==2)
    {
      WIDTH=1024;
      HEIGHT=768;
      RATIO=0.8;
      gScreen=SDL_SetVideoMode(WIDTH,HEIGHT, 32, SDL_SWSURFACE);
    }
  if(res==3)			// 1280x960
    {
      WIDTH=1280;
      HEIGHT=960;
      RATIO=1;
      gScreen = SDL_SetVideoMode(WIDTH,HEIGHT, 32, SDL_SWSURFACE);
    }
  animate=zoomSurface(animate,RATIO,RATIO,1);
  menu1=zoomSurface(menu1,RATIO,RATIO,1);
  menuan[0].h=960*RATIO;
  menuan[0].w=1280*RATIO;
  menuan[1].h=960*RATIO;
  menuan[1].w=1280*RATIO;
  menuan[1].x=1280*RATIO;
  cursor[0].h=100*RATIO;
  cursor[0].w=100*RATIO;
  cursor[1].h=100*RATIO;
  cursor[1].w=100*RATIO;
  cursor[1].x=100*RATIO;
  cur_x=350*RATIO;
  cur_y=300*RATIO;
  }*/
