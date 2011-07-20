#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include "SDL/SDL.h"

class menu
{
public:
  menu();
  ~menu();
  void paintmenu();
  void move_curs();
  void show_curs();
  int get_choice();
  bool getbchoice();
  //void changeres(int res);

protected:
  int choice;
  SDL_Surface *menu1;
  SDL_Surface *animate;
  SDL_Rect menuan[1];
  SDL_Rect cursor[1];
  bool m_choice;
  int frame;
  int cur_x;
  int cur_y;
};
#endif
