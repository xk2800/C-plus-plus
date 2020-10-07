#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

//******note that all shopping item files are not linked together as they are in seperate zip file from this source code, 
//shopping items text files are based from shop owner program during this program development.*********

//set your text file location here
static string location = "D://";    //all text files created from this program will be saved in this location, kindly check text files in this path

class Shopper{  //shopper class

    protected:
    //declaration related and used to inherited classes
      string username, password, cpassword, name, address, del, un, pw, line, savedline;
      string credfile = username + "-cred-details.txt";
      string infofile = username + "-details.txt";
      int id, offset_name, offset_pwd;
      size_t pos;
      

    public:

    //default constructor
      Shopper(){

      }

      //registration I/O, default for all class
      void account_reg(){

          cout<<"Enter your name: ";
            cin.ignore();
            getline(cin, name);
        
        cout<<"Enter you full address: ";
            //cin.ignore();
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

                //validate if both password input are same or not
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

        //function used to call and outpur auto gen value
        void auto_genID(){

            id_Gen idGen;

            cout<<"Your id is: "<<idGen()<<endl;
        }

        //registration logic, input data from user into text file
        void register_logic(){

            ofstream reg_file;
            ofstream cred_file;
            id_Gen idgen;

            username    = getUsername();

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

                //open file in appending mode to update existing txt file for user info
                reg_file.open(location + username +"-details.txt", std::ios_base::app); //full details of shopper here
                cred_file.open(location + username + "-cred-details.txt", std::ios_base::app);  //login credential of shopper here

                reg_file<<username<<"\t"<<name<<"\t"<<address<<"\t\t"<<id<<setw(10);
                cred_file<<username<<endl<<password<<endl<<endl;
                
            }

            reg_file.close();
        }

        //deregister shopper account
        void delete_account(){ 

            ifstream del_profile;
            string user;

            cout<<"Would you like to delete all your account information? [Y/N]";   getline(cin, del);

            if(del=="N" || del=="n"){   //program terminate as shopper said No
                cout<<"You said No, program will exit, thank you.";
                exit(0);
            } else{
                
                cout<<"Reconfirm your username : "; cin.ignore();   getline(cin, user);
                cout<<"Verify your password : "; cin.ignore();   getline(cin, password);
                
                //convert string element to const char pointer for function of removing and renaming file
                const char *convertfilename = infofile.c_str();
                const char *convertfilename1 = credfile.c_str();

                ifstream delete_file;
                delete_file.open(credfile, ios::in);

                while(getline(delete_file, line)){
                    
                    pos = line.find(user);

                    if(pos != string::npos){    //check shopper username based on input
                        
                        if(pos<10){
                            savedline = line;
                        }else{
                            delete_file.close();
                        }
                    }
                }
                delete_file.close();

                if(savedline==""){
                    cout<<"Item not Found"<<endl;
                }else{

                    line="";

                    ifstream input_file;
                    input_file.open(credfile, ios::in);

                    ofstream temp;
                    temp.open("temp-file.txt"); //create temp file to dump info into

                    while(getline(input_file, line)){
                        
                        if(line.compare(savedline)!=0){
                            temp<<line<<endl;
                        }
                    }
                    input_file.close();
                    temp.close();

                    if(remove(convertfilename1)==0){    //rename and remove temperory file to new name
                        cout<<"Original file has been removed"<<endl;

                        if(rename("temp.txt", convertfilename1)==0){
                            cout<<"Temp file renamed to original file"<<endl;
                        }else{
                            cout<<"File renamed";
                        }
                    }else{
                        cout<<"Fail to removed";
                    }
                }

                line=""; savedline="";

                ifstream delete_info_file;
                delete_info_file.open(infofile, ios::in);

                while(getline(delete_info_file, line)){
                    
                    pos = line.find(user);

                    if(pos != string::npos){    //check shopper username based on input

                        if(pos<10){
                            savedline = line;
                        }else{
                            delete_info_file.close();
                        }
                    }
                }

                delete_info_file.close();

                if(savedline==""){
                    cout<<"Item not found"<<endl;
                }else{
                    line="";

                    ifstream input_file;
                    input_file.open(infofile, ios::in);

                    ofstream temp;
                    temp.open("temp.txt");      //create temp file to dump info into

                        while(getline(input_file, line)){

                            if(line.compare(savedline)!=0){     
                                temp<<line<<endl;
                            }
                        }

                    input_file.close();
                    temp.close();

                    if(remove(convertfilename)==0){     //rename and remove temperory file to new name

                        cout<<"Original File Removed"<<endl;

                            if(rename("temp.txt", convertfilename)==0){
                                cout<<"Temp file renamed to original file"<<endl;
                            }else{
                                cout<<"Renamed failed";
                            }
                    }else{
                        cout<<"Fail to remove";
                    }
                }
            }
        }

