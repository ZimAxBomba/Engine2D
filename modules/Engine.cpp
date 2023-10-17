#include "Engine.h"
#include <iostream>
#include <string>
using namespace std;


Engine::Engine(){
    fullscreen = false;
    title = "Default";
    sizeX = 200;
    sizeY = 100;
    fps = 60;
    }
Engine::Engine(bool full,int x,int y,string name){
        fullscreen = full;
        title = name;
        sizeX = x;
        sizeY = y;
        fps = 60;
    }
void Engine::run(){
   // sf::RenderWindow mainWindow;
    if(fullscreen)
        mainWindow.create(sf::VideoMode(sizeX,sizeY),title,sf::Style::Fullscreen);
    else
        mainWindow.create(sf::VideoMode(sizeX,sizeY),title);
    mainWindow.setFramerateLimit(fps);
    while(mainWindow.isOpen()){
        //handle input
        //handle events
        //handle render
    }
}

void Engine::resize(int x, int y){
    sizeX = x;
    sizeY = y;
}

void Engine::setFps(int f){
    fps = f;
}

void Engine::setFullscreen(bool full){
    fullscreen = full;
}
