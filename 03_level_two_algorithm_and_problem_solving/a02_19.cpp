#include <cstdlib>
#include <iostream>
using namespace std;

int GenerateRandomNumber(int from, int to){
    int random = rand() % (to - from) + from;

    return random;
}

int main(){
    srand((unsigned) time(NULL));

    cout << GenerateRandomNumber(1, 10) << endl;
    cout << GenerateRandomNumber(1, 10) << endl;
    cout << GenerateRandomNumber(1, 10) << endl;

    return 0;
}
