/******************************
Name : KHEW XAVIER ETHAN
Id : 1181202757
Section : TC02
Title : Transportation (air,land,sea)
*****************************/

#include <iostream>
#include <fstream>

using namespace std;

//base class
class Transport{

    protected:
        string name, phone_num, location;
        int route, qty_ticket, price, total;

    public:
        //default constructor
        Transport(): price(0.0){ }

        //enter user info
        void enter_info(){
            cout<<endl<<"Enter your name\t: ";  cin.ignore();   getline(cin, name);
            cout<<"Enter your phone number\t: ";  getline(cin, phone_num);
        }

        //return name input from user
        string getName(){
            return name;
        }

        //return phone number input from user
        string getNum(){
            return phone_num;
        }

        //input users name into file to output to other parts of program
        void file_in(){

            ofstream in_file;

            if(in_file.fail()){     //if file unable to open
                cout<<"File cannot be found"<<endl;     exit(0);
            } else{
                enter_info();   //function that get user name and phone number

                name = getName();

                in_file.open("my-name.txt");    //to save users name
                in_file<<name;
                in_num();
            }
        }

        //file input for user phone number
        void in_num(){

            ofstream in_num;

            if(in_num.fail()){  //if file unable to open
                cout<<"File cannot be found"<<endl;     exit(0);
            } else{
                phone_num = getNum();

                in_num.open("my-phone-number.txt");     //to save users phone number
                in_num<<phone_num;
            }
        }

    virtual void display_price() = 0; 
    virtual void user_info() = 0;
    //reason to use pure virtual function is because i don't want to return anything default with the virtual function
};

class Air:public Transport{

    private:

    public:
        //default constructor
        Air() {}

        //this method to call function from base class then used to call in stand-alone function
        void user_info(){
            enter_info();
        }

        void display_price(){

            //routing msg display
            cout<<endl<<endl;
            cout<<"You can pick from the following destinations"<<endl;
            cout<<"1. KLIA2-Alor Setar Airport (RM 130)"<<endl;
            cout<<"2. KLIA2-Senai Airport (RM 135)"<<endl;
            cout<<"3. Penang Airport-KLIA2 (RM 150)"<<endl<<endl;
            cout<<"Enter your desired destinations: ";
                cin>>route;
            cout<<endl;
            
            //display back based on user input
            cout<<"You have selected option "<<route<<endl;

            //output, based on customer input from menu
            switch(route){
                case 1:
                    cout<<"Destination: KLIA2-Alor Setar Airport"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 130;
                break;

                case 2:
                    cout<<"Destination: KLIA2-Senai Airport"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 135;
                break;

                case 3:
                    cout<<"Destination: Penang Airport-KLIA2"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 150;
                break;

                default:
                    cout<<"Sorry, invalid entry"<<endl<<"Kindly try again.";
                    display_price();
                break;
            }

            total = qty_ticket * price;
            
            ofstream total_in;

            if(total_in.fail()){    //if file unable to open
                    cout<<"File cannot be found"<<endl;     exit(0);
            } else{
                total_in.open("my-total.txt");  //to save total need to pay

                total_in<<total;
            }

            ofstream location_in;

            if(location_in.fail()){     //if file unable to open
                cout<<"File cannot be found: Air Location file"<<endl;  exit(0);
            }
            else{
                location_in.open("my-location.txt");    //to save name of destination user selected

                //used to route destination name into file
                switch(route){

                    case 1:
                        location_in<<"KLIA2-Alor Setar Airport";
                    break;
                        
                    case 2:
                        location_in<<"KLIA2-Senai Airport";
                    break;

                    case 3:
                        location_in<<"Penang Airport-KLIA2";
                    break;
                }
            }
        }
};

class Land:public Transport{

    private:

    public:
        //default constructor
        Land(){ }

        //this method to call function from base class then used to call in stand-alone function
        void user_info(){
            enter_info();
        }

        void display_price(){

            //routing msg display
            cout<<endl<<endl;
            cout<<"You can pick from the following destinations"<<endl;
            cout<<"1. KLIA-Genting (RM 30)"<<endl;
            cout<<"2. KL-Johor (RM 35)"<<endl;
            cout<<"3. Penang-KL (RM 50)"<<endl<<endl;
            cout<<"Enter your desired destinations: ";
                cin>>route;
            cout<<endl;

            cout<<"You have selected option "<<route<<endl;

            //output, based on customer input from menu
            switch(route){
                case 1:
                    cout<<"Destination: KL-Genting"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 30;
                break;
                    
                case 2:
                    cout<<"Destination: KL-Johor"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 35;
                break;

                case 3:
                    cout<<"Destination: Penang-KL"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 50;
                break;

                default:
                    cout<<"Sorry, invalid entry"<<endl<<"Kindly try again.";
                    display_price();
                break;
            }

            total = qty_ticket * price;
            
            ofstream total_in;

            if(total_in.fail()){    //if file unable to open
                cout<<"File cannot be found"<<endl;     exit(0);
            } else{
                total_in.open("my-total.txt");  //to save total need to pay

                total_in<<total;
            }

            ofstream location_in;

            if(location_in.fail()){     //if file unable to open
                cout<<"File cannot be found: Land Location file"<<endl;  exit(0);
            }
            else{
                location_in.open("my-location.txt");    //if file unable to open

                //used to route destination name into file
                switch(route){
                    case 1:
                        location_in<<"KLIA-Genting";
                    break;
                        
                    case 2:
                        location_in<<"KL-Johor";
                    break;

                    case 3:
                        location_in<<"Penang-KL";
                    break;
                }
            }
        }
};

