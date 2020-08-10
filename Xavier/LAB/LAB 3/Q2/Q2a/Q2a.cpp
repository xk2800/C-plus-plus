#include <iostream>
#include <iomanip>
using namespace std;


class Cuboid
{ int length, width, height, volume;
  public:
  	void setdata(){
          cout<<"Enter the width, length, height of a Cuboid object: ";
            cin>>width>>length>>height;
      }
  	void findVolume(){
          volume = length * width * height;
      }
  	void display(){
          cout <<endl<<"------Display Cuboid Data------"<<endl;
          cout <<"Width :"<< width << "cm"<<endl;
          cout<<"Length :"<<length<<"cm"<<endl;
          cout<<"Height :"<<height<<"cm"<<endl;
          cout<<"Volume :"<<volume<<"cm^3"<<endl;
      }
};

int main()
{ Cuboid Q;
  Q.setdata();
  Q.findVolume();
  Q.display();
  return 0;
}
