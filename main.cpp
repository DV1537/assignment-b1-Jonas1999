#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

#include "Shape.h"
#include "Triangle.h"
#include "Line.h"
#include "Polygon.h"

using namespace std;

int main(int argc, const char * argv[])
{
    double a = 0;//used for saving numbers
    int l = 0;
    std::ifstream myReadFile;

    Polygon* arrayOfPolygons = new Polygon[2];

    myReadFile.open(argv[1]);//re-opens the file to save the numbers in the dynamic array
    std::string line;

    while (std::getline(myReadFile, line))
    {
        int values = 0;
        int dotCount = 0;
        std::istringstream iss (line);
        while (iss >> a)
        {
            values++;
        }
        dotCount = values / 2;

        Point* dots = new Point[dotCount];

        double val = 0;
        int p = 0;
        int c = 0;
        std::istringstream reader (line);
        Point tmp;
        while(reader >> val){
            if(c % 2){
                tmp.setY(val);
                dots[p] = tmp;
                p++;
            }else{
                tmp = Point(val,0);
            }
            c++;
        }
        Polygon basic(dots, dotCount);
        arrayOfPolygons[l] = basic;
        l++;
    }


    myReadFile.close();


    Polygon poly1 = arrayOfPolygons[0];//First polygon

    Polygon poly2 = arrayOfPolygons[1];//Second polygon

    Polygon finalPoly = Polygon();//add them together
    finalPoly = poly1 + poly2;
    std::cout << "Area: " << finalPoly.area() << std::endl;
    std::cout << "Shape type: " << finalPoly.getType() << std::endl;
    std::cout << "Area size: " << finalPoly.area() << std::endl;
    std::cout << "Circumference: " << finalPoly.circumreference() << std::endl;
    std::cout << "Center point: " << finalPoly.position().getX() << ", " << finalPoly.position().getY() << std::endl;
    if (finalPoly.isConvex() == true){
        std::cout << "The shape is convex" << std::endl;
    }
    else if (finalPoly.isConvex() == false){
        std::cout << "The shape isn't convex" << std::endl;
    }


    return 0;
}