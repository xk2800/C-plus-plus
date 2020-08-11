#include <iostream>

#define size 8

using namespace std;

class Stationary_Inventory{

    private:
        string code;
        int warehouse[size];

    public:
        void display_reserve(){

            int c=1;

            for(int i=7; i>0; i--){

                cout<<"Warehouse "<<c<<": "<<warehouse[i]<<endl;
                c++;
            }
        }

        void set_data(int *ptr){

            cout<<"Enter Stationary Code: ";
                getline(cin, code);
            
            cout<<"-------------------------------"<<endl<<"\tThe Inventory Info"<<endl<<"-------------------------------"<<endl;
            cout<<"Stationery code: "<<code<<endl;

            for(int x=0; x<size; x++){
                warehouse[x]=*ptr++;
            }

        }

        void process(){

            int c=1;

            cout<<"--------------------------------------"<<endl<<"\tColourful Book Holder Stock"<<endl<<"--------------------------------------"<<endl;
            cout<<"Enter the stocks for 8 warehouses: "<<endl;

            for(int i=0; i<size; i++){
                
                cin>>warehouse[i];
            }

            fflush(stdin);

            cout<<"Enter Stationary Code: ";
                getline(cin, code);
            cout<<"-------------------------------"<<endl<<"\tThe Inventory Info"<<endl<<"-------------------------------"<<endl;
            cout<<"Stationery code : "<<code<<endl;

            for(int i=7; i>0; i--){

                cout<<"Warehouse "<<c<<": "<<warehouse[i]<<endl;

                c++;
            }

        }

};

int main(){

    Stationary_Inventory hold;

    int warehouse[size]={5, 10, 15, 22, 20, 25, 30, 35};

    cout<<"\tSMART Stationery Shop"<<endl<<"###################################"<<endl<<"\tItem Entry"<<endl<<"-----------------------------------"<<endl; 

    hold.set_data(warehouse);
    hold.display_reserve();
    hold.process();

}