#include <iostream>

using namespace std;


class Strawberry{

    string selection;
    double price;

    public:
        void dispStrawberrySelection(){

            cout<<"[1] Strawberry & Nutella Crepe\t\t Price:  RM10.00"<<endl;
            cout<<"[2] Strawberry & Chocolate Crepe\t Price:  RM12.00"<<endl;
            cout<<"[3] Strawberry Waffle with Custard\t Price:  RM13.40"<<endl;
            cout<<"[4] Strawberry Smoothie\t\t\t Price:  RM10.00"<<endl;
            cout<<"[5] Strawberry & Country Cream\t\t Price:  RM13.00"<<endl;
        }

        void purchase(){

            cout<<"Enter your choice based on the number"<<endl;
                cin>>this->selection;
            
            //price -> selection logic
            if(selection=="1"){
                price = 10;
                selection = "Strawberry & Nutella Crepe";

            }else if(selection=="2"){
                price = 12;
                selection = "Strawberry & Chocolate Crepe";

            }else if (selection=="3"){
                price = 13.40;
                selection = "Strawberry Waffle with Custard";

            }else if(selection=="4"){
                price = 10;
                selection = "Strawberry Smoothie";

            }else if(selection=="5"){
                price = 13;
                selection = "Strawberry & Country Cream";

            }else /*if non 1-5*/{
                price = 0;
                selection = "Not Available";

            }
        }

        double getPrice(){

            return price;
        }

        string getSelection(){

            return selection;
        }

};

class Customer{

    string StrawSelect, name;
    double payment;
    Strawberry st;

    public:
        void set_data(){

            cout<<"++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"\tTutti Fruitti: Strawberry"<<endl;
            cout<<"++++++++++++++++++++++++++++++++++"<<endl;

            cout<<"Your name\t:";
                cin>>name;
            
            getOrder();
        }

        void getOrder(){

            st.dispStrawberrySelection();
            st.purchase();

            payment = st.getPrice();
            StrawSelect = st.getSelection();
        }

        void dispDetails(){

            cout<<"...................................."<<endl;
            cout<<name<<", Your purchase details"<<endl;
            cout<<"...................................."<<endl;

            cout<<"Selection\t\t: "<<StrawSelect<<endl;
            cout<<"Payment to be made\t: RM"<<payment<<".00"<<endl;
        }

};

int main(){

    Customer cust;

    cust.set_data();
    cust.dispDetails();

}