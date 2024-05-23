#pragma once
#include "shape.h"

class Triangle : public Shape
{
    Vector2D a,b,c;
public:
    Triangle(std::string color, Vector2D a, Vector2D b,Vector2D c) : Shape("triangle",color),a(a),b(b),c(c)  {}
    Shape* clone() const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;
    void translate(Vector2D T) override;
    void rotate(double angle, Vector2D R) override;  
    void exportToSVG(std::ostream& os) const override;
};