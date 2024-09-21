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
    
int MyRound(float Number) {
     int IntPart;     
     IntPart = int(Number); 
     float FractionsPart = GetFractionPart(Number); 
     if (abs(FractionsPart) >= .5) {
         if (Number > 0) {
            return ++IntPart;
         }else return --IntPart;     
          
          } else { 
            return IntPart;  
            }
                   
                    }
int main(){
    float num = Readnum("Enter a float number to get round");
    cout << "My Round: " << MyRound(num) << endl;
    cout << "C++ Round: " << round(num) << endl;
    return 0;
}