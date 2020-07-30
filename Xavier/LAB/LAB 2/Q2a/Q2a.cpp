#include <iostream>
using namespace std;

double calcu();
double get(double& , double& , double&);


int main(){

    double a, b, c, ans;

    ans = calcu();

    //display
    cout<<"The discriminant is "<< ans<< endl;
    
    return 0;

}


//b^2 4ac function
double calcu(){

    double ans, a, b, c;

    //cout<<a<<b<<c<<endl;
    get(a, b, c);

    
    return b*b - 4*a*c;

}


//get input function
double get(double& a, double& b, double& c){

    cout<<"Enter a, b and c: ";
    cin>>a >>b >>c;
    
    return a, b, c;

}