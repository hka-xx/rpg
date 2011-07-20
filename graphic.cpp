#include <cstdlib>
#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_rotozoom.h"

#include "graphic.hpp"
#include "functions.hpp"
#include "globals.hpp"

graphic::graphic()
{
  // char move
  gXpos = WIDTH / 2;
  gYpos = HEIGHT / 2;
  gXmov = 0;
  gYmov = 0;
  dfspd=2.0;
  curspd=dfspd;
  spdboost=2.0;
  jump=5;
  slowdown=0.98;
  // animation
  frame=0;
  //status="c_idle";
  aTick=3;
  lastatick=SDL_GetTicks(); // this belongs in graphic constructor @
  load("sprites/spider.png");
}

graphic::~graphic()
{
  SDL_FreeSurface(mob);
}

bool graphic::handle_input()
{
  switch(event.type)
    {
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{ 
	case SDLK_LEFT:
	  gXmov-=curspd;
	  break;
	case SDLK_RIGHT:
	  gXmov+=curspd;
	  break;
	case SDLK_UP:
	  gYmov-=curspd;
	  break;
	case SDLK_DOWN:
	  gYmov+=curspd;
	  break;
	case SDLK_SPACE:
	  break;
	case SDLK_LSHIFT:
	  curspd=dfspd*spdboost;
	  break;
	case SDLK_LCTRL:
	  break;
	}
      break;
      
    case SDL_KEYUP:          
      switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
	  gXmov+=curspd;
	  break;
	case SDLK_RIGHT:
	  gXmov-=curspd;
	  break;
	case SDLK_UP:
	  gYmov+=curspd;
	  break;
	case SDLK_DOWN:
	  gYmov-=curspd;
	  break;
	case SDLK_SPACE:
	  break;
	case SDLK_LSHIFT:
	  curspd=dfspd;
	  break;
	case SDLK_LCTRL:
	  break;
	case SDLK_ESCAPE:
	  return true;
	}
      break;

    case SDL_QUIT:
      return true;
    }
  return false;
}	
void graphic::move()  
{
  gXpos+=gXmov;
  gYpos+=gYmov;
    
  if((gXpos<0)||(gXpos+sprwi>lvl_w)) 
    {    
      gXpos-=gXmov;
    }

  if((gYpos<0)||(gYpos+sprhi>lvl_h))
    {    
      gYpos-=gYmov;
    }
}

void graphic::show()
{
  /*int tick=SDL_GetTicks();
  if(tick>lastatick)
    {
      if(gXmov==0&&gYmov==0)
	{
	  status="c_idle";
	  //if(frame>1)frame=0;	  
	  //frame++;
	  //lastatick+=1000/aTick;
	}
      else if(gXmov<0)
	{
	  status="c_left";
	  if(frame>3)frame=0;	  
	  frame++;
	  lastatick+=1000/(aTick+8);
	}
      else if(gXmov>0)
	{
	  status="c_right";
	  if(frame>3)frame=0;	  
	  frame++;	  
	  lastatick+=1000/(aTick+8);
	}
    }
      
  if(status=="c_idle")
    apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame]);
  else if(status=="c_left")
    apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame+30]);
  else if(status=="c_right")
    apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame+2]);
  else if(status=="c_jumpl")
    apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame+34]);
  else if(status=="c_jumpr")
    apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame+6]);
  else if(status=="c_expl")
  apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame+9]);*/

  if(gXmov==0&&gYmov==0)
    apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame]);
  else if(gXmov<0)
    {
      frame=3;
      apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame]);
    }
  else if(gXmov>0)
    {
      frame=1;
      apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame]);
    }
  else if(gYmov<0)
    {
      frame=0;
      apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame]);
    }
  else if(gYmov>0)
    {
      frame=2;
      apply_surface((int)gXpos-camera.x,(int)gYpos-camera.y,mob,gScreen,&sprite[frame]);
    }
}

int graphic::getXpos()
{
  return (int)gXpos;
}

int graphic::getYpos()
{
  return (int)gYpos;
}

void graphic::load(std::string img)
{
  mob=loadimg(img);
  //mob=zoomSurface(mob,RATIO,RATIO,1);
  sprwi=24*RATIO; //read from imgload
  sprhi=24*RATIO; //read from imgload
  for(int i=0;i<4;i++)
    {
      sprite[i].x=sprwi*i;
      sprite[i].y=sprhi;
      sprite[i].w=sprwi;
      sprite[i].h=sprhi;
    }
}


void graphic::uXpos(int change)
{
  gXpos+=change;
}

void graphic::uYpos(int change)
{
  gYpos+=change;
}

void graphic::s_cam()
{
  camera.x=(gXpos+sprwi/2)-WIDTH/2; 
  camera.y=(gYpos+sprhi/2)-HEIGHT/2;
  if(camera.x<0)camera.x=0;
  if(camera.y<0)camera.y=0;
  if(camera.x>lvl_w-camera.w)camera.x=lvl_w-camera.w;
  if(camera.y>lvl_h-camera.h)camera.y=lvl_h-camera.h;
}
