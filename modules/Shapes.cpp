#include "Shapes.h"

/**
 * Oblicza determinant macierzy 3x3.
 */
double EvalDet(Point2D p1,Point2D p2,Point2D p3){
    /*
     * {p1.x,p2.x,p3.x}
     * {p1.y,p2.y,p3.y}
     * {1   ,1   ,1   }
     */
    double det = 0.0;
    det = p1.x*((p2.y*1)-(p3.y-1))-p2.x*((p1.y*1)-(p3.y-1))+p3.x*((p1.y*1)-(p2.y-1));
    return det;
}

/**
 * Oblicza czy wsytępuje kolizja między 2 bokami.
 */
bool EvalCollision(Line2D l1, Line2D l2){
    double s1 = EvalDet(l1.p1,l2.p1,l2.p2);
    double s2 = EvalDet(l1.p2,l2.p1,l2.p2);
    double s3 = EvalDet(l2.p1,l1.p1,l1.p2);
    double s4 = EvalDet(l2.p2,l1.p1,l1.p2);

    if(s1<0 && s2>0 && s3>0 && s4<0)
        return true;
    else if(s1>0 && s2<0 && s3<0 && s4>0)
        return true;
    else
        return false;
}

/**
 * Dodaje kwadrat do wektora rysowania.
 * @param vec Wielkośc kwadratu.
 * @param origin Pozycja kwadratu.
 */
void PrimitiveRenderer::addRect(sf::Vector2f vec,sf::Vector2f origin){
    sf::RectangleShape *rect = new sf::RectangleShape(vec);
    rect->setPosition(origin.x,origin.y);
    shapes.push_back(rect);
}

/**
 * Dodaje koło do wektora rysowania.
 * @param r Promień koła.
 * @param origin Pozycja koła.
 */
void PrimitiveRenderer::addCirc(double r,sf::Vector2f origin){
    sf::CircleShape *circ = new sf::CircleShape(r);
    circ->setPosition(origin.x,origin.y);
    shapes.push_back(circ);
}

/**
 * Dodaje regularny wielokąt do wektora rysowania.
 * @param r Promień.
 * @param sides Ilość boków.
 * @param origin Pozycja wielokątu.
 */
 void PrimitiveRenderer::addRegPoly(double r, int sides,sf::Vector2f origin){
    sf::CircleShape *circ = new sf::CircleShape(r,sides);
    circ->setPosition(origin.x,origin.y);
    shapes.push_back(circ);
}
/**
 * Dodaje kwadrat do wektora rysowania.
 * @param vec Wielkośc kwadratu.
 * @param origin Pozycja kwadratu.
 * @param name Nazwa obiektu. Unikatowa.
 */
void PrimitiveRenderer::addRect(sf::Vector2f vec,sf::Vector2f origin,std::string name){
    sf::RectangleShape *rect = new sf::RectangleShape(vec);
    rect->setPosition(origin.x,origin.y);
    makeUpdateable(name,rect);
    shapes.push_back(rect);
}

/**
 * Dodaje koło do wektora rysowania.
 * @param r Promień koła.
 * @param origin Pozycja koła.
 * @param name Nazwa obiektu. Unikatowa.
 */
void PrimitiveRenderer::addCirc(double r,sf::Vector2f origin,std::string name){
    sf::CircleShape *circ = new sf::CircleShape(r);
    circ->setPosition(origin.x,origin.y);
    makeUpdateable(name,circ);
    shapes.push_back(circ);
}


/**
 * Dodaje regularny wielokąt do wektora rysowania.
 * @param r Promień.
 * @param sides Ilość boków.
 * @param origin Pozycja wielokątu.
 * @param name Nazwa wielokątu. Unikatowa.
 */
 void PrimitiveRenderer::addRegPoly(double r, int sides,sf::Vector2f origin,std::string name){
    sf::CircleShape *circ = new sf::CircleShape(r,sides);
    circ->setPosition(origin.x,origin.y);
    makeUpdateable(name,circ);
    shapes.push_back(circ);
}

/**
 * Domyślny konstuktor tworzący punkt o współrzędnych 0,0.
 */
