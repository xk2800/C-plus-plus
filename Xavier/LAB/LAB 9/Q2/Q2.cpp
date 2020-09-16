#include <iostream>

using namespace std;

class ChoreographyMarks{

    private:
        float points, total;

    public:
        ChoreographyMarks(){

            total = 30;
        }

        void setCgPoints(){

            cout<<"Enter Choreography Marks [max: 30]\t: ";
                cin>>points;
        }

    friend class Dancer;

};

class InventiveMarks{

    private:
        float points, total;

    public:
        InventiveMarks(){

            total = 20;
        }

        void setInvPoints(){

            cout<<"Enter Inventive Marks [max: 20]\t:";
                cin>>points;

                cin.ignore();
        }

    friend class Dancer;

};

class Dancer{

    private:
        string name;
        int age;
        float finalpoints=0, cpoints=0, ipoints=0;

    public:
        void set_details(){

            //age, name
            cout<<"Enter name\t\t:";
                getline(cin, name);
                //cin.ignore();
            cout<<"Enter age\t\t:";
                cin>>age;
        }

        void calcFinalPoints(ChoreographyMarks C, InventiveMarks I){

            cpoints = (C.points /C.total) * 100;
            ipoints= (I.points /I.total) * 100;
            finalpoints = (C.points + I.points) / (C.total + I.total);
        }

        int getAge(){

            return age;
        }

        string getName(){

            return name;
        }

        void displayScoreDetails(){

            cout<<":::::Score Board:::::"<<endl;
            cout<<"Choreography\t: "<<cpoints<<endl;
            cout<<"Inventive\t\t: "<<ipoints<<endl;
            cout<<"Final Score\t: "<<finalpoints<<endl;
        }
};

int main(){

    int dancers;

    cout<<"Enter number of dancers"<<endl;
        cin>>dancers;
    cout<<endl;
    
    cin.ignore();
    
    ChoreographyMarks *c_array = new ChoreographyMarks[dancers];
    InventiveMarks *i_array = new InventiveMarks[dancers];

    ChoreographyMarks C;
    InventiveMarks I;

    Dancer D;

    for(int k=0; k<dancers; k++){

        cout<<":::::Details for Dancer::::: ";

        D.set_details();
        D.calcFinalPoints(C, I);

        c_array->setCgPoints();
        i_array->setInvPoints();

        cout<<endl<<"========================================="<<endl;
        cout<<"Dancer #"<<k+1<<endl;
        cout<<"========================================="<<endl;
        cout<<"Name = "<<D.getName()<<endl;
        cout<<"Age = "<<D.getAge()<<endl;

        D.displayScoreDetails();
    }

    delete[] c_array, i_array;

    return 0;
}