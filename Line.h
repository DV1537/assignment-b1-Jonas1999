#include "Shape.h"
#include "Point.h"
#ifndef LINE_H
#define LINE_H

class Line: public Shape{
    public:
        Line();
        ~Line();
        Line(Point* dots, int n);
        Line(Point d1, Point d2);
        std::string getType();
        double area();
        bool isConvex();
        double circumreference();
        Point position();
    
    private:
        Point* d;
        int nums;
};
#endif