Point2D::Point2D(){
    x=0;
    y=0;
}

/**
 * Konsturktor tworzy punkt o współrżednych x,y.
 * @param x współrzędna x.
 * @param y współrzędna y.
 */
Point2D::Point2D(int px,int py){
    x = px;
    y = py;
}

int Point2D::getX(){
    return x;
}

int Point2D::getY(){
    return y;
}

void Point2D::setX(int px){
    x = px;
}

void Point2D::setY(int py){
    y = py;
}

/**
 * Rysuje jeden pixel w miejsce podanych współrzędnych.
 */
void CustomShape::addPixel(Point2D vec,Point2D origin){
    sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(vec.x,vec.y));
    rect->setFillColor(col);
    rect->setOutlineColor(col);
    rect->setPosition(origin.x,origin.y);
    shape.push_back(rect);

}

/**
 * Rysuje jeden pixel w miejsce podanych współrzędnych do podanego wektora.
 */
void CustomShape::addPixel(Point2D vec,Point2D origin,std::vector<sf::Shape*>&s){
    sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(vec.x,vec.y));
    rect->setPosition(origin.x,origin.y);
    rect->setFillColor(col);
    rect->setOutlineColor(col);
    s.push_back(rect);

}

/**
 * Dodaje punkt to wektora rysowania.
 * @param p Punkt do dodania.
 */
void PrimitiveRenderer::addPoint(Point *p){
    customShapes.push_back(p);
}

/**
 * Dodaje linię do wektora rysowania.
 * @param line Linia do dodania.
 */
void PrimitiveRenderer::addLine(Line2D *line){
    customShapes.push_back(line);
}
/**
 * Dodaje łamaną do wektora rysowania.
 * @param line Łamana do dodania.
 */
void PrimitiveRenderer::addBrokenLine(BrokenLine *line){
    customShapes.push_back(line);
}
/**
 * Dodaje koło do wektora rysowania.
 * @param circle koło do dodania.
 */
void PrimitiveRenderer::addCustomCircle(Circle *circle){
    customShapes.push_back(circle);
}
/**
 * Dodaje elipse do wektora rysowania.
 * @param elipse Elipsa do dodania.
 */
void PrimitiveRenderer::addCustomElipse(Elipse *elipse){
    customShapes.push_back(elipse);
}
/**
 * Dodaje wielokąt do wektora rysowania.
 * @param poly Wielokąt do dodania.
 */
void PrimitiveRenderer::addCustomPolygon(Polygon *poly){
    customShapes.push_back(poly);
}
/**
 * Dodaje obiekt sprite do wektora rysowania.
 * @param spr Sprite do dodania.
 */
void PrimitiveRenderer::addSprite(BitmapObject *spr){
    sprites.push_back(spr);
}
/**
 * Umożliwia aktualizowanie podanego obiektu.
 * @param name Nazwa obiektu.
 * @param shape Kształt do aktualizowania.
 */
void PrimitiveRenderer::makeUpdateable(std::string name,TransformableShape *shape){
    updateCustomMap.insert(std::pair<std::string,TransformableShape*>(name,shape));
}

/**
 * Umożliwia aktualizowanie podanego obiektu.
 * @param name Nazwa obiektu.
 * @param shape Kształt do aktualizowania.
 */
void PrimitiveRenderer::makeUpdateable(std::string name,sf::Shape *shape){
    updateMap.insert(std::pair<std::string,sf::Shape*>(name,shape));
}

/**
 * Konstruktor inicjializujący punkt o podanych koordynatach.
 * @param point Koordynaty stworzonego punktu.
 */
Point::Point(Point2D point){
    p = point;
    draw();
}

/**
 * Konstruktor inicjializujący punkt o podanych koordynatach i kolorze.
 * @param point Koordynaty stworzonego punktu.
 * @param color Kolor punktu.
 */
Point::Point(Point2D point,sf::Color color){
    p = point;
    col = color;
    draw();
}
/**
 * Funkcja rysująca punkt.
 */
void Point::draw(){
    addPixel(Point2D(1,1),p);
}
/**
 * Funkcja przenosi punkt o wektor.
 * @param vec Wektor przesunięcia.
 */
