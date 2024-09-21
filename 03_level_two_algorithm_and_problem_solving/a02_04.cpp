#include <iostream>
using namespace std;

int ReadNumber(string message){
    int Number = 0;
   do{
    cout << message << ": ";
    cin >> Number;
   }while(Number <= 0);

   return  Number;
}

bool GetNumberDivisions(int Number){
    int sum = 0;
    for(int x = 1; x < Number; x++){
        if(Number % x == 0) {
            sum+=x;
        }
    }
    return sum ==  Number;
}

void PrintPerfectNumber(int Number){
   for(int i = 1; i <= Number; i++){
    if(GetNumberDivisions(i)) cout << i << endl;
   }
}

int main(){
    PrintPerfectNumber(ReadNumber("Enter a number"));
    return 0;
}