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

int FindSumOfArray(int arr[100], int arrLength, int sum){

    for(int x = 0; x < arrLength; x++){
     
        sum += arr[x];
    }
    return  sum; 
}

int main(){

    srand((unsigned) time(NULL));
    int arr[100],arrLength, sum = 0;
    ReadAndFillArray(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "\nTotal sum: " << FindSumOfArray(arr, arrLength, sum) << endl;
    return 0;
}
