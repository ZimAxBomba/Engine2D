main:main.cpp
	g++ -c main.cpp
	g++ -c ./modules/Engine.cpp
	g++ -c ./modules/Shapes.cpp
	g++ main.o Engine.o Shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -I ./modules/
