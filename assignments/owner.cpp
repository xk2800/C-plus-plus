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
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

void registerLogic();
void loginUserValidationLogic();
void loginPassValidationLogic();
void signupDisplayLogic();
void menuDisplayLogic();
void showItemLogic();
void insertNewItemsLogic();
void deleteItemsLogic();
void updateItemsLogic();


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
    void usernameLogin() {
        cout<<"Enter your username : ";
        cin.ignore();
        getline(cin, username);
    }

    void passLogin() {
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
    int signin_selection, menu_selection;

public:
    void signInDisplay() {
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"          WELCOME TO MMU SHOPPING KIOSK OWNER SYSTEM          "<<endl;
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<endl<<endl;
        cout<<"--- Welcome to the system ! Before accessing to the system's features and all it's resources, owner can either ---"<<endl<<endl;
        cout<<" 1. Login "<<endl;
        cout<<" 2. Register "<<endl;
    }

    void menuDisplay() {
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"          WELCOME TO MMU SHOPPING KIOSK OWNER SYSTEM          "<<endl;
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<endl<<endl;
        cout<<" 1. View Items "<<endl;
        cout<<" 2. Insert New Items "<<endl;
        cout<<" 3. Update Information Of Items "<<endl;
        cout<<" 4. Delete Items "<<endl;
        cout<<" 0. Exit "<<endl;
    }

    void signinSelection() {
        cout<<endl;
        cout<<"Please choose an operation to proceed !"<<endl;
        cin>>signin_selection;

        if(signin_selection<0 ||signin_selection>2) {
            cout<<"Please enter an appropriate selection !";
            exit(1);
        }

        cin.ignore();
    }

    void menuSelection() {
        cout<<endl;
        cout<<"Please choose an operation to proceed !"<<endl;
        cin>>menu_selection;

        if(menu_selection<0 ||menu_selection>4) {
            cout<<"Please enter an appropriate selection !";
            exit(1);
        }

        cin.ignore();
    }

    friend void signupDisplayLogic();
    friend void menuDisplayLogic();
};

/*********************************************** OWNER INSERT ITEM CLASS ***********************************************/

class InsertNewItems {

private:
    int new_item_units, number, category_number, rand_number = 0, id ;
    string new_item_name, new_item_company;
    float new_item_price;

public:
    void insertItemsCategory() {
        cout<<"----------------------"<<endl;
        cout<<"    Item Categories    "<<endl;
        cout<<"----------------------"<<endl;
        cout<<" 1. Magazine "<<endl<<" 2. Book "<<endl<<" 3. Movie "<<endl<<endl;

        cout<<"Please choose a category that you would like to insert new items"<<endl;
        cin>>category_number;

        if(category_number<0 || category_number>4) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }
    }

    int insertgetCatergoryNumber() {
        return category_number;
    }

    void insertItemsInput() {

        cout<<endl;

        cout<<"How many new items you would like to add into system : ";
        cin>>number;

        if(number<0) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }

        cout<<endl;

        cin.ignore();
    }

    int insertgetNumber() {
        return number;
    }

    void insertItemsMenuDetails() {

        srand(time(NULL));
        rand_number = rand()%20;

        cout<<"Product ID : "<<rand_number<<endl;

        cout<<"Product name : ";
        getline(cin, new_item_name);

        cout<<"Product price : ";
        cin>>new_item_price;
        cout<<"Number of product units available : ";
        cin>>new_item_units;

        cin.ignore();

        cout<<"Name of the company which produces the item : ";
        getline(cin, new_item_company);

        if(new_item_price<0 || new_item_units<0) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }

    }

    int insertgetId() {
        return rand_number;
    }

    string insertgetName() {
        return new_item_name;
    }

    float insertgetPrice() {
        return new_item_price;
    }

    int insertgetUnit() {
        return new_item_units;
    }

    string insertgetCompany() {
        return new_item_company;
    }

    friend void insertNewItemsLogic();

};

