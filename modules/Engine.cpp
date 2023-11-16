#include "Engine.h"


Engine::Engine(){
    fullscreen = false;
    title = "Default";
    sizeX = 800;
    sizeY = 600;
    fps = 60;
    mouseInput = true;
    keyboardInput = true;
    mainWindow.setFramerateLimit(fps);
    }
Engine::Engine(bool full,int x,int y,std::string name){
        fullscreen = full;
        title = name;
        sizeX = x;
        sizeY = y;
        fps = 60;
    }
/*
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
        //sf::sleep(sf::milliseconds(1000/engine.getFps()));
    }
}
*/

/*
 * gotta change evens
void EngineWrapper::run(){
    sf::Clock dClock;
    double realDelta = 0.0;
    double lastUpdate = dClock.getElapsedTime().asSeconds();
    //double gameTimeFactor = 1.0;
    sf::RenderWindow &mainWindow = engine.getWindow();
    //sf::Event &event = engine.getEvent();
    engine.drawWindow();
    while(mainWindow.isOpen()){
        realDelta = dClock.getElapsedTime().asSeconds() - lastUpdate;
        lastUpdate += realDelta;
        double gameDelta = realDelta;// * gameTimeFactor;
        //handle events
        while(mainWindow.pollEvent(event)){
           HandleEvent(event);
                }
        mainWindow.clear();
        //update
        Update(gameDelta);
        //handle render
        drawShapes();
        mainWindow.display();
        //sf::sleep(sf::milliseconds(1000/engine.getFps()));
    }
}
*/

void EngineWrapper::run(){
    sf::Clock fpsClock;
    sf::Clock dClock;
    double realDelta = 0.0;
    double lastUpdate = dClock.getElapsedTime().asSeconds();
    //double gameTimeFactor = 1.0;
    sf::RenderWindow &mainWindow = engine.getWindow();
    mainWindow.setFramerateLimit(engine.getFps());
    //sf::Event &event = engine.getEvent();
    engine.drawWindow();
    while(mainWindow.isOpen()){
        realDelta = dClock.getElapsedTime().asSeconds() - lastUpdate;
        lastUpdate += realDelta;
        double gameDelta = realDelta;// * gameTimeFactor;
        //handle events
        while(mainWindow.pollEvent(event)){
           //HandleEvent(event);
           //HandleMovement();
                }
        mainWindow.clear();
        //update
        Update(gameDelta);
        //handle render
        drawShapes();
        mainWindow.display();
        std::cout << "\n\n";
        std::cout << 1.0f / fpsClock.getElapsedTime().asSeconds() << std::endl;
        fpsClock.restart();
    }
}

void EngineWrapper::Update(double dt){
    sf::RenderWindow &mainWindow = engine.getWindow();
    renderer.player.Update(dt);
    mainWindow.draw(renderer.player.c.sprite);
    //mainWindow.draw(renderer.player.p);
}



void Engine::drawWindow(){
    if(fullscreen)
        mainWindow.create(sf::VideoMode(sizeX,sizeY),title,sf::Style::Fullscreen);
    else
        mainWindow.create(sf::VideoMode(sizeX,sizeY),title);
}

void EngineWrapper::drawShapes(){
    sf::RenderWindow &mainWindow = engine.getWindow();
    if(renderer.shapes.size()!=0){
        for(auto i = renderer.shapes.begin();i!=renderer.shapes.end();i++)
            mainWindow.draw(**i);
    }
    //CUSTOM DRAW
    if(renderer.customShapes.size()!=0){
        for(int i=0;i<renderer.customShapes.size();i++){
            //for(auto j = renderer.customShapes[i].shape.begin();j!=renderer.customShapes[i].shape.end();j++)
            //literal black magic vodoo stuff
            for(int j=0;j<renderer.customShapes[i]->shape.size();j++)
                mainWindow.draw(*renderer.customShapes[i]->shape[j]);
        }
    }
    //SPRITES
    if(renderer.sprites.size()!=0){
        for(int i=0;i<renderer.sprites.size();i++)
            mainWindow.draw(renderer.sprites[i]->sprite);
    }
}
/*
void EngineWrapper::drawPoints(){
    sf::RenderWindow &mainWindow = engine.getWindow();
    for(auto i = renderer.points.begin();i!=renderer.points.end();i++)
        mainWindow.draw(*i,1,sf::Points);
}
*/


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
/*
void EngineWrapper::HandleMovement(){
    bool w = false;
    bool s = false;
    bool a = false;
    bool d = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        w = true;
    else
        w = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        s = true;
    else
        s = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        a = true;
    else
        a = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        d = true;
    else
        d = false;

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        renderer.player.speed.y-=30;

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        renderer.player.speed.y+=30;

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        renderer.player.speed.x-=30;

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        renderer.player.speed.x+=30;


    if(w)
        renderer.player.speed.y-=30;
    if(s)
        renderer.player.speed.y+=30;
    if(a)
        renderer.player.speed.x-=30;
    if(d)
        renderer.player.speed.x+=30;
}
*/

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
                    break;
                case sf::Keyboard::W:
                    renderer.player.speed.y-=10;
                    break;
                case sf::Keyboard::S:
                    renderer.player.speed.y+=10;
                    break;
                case sf::Keyboard::A:
                    renderer.player.speed.x-=10;
                    break;
                case sf::Keyboard::D:
                    renderer.player.speed.x+=10;
                    break;
                default:
                    break;
            }
            break;
            }
        case sf::Event::MouseButtonPressed:
            if(engine.mouse()){
                //
            }
            break;
        default:
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

