#include <iostream>
#include<iomanip>

using namespace std;


class Staff{

    protected: 
        string name, id;
        int age;
        float salary, nett_salary;

        public:
            void setdata(){

                cout<<"Enter Name\t: ";
                    cin.ignore();
                    getline(cin, name);
                cout<<"Enter ID\t: ";
                    cin>>id;
                cout<<"Entre Age\t: ";
                    cin>>age;
                cout<<"Enter salary\t: ";
                    cin>>salary;

            }

                float nett_sal(){

                    return nett_salary;
                }
};

class Executive:public Staff{

    private:
        int OT_hrs; float rate;

    public:
        void setExecutive(){

            cout<<"Enter OT_hrs\t: ";
                cin>>OT_hrs;
            cout<<"Enter Rate\t: RM ";
                cin>>rate;
        }

        void cal_salary_exec(){

            nett_salary=salary+(OT_hrs*rate);

            //return nett_salary;
        }

        void display(){

            //name, id, age, salary = setdata();
            
            cout<<endl<<"Name\t\t: "<<name<<endl;
            cout<<"ID\t\t: "<<id<<endl;
            cout<<"Age\t\t: "<<age<<endl;
            cout<<"Salary\t\t: RM"<<salary<<fixed<<setprecision(2)<<endl;
            cout<<"OT Hours\t: "<<OT_hrs<<endl;
            cout<<"OT Rate\t\t: RM"<<rate<<endl<<fixed<<setprecision(2);
            cout<<"Nett Salary\t: RM"<<nett_salary<<fixed<<setprecision(2);
        }

};


class Salesperson:public Staff{

    private:
        int units;
        float bonus;

    public:
        void setSalesperson(){

            cout<<"Enter Units\t: ";
                cin>>units;
        }

        void cal_salary_sales(){

            if(units>500){

                bonus = 500;
            } else{

                bonus = 250;
            }

            nett_salary = salary + bonus;
        }

        void display(){

            //name, id, age, salary = setdata();
            
            cout<<endl<<"Name\t\t: "<<name<<endl;
            cout<<"ID\t\t: "<<id<<endl;
            cout<<"Age\t\t: "<<age<<endl;
            cout<<"Salary\t\t: RM "<<salary<<fixed<<setprecision(2)<<endl;
            cout<<"Units\t\t: "<<units<<endl;
            cout<<"Bonus\t\t: RM"<<bonus<<endl<<fixed<<setprecision(2);
            cout<<"Nett Salary\t: RM"<<nett_salary<<fixed<<setprecision(2);
        }


};


int main(){

    Staff staff;
    Executive exec;
    Salesperson sales;

    int choice, staf=0, staf_tote=0;
    char con;
    double total=0, sal;
    //float nett_salary;

    cout<<"Do you want to continue ? ";
        cin>>con;

    while(con=='Y'){

        cout<<"Enter [1] for Executive     OR    [2] for Salesperson : ";
            cin>>choice;

        
        if(choice==1){

            exec.setdata();
            exec.setExecutive();
            exec.cal_salary_exec();
            exec.display();
            sal = exec.nett_sal();

            staf +=1;

        } else if(choice==2){

            sales.setdata();
            sales.setSalesperson();
            sales.cal_salary_sales();
            sales.display();
            sal = sales.nett_sal();


            staf +=1;
        } else{

            cout<<"Invalid Entry"<<endl;
        }

        total +=sal;

        cout<<endl<<"Do you want to continue ? ";
        cin>>con;
    }

    staf_tote +=staf;
    

    //tote1 = exec.cal_salary_exec();

    cout<<"Total staff:"<<staf_tote<<endl;
    cout<<"Total Payouts is RM "<<total;
}