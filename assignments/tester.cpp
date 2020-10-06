#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

//set your file location here
static string location = "D://";

class Shopper{

    protected:
      string username, password, cpassword, name, address, del, un, pw;
      int id, offset_name, offset_pwd;
      
      //ifstream del_profile;

    public:

      Shopper(){


      }

      //reg default for all class
      void account_reg(){

          cout<<"Enter your name: ";
            cin.ignore();
            getline(cin, name);
        
        cout<<"Enter you full address: ";
            cin.ignore();
            getline(cin, address);

        cout<<"Enter a username: ";
            cin>>username;

            ofstream reg_file;
            reg_file.open(location + username +"-details.txt", std::ios_base::app);
        
        cout<<"Enter a password: ";
            cin>>password;
        
        cout<<"Re-confirm your password: ";
            cin>>cpassword;

            auto_genID();

                while(password != cpassword){

                    cout<<"Make sure both passwords are same. Kindly check again and re-enter."<<endl;
                    
                    cout<<"Enter a password: ";
                        cin>>password;
                    
                    cout<<"Re-confirm your password: ";
                        cin>>cpassword;
                }

            reg_file.close();
      }

      string getName(){

          return name;
      }

      string getAddress(){

          return address;
      }

      string getUsername(){

          return username;
      }

      string getPassword(){

          return password;
      }

      string getConfirmPassword(){

          return cpassword;
      }

      //auto gen ID
      //structure to create auto generate user ID
        struct id_Gen
        {
            id_Gen()
            : _id (0){

                std::ifstream ifs("_id.txt"); //_id.txt file to save current running number
                ifs>>_id;
            }

            ~id_Gen(){

                std::ofstream ofs("_id.txt", std::ios_base::out | std::ios_base::trunc);
                ofs<<_id;
            }

            int operator()(){

                return _id++;
            }

            int _id;
        };

        void auto_genID(){

            id_Gen idGen;

            cout<<"Your id is: "<<idGen()<<endl;
        }

        void register_logic(){

            ofstream reg_file;
            ofstream cred_file;
            id_Gen idgen;

            //open file in appending mode to update existing txt file for user info
            username    = getUsername();
            //cout<<"TEST UNAME:"<<username;
            //reg_file.open(location+ username"-details.txt", std::ios_base::app);
            //cred_file.open("D://" + username + "cred-details.txt", std::ios_base::app);

            if(reg_file.fail()){
                cout<<"File cannot be found"<<endl;     exit(0);
            }
            else{  //continue if file found/has/can be created

                cout<<"===================================="<<endl<<"\t\tREGISTER"<<endl<<"===================================="<<endl;

                account_reg();

                name        = getName();
                address     = getAddress();
                username    = getUsername();
                id          = idgen();
                password    = getPassword();

                cout<<endl;

                reg_file.open(location + username +"-details.txt", std::ios_base::app);
                cred_file.open(location + username + "-cred-details.txt", std::ios_base::app);

                cout<<"TEST UNAME:"<<username;

                reg_file<<username<<"\t"/*<<password<<setw(10)*/<<name<<"\t"<<address<<"\t\t"<<id<<setw(10);
                cred_file<<username<<endl<<password<<endl<<endl;
                //cred_file<<username<<setw(10)<<password<<endl<<endl;
                //reg_file<<username<<"\t\t\t"<<password<<"\t\t\t"<<name<<"\t\t\t"<<address<<"\t\t\t"<<id;
                //reg_file<<username<<setw(10)/*<<password<<setw(10)*/<<name<<setw(10)<<address<<setw(10)<<id<<setw(10);

            }

            reg_file.close();
        }

        void delete_account(){ 

            ifstream del_profile;
            string user;

            cout<<"Would you like to delete all your account information? [Y/N]";   cin.ignore();   getline(cin, del);

            if(del=="N" || del=="n"){
                cout<<"You said No, you will be brought back to main menu";
            } else{
                
                cout<<"Reconfirm your username : "; cin.ignore();   getline(cin, user);
                cout<<"Verify your password : "; cin.ignore();   getline(cin, password);

                cout<<"test:"<<user;
                del_profile.open(location + user + "-cred-details.txt");

                    if(del_profile.fail()){
                        cout<<"File not found"; exit(0);
                    } else{
                        
                        //verify_account_logic();
                        ifstream check(location + username + "-cred-details.txt");

                        getline(check, un);
                        getline(check, pw);

                        if((offset_name = username.find(un,0))!=string::npos && (offset_pwd = password.find(pw, 0))!=string::npos){
                            if(un != username && pw != password){

                                //return true;
                            } else{

                                //return false;
                            }
                        }
                        //verify_account();
                    }
            }
        }

