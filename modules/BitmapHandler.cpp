#include "BitmapHandler.h"

/**
 * Ładuje teksture z pliku i ją zwraca.
 * @param str Nazwa/lokalizacja pliku z bitmapą.
 * @return Zwraca teksturę wczytaną z pliku.
 */
sf::Texture BitmapHandler::loadTexture(std::string str){
    sf::Texture texture;
    if(!texture.loadFromFile(str)){
        puts("Error loading file");
        return texture;
    }
    else
        return texture;
}

/**
 * Inicjializuje obiekt z teksturą.
 * @param path Ścieżka do pliku.
 */
BitmapObject::BitmapObject(std::string path){
    texture = loadTexture(path);
    sprite.setTexture(texture);
}

/**
 * Konsturktor incjializuje domyślne wartości.
 */
CharObject::CharObject(){
    dir = 8;
    speed = 0.15;
}

/**
 * Inicjializuje CharObject z podaną ilością kierunków d oraz prędkością s.
 * @param d Ilośc kierunków do animacji.
 * @param s Prędkość obiektu.
 */
CharObject::CharObject(unsigned int d,float s){
    dir = d;
    speed = s;
}

/**
 * Funkcja ładuje tekstury dla obiektu.
 */
void CharObject::setTextures(std::vector<sf::Texture> texs,unsigned int d){
   textures = texs;
   dir = d;
}

/**
 * Funkcja odpowiedzialna za animowanie obiektu.
 * @param dt Czas między klatkami gry.
 */
void CharObject::animate(double dt){
    bool w,a,s,d;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            w = true;
        else
            w = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                s = true;
            else
                s = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                a = true;
            else
                a = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                d = true;
            else
                d = false;
            
            /*

             345
             206
             187

             */

    int dir = 1;
    if(w && a)
        dir = 3;
    else if(s && a)
        dir = 1;
    else if(s && d)
        dir = 7;
    else if(w && d)
        dir = 5;
    else if(w)
        dir = 4;
    else if(a)
        dir = 2;
    else if(s)
        dir = 8;
    else if(d)
        dir = 6;
    sprite.setTexture(textures[dir-1]);

    frames+=dt;
    //std::cout << frames << std::endl;

    width = (curFrame%4)*256;
    height = (curFrame%3)*256;
    if(height==512 && width>512)
        width = 512;
    sf::IntRect f(width,height,256,256);

    //std::cout << curFrame << std::endl;
    //std::cout <<"Width: " << width <<"Height: "<< height << std::endl;

    if(frames < curFrame*speed){
        //sprite.setTextureRect(sf::IntRect(0,0,256,265));
        sprite.setTextureRect(f);
    }
    else{
        if(curFrame == maxFrame){
            curFrame = 1;
            frames = 0;
        }
        else
            curFrame++;
    }
}
