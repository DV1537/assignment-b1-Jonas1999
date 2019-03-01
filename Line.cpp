#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Line.h"

Line::Line(){
    nums = 0;
}

Line::~Line(){
    delete[] d;
}

Line::Line(Point* dots, int n){
    if(n >= 2){
        d = new Point[2];
        nums = 2;
    }else{
        nums = 2;
    }
}
Line::Line(Point d1, Point d2){
    d = new Point[2];
    nums = 2;
}

std::string Line::getType(){
    return "Line";
}

double Line::area(){
	return  -1;
}

bool Line::isConvex(){
    return true;
}

double Line::circumreference(){//more simple circumference than the one in polygon and triangle
	return sqrt(pow(d[0].getX() - d[1].getX(),2) + pow(d[0].getY() - d[1].getY(),2))*2;
}

Point Line::position(){
    double sumXCords = 0, sumYCords = 0;
    for (int z = 0; z < nums; z++) {
		sumXCords += d[z].getX();
        sumYCords += d[z].getY();
	}

return Point(sumXCords / nums, sumYCords / nums);
}