#include <iostream>
using namespace std;

void PrintHeader(){
     cout << endl;
    cout << "_______________________________________________________________________________________";
    cout << endl;
    cout << "\n\n\t\t\t Multiplication Table from 1 to 10\n\n";
    cout << "\t";
    
    for(int x = 1; x <= 10; x++){
        cout << x << "\t";
    }
    cout << endl;
    cout << "_______________________________________________________________________________________";
    cout << endl;
}

string ColumnSeparetor(int x){
    if(x < 10){
        return "   |";
    }else return "  |";
}

void PrintMultiplicationTable(){
    PrintHeader();
       for(int x = 1; x <= 10; x++){

        cout << "  " << x << ColumnSeparetor(x) << "\t";
        
        for(int y = 1; y<= 10; y++ ){
            
            cout  << y*x << "\t";
        }
        cout << endl;
    }
}

int main(){

   
    PrintMultiplicationTable();

  



    



    return 0;
}