        /*bool verify_account_logic(){

            
            ifstream check(location + username + "-cred-details.txt");

            getline(check, un);
            getline(check, pw);

            if((offset_name = username.find(un,0))!=string::npos && (offset_pwd = password.find(pw, 0))!=string::npos){
                if(un != username && pw != password){

                    return true;
                } else{

                    return false;
                }
            }
        }*/

        /*int verify_account(){

            //bool status = delete_account();

            if(status){

                cout<<"Login Fail"<<endl;
                system("PAUSE");
                return 0;
                
            }else{

                cout<<"Succesfully logged in!"<<endl;
                system("PAUSE");
                //after_login_menu();
                delete_account();

                return 1;
            }
        }*/

        virtual void display_profile() = 0;

};

class Login{

    private: 
        string username, password;

    public:
        
        void opening_msg(){

            cout<<"===================================="<<endl<<"\t\tLOGIN"<<endl<<"===================================="<<endl;
        }

        void account_login(){

            cout<<"Enter your username: ";
                cin.ignore();
                getline(cin, username);
            
            cout<<"Enter your password: ";
                cin>>password;
        }

        string getUsername(){

            return username;
        }

        string getPassword(){

            return password;
        }

        bool login_logic(){

            string username, password, un, pw;
            int offset_name, offset_pwd;

            cout<<"Enter username: ";
                cin>>username;
            cout<<"Enter password: ";
                cin>>password;

            ifstream read(location + username +"-cred-details.txt");
            //read.open("cred-details.txt");
            getline(read, un);
            getline(read, pw);

            if((offset_name = username.find(un,0))!=string::npos && (offset_pwd = password.find(pw, 0))!=string::npos){ //line.find(var);
                if(un != username && pw != password){

                    return true;
                } else{

                    return false;
                }
            }
            read.close();
        }



};

class Customer:public Shopper{

    private:

    string usernam;

    public:

    Customer(){


    }

    void update_cust_reg(){

        cout<<endl<<"Register is completed and the data is saved"<<endl<<endl;
    }

    //PVF to display user profile
    void display_profile(){

        string usernam, un, usr;
        int uname;

        ifstream read_profile;

        cout<<"Confirm username: "; cin.ignore();   getline(cin, username);

        read_profile.open(location + username + "-details.txt");

        if(read_profile.fail()){
            cout<<"File not found"; exit(0);
        } else{
            
            cout<<"Username\tName\tAddress\t\tID"<<endl;
            cout<<"-----------------------------------------"<<endl;
            while(getline(read_profile, username)){

                cout<<username<<endl;

            }
        }
    }

};

class MMUStudent:public Shopper{

    private:
    string maj,usernam;


    public:

    MMUStudent(){


    }

    //request student to enter major
    void student_major(){

        cout<<"Enter your major: "; 
            cin.ignore(); getline(cin, maj);
    }

    string stud_maje(){
        return maj;
    }


    //specific to add major into text file
    void update_stud_reg(){

        ofstream reg_file;

        //reg_file.open("test-details.txt", std::ios_base::app);
        reg_file.open(location + username +"-details.txt", std::ios_base::app);
        cout<<"STUD UNAME TEST: "<<username;
        if(!reg_file){
            cout<<"File is not found!"<<endl; exit(0);
        } else{

            student_major();
            maj = stud_maje();

            reg_file<<setw(10)<<maj<<endl;


        }
        reg_file.close();
    }

    //PVF to display user profile
    void display_profile(){

        string usernam, un, usr;
        int uname;

        ifstream read_profile;

        cout<<"Confirm username: "; cin.ignore();   getline(cin, username);

        read_profile.open(location + username + "-details.txt");

        if(read_profile.fail()){
            cout<<"File not found"; exit(0);
        } else{
            
            cout<<"Username\tName\tAddress\t\tID\tMajor"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            while(getline(read_profile, username)){

                cout<<username<<endl;

            }
        }
        read_profile.close();
        delete_account();
    }

};


