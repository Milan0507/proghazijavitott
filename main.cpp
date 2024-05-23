#include "drawing.h"
#include "shape.h"
#include "circle.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include <fstream>
#define MEMTRACE_H
#include "memtrace.h"

int main()
{
    Drawing drawing(1000,1000);

    std::ifstream f("drawing.txt");
    drawing.load(f);
    f.close();
    drawing.exportToSVG("shapes.svg");
    Drawing drawing2(drawing);
    drawing2.exportToSVG("shapescopyd.svg");
    drawing.translate({100,0});
    drawing.exportToSVG("translated.svg");
    drawing2.rotate(M_PI_2,{500,500});
    drawing2.exportToSVG("rotated.svg");
    drawing.rotate(-M_PI_2,{500,400});
    drawing.exportToSVG("trans&rot.svg");
    std::ofstream fi("transformateddrawing.txt");
    drawing.save(fi);
    fi.close();


    return 0;
}