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



int FindTheSmallestDigit( int arr[100], int arrLength){
    int smallestDigit = 0;
    smallestDigit = arr[0];
    for(int x = 0; x < arrLength; x++){
        if(arr[x] < smallestDigit){
          smallestDigit = arr[x];
     
        }
         
    }
    return smallestDigit;
}


int main(){
    srand((unsigned) time(NULL));

    int arr[100], arrLength;
    ReadAndFillArray(arr, arrLength);
    cout << "Array elements: ";
    PrintArray(arr, arrLength);
    cout << endl;
    cout << "Smallest digit: " << FindTheSmallestDigit(arr, arrLength) << endl;
    return 0;
}
