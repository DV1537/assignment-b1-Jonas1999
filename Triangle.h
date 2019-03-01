#include "Shape.h"
#include "Point.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape
{
    public: 
    Triangle();
    ~Triangle();
    Triangle(Point* dots, int n);
    Triangle(Point d1, Point d2, Point d3);
    std::string getType();
    double area();
    double circumreference();
    bool isConvex();
    Point position();

    private:
    Point* d;
    int nums;
};
#endif