void Point::move(Point2D vec){
    p.x += vec.x;
    p.y += vec.y;
    shape.clear();
    draw();
}

/**
 * Funckja obracająca punkt względem punktu 0,0.
 * @param angle Kąt przesunięcia.
 */
void Point::rotate(float angle){
    int nx,ny;
    nx = (p.x * cos(angle)) - (p.y * sin(angle));
    std::cout << nx << std::endl;
    ny = (p.x * sin(angle)) + (p.y * cos(angle));
    std::cout << ny << std::endl;
    p.x = nx;
    p.y = ny;

    shape.clear();
    draw();
}

/**
 * Funckja obracająca punkt względem punktu.
 * @param angle Kąt przesunięcia.
 * @param point Punkt względem którego wykonane jest obracanie.
 */
void Point::rotate(float angle,Point2D point){
    int nx,ny;
    nx = cos(angle)*(p.x-point.x)-sin(angle)*(p.y-point.y)+point.x;
    ny = sin(angle)*(p.x-point.x)+cos(angle)*(p.y-point.y)+point.y;
    p.x = nx;
    p.y = ny;

    shape.clear();
    draw();
}

/**
 * Funkcja skalująca punkt.
 * @param scale Skala skalowania.
 */
void Point::scale(float scale){
    shape.back()->setScale(scale,scale);
}

/**
 * Domyślny konstruktor inicjializujący linię.
 */
Line2D::Line2D(){
    p1.x=0;
    p1.y=0;

    p2.x=0;
    p2.y=0;
}

/**
 * Domyślny konstruktor inicjializujący linię.
 * @param a Początkowy punkt lini.
 * @param b Ostatni punkt lini.
 */
Line2D::Line2D(Point2D a,Point2D b){
    p1 = a;
    p2 = b;
    draw();
}

/**
 * Domyślny konstruktor inicjializujący linię.
 * @param a Początkowy punkt lini.
 * @param b Ostatni punkt lini.
 * @param color Kolor lini.
 */
Line2D::Line2D(Point2D a,Point2D b,sf::Color color){
    p1 = a;
    p2 = b;
    col = color;
    draw();
}

/**
 * Funkcja rysująca linię.
 */
void Line2D::draw(){
    float dx,dy,length,xLine,yLine,x,y;
    int sx,sy;
    dx = abs(p2.x-p1.x);
    dy = abs(p2.y-p1.y);
    sy = p2.y-p1.y>=0?1:-1;
    sx = p2.x-p1.x>=0?1:-1;
    if(dx >= dy)
        length = dx;
    else
        length = dy;

    xLine = dx/length;
    yLine = dy/length;
    x = p1.x+0.5*(xLine);
    y = p1.y+0.5*(yLine);
    for(int i=0;i<length;i++){
        addPixel(Point2D(1,1),Point2D(x,y));
        x += xLine*sx;
        y += yLine*sy;
    }
}

/**
 * Funkcja rysująca linię do podanego wektora.
 * @param shape Wektor, do którego rysowana jest linia.
 */
void Line2D::draw(std::vector<sf::Shape*> &shape){
    float dx,dy,length,xLine,yLine,x,y;
    int sx,sy;
    dx = abs(p2.x-p1.x);
    dy = abs(p2.y-p1.y);
    sy = p2.y-p1.y>=0?1:-1;
    sx = p2.x-p1.x>=0?1:-1;
    if(dx >= dy)
        length = dx;
    else
        length = dy;

    xLine = dx/length;
    yLine = dy/length;
    x = p1.x+0.5*(xLine);
    y = p1.y+0.5*(yLine);
    for(int i=0;i<length;i++){
        addPixel(Point2D(1,1),Point2D(x,y),shape);
        x += xLine*sx;
        y += yLine*sy;
    }
}
/**
 * Funkcja przesuwa linię o podany wektor.
 * @param vec Wektor przesunięcia.
 */
void Line2D::move(Point2D vec){
    p1.x += vec.x;
    p1.y += vec.y;
    p2.x += vec.x;
    p2.y += vec.y;

    shape.clear();
    draw();
}

