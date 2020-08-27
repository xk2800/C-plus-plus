#include<iostream>
#include<iomanip>
#include <string> 
using namespace std;

class IceCream {
   
   private:
      string flavour;
      int number;
      float price;

   public:
      void menu();
      void setflavour();
      void setHowMany();
      friend void displayReceipt(IceCream);
      IceCream();
      
      void setVar(string perisa, float harga, int no) {
      	flavour = perisa;
      	price = harga;
      	number = no;
	  }
};

int main() {
	
	IceCream IC;
	string flavour;
	float price;
	
	IC.menu();
	IC.setflavour();
	IC.setHowMany();
	displayReceipt(IC);
	
	return 0;
	
}

void IceCream::menu() {
  
    cout<<"================================="<<endl<<"\t===  CHOOSE FLAVOUR  ==="<<endl<<"================================="<<endl;
    cout<<"[1] === Strawberry Flavour RM 3.50"<<endl;
    cout<<"[2] === Chocolate Flavour  RM 2.50"<<endl;
    cout<<"[3] === Vanilla Flavour    RM 1.50"<<endl;
    cout<<"[4] === Durian Flavour     RM 0.50"<<endl;
}

void IceCream::setflavour() {
  
    int choice;
    
        cout<<"\nChoice of flavour : ";
            cin>>choice;
    
    switch(choice) {
        case 1: 
                price = 3.50;
                flavour.assign("Strawberry Flavour");
                break;
        case 2: 
                price = 2.50;
                flavour.assign("Chocolate Flavour");
                break;
        case 3: 
                price = 1.50;
                flavour.assign("Vanilla Flavour");
                break;
        case 4: 
                price = 0.50;
                flavour.assign("Durian Flavour");
                break;
        default: 
                price = 0.00;
                break;
    }
}

void IceCream::setHowMany() {
    
    cout<<"How many : ";
        cin>>number;
}
		
		
IceCream::IceCream() {
  
    cout<<"BARNEY'S HOUSE OF ICE"<<endl;
    cout<<endl;
}

void displayReceipt(IceCream dispIce) {
  
    float total_price = dispIce.price * dispIce.number;
    
    cout<<"\n================================="<<endl<<"\t===  PAYMENT  ==="<<endl<<"================================="<<endl;
    cout<<"Flavour	  : "<<dispIce.flavour<<endl;
    cout<<"Total Price  : "<<setprecision(2)<<fixed<<total_price<<endl;
}
