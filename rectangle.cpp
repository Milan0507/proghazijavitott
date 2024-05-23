#include "rectangle.h"

Shape* Rectangle::clone() const 
{
    return new Rectangle(*this);
}

void Rectangle::save(std::ostream& os) const
{
    os << getTitle() << " " << getColor() << " " << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << " " << d.x << " " << d.y << std::endl;
}

void Rectangle::load(std::istream& is)
{
    is >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >>d.y;
}

void Rectangle::translate(Vector2D T)
{
    a.x+=T.x;
    a.y+=T.y;
    b.x+=T.x;
    b.y+=T.y;
    c.x+=T.x;
    c.y+=T.y;
    d.x+=T.x;
    d.y+=T.y;
}

void Rectangle::rotate(double angle, Vector2D R)
{
    Vector2D A=a,B=b,C=c,D=d;
    a.x=((R.x-A.x)*cos(angle)-sin(angle)*(R.y-A.y))+R.x;
    a.y=((R.x-A.x)*sin(angle)+cos(angle)*(R.y-A.y))+R.y;
    b.x=((R.x-B.x)*cos(angle)-sin(angle)*(R.y-B.y))+R.x;
    b.y=((R.x-B.x)*sin(angle)+cos(angle)*(R.y-B.y))+R.y;
    c.x=((R.x-C.x)*cos(angle)-sin(angle)*(R.y-C.y))+R.x;
    c.y=((R.x-C.x)*sin(angle)+cos(angle)*(R.y-C.y))+R.y;
    d.x=((R.x-D.x)*cos(angle)-sin(angle)*(R.y-D.y))+R.x;
    d.y=((R.x-D.x)*sin(angle)+cos(angle)*(R.y-D.y))+R.y;
}

void Rectangle::exportToSVG(std::ostream& os) const
{
    os<<"<polygon points=\""<<a.x<<","<<a.y<<" "<<b.x<<","<<b.y<<" "<<c.x<<","<<c.y<<" "<<d.x<<","<<d.y<<"\" fill=\""<<getColor()<<"\"/>"<<std::endl;
}
