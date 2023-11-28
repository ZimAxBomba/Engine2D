#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
//#include <iostream>
#include <string>
#include <vector>
#include "Shapes.h"
/**
 * Główna klasa Silnik.
 * Zajmuje się rysowaniem okna
 */
class Engine{
    public:
        
        Engine();
        
        Engine(bool,int,int,std::string);

        bool isFullscreen(); /**< Zwraca czy okno jest w pełnym ekranie. */
        bool mouse(); /**< zwraca czy myszka jest włączona. */
        bool keyboard(); /**< Zwraca czy klawiatura jest włączona. */
        int getX(); /**< Zwraca szerokośc okna. */
        int getY(); /**< Zwraca wysokośc okna. */
        std::string getTitle(); /**< Zwraca nazwę okna. */
        sf::RenderWindow& getWindow(); /**< Zwraca okno jako referencję. */
        int getFps(); /**< Zwraca limit FPS. */

        void setX(int); /**< Ustawia szerokośc okna. */
        void setY(int); /**< Ustawia wysokośc okna. */
        void resize(int,int); /**< Zmienia wymiary okna na podane wartości. */
        void resize(); /**< Zmienia wymiary okna. */
        void drawWindow(); /**< Rysuje puste okno. */
        void setFps(int); /**< Ustawia limit FPS. */
        void setFullscreen(bool); /**< Ustawia pełny ekran. */
    private:
        sf::RenderWindow mainWindow; /**< Okno do rysowania. */

        bool fullscreen; /**< Parametr bool ustawiający pełny ekran. */
        bool mouseInput; /**< Parametr bool ustawiający myszkę. */
        bool keyboardInput; /** Parametr bool ustawiający klawiaturę. */
        std::string title; /**< Nazwa okna. */
        int sizeX; /**< Szerokość okna. */
        int sizeY; /**< Wysokośc okna. */
        int fps; /**< Limit FPS. */
};
/**
 * Opakowanie klasy Engine z rendererem i eventem.
 */
class EngineWrapper{
    public:
        void run();
        void HandleEvent(sf::Event);
        void HandleMovement();
        void drawShapes();
        void Update(double);
        Engine engine;
        PrimitiveRenderer renderer;
        sf::Event event;
};
#endif