class MMUStaff:public Shopper{

    private:

    string department, usernam;

    public:

    //default constructor
    MMUStaff(){


    }

    void staff_department(){

        cout<<"Enter the name of your department: ";
            cin.ignore();   getline(cin,department);
    }

    string staff_dept(){
        return department;
    }

    void update_staff_reg(){

        ofstream reg_file;

        reg_file.open("test-details.txt"/*, std::ios_base::app*/);

        if(!reg_file){
            cout<<"File is not found"<<endl; exit(0);
        } else{
            
            staff_department();
            department = staff_dept();

            reg_file<<setw(10)<<department;

            cout<<"Register is completed and data is saved !"<<endl<<endl;

        }
        reg_file.close();
    }

    //PVF to display user profile
    void display_profile(){

        string usernam, un, usr;
        int uname;

        ifstream read_profile;

        cout<<"Confirm username: "; cin.ignore();   getline(cin, username);

        read_profile.open(location + username + "-details.txt");

        if(read_profile.fail()){
            cout<<"File not found"; exit(0);
        } else{
            
            cout<<"Username\tName\tAddress\t\tID\tDepartment"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            while(getline(read_profile, username)){

                cout<<username<<endl;

            }
        }
    }

};



//////////////////////////////////////////////////////////////////////////
class ShoppingCart{

    protected:

    //used in other classes
    ofstream cart_file, add_to_cart;
    ifstream book_item_file, magazine_item_file, movie_item_file;
    string username, itemid, id, output;

    string line, gcl;
    bool validate;
    size_t pos;

    //used on in this class
    

    public:


};

class SCbook:public ShoppingCart{

    private:

    //int offset;
    string line, gcl;
    bool validate;
    size_t pos;

    public:

        void book_cart(){

            if(!cart_file){
                    cout<<"File cannot be found"<<endl;     exit(0);
                } else{

                    cout<<"Enter product ID: ";  cin.ignore();  getline(cin,itemid);

                    book_item_file.open("owner-book-insert.txt");

                    if(!book_item_file){
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(book_item_file.is_open()){
                            while(getline(book_item_file, line)) {

                                pos = line.find(itemid);

                                if(pos != string::npos) {

                                    if(pos < 3){

                                        output = line;
                                    }
                                }
                            }
                            cout << output << endl;
                        }

                        if(add_to_cart.fail()){
                            cout<<"File cannot be found"<<endl; exit(0);
                        }else{
                            //cout<<
                        }
                    }
                }
            book_item_file.close();
        }

        // void view(){
        //     Book b;
        //     b.item_Display();
        // }

};

class SCmagazine:public ShoppingCart{

    private:

    public:

        void magazine_cart(){

            if(!cart_file){
                cout<<"File cannot be found"<<endl; exit(0);
            } else{

                    cout<<"Enter product ID: "; cin>>itemid;

                    magazine_item_file.open("owner-movie-insert.txt");
                    
                    if(!magazine_item_file){
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(magazine_item_file.is_open()){
                            while(getline(magazine_item_file, line)) {

                                pos = line.find(itemid);

                                if(pos != string::npos) {

                                    if(pos < 3){

                                        output = line;
                                    }
                                }
                            }
                            cout << output << endl;
                        }
                    }
            }
            magazine_item_file.close();
        }

};
class SCmovie:public ShoppingCart{

    private:

    //int offset;
    //string line, itemname;
    string line, gcl;
    bool validate;
    size_t pos;

    public:

        void movie_cart(){

            if(!cart_file){
                    cout<<"File cannot be found"<<endl;     exit(0);
                } else{

                    cout<<"Enter product ID: "; cin>>itemid;

                    movie_item_file.open("owner-movie-insert.txt");
                    
                    if(!magazine_item_file){
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(movie_item_file.is_open()){
                            while(getline(movie_item_file, line)) {

                                pos = line.find(itemid);

                                if(pos != string::npos) {

                                    if(pos < 3){

                                        output = line;
                                    }
                                }
                            }
                            cout << output << endl;
                        }
                    }
                }
            movie_item_file.close();
        }
};

class CurrentCart/*:public ShoppingCart*/{

