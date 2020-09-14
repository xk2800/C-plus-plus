/**********|**********|**********|**********|**********|**********|**********|
Program :               oop_proj_y2s5.cpp
Course :                Object Oriented Programming
Year :                  2020/21 Trimester 1
Name :                  Elton Wong Chun Meng
ID:                     1181203056
Lecture Section:        TC02
Tutorial Section :      TT04
Email :                 eltonwcm00@gmail.com / 1181203056@student.mmu.edu.my
Phone :                 01111207201
/**********|**********|**********|**********|**********|**********|**********/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;


/* REGISTER CLASS */

class Register {
	
	private:
		string username;
		float pass, cfrmpass;
	
	public:
		
		void usernameRegister() {
			cout<<"Set a name : ";
			getline(cin, username);
			cout<<endl;	
		}
		
		void passRegister() {
			cout<<"Enter a password [0-9 digits only]: ";
			cin>>pass;
			cout<<"Re-enter the password : ";
			cin>>cfrmpass;	
		
			while(pass != cfrmpass) {
				cout<<"The password you entered is not matched ! Please try again"<<endl<<endl;
				cout<<"Enter a password [0-9 digits only]: ";
			    cin>>pass;
			    cout<<"Re-enter the password : ";
			    cin>>cfrmpass;	
			}	
		}
		
		string getUser() {
			return username;
		}
		
		float getPass() {
			return pass;
		}	
		
		float getCfrmpass() {
			return cfrmpass;
		}
		
};

int main() {
	
	/* REGISTER LOGIC */
	
	Register reg_obj;
	ofstream out_reg_file;
	
	string uname;
	float password, cfrmpassword;
	
	out_reg_file.open("register.txt");
	
	if(!out_reg_file) {
		cout<<"File is not found !"<<endl;
	} else {
		reg_obj.usernameRegister();
		reg_obj.passRegister();
		
		uname = reg_obj.getUser();
		password = reg_obj.getPass();
		cfrmpassword = reg_obj.getCfrmpass();
		
		cout<<endl;
		cout<<"Register is completed and the data is saved !"<<endl;
		
		out_reg_file<<"=============================="<<endl;
		out_reg_file<<"Shop Owner Account Details"<<endl;
		out_reg_file<<"=============================="<<endl;
		out_reg_file<<"Username      Password      Confirm Password"<<endl;
		out_reg_file<<uname<<setw(15)<<password<<setw(15)<<cfrmpassword<<endl;	
	}
			
	out_reg_file.close();		
}