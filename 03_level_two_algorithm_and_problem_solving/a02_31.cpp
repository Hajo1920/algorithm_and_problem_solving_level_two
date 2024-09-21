#include <cmath>
#include <cstddef>
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
        arr[x] = x+1;
    }
}

void Swap(int& num1, int& num2){
    int Temp = 0;
    Temp = num1;
    num1 = num2;
    num2 = Temp;
}

void ShuffleArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
       Swap(arr[ReadRandom(1, arrLength)-1] , arr[ReadRandom(1, arrLength)]);
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
    cout << "\nArray before shuffle " << endl;
    PrintArray(arr, arrLength);
    
    ShuffleArray(arr,arrLength);
    cout << "\nArray after shuffle " << endl;
    PrintArray(arr, arrLength);
    return 0;
}