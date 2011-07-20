#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#include "graphic.hpp"
#include "map.hpp"
#include "menu.hpp"

extern SDL_Surface *gScreen;
extern SDL_Event event;
extern Mix_Music *def_snd;
extern int gLastTick;
extern graphic *m_player;
extern SDL_Rect camera;
extern std::vector<SDL_Rect> box;
extern map *m_map;
extern menu *m_menu;
extern int WIDTH;
extern int HEIGHT;
extern double RATIO;
extern int lvl_w;
extern int lvl_h;

const int PHYSICSFPS=100;
#endif
