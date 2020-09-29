/*
Using the class definition of BasicShape, Circle and Rectangle from Q1, 

1. Make void calcArea() in BasicShape a virtual function and
2. Complete the code in main() to produce the following output.


Sample Run 
-----------

1. Circle [c] or Rectangle [any key]? c

Please enter the x coordinate of the circle's centre: 0
Please enter the y coordinate of the circle's centre: 0
Please enter the radius of the circle: 1


2. Circle [c] or Rectangle [any key]? f

Please enter the length of the rectangle: 2
Please enter the width of the rectangle: 4


3. Circle [c] or Rectangle [any key]? c

Please enter the x coordinate of the circle's centre: 2
Please enter the y coordinate of the circle's centre: 2
Please enter the radius of the circle: 1


4. Circle [c] or Rectangle [any key]? r

Please enter the length of the rectangle: 2
Please enter the width of the rectangle: 5


5. Circle [c] or Rectangle [any key]? r

Please enter the length of the rectangle: 2
Please enter the width of the rectangle: 6


Areas of shapes displayed in reverse order.
The area of shape 5 is 12
The area of shape 4 is 10
The area of shape 3 is 3.14159
The area of shape 2 is 8
The area of shape 1 is 3.14159

*/

#include <iostream>
using namespace std;

// Insert the class definition of BasicShape, Circle and Rectangle from Q1
...

int main()
{
   long x, y, length, width;
   double rad;
   const int NUMBER_OF_OBJECTS = 5;
   char choice;
   
   BasicShape* shapes[ NUMBER_OF_OBJECTS ];

   for( int i = 0; i < NUMBER_OF_OBJECTS; ++i )
   {
      cout << i + 1 << ". Circle [c] or Rectangle [any key]? ";
      cin >> choice;
      cout << endl;

      if( choice == 'c' )
      {
         cout << "Please enter the x coordinate of the circle's centre: ";
         cin >> x;
         cout << "Please enter the y coordinate of the circle's centre: ";
         cin >> y;
         cout << "Please enter the radius of the circle: ";
         cin >> rad;
         ....
      }
      else
      {
         cout << "Please enter the length of the rectangle: ";
         cin >> length;
         cout << "Please enter the width of the rectangle: ";
         cin >> width;
         ...
      }
      cout << endl << endl;
   }

   cout << "Areas of shapes displayed in reverse order.";    
   cout << endl;
   
   ....

   return 0;
}