class ShopItem {

protected:
    friend void insertNewItemsLogic();
    friend void deleteItemsLogic();
    int shopitem_yr = 0, shopitem_month = 0;
    string shopitem_author;
    string shopitem_actor;

public:
    virtual void itemDisplay() = 0;
};

class Magazine: public ShopItem {

public:
    void itemDisplay() {
        cout<<"Year of publication : ";
        cin>>shopitem_yr;
        cout<<"Month of publication : ";
        cin>>shopitem_month;

        cin.ignore();
    }

    friend void insertNewItemsLogic();
    friend void deleteItemsLogic();
    friend void updateItemsLogic();
};

class Book: public ShopItem {

public:
    void itemDisplay() {
        cout<<"Name of the author : ";
        getline(cin, shopitem_author);
    }

    friend void insertNewItemsLogic();
    friend void deleteItemsLogic();
    friend void updateItemsLogic();
};

class Movie: public ShopItem {

public:
    void itemDisplay() {
        cout<<"Name of the actor : ";
        getline(cin, shopitem_actor);
    }

    friend void insertNewItemsLogic();
    friend void deleteItemsLogic();
    friend void updateItemsLogic();
};

/*********************************************** OWNER SHOW ITEM CLASS ***********************************************/

class ShowItem {

private:
    int selection;

public:
    void showOption() {
        cout<<"-------------------"<<endl;
        cout<<" 1. Magazine\n 2. Book\n 3. Movie"<<endl;
        cout<<"-------------------"<<endl;

        cout<<"Which category of items you would like to see ? "<<endl;
        cin>>selection;

        if(selection<0 || selection>4) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }
    }

    int getOption() {
        return selection;
    }

    void showMagazine() {
        cout<<"-----------------------------------"<<endl;
        cout<<"           Magazine Stock          "<<endl;
        cout<<"-----------------------------------"<<endl;
    }

    void showBook() {
        cout<<"-----------------------------------"<<endl;
        cout<<"           Book Stock              "<<endl;
        cout<<"-----------------------------------"<<endl;
    }

    void showMovie() {
        cout<<"-----------------------------------"<<endl;
        cout<<"           Movie Stock              "<<endl;
        cout<<"-----------------------------------"<<endl;
    }

    friend void deleteItemsLogic();
};

/*********************************************** OWNER DELETE ITEM CLASS ***********************************************/

class DeleteItem {

private:
    int delete_id;

public:

    void deleteEnterByIdOption() {
        cout<<"Enter the ID of the product that you wish to delete from the stock list"<<endl;
        cin>>delete_id;

        if(delete_id<0) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }
    }

    int getDeleteId() {
        return delete_id;
    }

};

/*********************************************** OWNER UPDATE ITEM CLASS ***********************************************/

class UpdateItem {

private:
    int category_number, category_details_number, update_id = 0 ;
    int update_item_units = 0;
    string update_item_name, update_item_company;
    float update_item_price = 0;

    int update_magazine_yr = 0, update_magazine_month = 0;
    string update_book_author, update_movie_actor;

public:
    void updateItemsCategory() {
        cout<<"----------------------"<<endl;
        cout<<"    Item Categories    "<<endl;
        cout<<"----------------------"<<endl;
        cout<<" 1. Magazine "<<endl<<" 2. Book "<<endl<<" 3. Movie "<<endl<<endl;

        cout<<"Please choose a category that you would like update the items"<<endl;
        cin>>category_number;

        if(category_number<0 || category_number>4) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }

        cin.ignore();

