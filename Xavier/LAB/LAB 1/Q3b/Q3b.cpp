#include <iostream>
#include <string>        // Needed to use string objects
#include <cctype>        // Needed for the toupper function
using namespace std;
int main()
{    char ch;
     int vowelCount = 0;
     string sentence;
     cout << "Enter any sentence you wish and I will \n"
		 << "display the sentence in uppercase.\n";
	getline(cin, sentence);
	for (int pos = 0; pos < sentence.length(); pos++)
     {	// Uppercase a copy of the next character and assign it to ch
        putchar(toupper(sentence[pos]));
	}
      cout<<endl;
      return 0;
}
