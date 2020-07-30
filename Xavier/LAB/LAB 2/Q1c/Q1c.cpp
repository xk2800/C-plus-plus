#include<iostream>
#include <cmath>
using namespace std;

double kineticEnergy(double &k1, double &k2);

int main(){

    double mass, second, ke;

    //ask info
    cout<<"Enter an object's mass and velocity as required...."<<endl<<"\nMass in kilograms:";
        cin>>mass;
    cout<<"Velocity in meters per second: ";
        cin>>second;


    //cal
    ke = kineticEnergy(mass, second);

    //output
    cout<<endl<<"The kinetic energy of this object is :"<<ke<<" joules";

}

double kineticEnergy(double &k1, double &k2){

    double ke, mass, second;

    mass = k1;
    second=k2;
    ke=(mass*(pow(second, 2)))/2;

    return ke;

}