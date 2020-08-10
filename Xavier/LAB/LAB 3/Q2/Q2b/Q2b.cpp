#include <iostream>
#include <cmath>
using namespace std;


class Cuboid
{ 
  public:
  int length, width, height, volume;
  
  	void setdata(){
          cout<<"Enter the width, length, height of a Cuboid object: ";
            cin>>width>>length>>height;
      }
  	void findVolume(){
          volume = length * width * height;
      }
  	int getLenght(){
		return length;
	}
	
	int getWidth(){
		return width;
	}
	
	int getHeight(){
		return height;
	}
};

int main()
{ Cuboid Q;
  Q.setdata();
  Q.findVolume();

   cout <<endl<<"------Display Cuboid Data------"<<endl;
   cout <<"Width :"<< Q.getWidth() << "cm"<<endl;
    cout<<"Length :"<<Q.getLenght()<<"cm"<<endl;
    cout<<"Height :"<<Q.getHeight()<<"cm"<<endl;
    cout<<"Volume :"<<Q.volume<<" cm^3"<<endl;
  
}
