#include<iostream>
using namespace std;

class MasterStudent {
	
	string name, title;
	int status;
	
	public:
		MasterStudent(string n, string t, int x) {
			name = n;
			title = t;
			status = x;
		}
		
		MasterStudent() {
			name = "";
			title = "";
			status = 0;
		}
		
		int getStatus() {
			return status;
		}
		
		string getName() {
			return name;
		}
		
		string getTitle() {
			return title;
		}
		
		~MasterStudent() {
			cout<<"\n\n~End of Details~Student~"<<name<<endl;
		}
};

int main() {
	
	MasterStudent msArr[5] = { 	{"Johanes Kai", "Working with Generation X employees: food industry", 1},
					 			{"Cameron Chan", "Collective Co-Creation within the Open Source Software Community", 1},
					 			{"Meriam Azlan", "What Makes Online Video Advertisements Go Viral?", 0},
					 			{"Peter Pan", "A Study on Form 1 student's learning of Algebra", 1},
					 			{"Dory Dory", "Social media use for corporate communication", 0}
					 		 };
	int x;				 			 
	
	for(x=0; x<5; x++) {
		cout<<"\n=========================================="<<endl<<"\tMasters Student Details"<<x+1<<endl<<"=========================================="<<endl;
		cout<<"Name \t: "<<msArr[x].getName()<<endl;
		cout<<"Title \t: "<<msArr[x].getTitle()<<endl;
	
		cout<<"Status \t: ";
		if(msArr[x].getStatus()==1) {
			cout<<"Approved"<<endl;
		} else {
			cout<<"Pending"<<endl;
		}	
	}
	
	return 0;	
}


