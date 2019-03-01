#include <iostream>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Polygon.h"

Polygon::Polygon(){
    nums = 0;
}
Polygon::~Polygon(){
    delete[] d;
}
Polygon::Polygon(Point* dots, int n){
    d = dots;
    nums = n;
}
std::string Polygon::getType(){
    return "Polygon";
}
double Polygon::area(){
    int n = nums;
    double dotsTotalValue = 0;
    
    if((isConvex()) || n > 2){//inspiration from the shoelace formula
        for (int c = 0; c < n; c++) {
		    int dotAfter = 0, dotBefore = 0;//the dot value before and after the current dot
		    if (c == 0) {//the dot is first in the list
		    	dotAfter = nums - 1;
		    	dotBefore = 1;
		    } 
            else if (c == n - 1) {//the dot is in the end of the list
		    	dotAfter = c - 1;
		    	dotBefore = 0;
		    }
            else {// the dot is between first and last place in the list
		    	dotAfter = c - 1;
		    	dotBefore = c + 1;
		    }
		    double dotValue = d[c].getX() * (d[dotBefore].getY() - d[dotAfter].getY());

		    dotsTotalValue += dotValue;
        }
        dotsTotalValue = fabs(dotsTotalValue) / 2;
        return dotsTotalValue;
    }
    else{
        return -1;
    }

}

bool Polygon::isConvex(){//inspired from stackoverflow
    int s = nums - 2;
    double *cd = new double[s];
    double cDot[4] = {0};

    for (int c = 0; c < s; c++)
    {
        cDot[0] = d[c + 1].getX() - d[c].getX();
        cDot[1] = d[c + 1].getY() - d[c].getY();
        cDot[2] = d[c + 2].getX() - d[c + 1].getX();
        cDot[3] = d[c + 2].getY() - d[c + 1].getY();
        cd[c] = cDot[0] * cDot[3] - cDot[1] * cDot[2];
    }

    bool positive = false;
    bool negative = false;

    for (int c = 0; c < s; c++)
    {
        if (cd[c] > 0){
            positive = true;
        }else{
            negative = true;
        }
    }
    
    delete[] cd;
    cd = nullptr;

    if (positive && negative){
        return false;
    }else{
        return true;
    }
}

double Polygon::circumreference(){
	double lineTot = 0;//lineTot as in total line length
	
    if(nums < 3){
        lineTot = -1;
    }
    else{
        for(int z = 0; z < nums; z++){
        double dot1X = d[z].getX();
        double dot1Y = d[z].getY();
        double dot2X = 0;
        double dot2Y = 0;

        if(z == nums - 1){
            dot2X = d[0].getX();
            dot2Y = d[0].getY();
       }
       else{
            dot2X = d[z+1].getX();
            dot2Y = d[z+1].getY();
        }

		lineTot += sqrt(pow(dot1X-dot2X,2) + pow(dot1Y-dot2Y,2));
	}

    lineTot = round(lineTot * 1000); 
    lineTot = lineTot / 1000;

    }
	return lineTot;
}

Point Polygon::position(){
    Point pos = Point(0,0);

    if(isConvex() == true){
        double sumXCords = 0, sumYCords = 0;
        for (int c = 0; c < nums; c++) {
	        sumXCords += d[c].getX();
            sumYCords += d[c].getY();
	    }
        pos = Point(sumXCords / nums, sumYCords / nums);
    }
    else{
        int iBounds[4];
        for(int z = 0; z < nums; z++){
            if (d[z].getX() > d[iBounds[0]].getX()){
                iBounds[0] = z;
            }
            if (d[z].getX() < d[iBounds[1]].getX()){
                iBounds[1] = z;
            }
            if (d[z].getY() > d[iBounds[2]].getY()){
                iBounds[2] = z;
            }
            if (d[z].getY() < d[iBounds[3]].getY()){
                iBounds[3] = z;
            }
        }

        pos = Point(fabs(d[iBounds[0]].getX() + d[iBounds[1]].getX()) / 2, fabs(d[iBounds[2]].getY() + d[iBounds[3]].getY()) / 2);
    }


    return pos;
}

void Polygon::operator=(Polygon &basicShape2){
    nums = basicShape2.nums;
    d = new Point[basicShape2.nums];
    for (int e = 0; e < basicShape2.nums; e++)
        d[e] = basicShape2.d[e];
}//WIP
Polygon& operator+(Polygon shape1, Point shape2){
    Polygon* s = new Polygon();
    s->nums = shape1.nums + 1;

    Point* temp = new Point[s->nums];
    for(int i = 0; i < shape1.nums; i++){
        temp[i] = shape1.d[i];
    }
    temp[shape1.nums] = shape2;

    s->d = temp;
    return *s;
}
Polygon& operator+(Polygon shape1, Polygon shape2){
    Polygon* s = new Polygon();
    s->nums = shape1.nums + shape2.nums;

    Point* temp = new Point[s->nums];
    int tempC = 0, tempC2 = 0;

    while(tempC < shape1.nums){//deep copying the first shape to temp
        temp[tempC] = shape1.d[tempC];
        tempC++;
    }
    while(tempC2 < shape2.nums){//add the second shape were the first shape ended
        temp[tempC + tempC2] = shape2.d[tempC2];
        tempC2++;
    }

    s->d = temp;
    return *s;
}
std::ostream &operator<<(std::ostream &outStream, Polygon &s){

    for (int nums  = 0; nums < s.nums; nums++){
    outStream << "{" << s.d[nums].getX() << "," << s.d[nums].getY() << "} ";
    }
    outStream << '\n';
    return outStream;
}