#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float Readnum(string message){
    float num;

    cout << message << ": ";
    cin >> num;
  

    return num;
}

float GetFractionPart(float Number) {  
    return Number - int(Number); 
    } 
    
int MyCeil(float Number) {
    if(GetFractionPart(Number) > 0){
         if(Number < 0){
        return  int(Number);
    }

    return (int)Number +1;
    }

    return (int) Number;            
}
int main(){
    float num = Readnum("Enter a float number to get Ceil");
    cout << "My Ceil: " << MyCeil(num) << endl;
    cout << "C++ Ceil: " << ceil(num) << endl;
    return 0;
}