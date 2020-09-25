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
#include<cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;

void registerLogic();
void loginUserValidationLogic();
void loginPassValidationLogic();
void menuLogic();
void insertNewItemsLogic();
void updateItemsLogic();
void showItemLogic();
void deleteItemsLogic();

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
		usernameLogin() {	
			cout<<"Enter your username : ";
			cin.ignore();
			getline(cin, username);
		}
		
		passLogin() {
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
		int selection;
		
	public:
		menuDisplay() {
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"          WELCOME TO MMU SHOPPING KIOSK OWNER SYSTEM          "<<endl;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<endl<<endl;
			cout<<" 1. Login "<<endl; 				/***/
			cout<<" 2. Register "<<endl;			/***/
			cout<<" 3. View Items "<<endl;
			cout<<" 4. Insert New Items "<<endl;	/***/
			cout<<" 5. Update Information Of Items "<<endl;
			cout<<" 6. Delete Items "<<endl;
			cout<<" 0. Exit "<<endl;
		}
		
		menuSelection() {
			cout<<endl;
			cout<<"Please choose an operation to proceed !"<<endl;
			cin>>selection;
			
			cin.ignore();
		}
				
		friend void menuLogic();	
};

/*********************************************** OWNER INSERT ITEM CLASS ***********************************************/

class InsertNewItems {

	private:
		int new_item_units, number, category_number, /*rand_number*/id ;
		string new_item_name, new_item_company;
		float new_item_price;

	public:
		insertItemsCategory() {
			cout<<"----------------------"<<endl;
			cout<<"    Item Categories    "<<endl;
			cout<<"----------------------"<<endl;
			cout<<" 1. Magazine "<<endl<<" 2. Book "<<endl<<" 3. Movie "<<endl<<endl;
			
			cout<<"Please choose a category that you would like to insert new items"<<endl;
			cin>>category_number;
		}

		int insertgetCatergoryNumber() {
			return category_number;
		}
		
		insertItemsInput() {
			
			cout<<endl;
			
			cout<<"How many new items you would like to add into system : ";
			cin>>number;
			cout<<endl;

			cin.ignore();
		}

		int insertgetNumber() {
			return number;
		}

		insertItemsMenuDetails() {
			cout<<"Product ID : ";
			cin>>id;

			cin.ignore();
			
			cout<<"Product name : ";
			getline(cin, new_item_name);

			cout<<"Product price : ";
			cin>>new_item_price;
			cout<<"Number of product units available : ";
			cin>>new_item_units;
			
			cin.ignore();

			cout<<"Name of the company which produces the item : ";
			getline(cin, new_item_company);
			
		}

		int insertgetId() {
			return id;
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

		/*insertRandGenerate() {
			srand(time(NULL));
			rand_number = rand()%20;
		}*/

		/*getInsertRandGenerate() {
			return rand_number;
		}*/

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
			
			cin.ignore();		}

	friend void insertNewItemsLogic();
	friend void deleteItemsLogic();
};

class Book: public ShopItem {

	public:
		void itemDisplay() {
			cout<<"Name of the author : ";
			getline(cin, shopitem_author);
		}

	friend void insertNewItemsLogic();
	friend void deleteItemsLogic();
};

class Movie: public ShopItem {
	
	public:
		void itemDisplay() {
			cout<<"Name of the actor : ";
			getline(cin, shopitem_actor);
		}

	friend void insertNewItemsLogic();
	friend void deleteItemsLogic();
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

			cout<<"Which catergory of items you would like to see ? "<<endl;
			cin>>selection;
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

	friend void showItemLogic();
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
		}

		int getDeleteId() {
			return delete_id;
		}

	friend void deleteItemsLogic();
};

/*********************************************** OWNER UPDATE ITEM CLASS ***********************************************/

class UpdateItem {
	
	private:
		int category_number, category_details_number ;
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
			
