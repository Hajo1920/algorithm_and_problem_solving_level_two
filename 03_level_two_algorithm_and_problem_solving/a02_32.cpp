#include <iostream>
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
        arr[x] = ReadRandom(1, 100);
    }
}

void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
}

void CopyOfArray(int arr[100], int arr2[100], int arrLength){
       for(int x = 0; x < arrLength; x++){
        arr2[x] = arr[(arrLength-1)-x];
       }
}


int main(){
    srand((unsigned) time(0));
    int arr[100], arrLength;
    ReadAndFillArray(arr, arrLength);
    PrintArray(arr, arrLength);
    
    int arr2[100];
    CopyOfArray(arr, arr2, arrLength);
    cout << "\nCopy of array: ";
    PrintArray(arr2, arrLength);
    return 0;
}
