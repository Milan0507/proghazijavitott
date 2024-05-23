#pragma once
#include "shape.h"

class Rectangle : public Shape
{
    Vector2D a,b,c,d;
public:
    Rectangle(std::string color,Vector2D a, Vector2D b, Vector2D c,Vector2D d):
        Shape("rectangle",color), a(a),b(b), c(c), d(d) {}
    Shape* clone() const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;
    void translate(Vector2D T) override;
    void rotate(double angle, Vector2D R) override;  
    void exportToSVG(std::ostream& os) const override;
};