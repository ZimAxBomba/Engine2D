#include <iostream>
#include "modules/Engine.h"
#include "modules/Shapes.h"
#include <random>

int main(){
    srand(time(NULL));
    sf::Color c;
    int r,g,b;

    EngineWrapper app;

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    Point *point = new Point(Point2D(25,25),c);
    app.renderer.addPoint(point);

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    std::cout << r << ";" << g << ";" << b << std::endl;
    c.r=r;c.g=g;c.b=b;
    Line2D *line = new Line2D(Point2D(50,0),Point2D(50,100),c);
    app.renderer.addLine(line);

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    std::vector<Point2D> points = {Point2D(100,0),Point2D(100,100),Point2D(150,200)};
    BrokenLine *bLineO = new BrokenLine(points,true,c);
    app.renderer.addBrokenLine(bLineO);

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    std::vector<Point2D> points2 = {Point2D(200,0),Point2D(200,200),Point2D(250,300)};
    BrokenLine *bLineC = new BrokenLine(points2,false,c);
    app.renderer.makeUpdateable("closed",bLineC);
    app.renderer.addBrokenLine(bLineC);

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    Circle *circle = new Circle(Point2D(300,200),50,c);
    app.renderer.addCustomCircle(circle);

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    Elipse *elipse = new Elipse(Point2D(400,200),25,50,c);
    app.renderer.addCustomElipse(elipse);

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    std::vector<Point2D> points3 = {Point2D(400,0),Point2D(400,100),Point2D(450,400),Point2D(300,200)};
    Polygon *polygon = new Polygon(points3,c);
    app.renderer.addCustomPolygon(polygon);

    app.renderer.addCirc(25,sf::Vector2f(0,300));

    r = std::rand()%256;g = std::rand()%256;b = std::rand()%256;
    c.r=r;c.g=g;c.b=b;
    app.renderer.addRect(sf::Vector2f(100,100),sf::Vector2f(150,300),"kwadrat");
    app.renderer.shapes.back()->setOrigin(50,50);
    app.renderer.shapes.back()->setFillColor(c);
    app.renderer.shapes.back()->setOutlineColor(c);

    Line2D *l = new Line2D(Point2D(300,300),Point2D(300,500));
    app.renderer.makeUpdateable("linia",l);
    app.renderer.addLine(l);
    
    std::vector<sf::Texture> t = {
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir1.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir2.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir3.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir4.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir5.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir6.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir7.png"),
            app.renderer.player.c.loadTexture("textures/Knight_Walk_dir8.png")
        };

            
    app.renderer.player.p.setPosition(100,100);
    app.renderer.player.c.setTextures(t,8);

    BitmapObject *sprite = new BitmapObject("textures/knight2.png");
    app.renderer.addSprite(sprite);

    app.run();

    return 0;
}