    private:
    SCbook scb;
    SCmagazine scmag;
    SCmovie scmov;
    //Book b;

    string username, itemid, itemname, cardnumber, agree;
    int prod_selection;

    ofstream cart_file;

    public:

        void current_cart(){

            cout<<"Type of product:"<<endl<<"1. Book \t 2.Magazine \t 3. Movie"<<endl;
            cout<<"Re-confirm your type of product: ";  cin>>prod_selection;
            
            cout<<"Enter username: ";   cin.ignore();   getline(cin, username);
            
            cart_file.open(username + "-cart.txt");
                
                switch(prod_selection){

                    case 1:
                        scb.book_cart();
                        //scb.view();
                        //b.item_Display();
                    break;

                    case 2:
                        scmag.magazine_cart();
                    break;

                    case 3:
                        scmov.movie_cart();
                    break;

                }
                

            cart_file.close();

            // return 1;
                
        }

        void current_to_history(){ //take current file and rename

            ifstream check;
            check.open(username + "-cart.txt");

            rename;
        }


        void view_cart(){

            cout<<"Reconfirm your username: ";  cin.ignore();   getline(cin, username);

            cout<<"USERNAME for view_cart:"<<username;

            ifstream read;
            read.open(username + "-cart.txt");

            while(!read.eof()){
                while(read>>itemid, getline(read, itemname)){
                    cout<<itemid<<itemname<<endl;
                }
            }
            read.close();
        }

        void order_history(){

            cout<<"Reconfirm your username: ";  cin.ignore();   getline(cin, username);

            cout<<"USERNAME for order_history: "<<username;

            ifstream take;
            take.open(username + "-cart-history.txt");

            while(!take.eof()){
                while(take>>itemid, getline(take, itemname)){
                    cout<<itemid<<itemname<<endl;
                }
            }
            take.close();
        }

        void payment(){
            
            cout<<"Would you like to make payment?";    cin.ignore();   getline(cin, agree);
            

            do{
            cout<<"Enter your card number: ";   cin.ignore();   getline(cin, cardnumber);

            }while(cardnumber.size()==10);

            

        }
};
////////////////////////////////////////////////////////////////
class ShopItem{

    protected:

    int itemid;
    string itemname, add;

    CurrentCart cc;

    public:

    //default constructor
    ShopItem(){

    }

    virtual void item_Display() = 0;
};

class Book:public ShopItem{

    private:

    ifstream read_book_file;

    //CurrentCart cc;
    SCbook SCb;

    public:

        //default constructor
        Book(){

        }

    void item_Display(){

        read_book_file.open("owner-book-insert.txt");
        
        cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Author"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;

        while(!read_book_file.eof()){
            while(read_book_file>>itemid, getline(read_book_file, itemname)){

                
                cout<<itemid<<itemname<<endl;
            }
        }
        //PLEASE STOP LOOPING PLEASE
        read_book_file.close();

            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; cin>>add;
            if(add=="Y" || add=="y"){
                //SCb.book_cart();
                cout<<"HELLO WORLD"<<endl;
                cc.current_cart();
                //int returnValue = sc.current_cart(); //goes to 584
                /*if(returnValue == 1) {

                    cout << "sss" << endl;

                }*/
            } //else{


          //  }

        }

};

class Magazine:public ShopItem{

    private:

    ifstream read_mag_file;

    public:

    //default constructor
    Magazine(){

    }

    void item_Display(){

            read_mag_file.open("owner-magazine-insert.txt");

            cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Year"<<setw(15)<<"Month"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            while(read_mag_file>>itemid, getline(read_mag_file, itemname)){

                cout<<itemid/*<<setw(15)*/<<itemname<<endl;
            }

            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; cin>>add;
            if(add=="Y" || add=="y"){
                cc.current_cart();
            } else{


            }

        }

};

class Movie:public ShopItem{

    private:

    ifstream read_mov_file;
    SCmovie SCm;

    public:

    //default constructor
    Movie(){

    }

    void item_Display(){
            
            cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Actor"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            read_mov_file.open("owner-movie-insert.txt");

            while(read_mov_file>>itemid, getline(read_mov_file, itemname)){

                cout<<itemid<<itemname<<endl;
            }

            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; cin>>add;
            if(add=="Y" || add=="y"){
                SCm.movie_cart();
            } else{


            }

        }
};



