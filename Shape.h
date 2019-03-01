#include <string>
#include <iostream>
#include "Point.h"
#ifndef SHAPE_H
#define SHAPE_H

class Shape{
    public:
    virtual std::string getType() = 0;//returns a string denoting type of a shape (point, line, polygon ..)
    virtual double area() = 0;//returns area of the object, or -1 if the shape is concave, intersecting, or does not have an area
    virtual double circumreference() = 0;//returns circumreference of the object, default is 0
    virtual Point position() = 0;//returns center coordinates of the object
    virtual bool isConvex() = 0;//returns true if shape is convex, default is 0
    double distance(Shape& distcal);//returns distance to the center of another shape
};

#endif