#include "drawing.h"
#include "circle.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include <fstream>

Drawing::Drawing(const Drawing& drawing) //masolo konstruktor
{
    this->canvas_width=drawing.canvas_width; //beallitja a tagvaltozokat
    this->canvas_height=drawing.canvas_height;
    //Ezutan a masolt rajzhoz is hozzamentjuk az alakzatokat (deep copy!!!)
    for(const auto& shape: drawing.shapes) //lasd 110. sor
    {
        this->addShape(shape); 
    }
}

void Drawing::addShape(Shape* shape) // az addShape fuggvennyel tudunk hozzaadni alakzatokat a rajzhoz. 
{
    shapes.push_back(shape->clone()); // a push_back parancsal tudunk a vektorhoz elemet adni, es mivel deep copy-t csinalunk,
                                      // nem az alakzat cimet adjuk at, hanem klonozzuk azt.
}

void Drawing::save(std::ostream& os) const // afuggveny elmenti az egesz rajzot egy szoveges streambe.
{
    for (const auto& shape : shapes) {  //for loopban vegigmegyunk az egyes alakzatokon
        shape->save(os); //es az egyes alakzatokra meghivjuk a sajat save fgv. uket.
    }
}

void Drawing::load(std::istream& is)   //a fgv kiolvas egy rajzot egy szoveges streambol.
{
    while(!is.eof())    //az .eof() segitsegevel ellenorizzuk hogy van e meg olvasando adat
    {
        std::string title;  //ha van az elso lepes, hogy kiolvassuk egy egy valtozoba az alakzat nevet es szinet,
        is>>title;          // hisz ez ugyis van minden alakzatnak
        std::string color;
        is>>color;
        if(title=="circle")// utana megnezzuk, hogy melyik alakzattipus az alabbiakbol
        {
            
            Circle* circle=new Circle(color,{0,0},0); //ha megvan, foglalunk neki egy teruletet, default ertekekkel
            circle->load(is);//majd belementjuk a szoveges streamben irt ertekeket
            shapes.push_back(circle->clone());//a legvegen hozzaadjuk a klonjat a rajzhoz.
            delete circle;

        }
        if(title=="rectangle") //a tobbi orokolt osztalynal igy jarunk el
        {
            Rectangle* rectangle=new Rectangle(color, {0,0}, {0,0}, {0,0}, {0,0});
            rectangle->load(is);
            shapes.push_back(rectangle->clone());
            delete rectangle;
        }
        if(title=="line") 
        {
            double stroke_width; //a line-nal tudjuk, hogy a harmadik adat a vastagsaga, ezert azt is kimentjuk. 
            is>>stroke_width;
            Line* line=new Line(color,stroke_width,{0,0},{0,0});
            line->load(is);
            shapes.push_back(line->clone());
            delete line;
        }
        if(title=="triangle") 
        {
            Triangle* triangle=new Triangle(color, {0,0},{0,0},{0,0});
            triangle->load(is);
            shapes.push_back(triangle->clone());
            delete triangle;
        }
    }
}

void Drawing::translate(Vector2D T) //a fuggveny eltolja a rajzot T vektorral
{
    for(auto& shape:shapes)// vegigmegyunk a rajz alakzatain es
    {
        shape->translate({T.x,T.y}); //egyessevel eltoljuk oket a sajat eltolas fuggvenyukkel
    }
}

void Drawing::rotate(double angle,Vector2D R) //hasonloasn oldottam meg a forgatas fuggvenyt is
{
    for(auto& shape:shapes)
    {
        shape->rotate(angle,{R.x,R.y});
    }
}

void Drawing::exportToSVG(const std::string& filename) const //ez a fuggveny irja meg az svg fajlt, parameterkent kapja meg a nevet.
{
    std::ofstream file(filename);   
    if (file.is_open()) {
        file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\""<<canvas_width<<"\" height=\""<<canvas_height<<"\">" << std::endl; 
        // Ez az svg fajl fejlece ^
        for (const auto* shape : shapes) //egyesevvel az egyes alakzatokat beleirjuk a fajlba.
        {
            shape->exportToSVG(file);
        }
        file << "</svg>" << std::endl; // svg fajl vege
        file.close(); // close
    }
}

Drawing::~Drawing() // a destruktorban fontos hogy visszaadjuk a teruletet, amit az egyes shape-ek (a klonok) foglalnak.
{
    for(auto& shape:shapes)
    {
        delete shape;
    }
}

/*
    for(const auto& shape : drawing.shapes )
    Ez a ranged based loop, ezt talaltam a legegyszerubb megoldasnak arra, hogy menjunk vegig a shapes vektor Shape* elemein.
    Az auto& az egyes shape-ek tipusa, es az auto azert kell, mert a shape lehet circle, triangle, ...
    es azert auto&, mert igy nem csinalunk folosleges copyt, direkbe hozzaferunk az objektumhoz.
*/