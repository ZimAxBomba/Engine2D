#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <math.h>

class Point2D{
    public:
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        void drawPoint();
        Point2D(int,int);
    int x;
    int y;
};


class PrimitiveRenderer{
    public:
    void addRect(sf::Vector2f,sf::Vector2f);
    void addCirc(double,sf::Vector2f);
    void addRegPoly(double,int,sf::Vector2f);
    void addPoint(Point2D);
    void addBrokenLine(std::vector<Point2D>,bool);
    void addCustomCircle(Point2D,int);
    void addCustomElipse(Point2D,int,int);

    void addLine(Point2D,Point2D);

    std::vector<sf::Shape*>shapes;
    std::vector<sf::Vertex*>points;
};

#endif
