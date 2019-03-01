#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"
#include <cmath>

double Shape::distance(Shape& distcal){//distcal is short for distance calculation
    double dist = pow(position().getX() - distcal.position().getX(),2) + pow(position().getY() - distcal.position().getY(),2);
    dist = sqrt(dist);
    return dist;
}