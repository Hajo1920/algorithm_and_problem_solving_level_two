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

void DicrementNumber(int number){

    for(int x = 1; x <= number; x++){
       cout << endl;
        for(int y = x; y >= 1; y--){
            cout << x;
        }
         
    }
}

int main(){
    DicrementNumber(ReadNumber("Please enter a number"));
    return 0;
}
