#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <stdlib.h>
#include <math.h>
#include "BitmapHandler.h"

#include <iostream>

/**
 * Klasa przechowuje punkt w przestrzeni 2D.
 */
class Point2D{
    public:
        int getX(); /**< Zwraca wartośc x punktu. */
        int getY(); /**< Zwraca wartośc y punktu. */
        void setX(int); /**< Ustawia wartość x punktu. */
        void setY(int); /**< Ustawia wartość y punktu. */
        Point2D(int,int);
        Point2D();
    int x; /**< Wartość x punktu. */
    int y; /**< Wartość y punktu. */
};

/**
 * Klasa bazowa dla wszystkich nowo zaimplementowanych klas.
 */
class CustomShape{
    public:
        virtual void draw()=0; /**< Czysto wirtualna funkcja do rysowania kształtu. */
        void addPixel(Point2D,Point2D);
        void addPixel(Point2D,Point2D,std::vector<sf::Shape*>&);

        sf::Color col = sf::Color::White; /**< Kolor kształtu. Domyślnie biały. */
        std::vector<sf::Shape*>shape; /**< Przechowuje wszystkie pixele kształtu. */
};

/**
 * Klasa bazowa dla wszystkich dynamicznych obiektów.
 */
class UpdateableObject{
    public:
    virtual void Update(double)=0; /**< Czysto wirtualna funkcja aktualizująca obiekt. */
};

/**
 * Klasa bazowa dla wszystkich obiektów, które mogą być przekształcone.
 */
class TransformableShape{
    public:
        /**
         * Czysto wirtualna funkcja przenosząca obiekt
         * o podany wektor.
         * @param Point2D Wektor, o który przesunąć kształt.
         */
        virtual void move(Point2D)=0;
        /**
         * Czysto wirtualna funkcja obracająca obiekt
         * o podany kąt w radianach.
         * @param float Kąt w radianach, o który przesunąć kształt.
         */
        virtual void rotate(float)=0;
        virtual void rotate(float,Point2D)=0;
        /**
         * Czysto wirtualna funkcja skalująca obiekt.
         * @param float Skala, o którą przeskalować obiekt.
         */
        virtual void scale(float)=0;
};

/**
 * Klasa rysująca punkt.
 */
class Point: virtual public CustomShape,virtual public TransformableShape{
    public:
        Point();
        Point(Point2D);
        Point(Point2D,sf::Color color);
        void draw();
        void move(Point2D);
        void rotate(float);
        void rotate(float,Point2D);
        void scale(float);

        Point2D p; /**< Koordynaty punktu. */
};


/**
 * Klasa rysująca linię.
 */
class Line2D: virtual public CustomShape,virtual public TransformableShape{
    public:
    Line2D();
    Line2D(Point2D,Point2D);
    Line2D(Point2D,Point2D,sf::Color color);
    void draw();
    void draw(std::vector<sf::Shape*>&);
    void move(Point2D);
    void rotate(float);
    void rotate(float,Point2D);
    void scale(float);

    Point2D p1; /**< Pierwszy punkt lini. */
    Point2D p2; /**< Ostatni punkt lini. */
};


/**
 * Klasa rysująca łamaną otwartą lub zamkniętą.
 */
class BrokenLine: virtual public CustomShape,virtual public TransformableShape{
    public:
        BrokenLine();
        BrokenLine(std::vector<Point2D>,bool);
        BrokenLine(std::vector<Point2D>,bool,sf::Color);
        void draw();
        void move(Point2D);
        void rotate(float);
        void rotate(float,Point2D);
        void scale(float);

        std::vector<Point2D> points; /**< Wektor punktów łamanej.*/
        bool isOpen; /**< Określa czy łamana jest otwarta.*/
};

/**
 * Klasa rysująca koło.
 */
class Circle: virtual public CustomShape{
    public:
    Circle();
    Circle(Point2D,int);
    Circle(Point2D,int,sf::Color);
    void draw();
    void fill(Point2D);

    Point2D origin; /**< Środek koła. */
    int r; /**< Promień koła. */
};

/**
 * Klasa rysująca elipsę.
 */
class Elipse: virtual public CustomShape{
    public:
        Elipse();
        Elipse(Point2D,int,int);
        Elipse(Point2D,int,int,sf::Color);
        void draw();
        void fill(Point2D);

        Point2D origin;
        int rx;
        int ry;
};

/**
 * Klasa rysująca wielokąt.
 */
class Polygon: virtual public CustomShape{
    public:
        Polygon();
        Polygon(std::vector<Point2D>);
        Polygon(std::vector<Point2D>,sf::Color);
        void draw();

        std::vector<Point2D> points;
        bool intersecting; /**< Pokazuje czy boki wielokątu przecinają się.*/
};

/**
 * Klasa gracza. Umożliwia poruszanie się oraz animacje 8-kierunkowe.
 */
class Player:virtual public UpdateableObject{
    public:
        Player();
        Player(Point2D);
        void Update(double);

        float acc; /**< Przyspieszenie postaci. */
        float max_speed; /**< Maksymalna prędkość postaci. */
        sf::Vector2f speed; /**< Prędkośc postaci. */
        Point2D position; /**< Pozycja postaci. */
        sf::RectangleShape p;
        CharObject c; /**< Przechowuje bitmapy postaci. */

};

/**
 * Klasa przechowująca wszystkie obiekty do rysowania.
 */
class PrimitiveRenderer{
    public:
    void addRect(sf::Vector2f,sf::Vector2f);
    void addCirc(double,sf::Vector2f);
    void addRegPoly(double,int,sf::Vector2f);

    void addRect(sf::Vector2f,sf::Vector2f,std::string);
    void addCirc(double,sf::Vector2f,std::string);
    void addRegPoly(double,int,sf::Vector2f,std::string);
    
    //
    void addPoint(Point*);
    void addLine(Line2D*);
    void addBrokenLine(BrokenLine*);
    void addCustomCircle(Circle*);
    void addCustomElipse(Elipse*);
    void addCustomPolygon(Polygon*);

    void addSprite(BitmapObject*);
    void FillShape(CustomShape*,Point2D);
    void makeUpdateable(std::string,TransformableShape*);
    void makeUpdateable(std::string,sf::Shape*);

    Player player = Player(Point2D(50,50)); /**< Klasa gracza. */
    std::vector<BitmapObject*>sprites; /**< Wektor przechowujący sprite do rysowania. */
    std::vector<sf::Shape*>shapes; /**< Wektor przechowujący kształty do rysowania. Pochodzą one z sf::Shape. */
    std::vector<CustomShape*>customShapes; /**< Wektor przechowujący kształty do rysowania. Są to zaimplementowane od nowa klasy. */
    std::map<std::string,sf::Shape*> updateMap; /**< Mapa przechowuje obiekty, które można aktualizować. Pochodzą z sf::Shape. */
    std::map<std::string,TransformableShape*> updateCustomMap; /**< Mapa przechowuje obiekty, które można aktualizować. Są to zaimplementowane od nowa klasy. */
};

double EvalDet(Point2D,Point2D,Point2D);
bool EvalCollision(Line2D,Line2D);

#endif
