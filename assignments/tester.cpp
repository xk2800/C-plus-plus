#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

//set your file location here
static string location = "D://";

class Shopper{

    protected:
      string username, password, cpassword, name, address;
      int id;
      

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
            reg_file.open("D://"+ username +"-details.txt", std::ios_base::app);
        
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
            reg_file.open(location+"test-details.txt", std::ios_base::app);
            //cred_file.open("D://" + username + "cred-details.txt", std::ios_base::app);

            if(!reg_file){
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

                cred_file<<username<<endl<<password<<endl<<endl;
                //cred_file<<username<<setw(10)<<password<<endl<<endl;
                //reg_file<<username<<"\t\t\t"<<password<<"\t\t\t"<<name<<"\t\t\t"<<address<<"\t\t\t"<<id;
                reg_file<<username<<setw(10)/*<<password<<setw(10)*/<<name<<setw(10)<<address<<setw(10)<<id<<setw(10);

            }

            reg_file.close();
        }

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

        read_profile.open("test-details.txt");

        if(read_profile.fail()){
            cout<<"File not found"; exit(0);
        } else{
            
            test_main();
        }
    }

    bool test(){

        string un;
        int off;

        cout<<"Enter your username : "; cin.ignore(); getline(cin,usernam);//cin>>username;
        cout<<endl<<"UNAME FEEDBACK: "<<usernam<<endl<<endl;
            ifstream read("test-details.txt");
            getline(read, un);

            if(off = usernam.find(un, 0)){
                if(un != usernam){
                    return true;
                } else{
                    cout<<"No record found";
                    return false;
                }
            }

    }

    string getusername(){
        //cout<<username;
        return usernam;
    }

    int test_main(){

        bool status = test();
        //string username;
        //username = getusername();
        getusername() = usernam;
        cout<<status;

        if(!status){
            cout<<"No record found!!"<<endl<<"USERNAME"<<usernam;
            cout<<usernam;
            exit(0); return 0;
        } else{

            //ifstream read(location + username+"-details.txt");
            ifstream read("test-details.txt");

            while(getline(read, usernam)){

                cout<<usernam<<endl;

            }

            return 1;
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
        reg_file.open(location + username +"-details.txt"/*, std::ios_base::app*/);
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

        read_profile.open("test-details.txt");

        if(read_profile.fail()){
            cout<<"File not found"; exit(0);
        } else{
            
            test_main();

            /*cout<<"Enter your username : "; cin>>username;
            getline(read_profile, un);
            //if((uname = username.find(un,0))!=string::npos){
            if(un != username){
                getline(read_profile, username);
                    cout<<username<<endl;
                //cout<<"Sorry, no record found";
            }else{
                /*getline(read_profile, username);
                    cout<<username<<endl;
                cout<<"Sorry, no record found";*/
            //}
            //}
            //read_profile.close();
        }
    }

    bool test(){

        string un;
        int off;

        cout<<"Enter your username : "; cin.ignore(); getline(cin,usernam);//cin>>username;
        cout<<endl<<"UNAME FEEDBACK: "<<usernam<<endl<<endl;
            ifstream read("test-details.txt");
            getline(read, un);

            if(off = usernam.find(un, 0)){
                if(un != usernam){
                    return true;
                } else{
                    cout<<"No record found";
                    return false;
                }
            }

    }

    string getusername(){
        //cout<<username;
        return usernam;
    }

    int test_main(){

        bool status = test();
        //string username;
        //username = getusername();
        getusername() = usernam;
        cout<<status;

        if(!status){
            cout<<"No record found!!"<<endl<<"USERNAME"<<usernam;
            cout<<usernam;
            exit(0); return 0;
        } else{

            //ifstream read(location + username+"-details.txt");
            ifstream read("test-details.txt");

            while(getline(read, usernam)){

                cout<<usernam<<endl;

            }

            return 1;
        }
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

        read_profile.open("test-details.txt");

        if(read_profile.fail()){
            cout<<"File not found"; exit(0);
        } else{
            
            test_main();
        }

    }

    bool test(){

        string un;
        int off;

        cout<<"Enter your username : "; cin.ignore(); getline(cin,usernam);//cin>>username;
        cout<<endl<<"UNAME FEEDBACK: "<<usernam<<endl<<endl;
            ifstream read("test-details.txt");
            getline(read, un);

            if(off = usernam.find(un, 0)){
                if(un != usernam){
                    return true;
                } else{
                    cout<<"No record found";
                    return false;
                }
            }

    }

    string getusername(){
        //cout<<username;
        return usernam;
    }

    int test_main(){

        bool status = test();
        //string username;
        //username = getusername();
        getusername() = usernam;
        cout<<status;

        if(!status){
            cout<<"No record found!!"<<endl<<"USERNAME"<<usernam;
            cout<<usernam;
            exit(0); return 0;
        } else{

            //ifstream read(location + username+"-details.txt");
            ifstream read("test-details.txt");

            while(getline(read, usernam)){

                cout<<usernam<<endl;
            }

            return 1;
        }
    }


};


//////////////////////////////////////////////////////////////////////////
class ShoppingCart{

    protected:

    ofstream cart_file;
    ifstream book_item_file, magazine_item_file, movie_item_file;
    string username, itemid, id;

    public:

