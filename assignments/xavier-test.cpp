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

void custType();
class Shopper{

    protected:
        //string major;
        string uname, pwd, cpwd, address, name ;
		int ctype;
    public:
        //virtual void Register() {};
        
        void opening(){

            
        }

        void reg_acc(){

            cout<<"Enter your name: ";
                cin.ignore();
                getline(cin, name);
            cout<<"Enter your full address: ";
                cin.ignore();
                getline(cin, address);
            cout<<"Customer type: "<<endl;
			custType();


            cout<<"Enter a username: ";
                cin.ignore();
                getline(cin, uname);
            cout<<endl<<"Enter a password: ";
                cin>>pwd;
            cout<<"Re-confirm your password: ";
                cin>>cpwd;
            idGen();
        }

        string getUsername(){

            return uname;
        }

        string getPwd(){

            return pwd;
        }

        string getCpwd(){

            return cpwd;
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

                reg_acc();
                
                uname = getUsername();
                pwd = getPwd();
                cpwd = getCpwd();
                

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;

                reg_file<<uname<<setw(15)<<pwd<<setw(15)<<cpwd;
            }

            reg_file.close();
        }
        
        
};

class Login{

    private:
        string uname, pwd;
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

};


class Customer{

    private:
        
    
    public:

    
};

class MMUStudent:public Shopper{
    
    private:
        
        string maj;
    
    public: 

        void major(){

            cout<<"Enter your major: ";
                cin.ignore();
                getline(cin, maj);

        }

        string maje(){

            return maj;
        }

        void updatereg(){

            ofstream reg_file;

            //open file in append mode to update existing database of user info
            reg_file.open("shopper-details.txt", std::ios_base::app);

            if(!reg_file){

                cout<<"File is not found!"<<endl;
            } else{

                //if file found when continue
                /*cout<<"===================================="<<endl;
                cout<<"\t\tREGISTER"<<endl;
                cout<<"===================================="<<endl;

                reg_acc();
                
                uname = getUsername();
                pwd = getPwd();
                cpwd = getCpwd();
                

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;*/

                //reg_file<<uname<<setw(15)<<pwd<<setw(15)<<cpwd<<endl;

                maj = maje();
                
                reg_file<<endl<<setw(15)<<maj<<endl;
            }

            reg_file.close();
        }

        /*void registerLogic(){

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

                reg_acc();
                
                

                uname = getUsername();
                pwd = getPwd();
                cpwd = getCpwd();
                maj = major();
                

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;

                reg_file<<uname<<setw(15)<<pwd<<setw(15)<<cpwd<<maj<<endl;
            }

            reg_file.close();
        }*/

    //friend class Register;
};

class MMUStaff{

    private:
        
    
    public: 

        

};

//class Mainmenu:public Shopper{
void mainmenu(){
    //private:
    Shopper S;
    //test t;
    Login L;
    int choice, ctype;
    

    //public:
        cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
        cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
                cin>>choice;
    

        if(choice==1){

            S.registerLogic();

        }

    
}
void custType(){

    int ctype;

			cout<<"1. Normal Customer (Non MMU)"<<endl;
			cout<<"2. MMU Student"<<endl;
			cout<<"3. MMU Staff"<<endl;
            cout<<"Select a customer type: "<<endl;
                cin>>ctype;
            
            if(ctype==1){

                
            } else if(ctype==2){

                MMUStudent stud;

                stud.major();
                stud.updatereg();
            } else if(ctype=3){


            } else{

                cout<<"Kindly pick between 1-3 only.";
                custType();
            }
		}

/*class test:public Shopper{
private:
    string major;
public:
    void registerLogic(){

            MMUStudent stu;

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

                reg_acc();
                
                

                uname = getUsername();
                pwd = getPwd();
                cpwd = getCpwd();
                stu.major();

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;

                reg_file<<uname<<setw(15)<<pwd<<setw(15)<<cpwd<<endl;
            }

            reg_file.close();
        }


};

*/


int main(){
    
    Shopper S;
    Login L;
    int choice;
    //login and register function call, the 2 classes and function put into 1 function
    

    mainmenu();

}





/*Credits:

auto gen id = https://stackoverflow.com/questions/39098219/auto-generate-id-c/39099637


*/