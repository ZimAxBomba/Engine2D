#include <iostream>
#include "modules/Engine.h"
#include "modules/Shapes.h"

int main(){
    EngineWrapper app;
    //sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(100,100));

    app.renderer.addRect(sf::Vector2f(25,50),sf::Vector2f(10,10));
    app.renderer.addCirc(40,sf::Vector2f(0,100));
    app.renderer.addRegPoly(20,5,sf::Vector2f(90,10));

    app.run();

    return 0;
}
