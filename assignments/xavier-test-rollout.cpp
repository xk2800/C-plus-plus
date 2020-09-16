#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;


class Register{

    private:
        string uname, pwd, cpwd;

    public:
        //enter credential for acc registration
        void accRegister(){

            cout<<"Enter a username: ";
                cin.ignore();
                getline(cin, uname);
            cout<<endl;

            cout<<"Enter a password: ";
                cin>>pwd;
            cout<<"Re-confirm your password: ";
                cin>>cpwd;

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

};

class Login{

    private:
        string uname, pwd;
        Register Reg;
        ifstream login_file;

    public:
        
        int openingmsg(){

            cout<<"===================================="<<endl<<"\t\tLOGIN"<<endl<<"===================================="<<endl;
        }

        int accLogin(){

            cout<<"Enter your username: ";
                cin.ignore();
                getline(cin, uname);
            
            cout<<"Enter your password: ";
                cin>>pwd;
            
        }

        string getUsername(){

            return uname;
        }

        string getPwd(){

            return pwd;
        }

        void loginUserLogic(){


            string username, password;
            int offset_name, offset_pwd;
            bool validate_name, validate_pwd;

            login_file.open("shopper-details.txt");
            openingmsg();
            accLogin();
            uname = getUsername();
            pwd = getPwd();

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

        /*void logicPassLogic(){

            string password;

            int offset_pwd;
            bool valdate_pwd;

            login_file.open("shopper-details.txt");

        }*/


};

//function that contain controls and basic logic for register and login functions. Reason for this is to reduce clutter in main.
void mainmenu(){

    Register R;
    Login L;
    int choice;

    cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
    cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
        cin>>choice;

        switch(choice){

        case 1:
            R.registerLogic();
            
            cout<<endl;
        break;

            //cout<<"Reading from the file...."<<endl<<endl;
        
        case 2:
            L.loginUserLogic();
        break;
    }
}

int main(){

    mainmenu();



}