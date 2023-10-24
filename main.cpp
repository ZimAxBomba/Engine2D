#include <iostream>
#include "modules/Engine.h"
#include "modules/Shapes.h"

int main(){
    EngineWrapper app;
    //sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(100,100));

    //app.renderer.addRect(sf::Vector2f(25,50),sf::Vector2f(10,10));
    //app.renderer.addCirc(40,sf::Vector2f(0,100));
    //app.renderer.addRegPoly(20,5,sf::Vector2f(90,10));
    //app.renderer.addLine(Point2D(0,0),Point2D(10,40));
    //app.renderer.addLine(Point2D(0,10),Point2D(0,200));
    //app.renderer.addLine(Point2D(50,0),Point2D(50,100));
    //app.renderer.addLine(Point2D(100,0),Point2D(50,100));
    //app.renderer.addLine(Point2D(40,40),Point2D(40,0));
    //app.renderer.addPoint(Point2D(10,20));
    std::vector<Point2D> v = {Point2D(0,0),Point2D(0,40),Point2D(40,40),Point2D(40,0)};
    std::vector<Point2D> v2 = {Point2D(0,80),Point2D(0,20),Point2D(60,20),Point2D(60,80)};
    //app.renderer.addBrokenLine(v,true);
    //app.renderer.addBrokenLine(v2,false);
    app.renderer.addCustomCircle(Point2D(70,70),10);
    //app.renderer.addCustomElipse(Point2D(20,20),10,20);
    app.renderer.addCustomElipse(Point2D(20,20),30,20);

    app.run();

    return 0;
}
