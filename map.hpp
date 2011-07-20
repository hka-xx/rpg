#ifndef MAP_HPP
#define MAP_HPP

#include "SDL/SDL.h"
#include "SDL/SDL_image.h" 
#include <string>
#include <vector>

class map
{
 public:
  map();
  ~map();
  void genmap();
  void paintmap();
 private:
  SDL_Surface *bg_map[9]; //place generated level here
  SDL_Surface *bgc;
};

#endif
