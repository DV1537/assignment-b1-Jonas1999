#include "Shape.h"
#include "Point.h"
#ifndef POLYGON_H
#define POLYGON_H

class Polygon: public Shape{
    public:
        Polygon();
        ~Polygon();
        Polygon(Point* dots, int n);
        std::string getType();
        double area();
        double circumreference();
        bool isConvex();
        Point position();
        void operator=(Polygon &basicShape2);//for deep copying the object
        friend Polygon& operator+(Polygon shape1, Point shape2);//for adding a point to a shape
        friend Polygon& operator+(Polygon shape1, Polygon shape2);//for adding a shape to a shape
        friend std::ostream &operator<<(std::ostream &stream, Polygon &s);//prints list of shape vertices

    private:
    Point* d;
    int nums;
};

#endif