#include<iostream>
#include<iomanip>
using namespace std;
int main()
{  int j, i;
   int ray [3]= { 21,4, 12};
   int ray2 [3] = { 8,45, 12 };


    cout<<"Row 1: ";
    for(int i=0; i<3; i++){
       cout<<ray[i]<<setw(3);
       
    }
    
   cout<<endl;
   cout<<"Row 2: ";
   for(int j=0; j<3; j++){
      cout<<ray2[j]<<setw(4);
   }

   return 0;
}
