#include<iostream>
using namespace std;

class NumberGame
{ 
  private:
    int array[5];
  
  public:
    NumberGame();

    friend void search(NumberGame , int);

    void display(){
        
        for(int j=0; j<5; j++){
            cout<<array[j]<<endl;
        }
    }
};



int main()
{   NumberGame G ;
    int num;
    cout<<"Enter a number :";
    cin>>num;
    
    search(G, num);
    return 0;
}

NumberGame::NumberGame(): array{15, 20, 33, 38, 100} { }

void search(NumberGame numgame, int num){

    int j = 0;
    bool jumpa = false;

    do{

        if(num == numgame.array[j]){

            jumpa = true; break;
        }else{
            
            jumpa = false;
        }

        j++;
    }while(j<5);

    if(jumpa == true){
        cout<<num<<" is found !";
    }else{
        cout<<num<<" is NOT found !";
    }
}