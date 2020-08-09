#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


//add on 
struct Student
{    char name[30], grade; double marks[5], avg;

};

double calcu(double marks[], int size);
char grades(double);

int main(){

    //double marks[5], avg;
    //string name, grade;

    Student stud;
    cout<<"Enter Name: ";
    cin.get( stud.name, 30);

    for(int i=0; i<5; i++){
        
        cout<<"Enter Marks : ";
        cin>>stud.marks[i];
    }

    stud.avg = calcu(stud.marks, 5);

    stud.grade = grades(stud.avg);

    cout<<"Name : "<< stud.name<< endl<< "Average : "<< stud.avg<< endl<< "Grade : "<<stud.grade << endl;

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

char grades(double avg){

    char grade;

    if(avg >= 80){
        grade='A';

    }else if(avg>=60){
        grade='B';

    }else if(avg >= 50){
        grade='C';

    }else{
        grade='F';
    }

    return grade;
}