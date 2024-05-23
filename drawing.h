#pragma once
#include <vector>
#include "shape.h"

class Drawing //Drawing class a teljes rajz tarolasara
{
    std::vector<Shape*> shapes; //shapes vektorban tarolja az egyes shape ekre mutato Shape* pointereket.
    double canvas_width;    //itt taroljuk az alapvaszon mereteit
    double canvas_height;
public:
    Drawing(double canvas_width,double canvas_height): canvas_width(canvas_width),canvas_height(canvas_height) {} //konstruktor
    Drawing(const Drawing& drawing); //masolo konstruktor, hogy a teljes rajz masolhato es ertekul adhato legyen
    void addShape(Shape* shape); //ez a fuggveny ad hozza a rajzhoz alakzatokat
    void save(std::ostream& os) const; //ez a fugveny menti a rajzot szoveges streambe
    void load(std::istream& is); //ez a fuggveny tolti be a rajzot szoveges streambol
    void translate(Vector2D T); //ez a fuggveny tolja el a teljes rajzot
    void rotate(double angle,Vector2D R); //ez a fuggveny forgatja el a teljes rajzot
    void exportToSVG(const std::string& filename) const; //ez a fuggveny exportalja az egesz rajzot svg fajlba
    ~Drawing(); //destruktor
};