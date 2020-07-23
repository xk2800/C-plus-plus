#include<iostream>
#include<iomanip>
using namespace std;
int main()
{  
   float day1, day2, total;
   cout<<"Enter the sales for day 1 :" ;
        cin>>day1;
   cout << "Enter the sales for day 2 :";
        cin >> day2;
   //prompt user to enter the sales for second day
   
   //calculate the total sales;
   total = day1 + day2;
   //display the sales figures with the total
   cout << "\nQTech Sdn. Bhd Sales figures for 2 days";
   cout<< setprecision(2) << fixed << "\nDay 1 :" << day1 <<endl;
   cout << setprecision(2) << fixed << "Day 2 :" << day2 <<endl;
   cout << "Total: " << total << endl;

   return 0;
}

