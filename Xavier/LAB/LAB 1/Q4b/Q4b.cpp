#include <iostream>
using namespace std; 
int multi(int, int);
int main ()  
{   int number1, number2, ans; 
	
    cout<<"Enter 1st number: ";
        cin>> number1;
    cout<<endl;
    cout<<"Enter 2nd number: ";
        cin>> number2;

    ans = multi(number1, number2);

	cout << "\n "<<number1<<" * "
       <<number1<<" is " << ans << ".";
	return 0;
}

int multi(int number1, int number2){
    
    int ans;

    ans = number1 * number2;

    return(ans);
}
