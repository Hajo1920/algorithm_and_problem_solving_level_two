#include <iostream>
using namespace std;

void ReadNumbers(int& numbers, short& digit){
    cout << "Enter Numbers: ";
    cin >> numbers;
    cout << "Enter number to check frequncy of it: ";
    cin >> digit;

}

int CheckDigitFrequency(int num, short digit){
   
    int Reminder = 0, frequncy = 0;
    while (num > 0) {
        Reminder = num % 10;
        num = num / 10;
        if(Reminder == digit){
            frequncy ++;
        }
    
    }
    return frequncy;

}

void PrintResult(short digit, int frequncy){
    cout << "Digit " << digit << " frequency is " << frequncy << " Time(s)" << endl;
}

int main(){
    int numbers;
    short digit;
    ReadNumbers(numbers, digit);
    PrintResult(digit,CheckDigitFrequency(numbers, digit));
    return 0;
}
