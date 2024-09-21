#include <iostream>
using namespace std;

int ReadNumbers(string message){
    int numbers = 0;
    do{
        cout << message << ": ";
        cin >> numbers;
   
    }while(numbers <= 0);

    return numbers;
}


int CheckDigitFrequency(short digit,int num){
   
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

void PrintAllDigitFrequencyResult(int num){
    int checkdigit = 0;
    for(int i = 0; i <= 10; i++ ){
        checkdigit = CheckDigitFrequency(i, num);
        if(checkdigit > 0){
            cout << "Digit " << i << " frequency is " << checkdigit << endl;
        }
    }
}

int main(){
    PrintAllDigitFrequencyResult(ReadNumbers("Enter sequence of numbers"));
    return 0;
}
