#include <iostream>
#include <iomanip>
using namespace std;

/*#define A 0
#define B 0
#define C 0*/

class TravelPackage
{  public:
    char package;
    int noAdult, noChild;                                   
    float adultPrice, childPrice, discount, totalPrice;

};

int main(){

    TravelPackage pack;

    do{

        cout<<"Select travel package <A,B,C>: ";
            cin>>pack.package;


        //cout<<pack.package;

        if(pack.package !='A' && pack.package != 'B' && pack.package !='C'){
            cout<<"Invalid Selection. "<<endl;
        }
        
    }while((pack.package != 'A' && pack.package !='B' && pack.package !='C' ));
    //}while((pack.package != 0));


        cout<<endl<<"Enter no of adult : ";
            cin>>pack.noAdult;

        cout<<endl<<"Enter no of children : ";
            cin>>pack.noChild;

        switch(pack.package){

            case 'A' : 
                pack.adultPrice = 1000;
                pack.childPrice = 500;
                break;
            
            case 'B' :
                pack.adultPrice = 800;
                pack.childPrice = 600;
                break;

            case 'C' :
                pack.adultPrice = 500;
                pack.childPrice = 300;
                break;
        }

        pack.totalPrice = (pack.adultPrice * pack.noAdult) + (pack.childPrice * pack.noChild);

        if(pack.totalPrice>3000){
            pack.discount = pack.totalPrice * 0.8;
        } else{
            pack.discount = pack.totalPrice;
        }

        cout<<setprecision(2)<<fixed<<endl<<"Total price : RM"<<pack.discount;





}