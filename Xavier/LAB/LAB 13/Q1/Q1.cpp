#include<iostream>
#include<iomanip>
using namespace std;
class Rice
{  float price_per_kg, total_weight;

   public:
   	  Rice(float w)
   	  { price_per_kg = 10.0;
   	    total_weight = w;
   	  }
   	  
   	  void display_rice()
   	  {  cout<<"----------------------------------------"<<endl;
   	     cout<<"         Rice Details                 "<<endl;
		 cout<<fixed<<setprecision(2);
		 cout<<"Total weight      : "<<total_weight<<endl;
		 cout<<"Price perkg (RM) : "<<price_per_kg<<endl;
		 cout<<"Total (RM)        : "<<total_weight*price_per_kg<<endl;
   	  }
}; 

class Product{

	private:

		float kg;

	public:

		Rice operator+(const Product &prod){
			

			return Rice (kg + prod.kg);
		}

		void setdata(){

			cout<<"Enter product's weight (kg): ";	cin>>kg;

		}

};

int main(){

	Product A, B;
	A.setdata();
	B.setdata();

	Rice H = A + B;

	H.display_rice();
}