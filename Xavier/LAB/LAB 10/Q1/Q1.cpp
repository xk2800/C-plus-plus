//KHEW XAVIER ETHAN 1181202757

#include <iostream>
using namespace std;

int main ()
{
    int subject,num;
    double totalPayment = 0, averagePayment;
    double *fees;

    /* Display and get total subjects registered */
    cout << "How many subjects you have registered: ";
        cin >> subject;

    fees = new double [subject]; //new operator

    for( num = 0; num < subject; num++ )
    {
        cout << "Class " << num + 1 << " fees charge: RM ";
            cin >> *( fees + num );

    }

     /* Display Sept payment details; 
        whereas fees charges entered by user will be displayed accordingly */
    cout << "==== SEPTEMBER 2016 PAYMENT DETAILS =====" << endl;
    cout << "Fees charges you have entered: ";

    for(num=0; num<subject; num++){

        cout << *( fees + num ) << "(RM) ... ";
        totalPayment += *(fees + num);
        
    }

    cout << endl << "Total payment to be made: RM" << totalPayment << endl;

    averagePayment = totalPayment / subject;
    
    cout << "Minimum payment (Average of total payment) : RM " << averagePayment;

    return 0;
}
