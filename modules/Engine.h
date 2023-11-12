#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
//#include <iostream>
#include <string>
#include <vector>
#include "Shapes.h"

class Engine{
    public:
        Engine();
        Engine(bool,int,int,std::string);

        bool isFullscreen();
        bool mouse();
        bool keyboard();
        int getX();
        int getY();
        std::string getTitle();
        sf::RenderWindow& getWindow();
        int getFps();
        //event& getEvent();

        void setX(int);
        void setY(int);
        void resize(int,int);
        void resize();
        void drawWindow();
        void setFps(int);
        void setFullscreen(bool);
    private:
        sf::RenderWindow mainWindow;

        bool fullscreen;
        bool mouseInput;
        bool keyboardInput;
        std::string title;
        int sizeX;
        int sizeY;
        int fps;
};

class EngineWrapper{
    public:
        void run();
        void HandleEvent(sf::Event);
        void drawShapes();
        void drawPoints();
        void Update(double);
        Engine engine;
        PrimitiveRenderer renderer;
        sf::Event event;
};
#endif
