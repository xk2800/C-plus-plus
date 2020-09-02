#include <iostream>
#include<iomanip>
using namespace std;

class Books
{
	private:
		string isbnNo, title, author;
		float price, discountedprice, discountperc;
	public:
		void set_Data();
		void calcDiscountedPrice();
		void print();
		float getDiscountedPrice();
		~Books();
};

void func(Books &);

int main(){

    Books B1;
    Books B2[5];

    float max = 0, price[5];
    int total=0;

    cout<<"Enter data for new incoming book this Month......"<<endl<<endl;

    func(B1);
    cin.ignore();

    cout<<endl<<endl<<"Now we shall enter and display data for 5 special boooks...."<<endl<<endl<<endl;

    for(int j=0; j<5; j++ ){

        func(B2[j]);

        if(price[j]>max){
            max = price[j];
        }

        if(B2[j].getDiscountedPrice()<30){
            total +=1;
        }
    }

    cout<<endl<<"--------------------------------------------------------"<<endl<<endl;
   	cout<<"The most expensive book is RM "<<setprecision(2)<<fixed<<max<<endl;
   	cout<<"The number of books that are below RM 30 are :"<<total<<endl<<endl;
   	
   	return 0;

}

void func(Books &obj){

    obj.set_Data();
    obj.calcDiscountedPrice();
    obj.print();
}

void Books::set_Data(){

    cout<<"Enter ISBN\t:";
        cin>>isbnNo;
    cout<<"Enter Title\t:";
        cin.ignore();
        getline(cin, title);
    cout<<"Enter Author's name\t:";
        getline(cin, author);
    cout<<"Enter price\t: RM";
        cin>>price;
    cout<<"Enter discount (%)\t: ";
        cin>>discountperc;
}

void Books::calcDiscountedPrice(){

    discountedprice = price * (100 - discountperc) /100;
}

void Books::print(){

    cout<<"--------------------------------------------------------"<<endl<<"\tBook Details"<<endl<<"--------------------------------------------------------"<<endl;

    cout<<"ISBN\t: "<<isbnNo<<endl;
    cout<<"Title\t: "<<title<<endl;
    cout<<"Author\t: "<<author<<endl;
    cout<<"Original Price\t: "<<price<<setprecision(2)<<fixed<<endl;
    cout<<"Discounted Price\t: "<<discountedprice<<setprecision(2)<<fixed<<endl;
    
}

float Books::getDiscountedPrice(){

    return discountedprice;
}

Books::~Books(){

    cout<<"--------------Thank you-----------------"<<endl;
}