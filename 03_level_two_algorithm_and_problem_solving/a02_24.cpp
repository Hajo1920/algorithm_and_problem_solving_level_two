#include <cstdlib>
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

int FindTheBiggestDigit(int arr[100], int arrLength){
    int biggestDigit = 0;
    for(int x = 0; x < arrLength - 1; x++){
        if(arr[x] > biggestDigit){
            biggestDigit = arr[x];
     
        }
         
    }
    return biggestDigit;
}


int main(){
    srand((unsigned) time(NULL));

    int arr[100], arrLength;
    ReadAndFillArray(arr, arrLength);
    cout << "Array elements: ";
    PrintArray(arr, arrLength);
    cout << endl;
    cout << "Biggest digit: " << FindTheBiggestDigit(arr, arrLength) << endl;
    return 0;
}
