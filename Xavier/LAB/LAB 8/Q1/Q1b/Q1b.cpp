#include <iostream>
using namespace std;
class geometry
{
 	  private:
		  float PI, height, radius, length;
 	  public:
	  	  geometry(float hg, float rd, float l){
                
                height = hg;
                radius = rd;
                length = l;
                PI = 3.142;
            }

            ~geometry(){
                cout<<"= END OF PROGRAM =";
            }

            friend class cylinder;
            friend class cone;
            friend class cube;

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

class cube{

    private:
        float vol;

    public:
        void cal_vol(geometry &g){

            vol = g.length * g.length * g.length;

            cout<<"Volume of cube with length "<<g.length<<" is : "<<vol<<endl<<endl;

        }
};

int main()
{
 	  float hg, rd, l;

 	  cout << "Enter height : ";
	    cin  >> hg;

 	  cout << "Enter radius : "; 
	    cin  >> rd;

      cout<<"Enter length : ";
        cin>>l;

	   
	  //-----(7)-----
	  //-----(8)-----
	  //-----(9)-----
	  //-----(10)-----
	  //-----(11)-----

      geometry gmt(hg, rd, l);

      cylinder cyc;
      cyc.calc_vol(&gmt);
      
      cone cn;
      cn.calc_vol(gmt);

      cube cb;
      cb.cal_vol(gmt);

      return 0;
}
