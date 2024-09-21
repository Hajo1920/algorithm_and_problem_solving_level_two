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

double MySqrt(int input){
   return (double) pow(input, 0.5);
}

int main(){
    double input = ReadInput("Enter a number to get Sqrt");
    cout << "My SquareRoot: " << (double)MySqrt(input) << endl;
    cout << "C++ SquareRoot: " << sqrt(input) << endl;
    return 0;
}