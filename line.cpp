#include "line.h"

Shape* Line::clone() const //ugyan ugy klonozzuk a line-t is
{
    return new Line(*this);
}

void Line::save(std::ostream& os) const //ugyan ugy mentjuk streamre, csak a line nak a parametereivel 
{
    os<<getTitle()<<" "<<getColor()<<" "<<stroke_width<<" "<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<std::endl;
}

void Line::load(std::istream& is) //beolvasas
{
    is>>a.x>>a.y>>b.x>>b.y;
}

void Line::translate(Vector2D T)//eltolas
{
    a.x+=T.x;
    a.y+=T.y;
    b.x+=T.x;
    b.y+=T.y;
}

void Line::rotate(double angle, Vector2D R)//forgatas
{
    Vector2D A=a,B=b;
    a.x=((R.x-A.x)*cos(angle)-sin(angle)*(R.y-A.y))+R.x;
    a.y=((R.x-A.x)*sin(angle)+cos(angle)*(R.y-A.y))+R.y;
    b.x=((R.x-B.x)*cos(angle)-sin(angle)*(R.y-B.y))+R.x;
    b.y=((R.x-B.x)*sin(angle)+cos(angle)*(R.y-B.y))+R.y;
}

void Line::exportToSVG(std::ostream& os) const //svg exportalas
{
    os<<"<line x1=\""<<a.x<<"\" y1=\""<<a.y<<"\" x2=\""<<b.x<<"\" y2=\""<<b.y<<"\" stroke=\""<<getColor()<<"\" stroke-width=\""<<stroke_width<<"\" />"<<std::endl;
}
