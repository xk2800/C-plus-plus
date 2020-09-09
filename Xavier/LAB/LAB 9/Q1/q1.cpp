#include<iostream>
using namespace std;

class ArtificialGrass 
{	private: int length, width, depth;

	public:  	
	void grass_data(int q, int r, int s )
	{  length = q; width = r; depth = s; }
	
	int grass_gauge()
	{ return length * width * depth;	}

    ArtificialGrass(){
        length = 4;
        width = 6;
        depth = 3;

    }

    ~ArtificialGrass(){

        cout<<"Deleting the artificial grass details."<<endl<<endl;
    }
};

int main(){

    ArtificialGrass *ag = new ArtificialGrass;

    cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl<<"\tThe Artifical Grass Details"<<endl<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"The Previous Batch Set left..."<<endl;
    cout<<"Available Grass Size: "<<ag->grass_gauge()<<" cm [2 pieces in the set]"<<endl<<endl;

    delete ag;

    const int k = 3;
    int q, r, s;
    ArtificialGrass *ag_array = new ArtificialGrass[k];

    cout<<endl<<"========================================"<<endl<<"\tThe Stocks Available..."<<endl<<"++++++++++++++++++++++++++++++++++++++++"<<endl;

    for(int count=0; count<k; count++){

        ag_array->grass_data(count+2, count+2, count +2);

        cout<<"The Grass Size SET#"<<count+1<<endl;
        cout<<"->> "<<ag_array->grass_gauge()<<"cm [2 pieces in one set]"<<endl<<endl;
    }

    cout<<endl;

    delete[] ag_array;

    return 0;
}