        cout<<endl;
    }

    int getupdateItemsCategoryNumber() {
        return category_number;
    }

    void updateItemsInput() {
        switch(category_number) {
            case 1:
            case 2:
            case 3: cout<<"New name of the product : ";
                getline(cin, update_item_name);
                cout<<"New price of product : ";
                cin >> update_item_price;
                cout<<"New units available of product : ";
                cin >> update_item_units;

                if(update_item_price<0 || update_item_units<0) {
                    cout<<"Invalid input ! Please try again later";
                    exit(1);
                }

                cin.ignore();

                cout<<"New name of the manufacture : ";
                getline(cin, update_item_company);

                break;
        }

        switch(category_number) {
            case 1: cout<<"New publication year : ";
                cin >> update_magazine_yr;
                cout<<"New publication month : ";
                cin >> update_magazine_month;
                break;

            case 2: cout<<"New author name : ";
                getline(cin, update_book_author);
                break;
            case 3: cout<<"New actor name : ";
                getline(cin, update_movie_actor);
                break;

            default: cout<<"Please choose a appropriate category to update ! Try again later"<<endl;
                exit(1);
        }
        cout<<endl;

    }

    void updateEnterByIdOption() {
        cout<<"Enter the ID of the product that you wish to update in the stock list : ";
        cin>>update_id;

        if(update_id<0) {
            cout<<"Invalid input ! Please try again later";
            exit(1);
        }

        cin.ignore();
    }

    int getUpdateId() {
        return update_id;
    }

    string updategetItemName() {
        return update_item_name;
    }

    float updategetItemPrice() {
        return update_item_price;
    }

    int updategetItemUnit() {
        return update_item_units;
    }

    string updategetItemCompany() {
        return update_item_company;
    }

    int updategetItemYr() {
        return update_magazine_yr;
    }

    int updategetItemMonth() {
        return update_magazine_month;
    }

    string updategetItemAuthor() {
        return update_book_author;
    }

    string updategetItemActor() {
        return update_movie_actor;
    }
};

/*********************************************** menuDisplayLogic() ***********************************************/

void menuDisplayLogic() {

    Menu menu_obj;
    char proceed;

    do {

        cout<<endl;
        menu_obj.menuDisplay();
        menu_obj.menuSelection();
        cout<<endl;

        switch(menu_obj.menu_selection) {
            case 1 : cout<<"===================================="<<endl;
                cout<<"              VIEW ITEMS            "<<endl;
                cout<<"===================================="<<endl;
                cout<<endl;

                showItemLogic();
                break;

            case 2 : cout<<"=========================================="<<endl;
                cout<<"              INSERT NEW ITEMS            "<<endl;
                cout<<"=========================================="<<endl;
                cout<<endl;

                insertNewItemsLogic();
                break;

            case 3 : cout<<"=========================================="<<endl;
                cout<<"              UPDATE ITEMS                "<<endl;
                cout<<"=========================================="<<endl;
                cout<<endl;

                updateItemsLogic();
                break;

            case 4 : cout<<"=========================================="<<endl;
                cout<<"              DELETE ITEMS                "<<endl;
                cout<<"=========================================="<<endl;
                cout<<endl;

                deleteItemsLogic();
                break;

            case 0 : cout<<"Thank you for using !";
                exit(0);
                break;

        }

        cout<<endl;
        cout<<"Would you like to continue ? [ Y / N ]"<<endl;
        cin>>proceed;
        cout<<endl;

    } while (proceed == 'Y' || proceed == 'y');

    //cin.ignore();

    cout<<endl;
    cout<<"Thank you for using !";
}

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
        cout<<"Register is completed and the data is saved ! You can now proceed to log into the existing account"<<endl<<endl;

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
            menuDisplayLogic();
        } else {
            cout<<"Password incorrect ! Please try again later"<<endl<<endl;
            exit(1);
        }

        in_log_file_user.close();
    }
}

/*********************************************** signupDisplayLogic() ***********************************************/

void signupDisplayLogic() {

    Menu menu_obj;
    char proceed;

    menu_obj.signInDisplay();
    menu_obj.signinSelection();
    cout<<endl;

    switch(menu_obj.signin_selection) {
        case 1 : cout<<"===================================="<<endl;
                 cout<<"              LOGIN                 "<<endl;
                 cout<<"===================================="<<endl;
                 cout<<endl;

                 loginUserValidationLogic();

                 cout<<"Reading from the file...."<<endl<<endl;
                 break;

        case 2 : cout<<"===================================="<<endl;
                 cout<<"              REGISTER              "<<endl;
                 cout<<"===================================="<<endl;
                 cout<<endl;

                 registerLogic();
                 break;
    }
}


