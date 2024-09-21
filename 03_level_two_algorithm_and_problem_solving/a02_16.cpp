#include <iostream>
using namespace std;


void AllLettersLoop(){
    string letter = "";
  for(int x = 65; x <= 90; x++){

    for(int y = 65; y <= 90; y++){

        for(int z = 65; z <= 90; z++){
            letter = letter+char(x);
            letter = letter+char(y);
            letter = letter+char(z);

            cout << letter << endl;
            letter = "";
        }
    }

}

}

int main(){
    AllLettersLoop();
    return 0;
}
