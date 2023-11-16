#include <iostream>
#include "modules/Engine.h"
#include "modules/Shapes.h"

int main(){
    EngineWrapper app;
    //sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(100,100));
/*
    app.renderer.addRect(sf::Vector2f(25,50),sf::Vector2f(10,10));
    app.renderer.addCirc(40,sf::Vector2f(0,100));
    app.renderer.addRegPoly(20,5,sf::Vector2f(90,10));
    app.renderer.addLine(Point2D(0,0),Point2D(10,40));
    app.renderer.addLine(Point2D(0,10),Point2D(0,200));
    app.renderer.addLine(Point2D(50,0),Point2D(50,100));
    app.renderer.addLine(Point2D(100,0),Point2D(50,100));
    app.renderer.addLine(Point2D(40,40),Point2D(40,0));
    app.renderer.addPoint(Point2D(10,20));
    std::vector<Point2D> v = {Point2D(0,0),Point2D(0,40),Point2D(40,40),Point2D(40,0)};
    std::vector<Point2D> v2 = {Point2D(0,80),Point2D(0,20),Point2D(60,20),Point2D(60,80)};
    //app.renderer.addBrokenLine(v,true);
    //app.renderer.addBrokenLine(v2,false);
    app.renderer.addCustomCircle(Point2D(70,70),10);
    //app.renderer.addCustomElipse(Point2D(20,20),10,20);
    app.renderer.addCustomElipse(Point2D(20,20),30,20);
*/

    //Line2D *line = new Line2D(Point2D(1,2),Point2D(88,600));
    //app.renderer.addLine(line);
/*
    std::vector<Point2D> v = {Point2D(0,0),Point2D(0,40),Point2D(40,40),Point2D(40,0)};
    std::vector<Point2D> v2 = {Point2D(0,0),Point2D(0,40),Point2D(80,60),Point2D(40,100),Point2D(20,0)};
    //BrokenLine *line2 = new BrokenLine(v2,false);
    //app.renderer.addBrokenLine(line2);
    Polygon *poly1 = new Polygon(v);
    Polygon *poly = new Polygon(v2);
    app.renderer.addCustomPolygon(poly1);
    app.renderer.addCustomPolygon(poly);

    Circle *circ = new Circle(Point2D(100,100),50);
    //circ->fill(circ->origin);
    app.renderer.addCustomCircle(circ);
    Elipse *elipse = new Elipse(Point2D(100,200),50,100);
    app.renderer.addCustomElipse(elipse);


    Point2D point(100,100);
    Point *p = new Point(point);
    Point *p2 = new Point(point);
    app.renderer.addPoint(p);
    p2->rotate(0.5);
    app.renderer.addPoint(p2);


    Line2D *line = new Line2D(Point2D(40,50),Point2D(100,120));
    Line2D *line2 = new Line2D(Point2D(40,50),Point2D(100,120));
    app.renderer.addLine(line);
    line2->move(Point2D(40,40));
    line2->scale(2);
    app.renderer.addLine(line2);
 */  

    app.renderer.player.p.setPosition(100,100);

    BitmapObject *sprite = new BitmapObject("textures/knight2.png");
    app.renderer.addSprite(sprite);

    app.run();

    return 0;
}
