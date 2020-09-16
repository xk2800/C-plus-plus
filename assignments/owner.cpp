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



/**
  * Class - Input from user
  * Function - Feature logic
  * Main Function - Call others function
  */



#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;

void registerLogic();
void loginUserValidationLogic();
void loginPassValidationLogic();
void menuLogic();

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

/*********************************************** LOGIN CLASS ***********************************************/

class Login {
	
	private:
		string username;
		string pass;
		
	public:
		usernameLogin() {	
			cout<<"Enter your username : ";
			cin.ignore();
			getline(cin, username);
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

/*********************************************** OWNER MENU CLASS ***********************************************/

class Menu {
	
	private:
		int selection;
		
	public:
		menuDisplay() {
			
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"          WELCOME TO MMU SHOPPING KIOSK OWNER SYSTEM          "<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<endl<<endl;
			cout<<" 1. Login "<<endl;
			cout<<" 2. Register "<<endl;
			cout<<" 3. View Items "<<endl;
			cout<<" 4. Insert New Items "<<endl;
			cout<<" 5. Update Information Of Items "<<endl;
			cout<<" 6. Delete Items "<<endl;
			cout<<" 0. Exit "<<endl;
		}
		
		menuSelection() {
			cout<<endl;
			cout<<"Please choose an operation to proceed !"<<endl;
			cin>>selection;
			
			cin.ignore();
		}
				
		friend void menuLogic();	
};

/*********************************************** registerLogic() ***********************************************/

void registerLogic() {
	
	Register reg_obj;
	ofstream out_reg_file;
	
	string oname;
	string password, cfrmpassword;
	
	out_reg_file.open("owner-details.txt", std::ios_base::app);

	if(!out_reg_file) {
		cout<<"File is not found !"<<endl;
	} else {
		
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

/*********************************************** loginUserValidationLogic() ***********************************************/

void loginUserValidationLogic() {
	
	Login log_obj;
	ifstream in_log_file_user;

	string username, oname;
	int offset_name;
	bool validate_name;
	
	in_log_file_user.open("owner-details.txt");

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
			loginPassValidationLogic();
		} else {
			cout<<"Name is incorrect or not found ! Please exit the program and try again "<<endl<<endl;
			exit(1);
		}
	
		in_log_file_user.close();
	} else {
		cout<<"File is not found !";
	}		
}

/*********************************************** loginPassValidationLogic() ***********************************************/

void loginPassValidationLogic() {
	
	Login log_obj;
	ifstream in_log_file_user;

	string pass, password;
	int offset_pass;
	bool validate_pass;
	
	in_log_file_user.open("owner-details.txt");

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

/*********************************************** menuLogic() ***********************************************/

void menuLogic() {
	
	Menu menu_obj;
	char proceed;
	
	do {
		menu_obj.menuDisplay();
		menu_obj.menuSelection();
		cout<<endl;
		
		switch(menu_obj.selection) {
			case 0 : cout<<"Thank you for using !";
					 exit(0);
				 	 break;
				 		
			case 1 : cout<<"Reading from the file...."<<endl<<endl;
				 	 cout<<"===================================="<<endl;
				 	 cout<<"              LOGIN                 "<<endl;
	             	 cout<<"===================================="<<endl<<endl;
				 
				 	 loginUserValidationLogic();
				 	 break;
				 
			case 2 : cout<<"===================================="<<endl;
				 	 cout<<"              REGISTER              "<<endl;
		         	 cout<<"===================================="<<endl<<endl;
		
		         	 registerLogic();
				 	 break;
				 
			//case 3....6	
		}
	
		cout<<"Would you like to continue ? [ Y / N ]";
		cin>>proceed;
	
		cin.ignore();	
	} while (proceed == 'Y' || proceed == 'y');
	
	cout<<"Thank you for using !";	
}


/*********************************************** int main() ***********************************************/

int main() {	
	
	menuLogic();
		
	return 0;
}

// CREDIT : https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
//          https://www.youtube.com/watch?v=s3-DmI1ZWxE&t=151s