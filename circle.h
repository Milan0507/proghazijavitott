#pragma once
#include "shape.h"

class Circle : public Shape //oroklodik a Shape ososztalybol
{
    Vector2D a; //a kor kozeppontjanak koordinatai
    double r; //kor sugara
public:
    Circle(std::string color,Vector2D a, double r) : Shape("circle",color), a(a), r(r) {} //konstruktor
    Shape* clone() const override; 
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;
    void translate(Vector2D T) override;
    void rotate(double angle, Vector2D R) override;
    void exportToSVG(std::ostream& os) const override;
};