#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int in=0, total=0;

    while ((in < 99))
    {
        cout << "Enter a number : ";
            cin >> in;
        cout << endl;

        //count total
        total += in;
    }   
        total -= 99;
        cout << endl;
        cout << "The total is " << total;
    
}