        void current_cart(){
            
            cout<<"Enter username: ";   cin.ignore();   getline(cin, username);

            cart_file.open(username+"cart.txt");

            /*if(!cart_file){
                cout<<"File cannot be found"<<endl;     exit(0);
            } else{

                cout<<"Enter product ID: "; cin>>itemid;

                book_item_file.open("owner-book-insert.txt");
                magazine_item_file.open("owner-magazine-insert.txt");
                movie_item_file.open("owner-movie-insert.txt");

                if(!book_item_file){
                    cout<<"File cannot be found"<<endl;     exit(0);
                }else{

                    getline(book_item_file, id);


                    cout<<id;
                }

            }*/
            
        }


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
                    //magazine_item_file.open("owner-magazine-insert.txt");
                    //movie_item_file.open("owner-movie-insert.txt");

                    if(!book_item_file){
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        if(book_item_file.is_open()){
                            //while(!book_item_file.eof()){
                                ////getline(book_item_file, line);
                                
                            // while(getline(book_item_file, line)){   //

                            //     if(pos = line.find(itemid)!=string::npos){
                            //         /*cout<<"ITEMID: "<<itemid;
                            //         break;*/
                                    
                            //         if(pos<2){
                            //             validate =true;
                            //             gcl = line;
                            //         }
                                    
                            //         //getline(book_item_file, search);
                            //         //break;

                            //     }else{
                            //         //cout<<"NOT FOUND";  exit(0);
                            //         validate = false;
                            //     }

                            //cout << "open" << endl;
                            //cout << itemid << endl;

                            while(getline(book_item_file, line)) {

                                pos = line.find(itemid);

                                //cout << pos << endl;

                                if(pos != string::npos) {

                                    if(pos < 3){

                                        gcl = line;

                                    }

                                }

                            }

                            cout << gcl << endl;
                        }

                            /*if(validate==true){
                                //while(getline(book_item_file, search)){
                                cout<<"ITEMID"<<gcl;
                                //}
                            }else{
                                cout<<"NOT FOUND";
                            }*/
                        }
                        
                        
                        //getline(book_item_file, id);


                        //cout<<id;
                    }
                    book_item_file.close();
                }
        //}

};

class SCmovie:public ShoppingCart{

    private:

    int offset;
    string line, itemname;

    public:

        void movie_cart(){

            if(!cart_file){
                    cout<<"File cannot be found"<<endl;     exit(0);
                } else{

                    cout<<"Enter product ID: "; cin>>itemid;

                    book_item_file.open("owner-book-insert.txt");
                    //magazine_item_file.open("owner-magazine-insert.txt");
                    //movie_item_file.open("owner-movie-insert.txt");

                    if(!book_item_file){
                        cout<<"File cannot be found"<<endl;     exit(0);
                    }else{
                        
                        while(book_item_file>>itemid, getline(book_item_file, itemname)){
                            cout<<itemid<<itemname<<endl;
                        }



                        /*if(book_item_file.is_open()){
                            while(!book_item_file.eof()){

                                getline(book_item_file, line);
                                //book_item_file>>line;
                                //getline(book_item_file, itemid);
                                
                                if((offset = line.find(itemid, 0)) != string::npos){
                                    
                                    //while(book_item_file>>itemid){
                                    //getline(book_item_file, itemid);
                                    cout<<"FOUND: "<<itemid<<endl;
                                    //}
                                }
                            }
                        }*/
                        
                        
                        //getline(book_item_file, id);


                        //cout<<id;
                    }

                }
        }

};


////////////////////////////////////////////////////////////////
class ShopItem{

    protected:

    int itemid;
    string itemname, add;

    ShoppingCart SC;

    public:

    //default constructor
    ShopItem(){

    }

    virtual void item_Display() = 0;
};

class Book:public ShopItem{

    private:

    ifstream read_book_file;
    SCbook SCb;

    public:

        //default constructor
        Book(){

        }

    void item_Display(){

        read_book_file.open("owner-book-insert.txt");

        cout<<"Product ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Author"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;

            while(read_book_file>>itemid, getline(read_book_file, itemname)){

                
                cout<<itemid<<itemname<<endl;
            }

            cout<<"Would you like to add any item into your shopping cart? [Y/N]"; cin>>add;
            if(add=="Y" || add=="y"){
                SCb.book_cart();
            } else{


            }

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
                SC.current_cart();
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
void cust_Type(){

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


void after_login_menu(){

    int selection, prod_selection, uname;
    string confirm, search, username, un;

    ifstream read("test-details.txt");

    MMUStudent stud;

    Book b;
    Magazine mag;
    Movie mv;

    
    //menu start
    cout<<"Main Menu"<<endl;
    cout<<"1. View Profile"<<endl;
    cout<<"2. View Shopping Cart"<<endl;
    cout<<"3. View Order History"<<endl;
    cout<<"4. View Product"<<endl;
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

                MMUStudent *student = &stud;
                student->display_profile();
                
                //}
            }

        break;

        case 2: //view shopping cart

        break;

        case 3: //view order history

        break;

        case 4: //view product

            cout<<"Select type of product"<<endl;
            cout<<"1. Book"<<endl;
            cout<<"2. Magazine"<<endl;
            cout<<"3. Movie"<<endl;
                cin>>prod_selection;

            if(prod_selection==1){

                ShopItem *book = &b;
                book->item_Display();

            } else if(prod_selection==2){

                ShopItem *magazine = &mag;
                magazine->item_Display();

            } else if(prod_selection==3){

                ShopItem *movie = &mv;
                movie->item_Display();
            }

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
            //S.register_logic();

            /*string username, password;

            cout<<"Username: "; cin>>username;
            cout<<"Password: "; cin>>password;

            ofstream file;
            file.open("test-details.txt");
            file<<username<<endl<<password;
            file.close();
            exit(0);*/
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