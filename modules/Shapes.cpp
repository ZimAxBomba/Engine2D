#include "Shapes.h"

void PrimitiveRenderer::addRect(sf::Vector2f vec,sf::Vector2f origin){
    sf::RectangleShape *rect = new sf::RectangleShape(vec);
    rect->setPosition(origin.x,origin.y);
    shapes.push_back(rect);
}

void PrimitiveRenderer::addCirc(double r,sf::Vector2f origin){
    sf::CircleShape *circ = new sf::CircleShape(r);
    circ->setPosition(origin.x,origin.y);
    shapes.push_back(circ);
}

 void PrimitiveRenderer::addRegPoly(double r, int sides,sf::Vector2f origin){
    sf::CircleShape *circ = new sf::CircleShape(r,sides);
    circ->setPosition(origin.x,origin.y);
    shapes.push_back(circ);
}
