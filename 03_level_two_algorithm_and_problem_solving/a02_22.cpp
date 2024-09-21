#include <iostream>
using namespace std;

int ReadInput(string message){
    int input = 0;
    do
    {
        cout << message << ": ";
        cin >> input;

    } while(input <= 0);

    return input;
}

void ReadArray(int arr[100], int&arrLength){
   do
    {
        cout  << "Enter amount of array elements to add: ";
        cin >> arrLength;

    } while(arrLength <= 0);
    for(int x = 0; x < arrLength; x++){
        cout << "Element ["<<x+1<<"]: ";
        cin >> arr[x];
    }
}

void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
}

int ElementRepeatChecker(int NumberToCheck, int arr[100], int arrLength){
    int count = 0;

    for(int x = 0; x <= arrLength - 1; x++){
        if(NumberToCheck == arr[x]){
            count++;
        }
    }

    return count;
}

int main(){
    int arr[100], arrLength, NumberToCheck;
    ReadArray(arr, arrLength);

    NumberToCheck = ReadInput("Enter number of element to check");
    cout << "\nOriginal Array: ";
    PrintArray(arr, arrLength);

    cout << "\n Number " << NumberToCheck << " is repeated {";
    cout << ElementRepeatChecker(NumberToCheck, arr, arrLength) << "} time(s)" << endl;

    return 0;
}
