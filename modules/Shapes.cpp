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




/* temp comment
void PrimitiveRenderer::addLine(Point2D p1,Point2D p2){
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
        addRect(sf::Vector2f(1,1),sf::Vector2f((int)x,(int)y));
        x += xLine*sx;
        y += yLine*sy;
    }
}
*/


void PrimitiveRenderer::addPoint(Point2D point){
    addRect(sf::Vector2f(1,1),sf::Vector2f(point.x,point.y));
}
/* temp comment
void PrimitiveRenderer::addBrokenLine(std::vector<Point2D> points,bool isOpen){
    if(!isOpen)
        points.push_back(points[0]);
    for(int i=0;i<=points.size();i++){
        int j = i+1;
        if(j<points.size())
            addLine(Point2D(points[i].x,points[i].y),Point2D(points[j].x,points[j].y));
    }
}
*/
/*
void PrimitiveRenderer::addCustomCircle(Point2D origin,int r){
    float a,step;
    int x,y;

    step = 1.0/r;

    for(a=0;a<M_PI/2;a+=step){
       // x = origin.x + r*cos(a) + 0.5;
       // y = origin.y + r*sin(a) + 0.5;
        x = r*cos(a) + 0.5;
        y = r*sin(a) + 0.5;
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x+x,origin.y+y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x+y,origin.y-x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x-x,origin.y-y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x-y,origin.y+x));
    }
}
*/
/*
void PrimitiveRenderer::addCustomElipse(Point2D origin,int rx,int ry){
    float a,step;
    int x,y;

    step = 1.0/rx;

    for(a=0;a<M_PI/2;a+=step){
       // x = origin.x + r*cos(a) + 0.5;
       // y = origin.y + r*sin(a) + 0.5;
        x = ry*cos(a) + 0.5;
        y = rx*sin(a) + 0.5;
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x+y,origin.y+x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x+y,origin.y-x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x-y,origin.y-x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(origin.x-y,origin.y+x));
    }
}
*/

/*
void PrimitiveRenderer::addCustomCircle(Point2D o,int r){
    int x,y,r2;
    r2 = r*r;
    addRect(sf::Vector2f(1,1),sf::Vector2f(o.x,o.y+r));
    addRect(sf::Vector2f(1,1),sf::Vector2f(o.x,o.y-r));
    addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+r,o.y));
    addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-r,o.y));

    x=1;
    y=(int)(sqrt(r2-1)+0.5);
    while(x<y){
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+x,o.y+y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+x,o.y-y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-x,o.y+y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-x,o.y-y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+y,o.y+x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+y,o.y-x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-y,o.y+x));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-y,o.y-x));
        x+=1;
        y=(int)(sqrt(r2-x*x)+0.5);
    }
    
    if(x==y){
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+x,o.y+y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x+x,o.y-y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-x,o.y+y));
        addRect(sf::Vector2f(1,1),sf::Vector2f(o.x-x,o.y-y));
    }
}
*/

Point2D::Point2D(){
    x=0;
    y=0;
}

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

void CustomShape::addPixel(Point2D vec,Point2D origin){
    sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(vec.x,vec.y));
    rect->setPosition(origin.x,origin.y);
    shape.push_back(rect);

}


void CustomShape::addPixel(Point2D vec,Point2D origin,std::vector<sf::Shape*>&s){
    sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(vec.x,vec.y));
    rect->setPosition(origin.x,origin.y);
    s.push_back(rect);

}

void PrimitiveRenderer::addLine(Line2D *line){
    customShapes.push_back(line);
}

void PrimitiveRenderer::addBrokenLine(BrokenLine *line){
    customShapes.push_back(line);
}

void PrimitiveRenderer::addCustomCircle(Circle *circle){
    customShapes.push_back(circle);
}

void PrimitiveRenderer::addCustomElipse(Elipse *elipse){
    customShapes.push_back(elipse);
}

Line2D::Line2D(){
    p1.x=0;
    p1.y=0;

    p2.x=0;
    p2.y=0;
}

Line2D::Line2D(Point2D a,Point2D b){
    p1 = a;
    p2 = b;
    draw();
}


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

BrokenLine::BrokenLine(std::vector<Point2D> p,bool open){
    points = p;
    isOpen = open;
    draw();
}

void BrokenLine::draw(){
    if(!isOpen)
        points.push_back(points[0]);
    for(int i=0;i<=points.size();i++){
        int j = i+1;
        if(j<points.size()){
            //addLine(Point2D(points[i].x,points[i].y),Point2D(points[j].x,points[j].y));
            Line2D *tmp = new Line2D();
            tmp->p1 = Point2D(points[i].x,points[i].y);
            tmp->p2 = Point2D(points[j].x,points[j].y);
            tmp->draw(shape);
            }
    }
}

Circle::Circle(Point2D p, int rad){
    origin = p;
    r = rad;
    draw();
}

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

Elipse::Elipse(Point2D o, int rX, int rY){
    origin = o;
    rx = rX;
    ry = rY;
    draw();
}

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
