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
        arr[x] = ReadRandom(1, 100);
    }
}

void AddArrayElement(int number, int arr[100], int& arrLength){

    arrLength++;
    arr[arrLength-1] = number;
   
}

void CopyOddNumbersArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength) {
     
     for (int i = 0; i < arrLength; i++)        
     if(arrSource[i] % 2 == 1){
         AddArrayElement(arrSource[i], arrDestination, arrDestinationLength); 
     }

    }

void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
    
}
int main(){

    srand((unsigned) time(0));
    int arr[100], arrLength = 0 , arr2Length = 0;
    ReadAndFillArray(arr, arrLength);

    int arr2[100];
    CopyOddNumbersArray(arr, arr2, arrLength, arr2Length);
    cout << "Array-1 Elements: ";
    PrintArray(arr, arrLength);
    cout << endl;
    cout << "Array-2 Elements: ";
    PrintArray(arr2, arr2Length);
    cout << endl;

    return 0;

}