/**
 * Funkcja obraca linię względem punktu 0,0.
 * @param angle Kąt obrócenia.
 */
void Line2D::rotate(float angle){
    Point2D np1,np2;
    np1.x = (p1.x * cos(angle)) - (p1.y * sin(angle));
    std::cout << np1.x << std::endl;
    np1.y = (p1.x * sin(angle)) + (p1.y * cos(angle));
    std::cout << np1.y << std::endl;

    np2.x = (p2.x * cos(angle)) - (p2.y * sin(angle));
    std::cout << np2.x << std::endl;
    np2.y = (p2.x * sin(angle)) + (p2.y * cos(angle));
    std::cout << np2.y << std::endl;

    p1 = np1;
    p2 = np2;

    shape.clear();
    draw();
}
/**
 * Funkcja obraca linię.
 * @param angle Kąt obrócenia.
 * @param point Punkt obrócenia.
 */
void Line2D::rotate(float angle,Point2D point){
    Point2D np1,np2;
    np1.x = cos(angle)*(p1.x-point.x)-sin(angle)*(p1.y-point.y)+point.x;
    np1.y = sin(angle)*(p1.x-point.x)+cos(angle)*(p1.y-point.y)+point.y;

    np2.x = cos(angle)*(p2.x-point.x)-sin(angle)*(p2.y-point.y)+point.x;
    np2.y = sin(angle)*(p2.x-point.x)+cos(angle)*(p2.y-point.y)+point.y;
        
    p1 = np1;
    p2 = np2;

    shape.clear();
    draw();
}

/**
 * Funkcja skaluje linię.
 * @param scale Skala Skalowania.
 */
void Line2D::scale(float scale){
    Point2D np1,np2;
    np1.x = p1.x*scale;
    np1.y = p1.y*scale;

    np2.x = p2.x*scale;
    np2.y = p2.y*scale;

    p1 = np1;
    p2 = np2;

    shape.clear();
    draw();
}

/**
 * Konstruktor tworzący łamaną z podanego wektora punktów.
 * @param p Wektor punktów łamanej.
 * @param open Określa czy łamana jest zamknięta czy otwarta. true - otwarta, false - zamknięta.
 */
BrokenLine::BrokenLine(std::vector<Point2D> p,bool open){
    points = p;
    isOpen = open;
    draw();
}

/**
 * Konstruktor tworzący łamaną z podanego wektora punktów.
 * @param p Wektor punktów łamanej.
 * @param open Określa czy łamana jest zamknięta czy otwarta. true - otwarta, false - zamknięta.
 * @param color Kolor łamanej.
 */
BrokenLine::BrokenLine(std::vector<Point2D> p,bool open,sf::Color color){
    points = p;
    isOpen = open;
    col = color;
    draw();
}
void BrokenLine::draw(){
    if(!isOpen)
        points.push_back(points[0]);
    for(int i=0;i<points.size();i++){
        int j = i+1;
        if(j<points.size()){
            //addLine(Point2D(points[i].x,points[i].y),Point2D(points[j].x,points[j].y));
            Line2D *tmp = new Line2D();
            tmp->col = col;
            tmp->p1 = Point2D(points[i].x,points[i].y);
            tmp->p2 = Point2D(points[j].x,points[j].y);
            tmp->draw(shape);
            }
    }
}
/**
 * Funkcja przesuwa łamana o podany wektor.
 * @param p Wektor przesunięcia.
 */
void BrokenLine::move(Point2D p){
    for(int i=0;i<points.size();i++){
        points[i].x += p.x;
        points[i].y += p.y;
    }
    shape.clear();
    draw();
}

/**
 * Funckja obraca łamaną.
 * @angle Kąt obrócenia w radianach.
 * @point Punkt obracania.
 */
void BrokenLine::rotate(float angle,Point2D point){
    for(int i=0;i<points.size();i++){
        points[i].x = cos(angle)*(points[i].x-point.x)-sin(angle)*(points[i].y-point.y)+point.x;
        points[i].y = sin(angle)*(points[i].x-point.x)+cos(angle)*(points[i].y-point.y)+point.y;
    }
    shape.clear();
    draw();
}
/**
 * Funckja obraca łamaną przez punkt 0,0.
 * @angle Kąt obrócenia w radianach.
 */
