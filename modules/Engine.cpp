#include "Engine.h"
//using namespace std;


Engine::Engine(){
    fullscreen = false;
    title = "Default";
    sizeX = 200;
    sizeY = 100;
    fps = 60;
    mouseInput = true;
    keyboardInput = true;
    }
Engine::Engine(bool full,int x,int y,std::string name){
        fullscreen = full;
        title = name;
        sizeX = x;
        sizeY = y;
        fps = 60;
    }

void EngineWrapper::run(){
    sf::RenderWindow &mainWindow = engine.getWindow();
    //sf::Event &event = engine.getEvent();
    engine.drawWindow();
    while(mainWindow.isOpen()){
        //handle events
        while(mainWindow.pollEvent(event)){
           HandleEvent(event);
                }
        //handle render
        mainWindow.clear();
        drawShapes();
        mainWindow.display();
        sf::sleep(sf::milliseconds(1000/engine.getFps()));
    }
}



void Engine::drawWindow(){
    if(fullscreen)
        mainWindow.create(sf::VideoMode(sizeX,sizeY),title,sf::Style::Fullscreen);
    else
        mainWindow.create(sf::VideoMode(sizeX,sizeY),title);
}

void EngineWrapper::drawShapes(){
    sf::RenderWindow &mainWindow = engine.getWindow();
    for(auto i = renderer.shapes.begin();i!=renderer.shapes.end();i++)
        mainWindow.draw(**i);
}


void Engine::resize(int x, int y){
    mainWindow.create(sf::VideoMode(x,y),title);
    //sizeX = x;
    //sizeY = y;
}

void Engine::resize(){
    mainWindow.create(sf::VideoMode(sizeX,sizeY),title);
}
void Engine::setFps(int f){
    fps = f;
}

void Engine::setFullscreen(bool full){
    fullscreen = full;
}

void Engine::setX(int x){
    sizeX = x;
}

void Engine::setY(int y){
    sizeY = y;
}

sf::RenderWindow& Engine::getWindow(){
    return mainWindow;
}

bool Engine::isFullscreen(){
    return fullscreen;
}

bool Engine::mouse(){
    return mouseInput;
}

bool Engine::keyboard(){
    return keyboardInput;
}

int Engine::getFps(){
    return fps;
}

int Engine::getX(){
    return sizeX;
}
int Engine::getY(){
    return sizeY;
}

std::string Engine::getTitle(){
    return title;
}

void EngineWrapper::HandleEvent(sf::Event event){
    sf::RenderWindow &mainWindow = engine.getWindow();
    switch(event.type){
        case sf::Event::Closed:
            mainWindow.close();
            break;
        case sf::Event::KeyPressed:
            if(engine.keyboard()){
            switch(event.key.code){
                case sf::Keyboard::X:
                    engine.resize(800,600);
            }
            break;
            }
        case sf::Event::MouseButtonPressed:
            if(engine.mouse()){
                //
            }
            break;
    }
}

/*
void EngineWrapper::run(){
    sf::RenderWindow &mainWindow = engine.getWindow();
    EventHandler &eventHandler = engine.getHandler();
   // sf::RenderWindow mainWindow;
    if(engine.isFullscreen())
        mainWindow.create(sf::VideoMode(engine.getX(),engine.getY()),engine.getTitle(),sf::Style::Fullscreen);
    else
        mainWindow.create(sf::VideoMode(engine.getX(),engine.getY()),engine.getTitle());
    while(mainWindow.isOpen()){
        //handle input
        //handle events
        while(mainWindow.pollEvent(eventHandler.getEvent())){
                //eventHandler.HandleEvent(&engine);
                }
        //handle render
    }
}
*/

