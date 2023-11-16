#ifndef BITMAPS_H
#define BITMAPS_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <vector>
#include <iostream>

class BitmapHandler{
    public:
        sf::Texture loadTexture(std::string);
        //void adjustTexture(sf::IntRect);
};

class AnimatedObject{
   public:
        virtual void animate(double)=0;
        double frames;
};
class BitmapObject: virtual public BitmapHandler{
    public:
        BitmapObject();
        BitmapObject(std::string);
        sf::Texture texture;
        sf::Sprite sprite;
};

class CharObject: virtual public AnimatedObject, virtual public BitmapHandler{
    public:
        CharObject();
        CharObject(unsigned int,float);
        void setTextures(std::vector<sf::Texture>,unsigned int);
        void animate(double);

        float speed;
        unsigned int width;
        unsigned int height = 0;
        unsigned int curFrame = 1;
        unsigned int maxFrame = 11;
        unsigned int dir;
        std::vector<sf::Texture> textures;
        sf::Sprite sprite;
};

#endif
