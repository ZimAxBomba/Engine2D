#include "Engine.h"


/**
 * Konstruktor inicjializujący okno domyślnymi ustawieniami.
 */
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
/**
 * Konstruktor inicjalizuje okno z podanymi wartościami.
 * @param full Otwiera okno w pełnym ekranie jeśtli wartośc wynosi true.
 * @param x Szerokość okna.
 * @param y Wysokość okna.
 * @param name Wyświetlana nazwa okna.
 */
Engine::Engine(bool full,int x,int y,std::string name){
        fullscreen = full;
        title = name;
        sizeX = x;
        sizeY = y;
        fps = 60;
        mouseInput = true;
        keyboardInput = true;
    }
/**
 * Główna funckja uruchamiająca pętle gry.
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
           HandleEvent(event);
           //HandleMovement();
                }
        mainWindow.clear();
        //update
        Update(gameDelta);
        //handle render
        drawShapes();
        mainWindow.display();
        //std::cout << "\n\n";
        //std::cout << 1.0f / fpsClock.getElapsedTime().asSeconds() << std::endl;
        fpsClock.restart();
    }
}

void EngineWrapper::Update(double dt){
    sf::RenderWindow &mainWindow = engine.getWindow();
    renderer.player.Update(dt);
    mainWindow.draw(renderer.player.c.sprite);
    renderer.updateMap["kwadrat"]->rotate(10*dt);
    renderer.updateCustomMap["linia"]->rotate(10*dt,Point2D(300,400));
    //renderer.updateCustomMap["closed"]->move(Point2D(1,1));
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

/**
 * Funkcja przetwarza zdarzenia.
 */
void EngineWrapper::HandleEvent(sf::Event event){
    sf::RenderWindow &mainWindow = engine.getWindow();
    switch(event.type){
        case sf::Event::Closed:
            mainWindow.close();
            break;
            /*
        case sf::Event::Resized:
            int x = event.size.width;
            int y = event.size.height;
            engine.resize(x,y);
            break;
            */
        if(engine.keyboard()){
        case sf::Event::KeyPressed:
            switch(event.key.code){
                case sf::Keyboard::X:
                    engine.resize(800,600);
                    break;
                default:
                    break;
            }
            break;
            }
        if(engine.mouse()){
        case sf::Event::MouseButtonPressed:
            if(event.mouseButton.button == sf::Mouse::Left){
                renderer.addCirc(20,sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
                std::cout << event.mouseButton.x << ":" << event.mouseButton.y << std::endl;
            }
            if(event.mouseButton.button == sf::Mouse::Right){
                renderer.shapes.back()->move(10,10);
            }
            break;
        default:
            break;
        }
    }
}