        //pure virtual function for displaying profile
        virtual void display_profile() = 0;

};

class Login{    //login class for all code related to login is located in here

    private: 
        string username, password;

    public:
        
        void opening_msg(){

            cout<<"===================================="<<endl<<"\t\tLOGIN"<<endl<<"===================================="<<endl;
        }

        //login logic, based on boolean to validate if shopper input and crendtials in file true or false
        bool login_logic(){

            string username, password, un, pw;
            int offset_name, offset_pwd;

            //login IO
            cout<<"Enter username: ";
                cin>>username;
            cout<<"Enter password: ";
                cin>>password;

            ifstream read(location + username +"-cred-details.txt");

            getline(read, un);
            getline(read, pw);
            
            //password validation check, true/false value sent to int main() for validation
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

class Customer:public Shopper{  //customer class

    private:

    string usernam;

    public:

    //default construtor
    Customer(){

    }

    //message for after success registration
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

class MMUStudent:public Shopper{    //MMUStudent class

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

        reg_file.open(location + username +"-details.txt", std::ios_base::app);     //open file in append mode to add more info

        if(reg_file.fail()){
            cout<<"File is not found!"<<endl; exit(0);
        } else{

            student_major();
            maj = stud_maje();

            reg_file<<setw(10)<<maj<<endl;

            cout<<endl<<"Register is completed and the data is saved"<<endl<<endl;

        }
        reg_file.close();
    }

    //Pure Virtual Funection to display user profile
    void display_profile(){

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


class MMUStaff:public Shopper{  //MMUStaff class

    private:

    string department, usernam;

    public:

    //default constructor
    MMUStaff(){

    }

    //request staff to enter department
    void staff_department(){

        cout<<"Enter the name of your department: ";
            cin.ignore();   getline(cin,department);
    }

    string staff_dept(){
        return department;
    }

    //specific to add department into text file
    void update_staff_reg(){

        ofstream reg_file;

        reg_file.open("test-details.txt", std::ios_base::app);  //open file in append mode to add more info

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

    //Pure Virtual Funection to display user profile
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
class ShoppingCart{ //ShoppingCart class

    protected:

    //used in other classes
    ofstream cart_file, add_to_cart;
    ifstream book_item_file, magazine_item_file, movie_item_file;

    string username, itemid, id, output, line;
    bool validate;
    size_t pos;
    int qty;    

    public:

    //add item to cart function
    void add_cart(){
        
        ofstream add_cart_file;

            if(add_cart_file.fail()){
                cout<<"Cart file cannot be found"<<endl; exit(0);
            }else{

                add_cart_file.open(location + username+"-current-cart.txt", std::ios_base::app);    //open file in append mode to add more info

                add_cart_file<<output<<"\t"<<qty<<endl;
                cout<<"Item has been added to cart"<<endl;

            }
        add_cart_file.close();
    }

    //modity item in cart function
    void modify_cart(){

        ofstream mod_file;

        ifstream read_mod_file;
        
        cout<<"Note: You can only change quantity of product."<<endl<<endl;
        cout<<"Confirm username: "; /*cin.ignore();*/   getline(cin, username);

        mod_file.open(location + username + "-current-cart.txt", std::ios_base::app);   //open file in append mode to add more info
        read_mod_file.open(location + username + "-current-cart.txt", std::ios_base::app);  //open file in append mode to add more info

        if(mod_file.fail()){
            cout<<"Cart file cannot be found"<<endl;    exit(0);
        }else{


            cout<<"Enter product ID: "; getline(cin, itemid);
            cout<<"Enter new quantity: ";   cin>>qty;

            if(read_mod_file.is_open()){
                while(getline(read_mod_file, line)){

                pos=line.find(itemid);

                    if(pos!=string::npos){  //check product based on user input with data in text file

                        if(pos<3){
                            output=line;
                        }
                    }
                }
//slight error here
                mod_file<<qty;
                cout<<"Product with ID: "<<itemid<<"'s, quantity has been changed to "<<qty<<endl;
            }

        }
    mod_file.close();
    read_mod_file.close();
    }

    //delete item from current shopping cart function
    void delete_item(){

        ofstream delete_file;
        ifstream read_delete_file;

        cout<<"Confirm your username: ";    /*cin.ignore();*/   getline(cin, username);

        delete_file.open(location + username + "-current-cart.txt", std::ios_base::app);    //open file in append mode to add more info
        read_delete_file.open(location + username + "-current-cart.txt");

        if(delete_file.fail() || read_delete_file.fail()){  //if file fail to open (using C++ build in library .fail()), error will appear
            cout<<"Error opening file to modify shopping cart items";
        }else{

            cout<<"Enter product ID: "; getline(cin, itemid);

            if(read_delete_file.is_open()){
                while(getline(read_delete_file, line)){

                    pos=line.find(itemid);

                        if(pos!=string::npos){

                            if(pos<3){  //check for product id based on user input
                                output=line;
                            }
                        }
                }
                output = "";
                cout<<"Product with ID: "<<itemid<<" has been deleted from shopping cart"<<endl;
            }
        }
        delete_file.close();
        read_delete_file.close();
    }


};

class SCbook:public ShoppingCart{   //class for book item usage of shopping cart, used to add items into shopping cart

    private:


    public:

        void book_cart(){

            if(cart_file.fail()){ //if file fail to open (using C++ build in library .fail()), error will appear
                    cout<<"File cannot be found"<<endl;     exit(0);
                } else{
                    
                    cout<<"Reconfirm username: ";   getline(cin, username);
                    cout<<"Enter product ID: ";  cin.ignore();  getline(cin,itemid);
                    cout<<"Enter quantity: ";   cin>>qty;

                    book_item_file.open("owner-book-insert.txt");

                    if(book_item_file.fail()){  //if file fail to open (using C++ build in library .fail()), error will appear
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(book_item_file.is_open()){
                            while(getline(book_item_file, line)){  //while loop to read whole text file

                                pos=line.find(itemid);

                                if(pos!=string::npos){

                                    if(pos<3){  //check for product id based on user input

                                        output=line;
                                    }
                                }
                            }
                            cout<<"This is the item selected."<<endl;
                            cout<<output<<endl;

                            add_cart();
                        }
                    }
                }
            book_item_file.close();
        }

        

};

class SCmagazine:public ShoppingCart{   //class for book item usage of shopping cart, used to add items into shopping cart

    private:


    public:

        void magazine_cart(){

            if(cart_file.fail()){   //if file fail to open (using C++ build in library .fail()), error will appear
                cout<<"File cannot be found"<<endl; exit(0);
            } else{

                    cout<<"Reconfirm username: ";   getline(cin, username);
                    cout<<"Enter product ID: "; cin>>itemid;
                    cout<<"Enter quantity: ";   cin>>qty;

                    magazine_item_file.open("owner-movie-insert.txt");
                    
                    if(magazine_item_file.fail()){  //if file fail to open (using C++ build in library .fail()), error will appear
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(magazine_item_file.is_open()){
                            while(getline(magazine_item_file, line)){  //while loop to read whole text file

                                pos=line.find(itemid);

                                if(pos!=string::npos){  

                                    if(pos<3){  //check for product id based on user input

                                        output=line;
                                    }
                                }
                            }
                            cout<<"This is the item selected."<<endl;
                            cout<<output<<endl;

                            add_cart();
                        }
                    }
            }
            magazine_item_file.close();
        }

};
class SCmovie:public ShoppingCart{  //class for book item usage of shopping cart, used to add items into shopping cart

    private:
    

    public:

        void movie_cart(){

            if(cart_file.fail()){   //if file fail to open (using C++ build in library .fail()), error will appear
                    cout<<"File cannot be found"<<endl;     exit(0);
                } else{
                    
                    cout<<"Reconfirm username: ";   cin.ignore();   getline(cin, username);
                    cout<<"Enter product ID: "; cin>>itemid;
                    cout<<"Enter quantity: ";   cin>>qty;

                    movie_item_file.open("owner-movie-insert.txt");
                    
                    if(magazine_item_file.fail()){  //if file fail to open (using C++ build in library .fail()), error will appear
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(movie_item_file.is_open()){
                            while(getline(movie_item_file, line)){  //while loop to read whole text file

                                pos=line.find(itemid);

                                if(pos!=string::npos){

                                    if(pos<3){  //check for product id based on user input

                                        output=line;
                                    }
                                }
                            }
                            cout<<"This is the item selected."<<endl;
                            cout<<output<<endl;
                            
                            add_cart();
                        }
                    }
                }
            movie_item_file.close();
        }
};

class CurrentCart{  //CurrentCart class

    private:
        SCbook scb;
        SCmagazine scmag;
        SCmovie scmov;

        string username, itemid, itemname, cardnumber, agree, info, confirmation;
        int prod_selection;

        ofstream cart_file;

    public:

        void current_cart(){    //used to divert user to correct ""-cart() function based on what type of product they choose

            //user have to re-enter product type for program to call correct function to enable program to open correct product file to read and then insert into shopping cart file
            cout<<"Type of product:"<<endl<<"1. Book \t 2.Magazine \t 3. Movie"<<endl;
            cout<<"Re-confirm your type of product: ";  cin>>prod_selection;
            
            cout<<"Enter username: ";   cin.ignore();   getline(cin, username);
            
            cart_file.open(username + "-cart.txt");
                
                //check user input and call item's shopping cart function based on user input(integer value)
                switch(prod_selection){

                    case 1:
                        scb.book_cart();
                    break;

                    case 2:
                        scmag.magazine_cart();
                    break;

                    case 3:
                        scmov.movie_cart();
                    break;

                }
                
            cart_file.close();
                
        }

        void current_to_history(){ //used to read current shopping cart and convert into shopping history file

            cout<<"Confirm your username: ";    /*cin.ignore();*/   getline(cin, username);
            
            ifstream check;
            check.open(location + username + "-current-cart.txt");

            ofstream write;
            write.open(location + username+"-cart-history.txt", std::ios_base::app);    //open file in append mode to add more info

            ofstream clean;
            //open file normally because want to remove all data inside the file, so doesn't matter if all data in the file goes missing, as long as the data is transfered into shopping cart history
            clean.open(location + username + "-current-cart.txt");

            if(check.fail()){   //if file fail to open (using C++ build in library .fail()), error will appear
                cout<<"Cart file not found";    exit(0);
            }else{

                while(!check.eof()){    //program will read the program untill it reach end of fill, using C++ library
                    while(getline(check, info)){

                        if(write.fail()){   //if file fail to open (using C++ build in library .fail()), error will appear
                            cout<<"Cart History file unable to open";   exit(0);
                        }else{

                            write<<info<<endl<<endl;
                            clean<<"";  //this will clear the file, leaving it blank
                        }
                    }
                }
            }

            check.close();
            write.close();

        }

        void history_cart_convert(){    //allow user to view shopping cart history

            cout<<"Confirm username again: ";   cin.ignore();   getline(cin, username);

            ifstream read;
            read.open(location + username+"-cart-history.txt"); //open file to read shopping cart history file

            if(read.fail()){    //if file fail to open (using C++ build in library .fail()), error will appear
                cout<<"No file found. Shopping history file error.";    exit(0);
            }else{
                cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price/unit"<<setw(15)<<" Other product info"<<endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;

                while(!read.eof()){     //program will read the program untill it reach end of fill, using C++ library
                    while(getline(read, info)){

                        cout<<info<<endl;
                    }
                }
            }
        }

        void view_cart_history(){   //another function for history_cart_convert() to make function call in other part of code become more relevent
            history_cart_convert();
        }


        void view_cart(){   //this function is to view current shopping cart, items that have not been paid

            cout<<"Reconfirm your username: ";  
            cin.ignore();   getline(cin, username);

            ifstream read;
            read.open(location + username + "-cart.txt");

            if(read.fail()){    //if file fail to open (using C++ build in library .fail()), error will appear
                cout<<"File not found. Shopping cart file error.";  
                exit(0);
            }else{
                while(!read.eof()){ //program will read the program untill it reach end of fill, using C++ library
                    while(read>>itemid, getline(read, itemname)){
                        cout<<itemid<<itemname<<endl;   //this will print all items in the shopping cart file
                    }
                }
            }
            read.close();
        }


        void delete_shopping_history(){     //function to delete shopping cart history at shopper request
            
            cout<<"You are about to delete your shopping history, "<<"are you sure you want to do that? [Y/N]"; cin.ignore();   getline(cin, confirmation);

            if(confirmation=="N" || confirmation=="n"){ //when user enter N/n
                cout<<"You replied No, program will terminate.";
                exit(0);

            }else if(confirmation=="Y" || confirmation=="y"){

                cout<<"Confirm your username: ";    getline(cin, username);

                ofstream rewrite;
                rewrite.open(location + username + "-cart-history.txt");    //file in normal mode to delete all records in the file

                rewrite<<"";    //this is to clear shopping cart history

                cout<<"Shopping History Records Deleted, program will terminate now.";  exit(0);
                
            }else{  //when wrong input
                cout<<"Invalid selection."<<endl<<"Try again."<<endl;
                
                delete_shopping_history();
            }
        }

        void payment(){ //function for payment, function gets called from main menu after login has been successfull
            
            cout<<"Would you like to make payment?[Y/N]";    cin.ignore();   getline(cin, agree);
            
            if(agree=="Y" || agree=="y"){   //user agree and payment starts
                cout<<"Enter your card number: ";   
                getline(cin, cardnumber);

                if(cardnumber.size()==10){
                    
                    cout<<"Payment Successful"<<endl<<"Thank you for your payment"<<endl;
                    
                    current_to_history();   //used to remove current shopping cart items to shopping cart history

                    exit(0);
                }else if(cardnumber.size()<=9 || cardnumber.size()>=11){    //if user did not enter exact 10 digits for payment card number, error will happen and user need to try again
                    
                    cout<<"Error, kindly check your payment card number and re-enter, thank you"<<endl;
                    payment();  //sent back to start of payment due to user error
                }
            }else if(agree=="N" || agree=="n"){ //user disagree to continue with payment
                cout<<"You entered No, program will terminate, thank you."; 
                exit(0);

            } else{ //user enter input besides Y or N
                cout<<"Invalid input, try again"<<endl<<endl;
                payment();  //sent back to start of payment due to user error
            }

        }
};
////////////////////////////////////////////////////////////////
class ShopItem{ //ShopItem class

    protected:

        int itemid;
        string itemname, add;

        CurrentCart cc;

    public:

        //default constructor
        ShopItem(){

        }

        //pure virtual function to display item for shopping cart
        virtual void item_Display() = 0;
};

class Book:public ShopItem{ //Book class

    private:

        ifstream read_book_file;

        SCbook SCb;

    public:

        //default constructor
        Book(){

        }

        //display item for shopper to view to make a purchase of the products listed
        void item_Display(){

        read_book_file.open("owner-book-insert.txt");   //open file to read information for display
        
        cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Author"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;

            while(!read_book_file.eof()){   //program will read the program untill it reach end of fill, using C++ library
                while(read_book_file>>itemid, getline(read_book_file, itemname)){

                    
                    cout<<itemid<<itemname<<endl;   //display items found in the file 
                }
            }

        read_book_file.close();
            
            //ask shopper if they want to continue to add item into shopping cart
            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; 
            cin>>add;

            if(add=="Y" || add=="y"){
 
                cc.current_cart();
                
            }else if(add=="N" || add=="n"){ //user disagree to continue with shopping cart

                cout<<"You entered No, program will terminate, thank you."; 
                exit(0);
            }else{ //user enter input besides Y or N

                cout<<"Invalid input, try again"<<endl<<endl;
                item_Display();  //sent back to start of view item due to user error
            }

        }

};

class Magazine:public ShopItem{ //Magazine class

    private:

        ifstream read_mag_file;

    public:

        //default constructor
        Magazine(){

        }

        //display item for shopper to view to make a purchase of the products listed
        void item_Display(){

            read_mag_file.open("owner-magazine-insert.txt");    //open file to read information for display

            cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Year"<<setw(15)<<"Month"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                
                while(!read_mag_file.eof()){   //program will read the program untill it reach end of fill, using C++ library
                    while(read_mag_file>>itemid, getline(read_mag_file, itemname)){
                        cout<<itemid<<itemname<<endl;   //display items found in the file
                    }
                }

            read_mag_file.close();

            //ask shopper if they want to continue to add item into shopping cart
            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; 
            cin>>add;

                if(add=="Y" || add=="y"){
                    cc.current_cart();
                } else if(add=="N" || add=="n"){ //user disagree to continue with shopping cart

                cout<<"You entered No, program will terminate, thank you."; 
                exit(0);

                }else{ //user enter input besides Y or N

                    cout<<"Invalid input, try again"<<endl<<endl;
                    item_Display();  //sent back to start of view item due to user error
                }

            }

};

class Movie:public ShopItem{    //Movie class

    private:

        ifstream read_mov_file;
        SCmovie SCm;

    public:

        //default constructor
        Movie(){

        }

        //display item for shopper to view to make a purchase of the products listed
        void item_Display(){
            
            cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Actor"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            read_mov_file.open("owner-movie-insert.txt");   

                while(!read_mov_file.eof()){   //program will read the program untill it reach end of fill, using C++ library
                    while(read_mov_file>>itemid, getline(read_mov_file, itemname)){

                        cout<<itemid<<itemname<<endl;   //display items found in the file
                    }
                }

            read_mov_file.close();

            //ask shopper if they want to continue to add item into shopping cart
            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; cin>>add;
            if(add=="Y" || add=="y"){
                SCm.movie_cart();

            }else if(add=="N" || add=="n"){ //user disagree to continue with shopping cart

                cout<<"You entered No, program will terminate, thank you."; 
                exit(0);
            }else{ //user enter input besides Y or N

                cout<<"Invalid input, try again"<<endl<<endl;
                item_Display();  //sent back to start of view item due to user error
            }

        }
};


//////////////////////////////////////////////////////////////////////////
void cust_Type(){   //for register part, user pick what type of customer (profile) they are

    int custtype;
    
    Customer cust;
    MMUStudent stud;
    MMUStaff staf;

    //menu appear during registration for customer to determine information needed to for their profile
    cout<<"Customer type: "<<endl;
    cout<<"1. Normal Customer (Non MMU)"<<endl;
    cout<<"2. MMU Student"<<endl;
    cout<<"3. MMU Staff"<<endl;
    cout<<"Select a customer type: ";
        cin>>custtype;

    if(custtype==1){
        
        //pure virtual function call
        Shopper *normal = &cust;
        normal->register_logic();

        //call function inside customer class to show register success message
        cust.update_cust_reg();

    }else if(custtype==2){
        
        //pure virtual function call
        Shopper *student = &stud;
        student->register_logic();

        //call function inside MMUStudent class to enter major & show register success message
        stud.update_stud_reg();


    }else if(custtype==3){

        //pure virtual function call
        Shopper *staff = &staf;
        staff->register_logic();

        //call function inside MMUStaff class to enter department & show register success message
        staf.update_staff_reg();

    }else{  //if user enter value other than 1,2,3

        cout<<"Kindly pick between 1-3 only.";
        cust_Type(); //shopper will be sent back to start of registration 
    }

}

void after_login_menu(){    //diplayed after account authenication successful from login section

    int selection, prod_selection, uname, type ,choice;
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


    //menu start
    cout<<"Main Menu"<<endl;
    cout<<"1. View Profile"<<endl;
    cout<<"2. View Shopping Cart and other shopping cart related actions"<<endl;
    cout<<"3. View Order and Delete History"<<endl;
    cout<<"4. View Product and Purchase Product"<<endl;
    cout<<"5. Make payment for Products"<<endl;
    cout<<"0. Logout"<<endl;
        cin>>selection;

    switch(selection){

        case 1: //view profile

            cout<<"Are you sure? [Y/N]: ";
            cin>>confirm;

            if(confirm=="N" && confirm=="n"){
                after_login_menu(); //sends user back to main menu
            } else{

                //customer to enter their type for program to display corrent info as each customer category has their unique info to display
                cout<<"Are you 1. Normal Customer \t 2. MMU Student \t 3. MMU Staff"<<endl<<"Enter your choice: ";  
                cin>>type;
                    
                        if(type==1){

                            //pure virtual function call
                            Customer *customer = &cust;
                            customer->display_profile(); //goes directly to Customer class

                        }else if(type==2){

                            //pure virtual function call
                            MMUStudent *student = &stud;
                            student->display_profile(); //goes directly to MMUStudent class
                        }else if(type==3){
                            
                            //pure virtual function call
                            MMUStaff *staff = &staf;
                            staff->display_profile();   //goes directly to MMUStaff class

                        }else{  //if user enter value other than 1,2,3
                            cout<<"Input error";
                        }

            }

        break;

        case 2: //view shopping cart
            
            //options to choose from within 1st option for shopping cart features
            cout<<"Choose what you would like to do next"<<endl;
            cout<<"1. View current Shopping Cart"<<endl;
            cout<<"2. Modify Item in Shopping Cart"<<endl;
            cout<<"3. Delete Item from Shopping Cart"<<endl;
                cin>>choice;

                //redirect to respective function based on user input
                switch(choice){
                    case 1:
                        cc.view_cart(); //goes to function which display current shopping cart
                    break;

                    case 2:
                        sc.modify_cart();   //goes to function which allow user to modify item in current shopping cart
                    break;

                    case 3:
                        sc.delete_item();   //goes to function which allow user to delete item in current shopping cart
                    break;
                }
            
        break;

        case 3: //view order history
            
            //options to choose from within 1st option for order history features
            cout<<"Choose what you would like to do next"<<endl;
            cout<<"1. View Shopping Cart History"<<endl;
            cout<<"2. Delete Shopping Cart History"<<endl;
                cin>>choice;

                //redirect to respective function based on user input
                switch(choice){
                    case 1:
                        cc.history_cart_convert();
                        //cc.view_cart_history(); //goes to function which display current shopping cart information
                    break;

                    case 2:
                        cc.delete_shopping_history();   //goes to function which allow shopper to delete shopping cart history
                    break;

                }
        break;

        case 4: //view product

             //options to choose from within 1st option for view products features
            cout<<"Select type of product"<<endl;
            cout<<"1. Book"<<endl;
            cout<<"2. Magazine"<<endl;
            cout<<"3. Movie"<<endl;
                cin>>prod_selection;

            if(prod_selection==1){
                
                //pure virtual function call
                ShopItem *book = &b;
                book->item_Display(); //goes directly to book class

            } else if(prod_selection==2){
                
                //pure virtual function call
                ShopItem *magazine = &mag;
                magazine->item_Display();   //goes directly to magazine class
                
            } else if(prod_selection==3){

                //pure virtual function call
                ShopItem *movie = &mv;
                movie->item_Display();  //goes directly to movie class
            }
            
        break;

        case 5: //shopper make payment
            cc.payment();   //goes to function which shopper to make payment and shopping cart will be cleared and moved to shopping cart history

        case 0: //logout from system
            cout<<"Logged out!"<<endl;
            exit(0);
        break;

        default:    //occurs when user enters options other than 1,2,3,4,5,0
            cout<<"Wrong option, select again"<<endl<<endl;
            after_login_menu(); //sends user back to main menu
        break;

    }

}


int main(){

    int choice;

    Login L;

    //Login and registration welcome message display to display the options available 
        cout<<"Hello,"<<endl<<"Select from the options below"<<endl;
        cout<<"1. new here? Register an account."<<endl<<"2. Already a member? Login."<<endl;
                cin>>choice;

        
        if(choice==1){  //choice for registration

            cust_Type();    //shopper will be brought to menu and logic for registration

        }else if(choice==2){    //choice for login

            //login validation
            bool status = L.login_logic();  // I/O from login_logic() function located in login class which outputs a true or false output upon validation

            if(status){
                
                //if validation fail
                cout<<"Login Fail"<<endl;
                system("PAUSE");
                return 0;
            
            }else{
                
                //if validation success
                cout<<"Succesfully logged in!"<<endl;
                system("PAUSE");
                after_login_menu(); //sends user to main menu

                return 1;
            }

        }

}