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

//class MMUStudent;
class Shopper{

    private:
        string uname, pwd, cpwd, address, name;//MMUStudent m;
        MMUStudent mmustud;
		

    public:
        int ctype;
    //MMUStudent mmustud;
        //enter credential for acc registration
        void accRegister(){

			cout<<"Enter your name: ";
				cin.ignore();
				getline(cin, name);
			cout<<"Enter your full address: ";
				cin.ignore();
				getline(cin, address);
			cout<<"Customer type: "<<endl;
			custType();
            mmustud.test();
            cout<<"Enter a username: ";
                cin.ignore();
                getline(cin, uname);
            cout<<endl<<"Enter a password: ";
                cin>>pwd;
            cout<<"Re-confirm your password: ";
                cin>>cpwd;
            idGen();

            //if pwd and confirm pwd not same, error happens and user must retry until both same
                while(pwd != cpwd){

                    cout<<"Make sure both passwords are same. Kindly recheck and re-enter."<<endl;
                    cout<<"Enter a password: ";
                        cin>>pwd;
                    cout<<"Re-confirm your password: ";
                        cin>>cpwd;
                }
        }

        //return input
        string getUsername(){

            return uname;
        }

        string getPwd(){

            return pwd;
        }

        string getCpwd(){

            return cpwd;
        }

        //print customer type table
		void custType(){

			cout<<"1. Normal Customer (Non MMU)"<<endl;
			cout<<"2. MMU Student"<<endl;
			cout<<"3. MMU Staff"<<endl;
            cout<<"Select a customer type: "<<endl;
                cin>>ctype;
            
            /*switch (ctype){

                case 1:
                    
                break;
                case 2:
                    studmajor();
                    cout<<"detected input 2";
                break;
                case 3:
                    MMUStaff depart();
                break;

            }

            
            if(ctype==2){
                
                MMUStudent stud;
                stud.test();
            } else{
                
                cout<<"ctype func no work";
            }*/
		}

        //auto gen ID
        int idGen(){

            struct id_Gen
            {
                id_Gen()
                : _id (0)
                {
                    std::ifstream ifs("_id.txt");
                    ifs>>_id;
                }

                ~id_Gen()
                {
                    std::ofstream ofs("_id.txt", std::ios_base::out | std::ios_base::trunc);
                    ofs<<_id;
                }

                int operator()() { return _id++; }

                int _id;
            };

                id_Gen idGen;

                cout<<"Your id is: " << idGen()<<endl;

                return 0;
        }



        //Logic for registration part
        void registerLogic(){

            ofstream reg_file;

            //open file in append mode to update existing database of user info
            reg_file.open("shopper-details.txt", std::ios_base::app);

            if(!reg_file){

                cout<<"File is not found!"<<endl;
            } else{

                //if file found when continue
                cout<<"===================================="<<endl;
                cout<<"\t\tREGISTER"<<endl;
                cout<<"===================================="<<endl;

                accRegister();

                uname = getUsername();
                pwd = getPwd();
                cpwd = getCpwd();

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;

                reg_file<<uname<<setw(15)<<pwd<<setw(15)<<cpwd<<endl;
            }

            reg_file.close();
        }

//};

//class Login{

    private:
        string luname, lpwd;
        //Register Reg;
        ifstream login_file;

    public:
        
        int openingmsg(){

            cout<<"===================================="<<endl<<"\t\tLOGIN"<<endl<<"===================================="<<endl;
        }

        int accLogin(){

            cout<<"Enter your username: ";
                cin.ignore();
                getline(cin, luname);
            
            cout<<"Enter your password: ";
                cin>>lpwd;
            
        }

        string lgetUsername(){

            return luname;
        }

        string lgetPwd(){

            return lpwd;
        }

        void loginUserLogic(){


            string username, password;
            int offset_name, offset_pwd;
            bool validate_name, validate_pwd;

            login_file.open("shopper-details.txt");
            openingmsg();
            accLogin();
            uname = lgetUsername();
            pwd = lgetPwd();

            if(login_file.is_open()){

                while(!login_file.eof()){

                    getline(login_file, username);
                    getline(login_file, password);

                    if((offset_name = uname.find(username, 0))!= string::npos && (offset_pwd = password.find(pwd, 0))!=string::npos){

                        validate_name = true; 
                        validate_pwd = true; break;
                    } else{

                        validate_name = false;
                        validate_pwd = false;
                    }

                }

                if(validate_name == true && validate_pwd == true){

                    cout<<"Username and password matched!"<<endl<<endl;
                } else{

                    cout<<"Password incorrect ! Please try again"<<endl<<endl;
                    exit(1);
                }

            } else {

                cout<<"File is not found! ";
            }

            login_file.close();
        }

//};

//function that contain controls and basic logic for register and login functions. Reason for this is to reduce clutter in main.
/*void mainmenu(){

    //Register R;
    //Login L;
    int choice;

    cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
    cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
        cin>>choice;

        switch(choice){

        case 1:
            //R.registerLogic();
            registerLogic();
            
            cout<<endl;
        break;

            //cout<<"Reading from the file...."<<endl<<endl;
        
        case 2:
            //L.loginUserLogic();
            loginUserLogic();
        break;
    }
}*/
};

class Customer:public Shopper{

    private:
        
    
    public:

    
};

class MMUStudent/*:public Shopper*/{
    
    private:
        
        string major;
    
    public: 

        void test(){

            cout<<"What is your major";
                cin>>major;
        }

    //friend class Shopper;
};

class MMUStaff:public Shopper{

    private:
        
        string department;
    
    public:



        

};

//function that contain controls and basic logic for register and login functions. Reason for this is to reduce clutter in main.
void mainmenu(){

    Shopper s;
    MMUStudent stud;
    int choice;

    cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
    cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
        cin>>choice;

        switch(choice){

        case 1:
            //R.registerLogic();
            s.registerLogic();
            
            cout<<endl;
        break;

            //cout<<"Reading from the file...."<<endl<<endl;
        
        case 2:
            //L.loginUserLogic();
            s.loginUserLogic();
        break;
    }

    if(s.ctype==2){

        //stud.test();
    }
}
int main(){

    Shopper s;

    //login and register function call, the 2 classes and function put into 1 function
    mainmenu();
    
    


}





/*Credits:

auto gen id = https://stackoverflow.com/questions/39098219/auto-generate-id-c/39099637


*/