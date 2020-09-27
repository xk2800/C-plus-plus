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

/**DONE: Register, Login
 * 
 * TODO: virtual function + view profile(user),         shopping cart 
 * 
 * 
 * */


void loginmenu();
void custType();
class Shopper{

    protected:
        //string major;
        string uname, pwd, cpwd, address, name ;
		int ctype, id;

    public:
        //virtual void shopperprofile() = 0;

        //default contructor
        Shopper(){


        }

        //pure virtual function for profile
        //virtual void shopperprofile() /*= 0*/;

        //default registration IO
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
            auto_genID();
            //test();

                //validate password & confirm password input made by user
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
            
            //structure to auto generate user ID
            struct id_Gen
            {
                id_Gen()
                : _id (0)
                {
                    std::ifstream ifs("_id.txt"); //_id.txt file to save current running number
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
                void auto_genID(){
                id_Gen idGen;

                cout<<"Your id is: "<<idGen()<<endl;

                //return 0;
                }

        //}

        //Logic(insert into txt file) for registration part
        void registerLogic(){

            ofstream reg_file;
            id_Gen idgen;

            //open file in append mode to update existing database of user info
            reg_file.open("shopper-details.txt", std::ios_base::app);

            if(!reg_file){

                cout<<"File is not found!"<<endl;
            } else{  //if file found, then continue

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

        //pure virtual function for shopperprofile

        /*void shopperprofile(){

            ifstream file;

            file.open("shopper-details.txt");

            if(file.is_open()){

                //cout<<name<<endl;

                while(getline(file, name)){
                    
                    cout<<name<<endl;
                }

                file.close();
            } else{

                cout<<"File not found!";
            }

        }*/
        
        //virtual void shopperprofile() = 0;
        //virtual void shopperprofile() = 0;
        //friend void mine();

};
//#endif
class test:public Shopper{


    public:
        //virtual void shopperprofile() = 0;

};

class Login{

    private:
        string id, pwd;
        ifstream login_file;

    public:

        //default contructor
        Login(){


        }

        int openingmsg(){

            cout<<"===================================="<<endl<<"\t\tLOGIN"<<endl<<"===================================="<<endl;
        }

        int accLogin(){

            //IO user need to enter to login system
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

        //validate user input with txt file
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


class Customer:public Shopper{

    private:
        
    
    public:

        //default contructor
        Customer(){


        }

        void shopperprofile(){

            ifstream file;

            file.open("shopper-details.txt");

            if(file.is_open()){

                //cout<<name<<endl;

                while(getline(file, name)){
                    
                    cout<<name<<endl;
                }

                file.close();
            } else{

                cout<<"File not found!";
            }

        }

        //friend int main();

};

class MMUStudent:public Shopper{
    
    private:
        
        string maj;
    
    public: 

        //default contructor
        MMUStudent(){


        }

        void major(){

            cout<<"Enter your major: ";
                cin.ignore();
                getline(cin, maj);

        }

        string maje(){

            return maj;
        }

        void updateregstud(){

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


        void shopperprofile(){

            ifstream file;

            file.open("shopper-details.txt");

            if(file.is_open()){

                //cout<<name<<endl;

                while(getline(file, name)){
                    
                    cout<<name<<endl;
                }

                file.close();
            } else{

                cout<<"File not found!";
            }

        }
        //friend int main();

};

class profile:public Shopper{

    private:

    public:

     /*void shopperprofile(){

            ifstream file;

            file.open("shopper-details.txt");

            if(file.is_open()){

                //cout<<name<<endl;

                while(getline(file, name)){
                    
                    cout<<"tester for virtual function"<<endl;
                }

                file.close();
            } else{

                cout<<"File not found!";
            }

        }

        friend int main();*/
};

class MMUStaff:public Shopper{

    private:
        
        string dept;
    
    public: 

        void shopperprofile(){

            ifstream file;

            file.open("shopper-details.txt");

            if(file.is_open()){

                //cout<<name<<endl;

                while(getline(file, name)){
                    
                    cout<<name<<endl;
                }

                file.close();
            } else{

                cout<<"File not found!";
            }

        }

        //default contructor
        MMUStaff(){


        }

        void department(){

            cout<<"Enter the name of your department : ";
                cin.ignore();
                getline(cin, dept);
        }

        string dep(){

            return dept;
        }

        void updateregstaff(){

            ofstream reg_file;

            reg_file.open("shopper-details.txt", std::ios_base::app);

            if(!reg_file){

                cout<<"File is not found"<<endl;
            } else{

                department();
                dept = dep();

                reg_file<<dept;
            }

            reg_file.close();
        }

        friend int main();

};

//class Mainmenu:public Shopper{
/*void mainmenu(){
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

    
}*/
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
                stud.updateregstud();
            } else if(ctype==3){

                MMUStaff staff;

                staff.updateregstaff();
            } else{

                cout<<"Kindly pick between 1-3 only.";
                custType();
            }
		}

///////////////////////////////////////////////////////////////////////////////////////

class ShopItem{

    protected:


    public:

        //default constructor
        ShopItem(){


        }

        virtual void itemDisplay()=0;



};

class Book:public ShopItem{

    private:


    public:

        //default constructor
        Book(){


        }


};

class Magazine:public ShopItem{

    private:


    public:
        
        //default constructor
        Magazine(){


        }

};

class Movie:public ShopItem{

    private:


    public:

        //default constructor
        Movie(){


        }



};

class ShoppingCart{

    private:

    ofstream cart_file;
    string id, prod_name, author_name;
    float prod_price;
    int prod_units;


    public:

        void cart(){

            cart_file.open("")

        }


};



//////////////////////////////////////////////////////////
//menu after success login
void loginmenu(){

    cout<<"Main Menu"<<endl;
    cout<<"1. View Profile"<<endl;
    cout<<"2. View Shopping Cart"<<endl;


}

void mine(){

    
}

int main(){
    
    //friend int main();
    Shopper S;
    Login L;
    MMUStudent stud;
    int choice, ctype;
    
    //login & reg
        cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
        cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
                cin>>choice;
    

        if(choice==1){

            S.registerLogic();

        }else if(choice==2){

            L.loginUserLogic();
            //loginmenu();
            //stud.shopperprofile();
            
            //S.shopperprofile();
        }
    
    //login & reg end



}

/*Credits:

auto gen id = https://stackoverflow.com/questions/39098219/auto-generate-id-c/39099637


*/