void BrokenLine::rotate(float angle){
    for(int i=0;i<points.size();i++){
        points[i].x = (points[i].x * cos(angle)) - (points[i].y * sin(angle));
        points[i].y = (points[i].x * sin(angle)) + (points[i].y * cos(angle));
    }
    shape.clear();
    draw();
}

/**
 * Funkcja skaluje łamaną.
 * @scale Skala skalowania.
 */
void BrokenLine::scale(float scale){
     for(int i=0;i<points.size();i++){
        points[i].x = points[i].x*scale;
        points[i].y = points[i].y*scale;
    }
     shape.clear();
     draw();

}


/**
 * Konsturktor inicjalizuje koło o środku w punkcie p, oraz promieniu rad.
 * @param p Środek koła.
 * @param rad Promień koła.
 */
Circle::Circle(Point2D p, int rad){
    origin = p;
    r = rad;
    draw();
}

/**
 * Konsturktor inicjalizuje koło o środku w punkcie p, oraz promieniu rad.
 * @param p Środek koła.
 * @param rad Promień koła.
 * @param color Kolor koła.
 */
Circle::Circle(Point2D p, int rad,sf::Color color){
    origin = p;
    r = rad;
    col = color;
    draw();
}

/**
 * Rysuje koło.
 */
void Circle::draw(){
    float a,step;
    int x,y;

    step = 1.0/r;

    for(a=0;a<M_PI/2;a+=step){
       // x = origin.x + r*cos(a) + 0.5;
       // y = origin.y + r*sin(a) + 0.5;
        x = r*cos(a) + 0.5;
        y = r*sin(a) + 0.5;
        addPixel(Point2D(1,1),Point2D(origin.x+x,origin.y+y));
        addPixel(Point2D(1,1),Point2D(origin.x+y,origin.y-x));
        addPixel(Point2D(1,1),Point2D(origin.x-x,origin.y-y));
        addPixel(Point2D(1,1),Point2D(origin.x-y,origin.y+x));
    }
}

/**
 * Wypełnia koło.
 */
void Circle::fill(Point2D p){
    bool filled = false;
    for(int i = 0;i<shape.size();i++){
        sf::Vector2f v = shape[i]->getPosition();
        if(v.x == p.x && v.y == p.y){
            filled = true;
            break;
        }
    }
    if(!filled){
        addPixel(Point2D(1,1),p);
        Circle::fill(Point2D(p.x+1,p.y));
        Circle::fill(Point2D(p.x-1,p.y));
        Circle::fill(Point2D(p.x,p.y+1));
        Circle::fill(Point2D(p.x,p.y-1));
    }
}

/**
 * Konstuktor inicjializujący elipsę w punkcie o, o promieniach rX i rY.
 * @param o Środek elipsy
 * @param rX Promień elipsy.
 * @param rY Drugi promeiń elipsy.
 */
Elipse::Elipse(Point2D o, int rX, int rY){
    origin = o;
    rx = rX;
    ry = rY;
    draw();
}

/**
 * Konstuktor inicjializujący elipsę w punkcie o, o promieniach rX i rY.
 * @param o Środek elipsy
 * @param rX Promień elipsy.
 * @param rY Drugi promeiń elipsy.
 * @param color Kolor elipsy.
 */
Elipse::Elipse(Point2D o, int rX, int rY,sf::Color color){
    origin = o;
    rx = rX;
    ry = rY;
    col = color;
    draw();
}

/**
 * Funkcja rysująca elipsę.
 */
void Elipse::draw(){
    float a,step;
    int x,y;

    step = 1.0/rx;

    for(a=0;a<M_PI/2;a+=step){
       // x = origin.x + r*cos(a) + 0.5;
       // y = origin.y + r*sin(a) + 0.5;
        x = ry*cos(a) + 0.5;
        y = rx*sin(a) + 0.5;
        addPixel(Point2D(1,1),Point2D(origin.x+y,origin.y+x));
        addPixel(Point2D(1,1),Point2D(origin.x+y,origin.y-x));
        addPixel(Point2D(1,1),Point2D(origin.x-y,origin.y-x));
        addPixel(Point2D(1,1),Point2D(origin.x-y,origin.y+x));
    }
}

