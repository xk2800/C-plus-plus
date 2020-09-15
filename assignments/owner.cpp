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

void registerLogic();
void loginLogic();

/*********************************************** REGISTER CLASS ***********************************************/

class Register {
	
	private:
		string oname;
		string pass, cfrmpass;
	
	public:
		
		void usernameRegister() {
			cout<<"Set a username : ";
			getline(cin, oname);
			cout<<endl;	
		}
		
		void passRegister() {
			cout<<"Enter a password [0-9 digits only]: ";
			cin>>pass;
			cout<<"Re-enter the password : ";
			cin>>cfrmpass;	
		
			while(pass != cfrmpass) {
				cout<<"The password you entered is not matched ! Please try again"<<endl<<endl;
				cout<<"Enter a password : ";
			    cin>>pass;
			    cout<<"Re-enter the password : ";
			    cin>>cfrmpass;	
			}	
		}
		
		string getUser() {
			return oname;
		}
		
		string getPass() {
			return pass;
		}	
		
		string getCfrmpass() {
			return cfrmpass;
		}
};

/*********************************************** LOGIN CLASS ***********************************************/

class Login {
	
	private:
		string username;
		string pass;
		Register reg_friend_obj;
		
	public:
		usernameLogin() {	
			cout<<"Enter your username : ";
			cin.ignore();
			getline(cin, username);
			cout<<endl;
		}
		
		passLogin() {
			cout<<"Enter your password : ";
			cin>>pass;
		}
		
		string getUser() {
			return username;
		}
		
		string getPass() {
			return pass;
		}
};

/*********************************************** registerLogic() ***********************************************/

void registerLogic() {
	
	Register reg_obj;
	ofstream out_reg_file;
	
	string oname;
	string password, cfrmpassword;
	
	out_reg_file.open("owner-details.txt");
	
	if(!out_reg_file) {
		cout<<"File is not found !"<<endl;
	} else {
		reg_obj.usernameRegister();
		reg_obj.passRegister();
		
		oname = reg_obj.getUser();
		password = reg_obj.getPass();
		cfrmpassword = reg_obj.getCfrmpass();
		
		cout<<endl;
		cout<<"Register is completed and the data is saved !"<<endl;
		
		out_reg_file<<"=============================="<<endl;
		out_reg_file<<"Shop Owner Account Details"<<endl;
		out_reg_file<<"=============================="<<endl;
		out_reg_file<<"Username      Password      Confirm Password"<<endl;
		out_reg_file<<oname<<setw(15)<<password<<setw(15)<<cfrmpassword<<endl;	
	}
			
	out_reg_file.close();
}

/*********************************************** loginLogic() ***********************************************/

void loginLogic() {
	
	Login log_obj;
	ifstream in_log_file;

	string pass, password;
	int offset;
	bool validate;
	
	in_log_file.open("owner-details.txt");
	
	log_obj.passLogin();
	pass = log_obj.getPass();
	cout<<endl;
	
	if(in_log_file.is_open()) {
		cout<<"Reading from the file...."<<endl<<endl; 
	
		while(!in_log_file.eof()) {
			getline(in_log_file, password);
		
			if((offset = password.find(pass, 0))!= string::npos) {	
				validate = true;
				break;
			} else {
				validate = false;	
			}
		}
		
		if(validate == true) {
			cout<<"Successfully";
		} else {
			cout<<"Password incorrect ! Please try again"<<endl;	
		}
	} 
	
	in_log_file.close();
}

/*********************************************** int main() ***********************************************/

int main() {
	
	registerLogic();
	loginLogic();
		
	return 0;
}