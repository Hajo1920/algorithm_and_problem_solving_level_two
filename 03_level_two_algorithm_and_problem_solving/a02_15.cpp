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
    int letters = 64;
    for(int x = 1; x <= number; x++){
        
        letters++;
        for(int y = x; y >= 1; y-- ){
           
            cout << char(letters);
        }
        cout << endl;
         
    }
}


int main(){
    IncrementNumbersPrintLetter(ReadNumber("Please enter a number"));
    
    return 0;
}