			cout<<endl;
		}

		void updateItemsInput() {

			switch(category_number) {
				case 1: 
				case 2:
				case 3: cout<<"[1] Name of product"<<endl;
						cout<<"[2] Price of product"<<endl;
						cout<<"[3] Units available of product"<<endl;
						cout<<"[4] Name of the manufacture"<<endl;
						break;
			}

			switch(category_number) {
				case 1: cout<<"[5] Publication year"<<endl;
						cout<<"[6] Publication month"<<endl;
						break;
				case 2: cout<<"[5] Author name"<<endl;
						break;
				case 3: cout<<"[5] Actor name"<<endl;
						break;

				default: cout<<"Please choose a appopriate category to update ! Try again later"<<endl;
						 exit(1);
			}

			cout<<endl;
			cout<<"What are the element of the item you would like to update ? [1 - 6]"<<endl;
			cin>>category_details_number;

			cin.ignore();			
		}

		void updateItemsAskInput() {
			switch(category_number) {
		
				case 1 : 
				case 2 :
				case 3 : switch(category_details_number) {
					 
					 		case 1: cout<<"Enter the new product name : "; 
									getline(cin, update_item_name);
							 		break;

					 		case 2: cout<<"Enter the new product price : ";
					 				cin>>update_item_price;
									break;

					 		case 3: cout<<"Enter the new product units : ";
					 		 		cin>>update_item_units;
									break;

					 		case 4: cout<<"Enter the new product manufacture : ";
					 		 		getline(cin, update_item_company);
									break;

						}
			}
	
			switch(category_number) {
		
				case 1 : switch(category_details_number) { 
					 		
							 case 5: cout<<"Enter the new publication year : ";
					 		 		 cin>>update_magazine_yr;
							 		 break;	

					 		 case 6: cout<<"Enter the new publication month : ";
					 				 cin>>update_magazine_month;
								     break;	
				 		 }

				 		 break;
		
				case 2 : switch(category_details_number) {
					 		
							 case 5: cout<<"Enter the new author name : ";
					 		 		 getline(cin, update_book_author);
							 		 break;
				 		 }
				 
				         break;
				
				case 3 : switch(category_details_number) {

					 		 case 5: cout<<"Enter the new actor name : ";
					 				 getline(cin, update_movie_actor);
									 break;
				 		 }
				 
				 		 break;
			}
		}

		friend void updateItemsLogic();
};

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
		cout<<"Register is completed and the data is saved !"<<endl<<endl;
		
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
			
	/**/		getline(in_log_file_user, password);
			
			if((offset_pass = password.find(pass, 0))!= string::npos) {	
				validate_pass = true;
				break;
			} else {
				validate_pass = false;	
			}	
		}
		
		if(validate_pass == true) {
			cout<<"Password is matched !"<<endl<<endl;
		} else {
			cout<<"Password incorrect ! Please try again later"<<endl<<endl;
			exit(1);	
		}
	
		in_log_file_user.close();
	}
}

/*********************************************** menuLogic() ***********************************************/

