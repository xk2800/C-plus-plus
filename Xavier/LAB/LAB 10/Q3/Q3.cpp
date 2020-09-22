#include <iostream>
using namespace std;


class Numbers
{
   private:
      int* numbersOriginal;
      int size;
  
   public:

      Numbers(): size(3){

         numbersOriginal = new int[size];

         for(int k=0; k<size; k++){

            numbersOriginal[k] = 5;
         }
      }

      ~Numbers(){

         delete[] numbersOriginal;
         numbersOriginal = nullptr;
      }

      void displayOriginal();
      void getNumbers();
      void displaySorted();
};


//
// If needed, declare functions here
//



int main()
{
   Numbers a;
   cout << "Initial values by the default constructor :";
   a.displayOriginal();
   cout << endl;
   
   a.getNumbers();
   cout << "Display in the ascending order : ";
   a.displaySorted();
   cout << endl;
   cout << "Display in the original order : ";
   a.displayOriginal();
   cout << endl;
   
   Numbers num;

   cout<<"Initial values by the default constructor :";
   num.displayOriginal();

   num.getNumbers();
   cout<<endl<<"Display in the ascending order : ";
   num.displaySorted();
   cout<<endl<<"Display in the original order : ";
   num.displayOriginal();
   cout<<endl;

   return 0;

}


// Definition of class member functions from here

void Numbers::displayOriginal(){

   for(int j=0; j<size; j++){

      cout<<numbersOriginal[j]<<" ";
   }
}

void Numbers::getNumbers(){

   cout<<"How many numbers are needed? ";
      cin>>size;
   numbersOriginal = new int[size];

   for(int h=0; h<size; h++){

      cout<<"Number "<<h+1<<" : ";
         cin>>numbersOriginal[h];
   }
}

void Numbers::displaySorted(){

   int* numberAsc = new int[size];
   int swap;

   for(int j=0; j<size; j++){

      numberAsc[j] = numbersOriginal[j];
   }

   for(int q=0; q<size; q++){

      for(int w=0; w<size; w++){

         if(numberAsc[q]<numberAsc[w]){

            swap=numberAsc[w];
            numberAsc[w]=numberAsc[q];
            numberAsc[q]=swap;
         }
      }
   }

   for(int i=0; i<size; i++){

      cout<<numberAsc[i]<<" ";
   }

   delete[] numberAsc;
   numberAsc=nullptr;
}

// If needed, definition of functions from here
