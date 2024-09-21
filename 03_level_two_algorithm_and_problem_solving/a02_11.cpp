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

int StructureDigitsFromLeftToRight(int nums){
    int leftToRight = 0, reminder = 0;
    while(nums > 0){
        reminder = nums % 10;
        nums = nums /10;
        leftToRight = (leftToRight * 10 )+ reminder;
    }
    return leftToRight;
}


void PrintPalindromeOrNot(int num){
    if(StructureDigitsFromLeftToRight(num) == num) {
        cout << "Yes it is palindrome number" << endl;
    }else cout << "No it is not a palindrome number" << endl;
}

int main(){

    PrintPalindromeOrNot(ReadNumbers("Enter numbers sequence to check palindrome"));
    return 0;
}
