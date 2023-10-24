all:final
main.o:main.cpp
	g++ -c main.cpp
Engine.o:./modules/Engine.cpp
	g++ -c ./modules/Engine.cpp
Shapes.o:./modules/Shapes.cpp
	g++ -c ./modules/Shapes.cpp
final: main.o Engine.o Shapes.o
	g++ main.o Engine.o Shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -I ./modules/


