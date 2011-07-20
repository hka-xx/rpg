#include <cstdlib>

#include "map.hpp"
#include "graphic.hpp"
#include "globals.hpp"
#include "menu.hpp"
#include "functions.hpp"

int main(int argc, char *argv[])
{
  if(init())
    {
      m_map=new map();
      m_player=new graphic();
      m_menu=new menu();
      while(m_menu->getbchoice())
	m_menu->paintmenu();
      switch(m_menu->get_choice())
	{
	case 1:
	  while(1)
	    render(); //game loop
	  break;
	case 2:
	  break;
	case 3:
	  break;
	case 4:
	  break;
	case 5:
	  exit(0);
	  break;
	  }
    }
  return 0;
}