/*********************************************** insertNewItemsLogic() ***********************************************/

void insertNewItemsLogic() {

    InsertNewItems insert_new_obj;

    Magazine insert_magazine_obj;
    Book insert_book_obj;
    Movie insert_movie_obj;

    ofstream out_insert_file;

    int new_itemid = 0, new_itemunits = 0;
    string new_itemname, new_itemcompany;
    float new_itemprice = 0;

    int shop_itemyr = 0, shop_itemmonth = 0;
    string shop_itemauthor;
    string shop_itemactor;

    /*int random_number;*/

    insert_new_obj.insertItemsCategory();

    switch(insert_new_obj.category_number) {

        case 1 : out_insert_file.open("owner-magazine-insert.txt", std::ios_base::app);
            break;
        case 2 : out_insert_file.open("owner-book-insert.txt", std::ios_base::app);
            break;
        case 3:  out_insert_file.open("owner-movie-insert.txt", std::ios_base::app);
            break;
        default: cout<<"The option is unavailable at the moment ! Please try again later";
            exit(1);
    }

    if(!out_insert_file) {
        cout<<"File is not found !"<<endl;
    } else {

        insert_new_obj.insertItemsInput();

        for(int x=0; x<insert_new_obj.insertgetNumber(); x++) {

            insert_new_obj.insertItemsMenuDetails();

            /*random_number = insert_new_obj.getInsertRandGenerate();*/

            new_itemid = insert_new_obj.rand_number;
            new_itemname = insert_new_obj.new_item_name;
            new_itemprice = insert_new_obj.new_item_price;
            new_itemunits = insert_new_obj.new_item_units;
            new_itemcompany = insert_new_obj.new_item_company;

            shop_itemyr = insert_magazine_obj.shopitem_yr;
            shop_itemmonth = insert_magazine_obj.shopitem_month;
            shop_itemauthor = insert_book_obj.shopitem_author;
            shop_itemactor = insert_movie_obj.shopitem_actor;

            switch(insert_new_obj.category_number) {

                case 1: insert_magazine_obj.itemDisplay();

                    out_insert_file<<new_itemid<<setw(15)<<new_itemname<<setw(15)<<new_itemprice<<setw(15)<<
                                   new_itemunits<<setw(15)<<new_itemcompany<<setw(15)<<shop_itemyr<<setw(15)<<shop_itemmonth<<endl;
                    break;

                case 2: insert_book_obj.itemDisplay();

                    out_insert_file<<new_itemid<<setw(15)<<new_itemname<<setw(15)<<new_itemprice<<setw(15)<<
                                   new_itemunits<<setw(15)<<new_itemcompany<<setw(15)<<shop_itemauthor<<endl;
                    break;

                case 3: insert_movie_obj.itemDisplay();

                    out_insert_file<<new_itemid<<setw(15)<<new_itemname<<setw(15)<<new_itemprice<<setw(15)<<
                                   new_itemunits<<setw(15)<<new_itemcompany<<setw(15)<<shop_itemactor<<endl;
                    break;

                default: cout<<"The option is unavailable at the moment ! Please try again later";
                    exit(1);
                    break;
            }

            cout<<endl;
            cout<<"Insertion of new products is completed and the data is saved !"<<endl<<endl;
        }

        out_insert_file.close();
    }
}

/*********************************************** showItemLogic() ***********************************************/

