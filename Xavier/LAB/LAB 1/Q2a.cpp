#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int reg_hrs, total_hrs, ot;
    float ot_pay, base_pay, reg_wage, ot_wage, total_wage;

    reg_hrs = 40;
    ot_pay = 24.35;
    base_pay = 18.50;

    cout << "Please enter total hours you've worked this week: ";
        cin >> total_hrs;
    if(total_hrs > 40){
        ot = total_hrs - reg_hrs;
    }
    else{
        ot = 0;
        reg_hrs = total_hrs;
    }

    reg_wage = base_pay * reg_hrs;
    ot_wage = ot_pay * ot;

    //total
    total_wage = reg_wage + ot_wage;

    cout << setprecision(2) << fixed << endl << "Wages for this week are RM" << total_wage;

}