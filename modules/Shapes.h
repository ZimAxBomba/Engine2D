#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <math.h>

#include <iostream>

class Point2D{
    public:
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        void drawPoint();
        Point2D(int,int);
        Point2D();
    int x;
    int y;
};


class CustomShape{
    public:
        virtual void draw()=0;
        void addPixel(Point2D,Point2D);
        void addPixel(Point2D,Point2D,std::vector<sf::Shape*>&);

        sf::Color col;
        std::vector<sf::Shape*>shape;
        //std::vector<Point2D*>shape;
};

class TransformableShape{
    public:
        virtual void move()=0;
        virtual void rotate()=0;
        virtual void scale()=0;
};

class Line2D: virtual public CustomShape{
    public:
    Line2D();
    Line2D(Point2D,Point2D);
    void draw();
    void draw(std::vector<sf::Shape*>&);

    //std::vector<sf::Shape*>shape;
    //private:
    Point2D p1;
    Point2D p2;
};

class BrokenLine: virtual public CustomShape{
    public:
        BrokenLine();
        BrokenLine(std::vector<Point2D>,bool);
        void draw();

        std::vector<Point2D> points;
        bool isOpen;
};

class Circle: virtual public CustomShape{
    public:
    Circle();
    Circle(Point2D,int);
    void draw();
    void fill(Point2D);

    Point2D origin;
    int r;
};

class Elipse: virtual public CustomShape{
    public:
        Elipse();
        Elipse(Point2D,int,int);
        void draw();
        //void fill();

        Point2D origin;
        int rx;
        int ry;
};

class Polygon: virtual public CustomShape{
    public:
        Polygon();
        Polygon(std::vector<Point2D>);
        void draw();

        std::vector<Point2D> points;
        bool intersecting;
};

class PrimitiveRenderer{
    public:
    void addRect(sf::Vector2f,sf::Vector2f);
    void addCirc(double,sf::Vector2f);
    void addRegPoly(double,int,sf::Vector2f);
    void addPoint(Point2D);
    //
    void addLine(Line2D*);
    void addBrokenLine(BrokenLine*);
    void addCustomCircle(Circle*);
    void addCustomElipse(Elipse*);
    void addCustomPolygon(Polygon*);
    //
    //
    //void addCustomElipse(Point2D,int,int);
    //void addCustomCircle(Point2D,int);
    //void addLine(Point2D,Point2D);
    //void addBrokenLine(std::vector<Point2D>,bool);
    //
    void FillShape(CustomShape*,Point2D);

    std::vector<sf::Shape*>shapes;
    std::vector<CustomShape*>customShapes;
};

double EvalDet(Point2D,Point2D,Point2D);
bool EvalCollision(Line2D,Line2D);

#endif
