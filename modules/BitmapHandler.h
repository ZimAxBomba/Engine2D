#ifndef BITMAPS_H
#define BITMAPS_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <vector>
#include <iostream>

/**
 * Bazowa klasa do pracy przy bitmapach.
 */
class BitmapHandler{
    public:
        sf::Texture loadTexture(std::string);
        //void adjustTexture(sf::IntRect);
};

/**
 * Klasa bazowa dla animowanych obiektów.
 */
class AnimatedObject{
   public:
        virtual void animate(double)=0; /**< Czysto wirtualna funkcja do implementacji animacji. */
        double frames; /**< Ilośc klatek animacji. */
};

/**
 * Klasa bazowa obiektów używającyh sprite.
 */
class BitmapObject: virtual public BitmapHandler{
    public:
        BitmapObject(); /**< Domyślny konstruktor inicjializujący pusty BitmapObject. */
        BitmapObject(std::string);
        sf::Texture texture; /**< Textura obiektu. */
        sf::Sprite sprite; /**< Sprite, który używa tekstury. */
};

/**
 * Klasa dla postaci z animowanym ruchem.
 */
class CharObject: virtual public AnimatedObject, virtual public BitmapHandler{
    public:
        CharObject();
        CharObject(unsigned int,float);
        void setTextures(std::vector<sf::Texture>,unsigned int);
        void animate(double);

        float speed; /**< Prędkośc obiektu. */
        unsigned int width; /**< Szerokośc obiektu. */
        unsigned int height = 0; /**< Wysokość obiektu. */
        unsigned int curFrame = 1; /**< Aktualna klatka animacji. */
        unsigned int maxFrame = 11; /**< Ilośc klatek w animacji. */
        unsigned int dir; /**< Kierunek obiektu. */
        std::vector<sf::Texture> textures; /**< Tablica tekstur obiektu. */
        sf::Sprite sprite; /**< Sprite obiektu. */
};

#endif
