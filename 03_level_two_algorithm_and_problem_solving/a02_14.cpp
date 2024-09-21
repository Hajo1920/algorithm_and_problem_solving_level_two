#include <iostream>
using namespace std;

int ReadNumber(string message){
    int number = 0;
    do
    {
        cout << message << ": ";
        cin >> number;
    } while(number <= 0);
    return number;
}

void IncrementNumbersPrintLetter(int number){
    int letters = 64+number;
    for(int x = number; x >= 1; x--){
        cout << endl;
        for(int y = 1; y <= x; y++ ){
           
            cout << char(letters);
        }
         letters--;    
          
    }
}

int main(){
    IncrementNumbersPrintLetter(ReadNumber("Please enter a number"));
     cout << endl;
    return 0;
}
