#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;
double area(double radius); 
      //Returns the area of a circle with the specified radius.
int main( )
{   
    double radius, area_of_circle, volume_of_sphere;
    cout << "Enter a radius of a circle :";
    cin >> radius;

    area_of_circle = area(radius);
    cout << "Radius = " << radius << " inches\n"
            << "Area of circle = " << area_of_circle
            << " square inches\n";
    return 0;
}
// to complete

double area(double radius){

    double area_of_circle;

    area_of_circle = pow(radius, 2) * PI;
    return area_of_circle;
}