/**
 * Wypełnia elipse.
 */
void Elipse::fill(Point2D p){
    bool filled = false;
    for(int i = 0;i<shape.size();i++){
        sf::Vector2f v = shape[i]->getPosition();
        if(v.x == p.x && v.y == p.y){
            filled = true;
            break;
        }
    }
    if(!filled){
        addPixel(Point2D(1,1),p);
        Elipse::fill(Point2D(p.x+1,p.y));
        Elipse::fill(Point2D(p.x-1,p.y));
        Elipse::fill(Point2D(p.x,p.y+1));
        Elipse::fill(Point2D(p.x,p.y-1));
    }
}

/**
 * Konstruktor inicjializujący wielokąt z podanych punktów.
 * @param p Wierzchołki wielokątu.
 */
Polygon::Polygon(std::vector<Point2D> p){
    intersecting = false;
    points = p;
    draw();
}

/**
 * Konstruktor inicjializujący wielokąt z podanych punktów.
 * @param p Wierzchołki wielokątu.
 * @param color Kolor wielokątu.
 */
Polygon::Polygon(std::vector<Point2D> p,sf::Color color){
    intersecting = false;
    points = p;
    col = color;
    draw();
}
 /**
  * Konstruktor inicjializująca pusty wielokąt.
  */
Polygon::Polygon(){
    intersecting = false;
}

void Polygon::draw(){
    if(intersecting)
        return;
    //Check if it intersects
    points.push_back(points[0]);
    int size = points.size();
    int p1,p2,p3,p4;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j-i==1 || j-i==-1||j==i)
                    continue;
            p1=i;p2=i+1;
            p3=j;p4=j+1;
            if(p2<size && p4<size){
                intersecting = EvalCollision(Line2D(points[p1],points[p2]),Line2D(points[p3],points[p4]));
                //std::cout << intersecting << std::endl;
                if(intersecting)
                    return;
            }
        }
    }
    //draw
    for(int i=0;i<points.size();i++){
int j = i+1;
        if(j<points.size()){
            Line2D *tmp = new Line2D();
            tmp->col = col;
            tmp->p1 = Point2D(points[i].x,points[i].y);
            tmp->p2 = Point2D(points[j].x,points[j].y);
            tmp->draw(shape);
            }
    }
}
/**
 * Inicjializuje gracza z domyślnymi ustawieniami.
 */
Player::Player(){
    max_speed = 300;
    acc = 10;
    speed.x=0;speed.y=0;
    p.setSize(sf::Vector2f(50,50));
}

/**
 * Inicjializuje gracza w podanej pozycji.
 * @param origin Pozycja startowa gracza.
 */
Player::Player(Point2D origin){
    speed.x=0;speed.y=0;
    max_speed = 300;
    acc = 10;
    position = origin;
    p.setOrigin(position.x,position.y);
    c.sprite.setOrigin(position.x,position.y);
    p.setSize(sf::Vector2f(50,50));
}

/**
 * Funkcja akutalizująca gracza. Zajmuje się również ruchem postaci.
 */
void Player::Update(double dt){
   if(speed.x > max_speed)
       speed.x = max_speed;
   if(speed.x < max_speed*-1)
       speed.x = max_speed*-1;
   if(speed.y > max_speed)
       speed.y = max_speed;
   if(speed.y < max_speed*-1)
       speed.y = max_speed*-1;

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       speed.y -= acc;
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       speed.y += acc;
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       speed.x -= acc;
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       speed.x += acc;


   double sx, sy;
   sx = speed.x*dt;
   sy = speed.y*dt;

   c.animate(dt);

   //std::cout << sx << ":sx |sy: " << sy << std::endl;

   c.sprite.move(sx,sy);
   p.move(sx,sy);

   speed.x *= 0.95;
   speed.y *= 0.95;

}
