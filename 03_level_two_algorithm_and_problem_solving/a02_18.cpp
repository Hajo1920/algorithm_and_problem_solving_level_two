#include <iostream>
#include <string>
using namespace std;

string ReadName(string message){
    string name = "";
    do
    {
        cout << message << ": ";
        getline(cin, name);

    } while(name.length() <= 0);

    return name;
}

string EncryptName(string name, short encryptionKey){
    for(int x = 0; x <= name.length(); x++){
        name[x] = char((int) name[x] + encryptionKey);
    }

    return name;

}

string DecriptName(string encyptedName, short encryptionKey){
    for(int x = 0; x <= encyptedName.length(); x++){
        encyptedName[x] = char((int) encyptedName[x] - encryptionKey);
    }

    return encyptedName;

}

void PrintResult(string name, short encryptionKey){
    string encripted = EncryptName(name, encryptionKey);
    string decripted = DecriptName(encripted, encryptionKey);
    cout << "Originale name: " << name << endl;
    cout << endl;
    cout << "After Encrypted: " << encripted << endl;
    cout << "After Decripted: " << decripted << endl;
}

int main(){
short encryptionKey = 2;
PrintResult(ReadName("Enter Name you want to Encrypt"),  encryptionKey);
    return 0;

}

