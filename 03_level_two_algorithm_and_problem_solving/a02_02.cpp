#include <iostream>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

float ReadPostiveNumber(string Message){
    float Num;

        cout << "Enter a numbers to check Prime or not Prime: ";
        cin >> Num;
    while(Num <= 0){
        cout << Message;
        cin >> Num;
    }

    return Num;

}

enPrimeNotPrime CheckForPrimeNumber(int Num){
    int M = (Num / 2);

    for(int counter = 2; counter <= M; counter++){
      if(Num % counter == 0)  return enPrimeNotPrime::NotPrime;

    }
    return enPrimeNotPrime::Prime;
}

void PrintNumberType(int Num){
    cout << "Prime Numbers from 1 to "<< Num << " are" << endl;
  for(int i = 1; i <= Num; i++){
    if(CheckForPrimeNumber(i) == enPrimeNotPrime::Prime){
        cout << i << endl;
    }
  }
}

int main(){

    PrintNumberType(ReadPostiveNumber("Please Enter a postive number: "));
    return 0;
}