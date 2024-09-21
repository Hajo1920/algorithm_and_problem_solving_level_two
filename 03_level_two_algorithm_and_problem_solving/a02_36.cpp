#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber(){
    int number;
   do
    {
         
        cout  << "Please Inter a number: ";
        cin >>  number;
        
    } while(number <= 0);

   return number;
}

void AddArrayElement(int number, int arr[100], int& arrLength){
    arrLength++;
     arr[arrLength-1] = number;
}

void InputUserNumberInArray(int arr[100], int& arrLength){
    bool addMore = true;

    do {
    AddArrayElement(ReadNumber(), arr, arrLength);
    cout << "Do you want to add another number ? [1]yes [0]No ";
    cin >> addMore;

    }while (addMore);
   
    
}

void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
    
}
int main(){
    int arr[100], arrLength = 0;
    InputUserNumberInArray(arr, arrLength);
    cout << "Array Length: " << arrLength << endl;
    cout << "Array Elements: ";
    PrintArray(arr, arrLength);
    return 0;
}