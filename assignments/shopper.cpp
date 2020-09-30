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
//void custType();
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

        //default registration IO
        void reg_acc(){

            cout<<"Enter your name: ";
                cin.ignore();
                getline(cin, name);
            cout<<"Enter your full address: ";
                cin.ignore();
                getline(cin, address);
			//custType();

            cout<<"Enter a username (No space): ";
                //cin.ignore();
                //getline(cin, uname);
                cin>>uname;
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
                uname = getUsername();
                id = idgen();
                pwd = getPwd();
                //cpwd = getCpwd();
                

                cout<<endl;
                cout<<"Register is completed and the data is saved !"<<endl<<endl;

                //reg_file<<"|"<<setw(15)<<uname<<"|"<<setw(15)<<name<<"|"<<setw(15)<<address<<"|"<<setw(15)<<id<<""<<setw(15)<<pwd<<" |"<<endl;
                reg_file<<setw(15)<<uname<<setw(15)<<name<<setw(15)<<address<<setw(15)<<id<<setw(15)<<pwd<<endl;

            }

            reg_file.close();
        }

        
        virtual void displayProfile()=0;


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
                    //cin>>username;
                    getline(login_file, password);
                    
                    //cin>>password;

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

class Customer:public Shopper{

    private:
        
    
    public:

        //default contructor
        Customer(){


        }
        

        //pure virtual function for display user profile
        void displayProfile(){

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


        void displayProfile(){


        }

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

        void displayProfile(){

            
        }

};


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

    int itemid;
    string itemname;
    ifstream read_book_file;

    public:

        //default constructor
        Book(){

        }//finish output then move to display profile
        
        void itemDisplay(){

            read_book_file.open("owner-book-insert.txt");

            cout<<"Item ID"<<"Item Name"<<endl;
            cout<<"-------------------------------------------------"<<endl;

            while(read_book_file>>itemid, getline(read_book_file, itemname)){

                
                cout<<itemid<<itemname<<endl;
            }

        }

};

class Magazine:public ShopItem{

    private:

    int itemid;
    string itemname;
    ifstream read_mag_file;

    public:
        
        //default constructor
        /*Magazine(){


        }*/

        void itemDisplay(){

            read_mag_file.open("owner-magazine-insert.txt");

            while(read_mag_file>>itemid, getline(read_mag_file, itemname)){

                cout<<itemid/*<<setw(15)*/<<itemname<<endl;
            }


        }


};

class Movie:public ShopItem{

    private:

    int itemid;
    string itemname;
    ifstream read_mov_file;

    public:

        //default constructor
        Movie(){


        }

        void itemDisplay(){

            read_mov_file.open("owner-movie-insert.txt");

            while(read_mov_file>>itemid, getline(read_mov_file, itemname)){

                cout<<itemid<<itemname<<endl;
            }

        }


};

class ShoppingCart{
//no need PVF
    private:

    ofstream cart_file;
    string id, prod_name, author_name;
    float prod_price;
    int prod_units;


    public:

        void current_cart(){

            cart_file.open("cart ");

        }

        void history(){


        }


};


void custType(){

    int ctype;
            
            
            cout<<"Customer type: "<<endl;
			cout<<"1. Normal Customer (Non MMU)"<<endl;
			cout<<"2. MMU Student"<<endl;
			cout<<"3. MMU Staff"<<endl;
            cout<<"Select a customer type: "<<endl;
                cin>>ctype;
            
            if(ctype==1){
                
                Customer normal;

                Shopper *cust = &normal;
                    cust->registerLogic();
            } else if(ctype==2){

                MMUStudent student;

                Shopper *stud = &student;
                stud->registerLogic();

                student.updateregstud();
            } else if(ctype==3){

                MMUStaff staf;

                Shopper *staff = &staf;
                staff->registerLogic();

                staf.updateregstaff();
            } else{

                cout<<"Kindly pick between 1-3 only.";
                custType();
            }
}


//////////////////////////////////////////////////////////
//class l_menu/*:public ShopItem*/{
//menu after success login

    //public:
        void loginmenu(){

            int choice, prod_choice;
            //Book book;
            
            Book b;
            Magazine m;


            ShoppingCart scart;
            //Book book;


            cout<<"Main Menu"<<endl;
            cout<<"1. View Profile"<<endl;
            cout<<"2. View Shopping Cart"<<endl;
            cout<<"3. View Order History"<<endl;
            cout<<"4. View Product"<<endl;
                cin>>choice;


            switch(choice){

                case 1: 

                    break;

                case 2: 
                    scart.current_cart();
                    break;
                
                case 3:
                    scart.history();
                    break;

                case 4:
                    cout<<"Select type of product"<<endl;
                    cout<<"1. Book"<<endl;
                    cout<<"2. Magazine"<<endl;
                    cout<<"3. Movie"<<endl;
                        cin>>prod_choice;

                        /*switch(prod_choice){

                            case 1:
                                    ShopItem *book = &b;
                                    book->itemDisplay();
                                break;

                            case 2:
                                    ShopItem *mag = &m;
                                    mag->itemDisplay();
                                break;
                            
                            case 3:

                                break;


                        }*/

                        if(prod_choice==1){

                            ShopItem *book = &b;
                                    book->itemDisplay();
                        }else if(prod_choice==2){

                                    ShopItem *mag = &m;
                                    mag->itemDisplay();
                        }

                    break;

            }


        }



int main(){
    
    //Shopper S;
    Login L;
    Customer normal;
    MMUStudent student;
    MMUStaff staff;
    

    int choice, ctype;
    
    //login & reg
        cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
        cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
                cin>>choice;
    

        if(choice==1){

            custType();
            

        }else if(choice==2){

            L.loginUserLogic();
            loginmenu();
            //stud.shopperprofile();
            

            


            
            //S.shopperprofile();
        }
    
    //login & reg end



}

/*Credits:

auto gen id = https://stackoverflow.com/questions/39098219/auto-generate-id-c/39099637


*/