void showItemLogic() {

    ShowItem show_item_obj;

    InsertNewItems insert_item_obj;

    ifstream in_show_file;
    /*ofstream out_delete_file;*/

    int show_itemid = 0;
    string show_itemname;

    show_itemid = insert_item_obj.insertgetId();
    show_itemname = insert_item_obj.insertgetName();

    show_item_obj.showOption();

    switch(show_item_obj.getOption()) {

        case 1: in_show_file.open("owner-magazine-insert.txt");
            /*out_delete_file.open("tmp_magazine.txt", std::ios_base::app);*/

            if(in_show_file.is_open()) {

                cout<<endl;
                cout<<"----------------------------"<<endl;
                cout<<"   Magazine Stock Details   "<<endl;
                cout<<"----------------------------"<<endl;

                cout<<endl;
                cout<<"ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Year"<<setw(15)<<"Month"<<endl;
                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                while(in_show_file>>show_itemid , getline(in_show_file, show_itemname)) {

                    cout<<show_itemid<<setw(15)<<show_itemname<<endl;
                    /*out_delete_file<<show_itemid<<setw(15)<<show_itemname<<endl;*/
                }

                in_show_file.close();
                /*out_delete_file.close();*/

            } else {
                cout<<"File is not found !";
            }

            break;

        case 2: in_show_file.open("owner-book-insert.txt");

            if(in_show_file.is_open()) {

                cout<<endl;
                cout<<"----------------------------"<<endl;
                cout<<"     Book Stock Details     "<<endl;
                cout<<"----------------------------"<<endl;

                cout<<endl;
                cout<<"ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Author"<<endl;
                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                while(in_show_file>>show_itemid , getline(in_show_file, show_itemname)) {

                    cout<<show_itemid<<setw(15)<<show_itemname<<endl;
                }

                in_show_file.close();

            } else {
                cout<<"File is not found !";
            }

            break;

        case 3: in_show_file.open("owner-movie-insert.txt");

            if(in_show_file.is_open()) {

                cout<<endl;
                cout<<"----------------------------"<<endl;
                cout<<"     Movie Stock Details    "<<endl;
                cout<<"----------------------------"<<endl;

                cout<<endl;
                cout<<"ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Unit"<<setw(15)<<"Company"<<setw(15)<<"Actor"<<endl;
                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                while(in_show_file>>show_itemid , getline(in_show_file, show_itemname)) {

                    cout<<show_itemid<<setw(15)<<show_itemname<<endl;
                }

                in_show_file.close();

            } else {
                cout<<"File is not found !";
            }

            break;
    }
}

/*********************************************** deleteItemLogic() ***********************************************/

void deleteItemsLogic() {

    /**
      * Get all data from our file i.e record.txt
      * Write data into temp file
      * Use rename() and remove()
      */

    DeleteItem delete_item_obj;

    ShowItem show_item_obj;
    InsertNewItems insert_item_obj;

    int delete_itemid = 0;
    string delete_itemname;

    delete_itemid = insert_item_obj.insertgetId();
    delete_itemname = insert_item_obj.insertgetName();

    int deleteid;

    ofstream out_delete_file;
    ifstream in_delete_file;

    //showItemLogic();

    show_item_obj.showOption();

    cout<<endl;

    delete_item_obj.deleteEnterByIdOption();
    deleteid = delete_item_obj.getDeleteId();

    switch(show_item_obj.getOption()) {

        case 1 : in_delete_file.open("owner-magazine-insert.txt");
            out_delete_file.open("tmp_magazine.txt", std::ios_base::app);

            if(in_delete_file.is_open()) {

                while(in_delete_file>>delete_itemid , getline(in_delete_file, delete_itemname)) {

                    if(delete_itemid != deleteid) {
                        out_delete_file<<delete_itemid<<setw(15)<<delete_itemname<<endl;
                    }
                }

                in_delete_file.close();
                out_delete_file.close();

                remove("owner-magazine-insert.txt");
                rename("tmp_magazine.txt", "owner-magazine-insert.txt");

            } else {
                cout<<"File is not found !";
                exit(1);
            }

            break;

        case 2 : in_delete_file.open("owner-book-insert.txt");
            out_delete_file.open("tmp_book.txt", std::ios_base::app);

            if(in_delete_file.is_open()) {

                while(in_delete_file>>delete_itemid , getline(in_delete_file, delete_itemname)) {

                    if(delete_itemid != deleteid) {
                        out_delete_file<<delete_itemid<<setw(15)<<delete_itemname<<endl;
                    }
                }

                in_delete_file.close();
                out_delete_file.close();

                remove("owner-book-insert.txt");
                rename("tmp_book.txt", "owner-book-insert.txt");

            } else {
                cout<<"File is not found !";
                exit(1);
            }

            break;

        case 3 : in_delete_file.open("owner-movie-insert.txt");
            out_delete_file.open("tmp_movie.txt", std::ios_base::app);

            if(in_delete_file.is_open()) {

                while(in_delete_file>>delete_itemid , getline(in_delete_file, delete_itemname)) {

                    if(delete_itemid != deleteid) {
                        out_delete_file<<delete_itemid<<setw(15)<<delete_itemname<<endl;
                    }
                }

                in_delete_file.close();
                out_delete_file.close();

                remove("owner-movie-insert.txt");
                rename("tmp_movie.txt", "owner-movie-insert.txt");

            } else {
                cout<<"File is not found !";
                exit(1);
            }

            break;

        default : cout<<"Operation failed !";
            exit(1);
            break;

    }

    cout<<endl;
    cout<<"Delete successfully ! Proceed to View Item to see the latest stock list"<<endl;
}

