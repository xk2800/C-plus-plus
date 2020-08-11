#include <iostream>
#include <iomanip>

using namespace std;

struct Rental
{      char name[20];
       float rent; int month;      
};

float report(struct Rental[]);

int main(){

    double total;

    struct Rental R[3] = {{"Ali", 300, 4}, {"Johnson", 250, 1}, {"David", 790, 2}};
    
    total = report(R);

    cout<<"Total rental to be collected : $"<<total;

    return 0;

}

float report(struct Rental *R){

    double amtdue[3], total;

    //static part
    cout<<"----------------------------------------------------"<<endl
    <<"-\t\tAMOUNT DUE MORE THAN $1000.00-"<<endl
    <<"----------------------------------------------------"<<endl;


    for(int i=0; i<3; i++){

        amtdue[i]=R->rent * R->month;

            if(amtdue[i]>1000){

                total +=amtdue[i];

                //output
                cout<<"Tenant name   : "<<R->name<<endl;
                cout<<setprecision(2)<<fixed<<"Monthly rental : $"<<R->rent<<endl;
                cout<<"Unpaid months : "<<R->month<<endl;
                cout<<"Unpaid amount $"<<amtdue[i]<<endl<<endl;

            }else{
                total += 0;
            }

            R++;

    }

    return total;

}