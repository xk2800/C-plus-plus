#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int x=0, in, even=0, odd=0, total=0;

    do{
        cout << "Enter a number: ";
            cin >> in;
        cout << endl;

        if (in == 0){
            even += 1;
        } 
        else{
            odd += 1;
        }

        total += in;
        x++;
    }while(x < 10);

    //output
    cout << "There are " << even << " even numbers and " << odd << " odd numbers." << endl;
    cout << "The total of all the 10 numbers are " << total << ".";
}
