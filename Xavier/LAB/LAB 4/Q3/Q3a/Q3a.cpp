#include <iostream>

using namespace std;

class Increment{

    char name[30], rating;
    float Sc_Point;

    public:
        char* set_name(){

            cout<<"Enter Name\t:";
                cin.get(name, 30);

                return name;
            
        }

        float set_Sc_Point(){
            
            cout<<"Score Point\t:";
                cin>>Sc_Point;

                return Sc_Point;
        }

        float set_rating(){

            if(Sc_Point > 3 && Sc_Point < 4){
                rating = 'A';
            }else if(Sc_Point > 2 && Sc_Point < 2.99){
                rating = 'B';
            }else{
                rating = 'F';
            }

            return rating;
        }
};

int main(){

    //call class
    Increment M;

    //declare
    string name;
    float point;
    char rating;

    cout<<"==================================="<<endl<<"\tAGENT INFORMATION"<<endl<<"==================================="<<endl;

    name = M.set_name();
    point = M.set_Sc_Point();
    rating = M.set_rating();

    cout<<"==================================="<<endl<<"\tINCREMENT SLIP"<<endl<<"==================================="<<endl;

    cout<<"Name\t\t: "<<name<<endl;
    cout<<"Point Awarded\t: "<<point<<endl;
    cout<<"Rating\t\t: "<<rating<<endl;

}