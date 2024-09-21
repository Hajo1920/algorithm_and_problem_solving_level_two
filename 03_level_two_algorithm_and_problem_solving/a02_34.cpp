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

int ReadSearchNumber(string message){
    int number = 0;
    do {
    cout << message << ": ";
    cin >> number;
    }while (number <= 0);

    return number;
}

short SearchNumber(short number, int arr[100], int arrLength){

    for(short x = 0; x <= arrLength; x++){
        if(number == arr[x]){
            return  x;
        }
    }
    return -1;
}

int main(){
    int arr[100], arrLength;
    ReadAndFillArray(arr, arrLength);
    cout << "Array Elements: ";
    PrintArray(arr, arrLength);
    cout << endl;
    int number  = ReadSearchNumber("Enter the number you want to search from 1 - 100");
    short numberPosition = SearchNumber(number, arr, arrLength);
    cout << "The number you are looking for is " << number << endl;
    if(numberPosition == -1){
             cout << "The number you are serching is not in the list !" << endl;
           
        }else{
            cout << "The number position in array is: "  << numberPosition << endl;
            cout << "The number Order in array is: "  << numberPosition+1 << endl;
        }

        return 0;
}
