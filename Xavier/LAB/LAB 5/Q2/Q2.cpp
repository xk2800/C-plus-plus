#include <iostream>

using namespace std;


class Achievement{

    string classname, result;
    int score;

    public:
        void set_data(string name1, int score1){

            classname = name1;
            score = score1;
        }

        void display_scale(){
            
            if(score >= 85 && score <=100){
                result="*****";
            }else if(score>=70 && score<=84.9){
                result="****";
            }else if(score>=60 && score<=69.9){
                result="***";
            }else if(score>=50 && score<=59.9){
                result="**";
            }else{
                result="Poor Achievement";
            }

            cout<<"===================================="<<endl<<classname<<endl<<"The Class Passing Grade Achievement: "<<score<<"%"<<endl<<result<<endl;
        }
};

int main(){

    Achievement a[4];
    string name;
    int score;

    cout<<"==================================="<<endl<<"\tEnter Class Achievement"<<endl<<"===================================";

    for(int i=0; i<4; i++){

        cout<<endl<<"Enter the class name\t: ";
            cin>>name;
        cout<<"The class achievement (%) : ";
            cin>>score;
        a[i].set_data(name, score);
    }

    cout<<endl<<endl<<endl<<" THE SUMMARY OF UPSR TRAIL EXAM RESULTS"<<endl;

    for(int i=0; i<4; i++){
        a[i].display_scale();
    }

    cout<<"========================================"<<endl;

}