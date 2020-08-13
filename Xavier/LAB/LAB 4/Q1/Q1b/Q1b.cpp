#include<iostream>
#include<iomanip>
using namespace std;

class CarProduction
{   int quantity;
    string plantno;
    
    public:
    void setdata(string s, int q)
    	{ plantno = s;
    	  quantity = q; 
    	}
    //b.display_graph() function
    void display_graph(){

        int hash, call;

        cout<<"======================================="<<endl<<this->plantno<<endl;

        hash=quantity%2;
        call=(quantity-hash)/2;
        
        
            for(int x=0; x<call; x++){
                cout<<'*';
            }

            for(int w=0; w<hash; w++){
                cout<<'#';
            }

        cout<<endl;
    }

};
int main()
{  //a. declare an array named C of 4 object elements of CarProduction class
    CarProduction C[4];
   string s; int qty;
   for(int i=0; i<4; i++)
   {  cout<<"Enter the plant no#                     : "; 
      cin>>s;
      cout<<"Enter the amount of cars produced today : "; 
      cin>>qty;
      C[i].setdata(s, qty);
   }
   cout<<"\n       Daily Productivity Report       "<<endl;
   for(int i=0; i<4; i++)
       C[i].display_graph();
}  
