#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    int a, b;
	int *p,*q;
	a = 20;
	p = &a;
	b = *p%2 + 40;
	q = p;
	cout<<"a  = "<<a<<endl;
	cout<<"b  = "<<b<<endl;
	cout<<"*p = "<<*p<<endl;
    cout<<"*q = "<<*q<<endl;
}