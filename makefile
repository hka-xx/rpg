lib = -lSDL_image -lSDL_mixer -lSDL_gfx
sdl =  `sdl-config --cflags --libs`
rpg : main.o globals.o functions.o map.o graphic.o menu.o
	g++ -o rpg $(sdl) main.o globals.o functions.o map.o graphic.o menu.o $(lib) -g
main.o : main.cpp functions.hpp map.hpp graphic.hpp globals.hpp menu.hpp
	g++ -c main.cpp
globals.o : globals.cpp globals.hpp graphic.hpp map.hpp menu.hpp
	g++ -c globals.cpp
functions.o : functions.cpp functions.hpp map.hpp graphic.hpp globals.hpp functions.hpp
	g++ -c functions.cpp
map.o : map.cpp map.hpp functions.hpp globals.hpp
	g++ -c map.cpp
graphic.o : graphic.cpp graphic.hpp functions.hpp globals.hpp map.hpp
	g++ -c graphic.cpp
menu.o : menu.cpp menu.hpp globals.hpp functions.hpp 
	g++ -c menu.cpp
clean :
	rm *.o rpg
