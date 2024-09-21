#include <iostream>
#include <cmath>

using namespace std;

int ReadRandom(int from, int to){
    int random = rand() % (to - from) + from;
    return random;
}

void ReadAndFillArray(int arr[100], int&arrLength){
  arrLength = 5;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 20;
  arr[4] = 10;
//   arr[5] = 90;
//   arr[6] = 60;
//   arr[7] = 80;
//   arr[8] = 60;
//   arr[9] = 50;
//   arr[10] = 50;

}

bool isArrayPalindrome(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        if(arr[x] == arr[arrLength-1] - x){
            return true;
        }
    }
    return false;
}

void PrintArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
        cout << arr[x] << " ";
    }
    
}
int main(){

    srand((unsigned) time(0));
    int arr[100], arrLength = 0;
    ReadAndFillArray(arr, arrLength);

    cout << "Array-1 Elements: ";
    PrintArray(arr, arrLength);
    cout << endl;

    if(isArrayPalindrome(arr, arrLength)) cout << "This array is palindrome" << endl;
    else cout << "This array is not palindrome" << endl;

    return 0;

}