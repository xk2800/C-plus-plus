#include <iostream>

using namespace std;


class Fraction
{  
	
};


int isValid(Fraction ob)
{  int valid;
     if (ob.getDenom()==0)
	 {  valid = 0;
	    cout<<"\nAlert:Denominator is having value zero "<<endl;
	 } 
	 else if (ob.getNume()>ob.getDenom())
	 {  valid = 0;
	   cout<<"\nAlert:Numerator greater than denominator"<<endl;
     }
	 else
	   valid = 1;	
	return valid;
}

int main()
{	Fraction ob1[3];
	for(int i=0; i<3; i++)
	{	ob1[i].setdata(i+1,2-i);
		--------(b)----------
	}
	return 0;
}
