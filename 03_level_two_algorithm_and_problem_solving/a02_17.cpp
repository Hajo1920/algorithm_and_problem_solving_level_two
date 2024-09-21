#include <iostream>
using namespace std;

string ReadUserInput(string message){
    string input;
    do
    {
        cout << message << ": ";
        cin >> input;

    } while(input.length() != 3);

    return input;
}

void AllLettersLoop(string userInput){
    string letter = "";
    int count = 0;
  for(int x = 65; x <= 90; x++){

    for(int y = 65; y <= 90; y++){

        for(int z = 65; z <= 90; z++){
            count++;
            letter = letter+char(x);
            letter = letter+char(y);
            letter = letter+char(z);

            cout << "Trial ["<< count << "]: " << letter << endl;
            if(letter ==  userInput){
                cout << endl;
                cout << "Password " << userInput << " found" << endl;
                cout << "Found at Trial-> " << count << endl;
                cout << endl;
                return;
            }
            letter = "";
        }
    }

}

}

int main(){
    AllLettersLoop(ReadUserInput("Please Add Keys to check"));
    return 0;
}
