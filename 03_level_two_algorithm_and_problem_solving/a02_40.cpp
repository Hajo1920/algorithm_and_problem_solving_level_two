#include <iostream>
#include <cmath>

using namespace std;

int ReadRandom(int from, int to){
    int random = rand() % (to - from) + from;
    return random;
}

void ReadAndFillArray(int arr[100], int&arrLength){

  arrLength = 10;
  arr[0] = 70;
  arr[1] = 70;
  arr[2] = 70;
  arr[3] = 70;
  arr[4] = 80;
  arr[5] = 90;
  arr[6] = 60;
  arr[7] = 80;
  arr[8] = 60;
  arr[9] = 50;
  arr[10] = 50;

}

void AddArrayElement(int number, int arr[100], int& arrLength){

    arrLength++;
    arr[arrLength-1] = number;
   
}

short SearchNumber(short number, int arr[100], int arrLength){

    for(short x = 0; x <= arrLength; x++){
        if(number == arr[x]){
            return x;
        }
    }
    return -1;
}

bool IsNumberInArray(short number, int arr2[100], int arr2Length){
    return SearchNumber(number, arr2, arr2Length) != -1;
}

void CopyDistinctElements(int arrSource[100], int arr2[100], int arrLength, int& arr2Length) {
    for(int x = 0; x < arrLength; x++){
        if (!IsNumberInArray(arrSource[x], arr2, arr2Length)){
               AddArrayElement(arrSource[x], arr2, arr2Length);
        }
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
    CopyDistinctElements(arr, arr2, arrLength, arr2Length);
    cout << "Array-1 Elements: ";
    PrintArray(arr, arrLength);
    cout << endl;
    cout << "Array-2 Elements: ";
    PrintArray(arr2, arr2Length);
    cout << endl;

    return 0;

}