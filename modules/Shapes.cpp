#include "Shapes.h"

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

bool EvalCollision(Line2D l1, Line2D l2){
    double s1 = EvalDet(l1.p1,l2.p1,l2.p2);
    double s2 = EvalDet(l1.p2,l2.p1,l2.p2);
    double s3 = EvalDet(l2.p1,l1.p1,l1.p2);
    double s4 = EvalDet(l2.p2,l1.p1,l1.p2);
    //std::cout << s1 << "|" << s2<< "|" << s3<< "|" << s4 << std::endl;

    if(s1<0 && s2>0 && s3>0 && s4<0)
        return true;
    else if(s1>0 && s2<0 && s3<0 && s4>0)
        return true;
    else
        return false;
}

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

/*
void PrimitiveRenderer::addPoint(Point2D point){
    addRect(sf::Vector2f(1,1),sf::Vector2f(point.x,point.y));
}
*/
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

void PrimitiveRenderer::addPoint(Point *p){
    customShapes.push_back(p);
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

void PrimitiveRenderer::addCustomPolygon(Polygon *poly){
    customShapes.push_back(poly);
}

void PrimitiveRenderer::addSprite(BitmapObject *spr){
    sprites.push_back(spr);
}

Point::Point(Point2D point){
    p = point;
    draw();
}

void Point::draw(){
    addPixel(Point2D(1,1),p);
}

void Point::move(Point2D vec){
    p.x += vec.x;
    p.y += vec.y;
    shape.clear();
    draw();
}

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

void Point::scale(float scale){
    //
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

void Line2D::move(Point2D vec){
    p1.x += vec.x;
    p1.y += vec.y;
    p2.x += vec.x;
    p2.y += vec.y;

    shape.clear();
    draw();
}

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

BrokenLine::BrokenLine(std::vector<Point2D> p,bool open){
    points = p;
    isOpen = open;
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

Polygon::Polygon(std::vector<Point2D> p){
    intersecting = false;
    points = p;
    draw();
}

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
            tmp->p1 = Point2D(points[i].x,points[i].y);
            tmp->p2 = Point2D(points[j].x,points[j].y);
            tmp->draw(shape);
            }
    }
}

Player::Player(){
    max_speed = 300;
    acc = 10;
    speed.x=0;speed.y=0;
    p.setSize(sf::Vector2f(50,50));
}

Player::Player(Point2D origin){
    speed.x=0;speed.y=0;
    max_speed = 300;
    acc = 10;
    position = origin;
    p.setOrigin(position.x,position.y);
    c.sprite.setOrigin(position.x,position.y);
    p.setSize(sf::Vector2f(50,50));
}

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

   c.animate();

   std::cout << sx << " | " << sy << std::endl;
   std::cout << dt << std::endl;

   c.sprite.move(sx,sy);
   p.move(sx,sy);

   speed.x *= 0.95;
   speed.y *= 0.95;

}
