all:final
main.o:main.cpp
	g++ -c main.cpp
Engine.o:./modules/Engine.cpp
	g++ -c ./modules/Engine.cpp
Shapes.o:./modules/Shapes.cpp
	g++ -c ./modules/Shapes.cpp
BitmapHandler.o:./modules/BitmapHandler.cpp
	g++ -c ./modules/BitmapHandler.cpp
final: main.o Engine.o Shapes.o BitmapHandler.o
	g++ main.o Engine.o Shapes.o BitmapHandler.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -I ./modules/


