#include <vector>
#include <sstream>
#include "SDL/SDL_rotozoom.h"
#include "SDL/SDL.h"

#include "map.hpp"
#include "functions.hpp"
#include "globals.hpp"

std::string toint(int n)
{
  std::stringstream out;
  out<<n;
  return out.str();
}

map::map()
{
  
}

map::~map()
{
  for(int i=0;i<9;++i)
    SDL_FreeSurface(bg_map[i]);
}

void map::genmap()	// code for generating next map seg and updating col boxes
{
  for(int i=0;i<9;++i)
    bg_map[i]=loadimg("mapdata/"+toint(i)+".png");
 
  //bg1=loadimg("mapsegments/"+next()+".png");
  //bg2=loadimg("mapsegments/"+next()+".png");

  bgc=SDL_CreateRGBSurface(SDL_SWSURFACE,3072,2304,32,0,0,0,0);
  int x=0,y=0;
  for(int i=0;i<9;++i)
    {
      apply_surface(x,y,bg_map[i],bgc);
      x+=1024;
      if(i==2||i==5)
	{
	  y+=768;
	  x=0;
	}
    }
  if (SDL_MUSTLOCK(bgc)) 
    SDL_UnlockSurface(bgc);
  SDL_Flip(bgc);

  bgc=zoomSurface(bgc,RATIO,RATIO,1);

  m_player->uXpos(-(1280*RATIO));  
}
void map::paintmap()
{
  //  if(m_player->getXpos()+m_player->sprwi/2>lvl_w-WIDTH/2)
  //  neednew=true;
  apply_surface(0,0,bgc,gScreen,&camera);
}

