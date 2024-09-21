#include <iostream>
using namespace std;

enum enCharType {smallLetter = 1, capitalLetter=2, specialCharacter=3, digit=4};

int ReadRandom(int from, int to){
    int random = rand() % (to - from) + from;
    return random;
}

int ReadInput(string message){
    int input = 0;
    do
    {
        cout << message << ": ";
        cin >> input;

    } while(input <= 0);

    return input;
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

string GenerateWord(short Length, enCharType Type){
    string Word = "";
    for(int x = 1; x <= Length; x++){
        Word = Word + GenerateRnadomCharacter(Type);
    }
    return  Word;
}

string GenerateKey(){
    string Key = "";

    Key = GenerateWord(4, enCharType::capitalLetter) + "-";
    Key = Key + GenerateWord(4, enCharType::capitalLetter) + "-";
    Key = Key + GenerateWord(4, enCharType::capitalLetter) + "-";
    Key = Key + GenerateWord(4, enCharType::capitalLetter);

    return Key;
}

void GenrateRequestedNumberOfKeys(int input){
    for(int x = 1; x <= input; x++){
        cout << "Key ["<<x<<"]: "<< GenerateKey()<<endl;
    }
}


int main(){
srand((unsigned) time(NULL));
GenrateRequestedNumberOfKeys(ReadInput("Enter number to Generate Keys"));
    return 0;
}
