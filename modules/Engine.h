#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
//#include <iostream>
#include <string>

class Engine{
    public:
        Engine();
        Engine(bool,int,int,std::string);

        bool isFullscreen();
        int getX();
        int getY();
        std::string getTitle();
        sf::RenderWindow& getWindow();
        //event& getEvent();

        void resize(int,int);
        void setFps(int);
        void setFullscreen(bool);
    private:
        sf::RenderWindow mainWindow;
        //

        bool fullscreen;
        std::string title;
        int sizeX;
        int sizeY;
        int fps;

};

class EngineWrapper{
    public:
        void run();
        void HandleEvent(sf::Event);
        Engine engine;
        sf::Event event;
};
#endif