//////////////////////////////////////////////////////////////////////////
void cust_Type(){   //for register part, user pick what type of customer (profile) they are

    int custtype;
    
    //Shopper s;
    Customer cust;
    MMUStudent stud;
    MMUStaff staf;

    cout<<"Customer type: "<<endl;
    cout<<"1. Normal Customer (Non MMU)"<<endl;
    cout<<"2. MMU Student"<<endl;
    cout<<"3. MMU Staff"<<endl;
    cout<<"Select a customer type: ";
        cin>>custtype;

    if(custtype==1){

        Shopper *normal = &cust;
        normal->register_logic();

        cust.update_cust_reg();

    }else if(custtype==2){

        //s.register_logic();
        Shopper *student = &stud;
        student->register_logic();

        stud.update_stud_reg();


    }else if(custtype==3){

        Shopper *staff = &staf;
        staff->register_logic();

        staf.update_staff_reg();

    }else{

        cout<<"Kindly pick between 1-3 only.";
        cust_Type();
    }

}

///class AfterLoginMenu{
void after_login_menu(){    //diplayed after account authenication successful from login section
    //private:
    int selection, prod_selection, uname, type;
    string confirm, search, username, un;

    ifstream read("test-details.txt");

    Customer cust;
    MMUStudent stud;
    MMUStaff staf;

    Book b;
    Magazine mag;
    Movie mv;
    ShoppingCart sc;
    CurrentCart cc;

    //public:
    //menu start
    cout<<"Main Menu"<<endl;
    cout<<"1. View Profile"<<endl;
    cout<<"2. View Shopping Cart"<<endl;
    cout<<"3. View Order History"<<endl;
    cout<<"4. View Product and Purchase Product"<<endl;
    cout<<"5. Make payment for Products"<<endl;
    cout<<"0. Logout"<<endl;
        cin>>selection;

    switch(selection){

        case 1: //view profile

        cout<<"Are you sure? [Y/N]: ";
            cin>>confirm;

            if(confirm=="N" && confirm=="n"){
                after_login_menu();
            } else{

                //cout<<"Enter your username: "; cin>>username;

                /*getline(read, un);
                while((uname = username.find(un,0))!=string::npos){*/

                cout<<"Are you 1. Normal Customer \t 2. MMU Student \t 3. MMU Staff"<<endl<<"Enter your choice: ";  
                cin>>type;

                    

                        if(type==1){ 
                            Customer *customer = &cust;
                            customer->display_profile();

                        }else if(type==2){

                            MMUStudent *student = &stud;
                            student->display_profile();
                        }else if(type==3){

                            MMUStaff *staff = &staf;
                            staff->display_profile();
                        }else{
                            cout<<"Input error";
                        }


                    

            }

        break;

        case 2: //view shopping cart
            cc.view_cart();
        break;

        case 3: //view order history
            cc.order_history();
        break;

        case 4: //view product

            cout<<"Select type of product"<<endl;
            cout<<"1. Book"<<endl;
            cout<<"2. Magazine"<<endl;
            cout<<"3. Movie"<<endl;
                cin>>prod_selection;

            if(prod_selection==1){

                ShopItem *book = &b;
                book->item_Display(); //goes directly to book class

            } else if(prod_selection==2){

                ShopItem *magazine = &mag;
                magazine->item_Display();   //goes directly to mag class
                
            } else if(prod_selection==3){

                ShopItem *movie = &mv;
                movie->item_Display();  //goes directly to mov class
            }
            
        break;

        case 5: //shopper make payment
            cc.payment();

        case 0: //logout from system
            cout<<"Logged out!"<<endl;
            exit(0);
        break;

        default:
            cout<<"Wrong option, select again"<<endl<<endl;
            after_login_menu();
        break;

    }

}


int main(){

    int choice;

    Login L;
    //Shopper S;

    //login & reg
        cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
        cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
                cin>>choice;

        
        if(choice==1){

            cust_Type();

        }else if(choice==2){

            bool status = L.login_logic();

            if(status){

                cout<<"Login Fail"<<endl;
                system("PAUSE");
                return 0;
            
            }else{

                cout<<"Succesfully logged in!"<<endl;
                system("PAUSE");
                after_login_menu();

                return 1;
            }

        }


}