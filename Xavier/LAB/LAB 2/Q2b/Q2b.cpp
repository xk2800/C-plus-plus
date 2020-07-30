#include <iostream>
#include <string>

using namespace std;

double calcu(double marks[], int size);
string grades(double);

int main(){

    double marks[5], avg;
    string name, grade;

    cout<<"Enter Name: ";
    getline(cin, name);

    for(int i=0; i<5; i++){
        
        cout<<"Enter Marks : ";
        cin>>marks[i];
    }

    avg = calcu(marks, 5);

    grade = grades(avg);

    cout<<"Name : "<< name<< endl<< "Average : "<< avg<< endl<< "Grade : "<<grade << endl;

    return 0;

}

double calcu(double marks[], int size){
    
    double total, avg;

    for(int i=0; i<size; i++){

        total += marks[i];
    }

    //cout<<total <<endl;

    avg = total/size;

    return avg;

}

string grades(double avg){

    string grade;

    if(avg >= 80){
        grade="A";

    }else if(avg>=60){
        grade="B";

    }else if(avg >= 50){
        grade="C";

    }else{
        grade="F";
    }

    return grade;
}