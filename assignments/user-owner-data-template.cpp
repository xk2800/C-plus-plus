#include<fstream>
#include<iostream>
using namespace std;
int main() {
	
	ofstream out_reg_file_template;
	
	out_reg_file_template.open("owner-details.txt", std::ios_base::app);
	
	if(out_reg_file_template) {
		out_reg_file_template<<"=============================="<<endl;
		out_reg_file_template<<"   Shop Owner Account Details   "<<endl;
		out_reg_file_template<<"=============================="<<endl;
		out_reg_file_template<<"Username      Password      Confirm Password"<<endl<<endl;
		
		cout<<"The owner data template has been created ! You shall proceed to run your program";
	} else {
		cout<<"The file is not file";	
	}
	
	out_reg_file_template.close();
}