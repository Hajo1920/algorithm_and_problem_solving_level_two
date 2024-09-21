#include <iostream>
using namespace std;

int ReadNumbers(string message){
    int nums = 0;
    do{
        cout << message << ": ";
        cin >> nums;
    }while(nums <= 0);

    return nums;
}

int ReverseNumbers(int nums){
    int reversed = 0, reminder = 0;
    while(nums > 0){
        reminder = nums % 10;
        nums = nums /10;
        reversed = (reversed * 10 )+ reminder;
    }
    return reversed;
}

void PrintDigitsFromLeftToRight(int nums){
    int Remainder = 0;
    while(nums > 0){
        Remainder = nums % 10;
        nums = nums /10;
        
        cout << Remainder << endl;
    }

}

int main(){
    
    PrintDigitsFromLeftToRight(ReverseNumbers(ReadNumbers("Enter number sequence")));
    return 0;
}