class Sea:public Transport{

    private:

    public:
        //default constructor
        Sea(){ }

        //this method to call function from base class then used to call in stand-alone function
        void user_info(){
            enter_info();
        }

        void display_price(){

            //routing msg display
            cout<<endl<<endl;
            cout<<"You can pick from the following destinations"<<endl;
            cout<<"1. Penang Mainland Port-Penang Island Port (RM 60)"<<endl;
            cout<<"2. Port Klang-Melaka Port (RM 45)"<<endl;
            cout<<"3. Johor Port-Singapore Port (RM 30)"<<endl<<endl;
            cout<<"Enter your desired destinations: ";
                cin>>route;
            cout<<endl;

            //display back based on user input
            cout<<"You have selected option "<<route<<endl;

            //output, based on customer input from menu
            switch(route){
                case 1:
                    cout<<"Destination: Penang Mainland Port-Penang Island Port"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 60;
                break;
                    
                case 2:
                    cout<<"Destination: Port Klang-Melaka Port"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 45;
                break;

                case 3:
                    cout<<"Destination: Johor Port-Singapore Port"<<endl<<endl;
                    cout<<"Kindly enter quantity of ticket(s): ";   cin>>qty_ticket;
                    price = 30;
                break;

                default:
                    cout<<"Sorry, invalid entry"<<endl<<"Kindly try again.";
                    display_price();
                break;
            }

            total = qty_ticket * price;
            
            ofstream total_in;

            if(total_in.fail()){    //if file unable to open
                    cout<<"File cannot be found"<<endl;     exit(0);
            } else{
                    total_in.open("my-total.txt");  //to save total need to pay

                    total_in<<total;
            }

            ofstream location_in;

            if(location_in.fail()){     //if file unable to open
                cout<<"File cannot be found: Land Location file"<<endl;  exit(0);
            } else{
                location_in.open("my-location.txt");    //if file unable to open

                //used to route destination name into file
                switch(route){
                    case 1:
                        location_in<<"Penang Mainland Port-Penang Island Port";
                    break;
                        
                    case 2:
                        location_in<<"Port Klang-Melaka Port";
                    break;

                    case 3:
                        location_in<<"Johor Port-Singapore Port";
                    break;
                }
            }
        }
};

void receipt(){

    string name, phone_num, location, price, total;

    //ifstreams for files
    ifstream name_file, number_file, total_file, location_file;

    //open files
    name_file.open("my-name.txt");
    number_file.open("my-phone-number.txt");
    total_file.open("my-total.txt");
    location_file.open("my-location.txt");

    system("PAUSE");

    cout<<endl<<endl;
    cout<<"----------------------"<<endl;
    cout<<"\tRECEIPT"<<endl;
    cout<<"----------------------"<<endl;

        if(name_file.fail() || number_file.fail() || location_file.fail() || total_file.fail()){    //if files unable to open
            cout<<"File not found: name file";  exit(0);
        } else{
            
           while(getline(name_file, name)){
                cout<<"Name\t\t\t: "<<name<<endl;
            }

            while(getline(number_file, phone_num)){
                cout<<"Phone Number\t\t: "<<phone_num<<endl;
            }

            while(getline(location_file, location)){
                cout<<"Destination\t\t: "<<location<<endl;
            }

            while(getline(total_file, total)){
                cout<<"Total amount to pay\t: RM "<<total<<endl;
            }
        }
}

void pick_transport(){

    int trans_type;

    Air airr;
    Land landd;
    Sea seaa;

    cout<<"1. Air Transportation"<<endl;
    cout<<"2. Land Transportation"<<endl;
    cout<<"3. Sea Transportation"<<endl<<endl;
    cout<<"Enter your desired transport type: ";
        cin>>trans_type;

        if(trans_type==1){
            //pure virtual function to push user to have price displayed
            Air *air = &airr;
            air->display_price();

            //to call function that fill bring in user input
            Transport *aira = &airr;
            aira->file_in();

        } else if(trans_type==2){
            //pure virtual function to push user to have price displayed
            Land *land = &landd;
            land->display_price();

            //to call function that fill bring in user input
            Transport *landa = &landd;
            landa->file_in();

        } else if(trans_type==3){
            //pure virtual function to push user to have price displayed
            Sea *sea = &seaa;
            sea->display_price();

            //to call function that fill bring in user input
            Transport *seaaa = &seaa;
            seaaa->file_in();

        } else{
            cout<<endl<<"Invalid type, kindly try again"<<endl<<endl;
            pick_transport();
        }
}

int main(){
    //opening msg 
    cout<<"Welcome to Jacko Transportation Agency"<<endl;
    cout<<"---------------------------------------"<<endl<<endl;
    cout<<"Kindly pick your type of transportation"<<endl;

    //run function that will pick up the input from cust for type of transport
    pick_transport();
    
    //run function that will product receipt for user
    receipt();
}