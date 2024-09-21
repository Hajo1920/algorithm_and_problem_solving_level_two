#include <iostream>
#include <cmath>

using namespace std;

int ReadRandom(int from, int to){
    int random = rand() % (to - from) + from;
    return random;
}

void ReadAndFillArray(int arr[100], int&arrLength){

   do
    {
        cout  << "Enter amount of array elements: ";
        cin >> arrLength;

    } while(arrLength <= 0);
    for(int x = 0; x < arrLength; x++){
        arr[x] = ReadRandom(-100, 100);
    }
}


void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
    
}
int ArrayNegativeNumberCount(int arr[100], int arrLength){
    int counter = 0;
    for(int x = 0; x < arrLength; x++){
        if(arr[x] < 0){
            counter++;
        }
    }
    return counter;
}
int main(){

    srand((unsigned) time(0));
    int arr[100], arrLength = 0;
    ReadAndFillArray(arr, arrLength);

    cout << "Array-1 Elements: ";
    PrintArray(arr, arrLength);
    cout << endl;
    cout << "Odd Number count ";

    cout << ArrayNegativeNumberCount(arr, arrLength) << endl;
    cout << endl;

    return 0;

}