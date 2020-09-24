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
		int ctype, id;

    public:
        //virtual void Register() {};


        void reg_acc(){

            cout<<"Enter your name: ";
                cin.ignore();
                getline(cin, name);
            cout<<"Enter your full address: ";
                cin.ignore();
                getline(cin, address);
            cout<<"Customer type: "<<endl;
			custType();

            /*cout<<"Enter a username: ";
                cin.ignore();
                getline(cin, uname);*/
            cout<<endl<<"Enter a password: ";
                cin>>pwd;
            cout<<"Re-confirm your password: ";
                cin>>cpwd;
            test();

            //if pwd and confirm pwd not same, error happens and user must retry until both same
                while(pwd != cpwd){

                    cout<<"Make sure both passwords are same. Kindly recheck and re-enter."<<endl;
                    cout<<"Enter a password: ";
                        cin>>pwd;
                    cout<<"Re-confirm your password: ";
                        cin>>cpwd;
                }
        }

        string getName(){

            return name;
        }
        
        string getAddress(){

            return address;
        }

        /*string getUsername(){

            return uname;
        }*/

        string getPwd(){

            return pwd;
        }

        string getCpwd(){

            return cpwd;
        }

        //auto gen ID
        //int idGen(){

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
                void test(){
                id_Gen idGen;
                

                cout<<"Your id is: " << idGen()<<endl;

                //return 0;
                }

        //}

        //Logic for registration part
        void registerLogic(){

            ofstream reg_file;
            id_Gen idgen;

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
                
                name = getName();
                address = getAddress();
                //uname = getUsername();
                id = idgen();
                pwd = getPwd();
                //cpwd = getCpwd();
                

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;

                reg_file/*<<setw(15)<<uname*/<<setw(10)<<name<<setw(10)<<address<<setw(10)<<id<<setw(10)<<pwd<<endl;
            }

            reg_file.close();
        }
        
        
};

class Login{

    private:
        string id, pwd;
        ifstream login_file;

    public:
        
        int openingmsg(){

            cout<<"===================================="<<endl<<"\t\tLOGIN"<<endl<<"===================================="<<endl;
        }

        int accLogin(){

            cout<<"Enter your ID: ";
                //cin.ignore();
                //getline(cin, id);
                cin>>id;
            
            cout<<"Enter your password: ";
                cin>>pwd;
            
        }

        string getID(){

            return id;
        }

        string getPwd(){

            return pwd;
        }

        void loginUserLogic(){


            string ID, password;
            int offset_name, offset_pwd;
            bool validate_name, validate_pwd;

            login_file.open("shopper-details.txt");
            openingmsg();
            accLogin();
            id = getID();
            pwd = getPwd();

            if(login_file.is_open()){

                while(!login_file.eof()){

                    getline(login_file, ID);
                    getline(login_file, password);

                    if((offset_name = id.find(ID, 0))!= string::npos && (offset_pwd = password.find(pwd, 0))!=string::npos){

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

                major();
                maj = maje();
                
                reg_file<</*endl<<setw(30)<<*/maj/*<<endl*/;
            }

            reg_file.close();
        }

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

        }else if(choice==2){

            L.loginUserLogic();
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

                //stud.major();
                stud.updatereg();
            } else if(ctype=3){


            } else{

                cout<<"Kindly pick between 1-3 only.";
                custType();
            }
		}



int main(){
    
    Shopper S;
    Login L;
    int choice, ctype;
    
    //login & reg
        cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
        cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
                cin>>choice;
    

        if(choice==1){

            S.registerLogic();

        }else if(choice==2){

            L.loginUserLogic();
        }
    //login & reg end



}

/*Credits:

auto gen id = https://stackoverflow.com/questions/39098219/auto-generate-id-c/39099637


*/