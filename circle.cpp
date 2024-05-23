#include "circle.h"

Shape* Circle::clone() const 
{
    return new Circle(*this); //a klonnak egy uj memoriacimmel ter vissza (ujat is foglal)
}

void Circle::save(std::ostream& os) const
{
    os << getTitle() << " " << getColor() << " " << a.x << " " << a.y << " " << r << std::endl; //az os szoveges streambe menti a kor parametereit. A szint es a nevet a shape class getter jevel eri el
}

void Circle::load(std::istream& is)
{
    is >> a.x >> a.y >> r;//az is szoveges streambol kimenti a kor parametereit.
}

void Circle::translate(Vector2D T) //eltolas fgv
{
    a.x+=T.x; //a kor kozeppontjanak x koordinatajahoz hozzaadja az eltolasvektor x koordinatajat
    a.y+=T.y; //a kor kozeppontjanak y koordinatajahoz hozzaadja az eltolasvektor y koordinatajat
}

void Circle::rotate(double angle, Vector2D R) //forgatas fgv
{
    a.x=((R.x-a.x)*cos(angle)-sin(angle)*(R.y-a.y))+R.x; // eloszor bazistrafo, majd forgatasmx szorzas, majd ujra bazistrafo
    a.y=((R.x-a.x)*sin(angle)+cos(angle)*(R.y-a.y))+R.y;
}

void Circle::exportToSVG(std::ostream& os) const //svg exportalas, a helyes formatumban
{
    os<<"<circle cx=\""<<a.x<<"\" cy=\""<<a.y<<"\" r=\""<<r<<"\" fill=\""<<getColor()<<"\" />"<<std::endl;
}
