#include <iostream>
using namespace std;
class geometry
{
 	  private:
		  float PI, height, radius;
 	  public:
	  	  geometry(float hg, float rd){
                
                height = hg;
                radius = rd;
                PI = 3.142;
            }

            ~geometry(){
                cout<<"= END OF PROGRAM =";
            }

            friend class cylinder;
            friend class cone;

	  	  //-----(2)-----
	  
	  	  //-----(3)-----

	  	  //-----(4)-----
};

class cylinder
{
 	  private:
	  	float vol; 
 	  public:
	  	//-----(5)-----	 
        
        void calc_vol(geometry *g) {

			vol = ((*g).PI) * ((*g).radius) * ((*g).radius) * ((*g).height);  
			cout<<endl<<"Volume of cylinder with radius "<<(*g).radius<<" and "<<(*g).height<<" is : "<<vol<<endl; 
		}
	  		 
};

class cone
{
 	  private:
	  	float vol; 
 	  public:
	  	//-----(6)-----	 

        void calc_vol(geometry &g) {
			
			vol = (g.PI * g.radius * g.radius * g.height) / 3;
			cout<<"Volume of cone with radius "<<g.radius<<" and "<<g.height<<" is : "<<vol<<endl<<endl; 
		}
};

int main()
{
 	  float hg, rd;
 	  cout << "Enter height : ";
	  cin  >> hg;
 	  cout << "Enter radius : "; 
	  cin  >> rd;
	   
	  //-----(7)-----
	  //-----(8)-----
	  //-----(9)-----
	  //-----(10)-----
	  //-----(11)-----

      geometry gmt(hg, rd);

      cylinder cyc;
      cyc.calc_vol(&gmt);
      
      cone cn;
      cn.calc_vol(gmt);

      return 0;
}
