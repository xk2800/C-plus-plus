#include <iostream>

using namespace std;

class Ticket{
    private:
        int no;
        float price;

    friend class Student;

    public:
        Ticket(){
            price = 10;
        }

        void setTickets(){

            cout<<"Please enter number of tickets to purchase: ";
                cin>>no;
        }
};

class Student{
    private:
        string id, name;
        char purchase;
        Ticket P;

    public:
        void setStudent(){

            cout<<"Enter ID\t: ";
                cin>>id;
            cout<<"Enter Name\t: ";
                cin>>name;
        }
        
        void ticket_entry(){

            cout<<"Do you want to purchase charity tickets? [Enter Y or N]: ";
                cin>>purchase;
                cin.ignore();

            if(purchase =='Y'){
        /**/        cout<<"test Y";

                P.setTickets();
                
            }else{
        /**/        cout<<"test N";
                cout<<"--------No tickets purchase--------";
            }
        }

        void display(){

            float total = P.price * P.no;

            cout<<"--------------------------------"<<endl<<"\tSTUDENT DETAILS"<<endl<<"--------------------------------"<<endl;
            cout<<"ID\t:"<<id<<endl;
            cout<<"Name\t:"<<name<<endl;

            cout<<"--------------------------------"<<endl<<"\tADDITIONAL DETAILS"<<endl<<"--------------------------------"<<endl;

            if(purchase=='Y'){
                cout<<"You've purchase "<<P.no<<" tickets"<<endl;
                cout<<"Total amount  : RM "<<total<<endl<<endl;
            }else{

                cout<<"You've not purchased any tickets"<<endl<<endl;
            }

        }

};

int main(){

            //Student P;

            //P.ticket_entry();

            Student arrey[3];

            for (int i=0; i<3; i++){
                arrey[i].setStudent();
                arrey[i].ticket_entry();
                arrey[i].display();
            }
}