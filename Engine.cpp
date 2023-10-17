#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class Engine{
    private:
        bool fullscreen;
        string title;
        int sizeX;
        int sizeY;
        int fps;

        void displayWindow(bool fullscreen, int x,int y,string title){
            if(fullscreen)
                sf::RenderWindow mainWindow(sf::VideoMode(x,y),title,sf::Style::Fullscreen);
            else
                sf::RenderWindow mainWindow(sf::VideoMode(x,y),title);
        }
};
