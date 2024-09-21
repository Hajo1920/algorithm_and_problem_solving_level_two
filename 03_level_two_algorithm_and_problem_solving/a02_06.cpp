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
    // string num_str = to_string(num);
    // for(int i = num_str.length(); i >= 0; i--){
    //     cout << num_str[i] << endl;
    // }

    int Reminder = 0;
    int sum = 0;
    while (num > 0) {
        Reminder = num % 10;
        num = num / 10;
        sum+=Reminder;
    
    }
    cout << "Sum of all: "<< sum << endl;
}

int main(){
    PrintReversed(ReadNumber("Enter a number"));
    return 0;
}
