#include "triangle.h"

Shape* Triangle::clone() const 
{
    return new Triangle(*this);
}

void Triangle::save(std::ostream& os) const
{
    os << getTitle() << " " << getColor() << " " << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << std::endl;
}

void Triangle::load(std::istream& is)
{
    is >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
}

void Triangle::translate(Vector2D T)
{
    a.x+=T.x;
    a.y+=T.y;
    b.x+=T.x;
    b.y+=T.y;
    c.x+=T.x;
    c.y+=T.y;
}

void Triangle::rotate(double angle, Vector2D R)
{
    Vector2D A=a,B=b,C=c;
    a.x=((R.x-A.x)*cos(angle)-sin(angle)*(R.y-A.y))+R.x;
    a.y=((R.x-A.x)*sin(angle)+cos(angle)*(R.y-A.y))+R.y;
    b.x=((R.x-B.x)*cos(angle)-sin(angle)*(R.y-B.y))+R.x;
    b.y=((R.x-B.x)*sin(angle)+cos(angle)*(R.y-B.y))+R.y;
    c.x=((R.x-C.x)*cos(angle)-sin(angle)*(R.y-C.y))+R.x;
    c.y=((R.x-C.x)*sin(angle)+cos(angle)*(R.y-C.y))+R.y;
}

void Triangle::exportToSVG(std::ostream& os) const
{
    os<<"<polygon points=\""<<a.x<<","<<a.y<<" "<<b.x<<","<<b.y<<" "<<c.x<<","<<c.y<<"\" fill=\""<<getColor()<<"\"/>"<<std::endl;
}
