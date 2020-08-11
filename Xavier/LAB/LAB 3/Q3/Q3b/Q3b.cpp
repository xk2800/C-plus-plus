#include <iostream>

using namespace std;

class Purchase{

    private:
        //char name[30], code[5];
        string name, code;
        int qty;
        float price, total;


    public:
        void set_data(string name1, string code1, float qty1, float price1){
        //To set all the data to the appropriate variables.
            name = name1;
            code = code1;
            qty = qty1;
            price = price1;
        }

        void calculate(){
        //Calculate the total amount of payment to be made.
            total = price * qty;
        }

        void print(){
        //Display all the information on screen.
        
        //static output
        cout<<endl<<"========================"<<endl<<"\tRECEIPT"<<endl<<"========================"<<endl;

        cout<<"Name\t\t: "<<name<<endl;
        cout<<"Product Code\t: "<<code<<endl;
        cout<<"Quantity\t: "<<qty<<endl;
        cout<<"Product Price\t: RM "<<price<<endl;
        cout<<"Total payment\t: RM "<<total<<endl;

        }

};

int main (){

    Purchase p;

    //declare for main
    string name,code;
    char check;
    float qty, price;

    //check
    cout<<"You have another customer to purchase item? [Y/N]: ";
        cin>>check;

    while(check =='Y'){

    //static output
    cout<<"========================"<<endl<<"\tWELCOME"<<endl<<"========================"<<endl;

    fflush(stdin);

    //input and output start
    cout<<"Enter name\t: ";
        getline(cin, name);
    cout<<"Product code\t: ";
        getline(cin,code);
    cout<<"Enter quantity\t: ";
        cin>>qty;
    cout<<"Enter price\t: RM ";
        cin>>price;

    //input and output end

    p.set_data(name, code, qty, price);
    p.calculate();
    p.print();

    cout<<"You have another customer to purchase item? [Y/N]: ";
        cin>>check;
        
    }


}