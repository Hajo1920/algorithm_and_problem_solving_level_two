#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int ReadInput(string message){
    int input;

    cout << message << ": ";
    cin >> input;
  

    return input;
}

int MyAbs(int input){
    int abs = input*-1;

    if(input >= 0){
        return input;
    }
    else return abs;
    
}

int main(){
    int input = ReadInput("Enter a number to get abs");
    cout << "My Absolute: " << MyAbs(input) << endl;
    cout << "C++ Absolute: " << abs(input) << endl;
    return 0;
}