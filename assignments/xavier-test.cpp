/**********|**********|**********|
Program             : shopper.cpp
Course              : Object Oriented Programming
Year                : 2020/21 Trimester 1
Name                : Khew Xavier Ethan
ID                  : 1181202757
Lecture Section     : TC02
Tutorial Section    : TT04
Email               : 1181202757@student.mmu.edu.my
Phone               : 010-2311245
**********|**********|**********/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;


//***************************************************************************************Declare Global Var
void registerLogic();
void loginUserLogic();
void loginPassLogic();

//***************************************************************************************Register
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
			cout<<"Enter a password : ";
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

//***************************************************************************************Login

class Login {
	
	private:
		string username;
		string pass;
		Register reg_friend_obj;
		
	public:
		int openingmsg(){

			cout<<"===================================="<<endl;
            cout<<"              LOGIN                 "<<endl;
            cout<<"===================================="<<endl;
		}
		int usernameLogin() {

			cout<<"Enter your username : ";
			cin.ignore();
			getline(cin, username);
		}
		
		int passLogin() {

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

//***************************************************************************************registerLogic()

void registerLogic() {
	
	Register reg_obj;
	ofstream out_reg_file;
	
	string oname;
	string password, cfrmpassword;
	
	out_reg_file.open("shopper-details.txt", std::ios_base::app);

	if(!out_reg_file) {
		cout<<"File is not found !"<<endl;
	} else {

		cout<<"===================================="<<endl;
        cout<<"              REGISTER              "<<endl;
        cout<<"===================================="<<endl;
		
		reg_obj.usernameRegister();
		reg_obj.passRegister();
		
		oname = reg_obj.getUser();
		password = reg_obj.getPass();
		cfrmpassword = reg_obj.getCfrmpass();
		
		cout<<endl;
		cout<<"Register is completed and the data is saved !"<<endl<<endl;
		
		out_reg_file<<oname<<setw(15)<<password<<setw(15)<<cfrmpassword<<endl;		
	}
			
	out_reg_file.close();
}

//***************************************************************************************loginUserLogic()

void loginUserLogic() {
	
	Login log_obj;
	ifstream in_log_file_user;

	string username, oname;
	int offset_name;
	bool validate_name;
	
	in_log_file_user.open("shopper-details.txt");
	log_obj.openingmsg();
	log_obj.usernameLogin();
	username = log_obj.getUser();
	
	if(in_log_file_user.is_open()) {

		while(!in_log_file_user.eof()) {
			
			getline(in_log_file_user, oname);
			
			if((offset_name = oname.find(username, 0))!= string::npos) {	
				validate_name = true;
				break;
			} else {
				validate_name = false;	
			}	
		}
		
		if (validate_name == true) {
			cout<<"Username is matched ! You can proceed to enter your password "<<endl<<endl;
			loginPassLogic();
		} else {
			cout<<"Name is incorrect or not found ! Please exit the program and try again "<<endl<<endl;
			exit(1);
		}
	
		in_log_file_user.close();
	} else {
		cout<<"File is not found !";
	}		
}

//***************************************************************************************loginPassLogic()

void loginPassLogic() {
	
	Login log_obj;
	ifstream in_log_file_user;

	string pass, password;
	int offset_pass;
	bool validate_pass;
	
	in_log_file_user.open("shopper-details.txt");

	log_obj.passLogin();
	pass = log_obj.getPass();
	
	if(in_log_file_user.is_open()) {

		while(!in_log_file_user.eof()) {
			
			getline(in_log_file_user, password);
			
			if((offset_pass = password.find(pass, 0))!= string::npos) {	
				validate_pass = true;
				break;
			} else {
				validate_pass = false;	
			}	
		}
		
		if(validate_pass == true) {
			cout<<"Password is matched !"<<endl<<endl;
		} else {
			cout<<"Password incorrect ! Please try again later"<<endl<<endl;
			exit(1);	
		}
	
		in_log_file_user.close();
	}
}



/*class customer{

    private:
        string name, address, password, id;
        int cust_type;
    
    public:

        void input(){

            
        }

};

class student{
    
    private:
        string name, address, password, id;
        int cust_type;
    
    public: 

};

class staff{

    private:
        string name, address, password, id;
        int cust_type;
    
    public: 
};*/


int main(){

    int choice;

    cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
    cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
        cin>>choice;

    switch(choice){

        case 1:
            registerLogic();
            
            cout<<endl;
        break;

            //cout<<"Reading from the file...."<<endl<<endl;
        
        case 2:
            loginUserLogic();
        break;
    }
		
	return 0;
    
}