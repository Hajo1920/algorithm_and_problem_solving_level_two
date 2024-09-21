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

void IncrementNumber(int number){

    for(int x = number; x >= 1; x--){
      
        for(int y = 1; y <= x-1; y++ ){
            cout << x;
        }
          cout << x << endl;
    }
}


int main(){
    IncrementNumber(ReadNumber("Please enter a number"));
    return 0;
}
