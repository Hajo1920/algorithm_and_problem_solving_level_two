#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string message){
    int num = 0;
    cout << message << ": ";
    cin >> num;
    return num;
}

void PrintReversed(int num){

    int Reminder = 0, num2 = 0;
    while (num > 0) {
        Reminder = num % 10;
        num = num / 10;
        num2 = (num2 * 10) + Reminder;
        
    
    }
    cout << num2;
}

int main(){
    PrintReversed(ReadNumber("Enter a number"));
    return 0;
}
