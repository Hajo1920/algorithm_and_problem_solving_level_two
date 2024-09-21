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
    
int MyFloor(float Number) {

    if(Number > 0){
        return (int) Number;
    }

    return (int)Number -1;
                   
}
int main(){
    float num = Readnum("Enter a float number to get Floor");
    cout << "My Floor: " << MyFloor(num) << endl;
    cout << "C++ Floor: " << floor(num) << endl;
    return 0;
}