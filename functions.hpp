#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "SDL/SDL.h"
#include <string>

void render(); //function for doing all stuff
bool init();            //init all there is...graphic isn't loaded thought
SDL_Surface *loadimg(std::string img);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* dest, SDL_Rect* clip = NULL );
void clean(); 
#endif
