#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>

class Point2D{
    private:
    int pX;
    int pY;
};

class PrimitiveRenderer{
    public:
    void addRect(sf::Vector2f,sf::Vector2f);
    void addCirc(double,sf::Vector2f);
    void addRegPoly(double,int,sf::Vector2f);
    std::vector<sf::Shape*>shapes;
};

#endif
