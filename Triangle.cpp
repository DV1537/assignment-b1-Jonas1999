#include "Triangle.h"
#include "Point.h"
#include <cmath>

Triangle::Triangle(){
    nums = 0;
}

Triangle::~Triangle(){
    delete[] d;
}

Triangle::Triangle(Point* d, int n){
    if(n >= 3){
        Point* triDots = new Point[3];
        for (int b = 0; b < 3; b++){
            triDots[b] = d[b];
        }
        d = triDots;
        nums = 3;
    }else{
        nums = 0;
    }
}
Triangle::Triangle(Point d1, Point d2, Point d3){
    d = new Point[3];
    d[0] = d1;
    d[1] = d2;
    d[2] = d3;
    nums = 3;
}

std::string Triangle::getType(){
    return "Triangle";
}

double Triangle::area(){
    double area = -1;
    Point* myPoints = d;
    int n = nums;
    double dotsTotalValue = 0;
    
    if(n > 2){//inspiration from the shoelace formula
        for (int c = 0; c < n; c++) {
		    int dotAfter = 0, dotBefore = 0;//the dot value before and after the current dot
		    if (c == 0) {//the dot is first in the list
		    	dotAfter = c - 1;
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

double Triangle::circumreference(){
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

Point Triangle::position(){
    double sumXCords = 0, sumYCords = 0;
    for (int z = 0; z < nums; z++) {
		sumXCords += d[z].getX();
        sumYCords += d[z].getY();
	}

return Point(sumXCords / nums, sumYCords / nums);
}

bool Triangle::isConvex(){//inspired from stackoverflow
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