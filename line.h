#pragma once
#include "shape.h"

class Line : public Shape
{
    double stroke_width; //a vonalnak vastagsaga van
    Vector2D a,b;        //es ket koordinataja (kezdo es vegpont)
public:
    Line(std::string stroke_color, double stroke_width, Vector2D a, Vector2D b) 
        : Shape("line",stroke_color), stroke_width(stroke_width), a(a),b(b) {} //konstruktor
    Shape* clone() const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;
    void translate(Vector2D T) override;
    void rotate(double angle, Vector2D R) override;
    void exportToSVG(std::ostream& os) const override;
};