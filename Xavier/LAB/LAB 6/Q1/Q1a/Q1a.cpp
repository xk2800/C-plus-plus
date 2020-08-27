#include<iostream>
using namespace std;

class MasterStudent
{   string name, title;
    int status;
    
    public: 
     MasterStudent(string n, string t, int x)
     {   name = n;
         title = t;
         status = x;
     }
     
     MasterStudent()
     { name = "Peter";
       title = "A Study on the Usability Factors of Mobile Apps.";
       status = 1;
     }
     
     int getStatus()
     { return status;
     }
     
     string getName()
     { return name;
     }
     
     string getTitle()
     { return title;
     }
     
     ~MasterStudent()
     { cout<<"\n\n~End of Details~Student~"<<name<<endl;
     }
}; 

int main()
{  MasterStudent MS1;
   cout<<"================================="<<endl; 
   cout<<"   Masters Student Details       "<<endl;
   cout<<"================================="<<endl;
   cout<<"Name \t: "<<MS1.getName()<<endl;
   cout<<"Title \t: "<<MS1.getTitle()<<endl;
   cout<<"Status \t: ";
   if(MS1.getStatus() ==1) cout<<"Approved"<<endl;
   else cout<<"Pending"<<endl;
   
   //Create another object passing the values 
   MasterStudent MS2("Aliana Mahmud", "Customer Satisfaction towards Green Products", 0);
   //"Aliana Mahmud" for name, 
   //"Customer Satisfaction towards Green Products" for title, 0 for status
   //Use the cout statements given earlier to display the content of the    
   // new object. 
   //refer to label X for the output to be displayed

   cout<<"================================="<<endl<<"\tMaster Student Details"<<endl<<"================================="<<endl;
   cout<<"Name\t: "<<MS2.getName()<<endl;
   cout<<"Title \t: "<<MS2.getTitle()<<endl;
   cout<<"Status \t: ";
   if(MS1.getStatus() ==1){
     cout<<"Approved"<<endl;
   }else{
     cout<<"Pending"<<endl;
   }
   return 0;
}
