#pragma once
#include <iostream>
#include <cmath>

struct Vector2D{ // ez a struktura egyszerusiti a koordinatak tarolasat
    double x,y;
};

class Shape {
    std::string title; //az egyes alakzatok nevei, ami alapjan megkulonboztetjuk oket
    std::string color; //minden alakzatnak van szine
public:
    Shape(std::string title,std::string color) : title(title), color(color) {} //konstruktor
    virtual Shape* clone() const = 0; //clone fgv.: visszaadja egy objektum klonjat. A deep copy miatt van rá szükség
    std::string getTitle() const { return title; } //Title getter
    std::string getColor() const { return color; } //Color getter
    virtual void save(std::ostream& os) const = 0; //save fgv: save fgv ment szoveges streambe
    virtual void load(std::istream& is) = 0; //load fgv: tolt be szoveges streambol
    virtual void translate(Vector2D T) = 0; //translate fgv: eltolja az egyes alakzatokat T vektorral
    virtual void rotate(double angle, Vector2D R) = 0; //rotate fgv: elforgatja az egyes alakzatokat angle szoggel, R pont korul
    virtual void exportToSVG(std::ostream& os) const =0; //svg fajlba exportalja az alakzatokat.
    inline virtual ~Shape()=default; //Destruktor: azert egyenlo default, mert jo az alapertelmezett destruktor 
                                     //csak virtualis kell hogy legyen
};