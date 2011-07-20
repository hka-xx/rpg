#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <vector>
#include "map.hpp"

class graphic
{
 public:
  graphic();
  ~graphic();
  bool handle_input(); //input
  void move();
  void show(); //paint char to screen, will make other for level and yet another for spawns
  int getXpos();
  int getYpos();
  void uXpos(int change);
  void uYpos(int change);
  void load(std::string img); //need to modify @@@ broken
  void s_cam();
  friend class map;

 private:
  double gXpos,gYpos;
  double gXmov,gYmov,gXjump;
  double dfspd;
  double curspd;
  double spdboost;
  double jump;
  int sprwi;
  int sprhi;
  double slowdown;
  SDL_Surface *mob;  
  SDL_Rect sprite[4]; //clip for spritesheet
  int frame;
  //std::string status;
  int aTick; //speed of animation
  int lastatick;
};

#endif
