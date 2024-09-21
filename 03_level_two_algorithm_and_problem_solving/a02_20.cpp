#include <cstdlib>
#include <iostream>
using namespace std;

enum enCharType {smallLetter = 1, capitalLetter=2, specialCharacter=3, digit=4};

int ReadRandom(int from, int to){
    int random = rand() % (to - from) + from;
    return random;
}

char GenerateRnadomCharacter(enCharType charType){
    switch (charType) {
        case enCharType::smallLetter:
        return ReadRandom(97, 122);
        break;

        case enCharType::capitalLetter:
        return ReadRandom(65, 90);
        break;

        case enCharType::specialCharacter:
        return ReadRandom(33, 47);
        break;

        case enCharType::digit:
        return ReadRandom(48, 57);
        break;
    }
    return charType;
}

int main(){
    srand((unsigned) time(NULL));

    cout <<  GenerateRnadomCharacter(enCharType::smallLetter) << endl;
    cout <<  GenerateRnadomCharacter(enCharType::specialCharacter) << endl;
    cout <<  GenerateRnadomCharacter(enCharType::capitalLetter) << endl;
    cout <<  GenerateRnadomCharacter(enCharType::digit) << endl;


    return 0;
}
