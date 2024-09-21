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

void CopyOfArray(int arr[100], int arr2[100], int arrLength){
   
    int content;
    for(int x = 0; x < arrLength; x++){
        arr2[x] = arr[x];
        
    }
    
}

void SumOffTwoArrayDigits(int arr[100], int arr2[100], int arrSum[100], int arrLength){
    
    for(int x = 0; x <= arrLength; x++){
        arrSum[x] = arr[x] + arr2[x];
    }
}

void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
}

int main(){
    srand((unsigned) time(NULL));
    int arr[100], arrLength;
    ReadAndFillArray(arr, arrLength);
    cout << "\nOriginal array: \n";
    PrintArray(arr, arrLength);
    cout << endl;
    int arr2[100];
    CopyOfArray(arr, arr2, arrLength);
    cout << "\nCopy of array: \n";
    PrintArray(arr2, arrLength);
    cout << endl;
    cout << "\nSum of both array elements: \n";
    int arrSum[100];
    SumOffTwoArrayDigits(arr, arr2, arrSum, arrLength);
    PrintArray(arrSum, arrLength);
    cout << endl;
    return 0;
}
