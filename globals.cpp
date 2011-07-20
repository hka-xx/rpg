#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#include "globals.hpp"
#include "graphic.hpp"
#include "map.hpp"
#include "menu.hpp"

SDL_Surface *gScreen=NULL;
SDL_Event event;
Mix_Music *def_snd;
int gLastTick=0;
graphic *m_player;
SDL_Rect camera = {0,0,WIDTH,HEIGHT}; 
std::vector<SDL_Rect> box;
map *m_map;
menu *m_menu;
int WIDTH=1024;
int HEIGHT=768;
double RATIO=1;
int lvl_w=WIDTH*3;
int lvl_h=HEIGHT*3;
