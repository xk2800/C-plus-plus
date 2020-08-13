#include <iostream>

using namespace std;


class Fraction
{  
	int denom, nume;

	public:
		void setData(int denom1, int nume1){
			this->denom = denom1;
			this->nume = nume1;
		}

		int getDenom(){
			return denom;
		}

		int getNume(){
			return nume;
		}
};


int isValid(Fraction ob)
{  int valid;
     if (ob.getDenom()==0)
	 {  
		valid = 0;
	    cout<<"\nAlert:Denominator is having value zero "<<endl;
	 } 
	 else if (ob.getNume()<ob.getDenom())
	 {  
		valid = 0;
	   cout<<"\nAlert:Numerator greater than denominator"<<endl;
     }
	 else{
	   valid = 1;
	}
	return valid;
}

int main()
{	Fraction ob[3];
	int valid;

	for(int i=0; i<3; i++)
	{	ob[i].setData(i+1,2-i);

		cout<<"Fraction"<<i+1<<"/"<<2-i;
	
		valid=isValid(ob[i]);

		if(valid==0){
			cout<<"is Invalid"<<endl;

		}else if(valid==1){
			cout<<"is valid"<<endl;
		}
	}
	return 0;
}
