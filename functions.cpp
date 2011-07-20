#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"

#include "functions.hpp"
#include "globals.hpp"
#include "map.hpp"
#include "graphic.hpp"

void render()
{
  int tick = SDL_GetTicks();
  if(tick <= gLastTick) 
    {
      SDL_Delay(1);
      return;
    }
  
  while (gLastTick < tick)
    {
      while(SDL_PollEvent(&event))
	if(m_player->handle_input())
	  clean();
      gLastTick += 1000 / PHYSICSFPS;
    }
  
  if(SDL_MUSTLOCK(gScreen))
    if(SDL_LockSurface(gScreen) < 0) 
      return;
  
  /*if(neednew) 
    m_level->genlevel();
    m_level->paintlevel(); */

  m_player->move();
  m_player->s_cam();    
  
  m_player->show();

  if (SDL_MUSTLOCK(gScreen)) 
    SDL_UnlockSurface(gScreen);
  SDL_Flip(gScreen);

}

bool init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
      fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
      return false;
    }

  //if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096) == -1 )return false;
 
  atexit(SDL_Quit); //make sure it exits nicely
  
  //set screen
  gScreen = SDL_SetVideoMode(WIDTH,HEIGHT, 32, SDL_SWSURFACE);
  if(gScreen==NULL)return false;
  SDL_WM_SetCaption( "RPG", NULL ); 
  
  gLastTick = SDL_GetTicks();

  //  def_snd=Mix_LoadMUS("music/The_Ultimate_Game_in-play.mp3");
  //Mix_PlayMusic(def_snd,-1);
  return true;
}

SDL_Surface *loadimg(std::string img)
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;
  loadedImage = IMG_Load( img.c_str() );
  if( loadedImage != NULL )
    {
      optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
      SDL_FreeSurface( loadedImage );
    }
  return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* dest, SDL_Rect* clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface( source, clip, dest, &offset );
}

void clean() 
{
  Mix_FreeMusic(def_snd);
  Mix_CloseAudio;
  exit(0);
}


