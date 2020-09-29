/*

Complete the class definition of Circle and Rectangle so that the code
in main() produces the correct output as follows.


Sample Run 1
------------

Please enter the x coordinate of the circle's centre: 1
Please enter the y coordinate of the circle's centre: 1
Please enter the radius of the circle: 2
The area of the circle is 12.5664.

Please enter the length of the rectangle: 2
Please enter the width of the rectangle: 4
The area of the rectangle is 8.

Sample Run 2
------------

Please enter the x coordinate of the circle's centre: 1
Please enter the y coordinate of the circle's centre: 2
Please enter the radius of the circle: 3
The area of the circle is 28.2743.

Please enter the length of the rectangle: 4
Please enter the width of the rectangle: 5
The area of the rectangle is 20.

*/

#include <iostream>
using namespace std;

class BasicShape
{
   private:
      double area;

   public:
      double getArea() 
      {
         return area;
      }

      void calcArea()
      {
         cout << "Not possible to calculate the area of a basic shape" << endl;
      }

      void setArea( double a ) 
      {
         area = a;
      }
};

class Circle : public BasicShape
{
   private:
      long centreX;
      long centreY;
      double radius;
   public:
      Circle( long x, long y, double rad )
         : centreX( x ), centreY( y ), radius( rad )
      {
         ...
      }

      long getCentreX() 
      {
         return centreX;
      }

      long getCentreY() 
      {
         return centreY;
      }

      void calcArea()	
      {
         double temp = 3.14159 * radius * radius;
         ...
      }
};


class Rectangle : public BasicShape
{
private:
   long width;
   long length;

public:
   Rectangle(long w, long l)
      : width( w ), length( l )
   {
      ...
   }

   long getWidth() 
   {
      return width;
   }

   long getLength() 
   {
      return length;
   }

   void calcArea() 
   {
      double temp = length * width;
      ...
   }
};



int main()
{
   long x, y, length, width;
   double rad;

   // Demonstrate a Circle.
   cout << "Please enter the x coordinate of the circle's centre: ";
   cin >> x;
   cout << "Please enter the y coordinate of the circle's centre: ";
   cin >> y;
   cout << "Please enter the radius of the circle: ";
   cin >> rad;
   Circle c( x, y, rad );
   cout << "The area of the circle is " << c.getArea() << ".";

   // Demonstrate a Rectangle.
   cout << endl << endl << "Please enter the length of the rectangle: ";
   cin >> length;
   cout << "Please enter the width of the rectangle: ";
   cin >> width;
   Rectangle r(width, length);
   cout << "The area of the rectangle is " << r.getArea() << ".\n";

   return 0;
}

