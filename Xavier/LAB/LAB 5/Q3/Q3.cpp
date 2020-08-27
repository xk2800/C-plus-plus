#include <iostream>
#include<iomanip>

using namespace std;


class PreOrder{

    string title;
    double price;
    int selection;

    public:
        void BookSelection(){

            cout<<"[1] Mum’s Favourite Recipes Book\t\t\tPrice: RM\t14.00"<<endl;
            cout<<"[2] Weight Watchers Everyday Favourite Recipes Book\tPrice: RM\t12.00"<<endl;
            cout<<"[3] The Skinny 5:2 Diet Family Recipes Book\t\tPrice: RM\t10.90"<<endl;
            cout<<"[4] Favourite Teatime Recipes Book\t\t\tPrice: RM\t10.00"<<endl;
            cout<<"[5] Favourite Traditional and Retro Recipes\t\tPrice: RM\t13.00"<<endl;
        }

        void BookPreOrder(){

            cout<<endl<<"Enter your choice, put your selection number:"<<endl;
                cin>>selection;

            if(selection==1){
                title = "Mum’s Favourite Recipes Book";
                price = 14;
            }else if(selection==2){
                title = "Weight Watchers Everyday Favourite Recipes Book";
                price = 12;
            }else if(selection==3){
                title = "The Skinny 5:2 Diet Family Recipes Book";
                price = 10.90;
            }else if(selection==4){
                title ="Favourite Teatime Recipes Book";
                price = 10;
            }else if(selection==5){
                title="Favourite Traditional and Retro Recipes";
                price = 13;
            }else{
                title="No title";
                price = 0;
            }
        }

        double getPrice(){

            return price;
        }

        string getTitle(){
            
            return title;
        }

};

class Buyer{

    string Booktitle, name;
    double payment;
    
    PreOrder order;

    public:
        void set_data(){

            //get name, user input, call getBook()

            cout<<"===================================="<<endl<<"\t FAVOURITE RECIPE BOOK OF THE MONTH"<<endl<<"===================================="<<endl;

            cout<<"Type your name\t:";
                getline(cin,name);

            getBook();

        }

        void getBook(){

            order.BookSelection();
            order.BookPreOrder();
            payment = order.getPrice();
            Booktitle = order.getTitle();
        }

        void showDetails(){

            cout<<"...................................."<<endl<<name<<", Your order details"<<endl<<"...................................."<<endl;
            cout<<"Book title\t:"<<Booktitle<<endl;
            cout<<fixed<<setprecision(2)<<"Price\t\t:RM"<<payment;
        }
};

int main(){

    Buyer buy;

    buy.set_data();
    buy.showDetails();
}