void menuLogic() {
	
	Menu menu_obj;
	char proceed;
	
	do {
		menu_obj.menuDisplay();
		menu_obj.menuSelection();
		cout<<endl;
		
		switch(menu_obj.selection) {
			case 0 : cout<<"Thank you for using !";
					 exit(0);
				 	 break;
				 		
			case 1 : cout<<"Reading from the file...."<<endl<<endl;
				 	 cout<<"===================================="<<endl;
				 	 cout<<"              LOGIN                 "<<endl;
	             	 cout<<"===================================="<<endl;
				 	 cout<<endl;

				 	 loginUserValidationLogic();
				 	 break;
				 
			case 2 : cout<<"===================================="<<endl;
				 	 cout<<"              REGISTER              "<<endl;
		         	 cout<<"===================================="<<endl;
					 cout<<endl;

		         	 registerLogic();
				 	 break;

			case 3 : cout<<"===================================="<<endl;
				 	 cout<<"              VIEW ITEMS            "<<endl;
		         	 cout<<"===================================="<<endl;
					 cout<<endl;

					 showItemLogic();
					 break;
				 
			case 4 : cout<<"=========================================="<<endl;
				 	 cout<<"              INSERT NEW ITEMS            "<<endl;
		         	 cout<<"=========================================="<<endl;
					 cout<<endl;

					 insertNewItemsLogic();
					 break;

			case 5 : cout<<"=========================================="<<endl;
				 	 cout<<"              UPDATE ITEMS                "<<endl;
		         	 cout<<"=========================================="<<endl;
					 cout<<endl;

					 //updateItemsLogic();
					 break;
			
			case 6 : cout<<"=========================================="<<endl;
				 	 cout<<"              DELETE ITEMS                "<<endl;
		         	 cout<<"=========================================="<<endl;
					 cout<<endl;

					 deleteItemsLogic();
					 break;
		}
	
		cout<<endl;
		cout<<"Would you like to continue ? [ Y / N ]"<<endl;
		cin>>proceed;
		cout<<endl;
	
		//cin.ignore();

	} while (proceed == 'Y' || proceed == 'y');
	
	cout<<endl;
	cout<<"Thank you for using !";	
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

			new_itemid = insert_new_obj.id;
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
	
/*********************************************** int main() ***********************************************/

int main() {	
	
	menuLogic();
	//deleteItemsLogic();
		
	return 0;
}




/*********************************************** updateItemLogic() ***********************************************/

/*void updateItemsLogic() {

	InsertNewItems insert_item_obj;
	UpdateItem update_item_obj;
	
	Magazine insert_magazine_obj;
	Book insert_book_obj;
	Movie insert_movie_obj;

	ifstream in_update_file;	// read the file
	ofstream out_update_file;	// update the file

	/*int rand_no = insert_item_obj.getInsertRandGenerate();
	int newid = insert_item_obj.id;
	int new_itemunits = insert_item_obj.new_item_units;		//oname.find()
	string new_itemcompany = insert_item_obj.new_item_company;
	string new_itemname = insert_item_obj.new_item_name;
	float new_itemprice = insert_item_obj.new_item_price;
	int shop_itemyr = insert_magazine_obj.shopitem_yr;
	int shop_itemmonth = insert_magazine_obj.shopitem_month;
	string shop_itemauthor = insert_book_obj.shopitem_author;
	string shop_itemactor = insert_movie_obj.shopitem_actor;

	int update_itemunits = update_item_obj.update_item_units;		//find(user key in to update)
	string update_itemname = update_item_obj.update_item_name;
	string update_itemcompany = update_item_obj.update_item_company;
	float update_itemprice = update_item_obj.update_item_price;
	int shopupdate_itemyr = update_item_obj.update_magazine_yr; 
	int shopupdate_itemmonth = update_item_obj.update_magazine_month;
	string shopupdate_itemauthor = update_item_obj.update_book_author;
	string shopupdate_itemactor = update_item_obj.update_movie_actor;

										
	update_item_obj.updateItemsCategory();
	update_item_obj.updateItemsInput();
	update_item_obj.updateItemsAskInput();

	cout<<endl;

	if(update_item_obj.category_number == 1) {
		
		in_update_file.open("owner-magazine-insert.txt");
		out_update_file.open("owner-magazine-update.txt", std::ios_base::app);

	}


	/////////////////////////	
}


// CREDIT : https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
//          https://www.youtube.com/watch?v=s3-DmI1ZWxE&t=151s
//			http://key-to-programming.blogspot.com/2015/01/program-for-auto-number-generator-auto.html
//			https://www.educative.io/edpresso/what-is-a-cpp-abstract-class
//          https://www.youtube.com/watch?v=1xH_w-bTOVc&list=LLKDL2NRkpulBjnktk_gDrsQ&index=1&t=1459s
//			https://github.com/nouman-newworld/file-handling/blob/master/c%2B%2B%20file%20handling%202020
//          https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/


/***random gen number issue***/