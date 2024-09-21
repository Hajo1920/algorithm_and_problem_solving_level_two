#include <cmath>
#include <cstddef>
#include <iostream>
using namespace std;

enum enCheckPrime {Prime=1, NotPrime=2};

int ReadRandom(int from, int to){
    int random = rand() % (to - from) + from;
    return random;
}

enCheckPrime CheckPrime(int number){
    int M = round(number / 2);

    for(int x = 2; x <= M; x++){
        if(number % x == 0) return enCheckPrime::NotPrime;
    }
    return enCheckPrime::Prime;
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



void CopyOfPrimeNumbersArray(int arr[100], int arr2[100], int arrLength,int& arr2Length){
   
    int counter= 0;
    for(int x = 0; x < arrLength; x++){
        if(CheckPrime(arr[x]) == enCheckPrime::Prime){
            arr2[counter] = arr[x];
            counter++;
        }
    }
    arr2Length = --counter;
    
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
    cout << "\nArray-1 all digits: " << endl;
    PrintArray(arr, arrLength);
    
    int arr2[100], arr2Length = 0;
    CopyOfPrimeNumbersArray(arr, arr2, arrLength, arr2Length);
    cout << "\nCopy of array-1 prime nums only: " << endl;
    PrintArray(arr2, arr2Length);
    return 0;
}