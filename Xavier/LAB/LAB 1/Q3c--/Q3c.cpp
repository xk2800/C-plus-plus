#include <iostream>
#include <iomanip>
using namespace std;
int main()
{    const int NUM_EMPS = 5;
	int index;
	int hours[NUM_EMPS];         // Define 2 parallel arrays
	double payRate[NUM_EMPS];
	double grossPay;

	// Get employee work data
	cout << "Enter the hours worked and hourly pay rates of "
		 << NUM_EMPS << " employees. \n";  

	for (index = 0; index < NUM_EMPS; index++)
	{  cout << "Hours worked by employee #" << (index + 1) << ": ";
        cin  >> hours[index];
	   cout << "Hourly pay rate for employee #" << (index + 1) << ": ";
        cin  >> payRate[index];
	}
	// Display the data
	
	return 0;
}
