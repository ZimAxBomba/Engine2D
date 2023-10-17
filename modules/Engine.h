#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

class Engine{
    public:
        Engine();
        Engine(bool,int,int,std::string);
        void run();
        void resize(int,int);
        void setFps(int);
        void setFullscreen(bool);
    private:
        sf::RenderWindow mainWindow;
        bool fullscreen;
        std::string title;
        int sizeX;
        int sizeY;
        int fps;

};

#endif