/*********************************************** updateItemLogic() ***********************************************/

void updateItemsLogic() {

    UpdateItem update_item_obj;
    InsertNewItems insert_item_obj;
    Movie insert_movie_obj;
    Magazine insert_magazine_obj;
    Book insert_book_obj;

    ofstream out_update_file;
    ifstream in_update_file;

    int update_itemreadid = 0;
    string update_itemreadname;

    update_itemreadid = insert_item_obj.insertgetId();
    update_itemreadname = insert_item_obj.insertgetName();

    string update_itemreadcompany, update_bookreadauthor, update_moviereadactor;
    int update_itemreadunits = 0, update_magazinereadyr = 0, update_magazinereadmonth = 0;
    float update_itemreadprice = 0;

    update_itemreadprice = insert_item_obj.insertgetPrice();
    update_itemreadunits = insert_item_obj.insertgetUnit();
    update_itemreadcompany = insert_item_obj.insertgetCompany();
    update_magazinereadyr = insert_magazine_obj.shopitem_yr;
    update_magazinereadmonth = insert_magazine_obj.shopitem_month;
    update_bookreadauthor = insert_book_obj.shopitem_author;
    update_moviereadactor = insert_book_obj.shopitem_actor;

    string update_itemname, update_itemcompany, update_bookauthor, update_movieactor;
    int update_itemid, update_itemunits, update_magazineyr, update_magazinemonth;
    float update_itemprice;

    update_item_obj.updateItemsCategory();
    update_item_obj.updateEnterByIdOption();
    update_itemid = update_item_obj.getUpdateId();

    cout << endl;

    update_item_obj.updateItemsInput();

    update_itemname = update_item_obj.updategetItemName();
    update_itemprice = update_item_obj.updategetItemPrice();
    update_itemunits = update_item_obj.updategetItemUnit();
    update_itemcompany = update_item_obj.updategetItemCompany();
    update_magazineyr = update_item_obj.updategetItemYr();
    update_magazinemonth = update_item_obj.updategetItemMonth();
    update_bookauthor = update_item_obj.updategetItemAuthor();
    update_movieactor = update_item_obj.updategetItemActor();

    switch (update_item_obj.getupdateItemsCategoryNumber()) {

        case 1 :
            in_update_file.open("owner-magazine-insert.txt");
            out_update_file.open("temp_updatemag.txt", std::ios_base::app);

            if (in_update_file.is_open()) {

                while (in_update_file >> update_itemreadid, getline(in_update_file, update_itemreadname)) {

                    if (update_itemreadid == update_itemid) {
                        out_update_file<<update_itemreadid<<setw(15)<<update_itemname<<setw(15)
                                       <<update_itemprice<<setw(15)
                                       <<update_itemunits<<setw(15)<<update_itemcompany << setw(15)
                                       <<update_magazineyr<<setw(15)
                                       <<update_magazinemonth << endl;
                    } else {
                        out_update_file<<update_itemreadid<<setw(15)<<update_itemreadname<<endl;
                    }
                }

                out_update_file.close();
                in_update_file.close();

                remove("owner-magazine-insert.txt");
                rename("temp_updatemag.txt", "owner-magazine-insert.txt");

            } else {
                cout<<"File is not found !";
                exit(1);
            }

            break;

        case 2 :
            in_update_file.open("owner-book-insert.txt");
            out_update_file.open("temp_updatebook.txt", std::ios_base::app);

            if (in_update_file.is_open()) {

                while (in_update_file >> update_itemreadid, getline(in_update_file, update_itemreadname)) {

                    if (update_itemreadid == update_itemid) {
                        out_update_file<<update_itemreadid<<setw(15)<<update_itemname<<setw(15)
                                       <<update_itemprice<<setw(15)
                                       <<update_itemunits<<setw(15)<<update_itemcompany<<setw(15)
                                       <<update_bookauthor<<endl;
                    } else {
                        out_update_file<<update_itemreadid<<setw(15)<<update_itemreadname<<endl;
                    }
                }

                out_update_file.close();
                in_update_file.close();

                remove("owner-book-insert.txt");
                rename("temp_updatebook.txt", "owner-book-insert.txt");

            } else {
                cout<<"File is not found !";
                exit(1);
            }

            break;

        case 3 :
            in_update_file.open("owner-movie-insert.txt");
            out_update_file.open("temp_updatemovie.txt", std::ios_base::app);

            if (in_update_file.is_open()) {

                while (in_update_file >> update_itemreadid, getline(in_update_file, update_itemreadname)) {

                    if (update_itemreadid == update_itemid) {
                        out_update_file <<update_itemreadid<<setw(15)<<update_itemname<<setw(15)
                                        <<update_itemprice<<setw(15)
                                        <<update_itemunits<<setw(15)<<update_itemcompany<<setw(15)
                                        <<update_bookauthor<<endl;
                    } else {
                        out_update_file<<update_itemreadid<<setw(15)<<update_itemreadname<<endl;
                    }
                }

                out_update_file.close();
                in_update_file.close();

                remove("owner-movie-insert.txt");
                rename("temp_updatemovie.txt", "owner-movie-insert.txt");

            } else {
                cout<<"File is not found !";
                exit(1);
            }

            break;
    }

    cout<<endl;
    cout<<"Update successfully ! Proceed to View Item to see the latest stock list"<<endl;
}


/*********************************************** int main() ***********************************************/

int main() {

    signupDisplayLogic();
    //deleteItemsLogic();

    return 0;
}

//**clion git push 1st test**

// CREDIT : https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
//          https://www.youtube.com/watch?v=s3-DmI1ZWxE&t=151s
//			http://key-to-programming.blogspot.com/2015/01/program-for-auto-number-generator-auto.html
//			https://www.educative.io/edpresso/what-is-a-cpp-abstract-class
//          https://www.youtube.com/watch?v=1xH_w-bTOVc&list=LLKDL2NRkpulBjnktk_gDrsQ&index=1&t=1459s
//			https://github.com/nouman-newworld/file-handling/blob/master/c%2B%2B%20file%20handling%202020
//          https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/


/*    TODO  1) random gen number issue ( X ) */
/*    TODO  2) negative numb issue ( X ) */
/*    TODO  3) login / register before using ( X ) */
/*    TODO  4) display only 10 items per page */
/*    TODO  5) analyze sales of shopper and generate a report */
/*    TODO  6) able to change username / password */