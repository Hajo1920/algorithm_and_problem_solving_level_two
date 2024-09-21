#include<iostream>
#include<cstdlib>
using namespace std; 
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 }; 
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 }; 

struct stRoundInfo{ short RoundNumber = 0; 
enGameChoice Player1Choice; 
enGameChoice ComputerChoice; 
enWinner Winner; 
string WinnerName; 
}; 

struct stGameResults{ 
    short GameRounds = 0; 
    short Player1WinTimes = 0; 
    short Computer2WinTimes = 0; 
    short DrawTimes = 0; 
    enWinner GameWinner; 
    string WinnerName = ""; }; 

 string Tabs(short tapAmount){
    string tap = "";
   for(int x = 1; x <= tapAmount; x++){
    tap= tap+"\t";
    cout << tap;
   }

   return tap;
 }

 short ReadRandom(short from, short to){
    short random = rand() % (to - from) + from;
    return random;
}

void ResetScreen(){
    system("clear");
}

short HowManyRounds(string message){
    short round;
    do {

        cout << message;
        cin >> round;

    }while (round <= 0 || round > 10);

    return round;
}

enGameChoice ReadPlayerChoise(){
    short playerChoise;
   do {
    cout << "Choose--> Stone[1] -- Papper[2] -- Scissor[3] : ";
    cin >> playerChoise;
   }while (playerChoise < 1 || playerChoise > 3);

   return (enGameChoice) playerChoise;

}

enGameChoice GetComputerChoise(){
    return (enGameChoice) ReadRandom(1, 3);
}
enWinner ComparePlayerAndComputerChoise(stRoundInfo RoundInfo){
    if(RoundInfo.Player1Choice == RoundInfo.ComputerChoice){
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice) {
        case enGameChoice::Paper:
        if(RoundInfo.ComputerChoice == enGameChoice::Scissors) {return enWinner::Computer;}
         break;

        case enGameChoice::Scissors:
        if(RoundInfo.ComputerChoice == enGameChoice::Stone) {return enWinner::Computer;}
        break;

        case enGameChoice::Stone:

        if(RoundInfo.ComputerChoice == enGameChoice::Paper) {return enWinner::Computer;}
        break;
    
    }

    return enWinner::Player1;
}

string WinnerName(enWinner Winner) { 
    string arrWinnerName[3] = { "Player1","Computer","No Winner"}; 
    return arrWinnerName[Winner - 1]; 
    } 
string ChoiseName(enGameChoice Choise){
    string arrNameChoise[3] = {"Stone", "Papper", "Scissor"};
    return arrNameChoise[Choise-1];
}

void PrintRoundGameInfo(stRoundInfo RoundInfo){
    cout << endl;
    cout << "_------- Round ["<<RoundInfo.RoundNumber<<"] Results --------_"<< endl << endl;
    cout << Tabs(1) << " Player1 Choise: " << ChoiseName (RoundInfo.Player1Choice)<< endl << endl;
    cout << Tabs(1) << " Computer Choise: " << ChoiseName (RoundInfo.ComputerChoice)<<endl << endl;
    cout << Tabs(1) << " Round Winner: " << RoundInfo.WinnerName << endl;
    cout << "_---------------------------------_"<<endl << endl;
}

enWinner WhoWonTheGame(short player_win_times, short computer_win_times){
    if(player_win_times > computer_win_times) return  enWinner::Player1;
    else if(computer_win_times > player_win_times) return enWinner::Computer;
    else return enWinner::Draw;

}

stGameResults FillGameResults(short total_round, short player_win_times, short computer_win_times, short draw_times){
    stGameResults GameResults;
    GameResults.GameRounds = total_round;
    GameResults.DrawTimes = draw_times;
    GameResults.Computer2WinTimes = computer_win_times;
    GameResults.Player1WinTimes = player_win_times;
    GameResults.GameWinner = WhoWonTheGame(player_win_times, computer_win_times);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}


stGameResults playGame(short HowManyRounds){
    stRoundInfo RoundInfo;
    short PlayerWins = 0, ComputerWins=0, Draw=0;
    for(short gameRound = 1; gameRound <= HowManyRounds; gameRound++){
          RoundInfo.RoundNumber = gameRound;
          RoundInfo.Player1Choice = ReadPlayerChoise();
          RoundInfo.ComputerChoice = GetComputerChoise();
          RoundInfo.Winner = ComparePlayerAndComputerChoise(RoundInfo);
          RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

          if(RoundInfo.Winner == enWinner::Player1) PlayerWins++;
          else if(RoundInfo.Winner == enWinner::Computer) ComputerWins++;
          else Draw++;

          PrintRoundGameInfo(RoundInfo);

    }

    return FillGameResults(HowManyRounds,PlayerWins, ComputerWins, Draw);

}

void ShowGameOver(){

cout << Tabs(2)<< "|+++| ~ G a m e O v e r ~ |+++|" << endl;

}

void ShowFinalGameResult(stGameResults GameResults){

ResetScreen();
cout << Tabs(2)<< "Total Game Round: " << GameResults.GameRounds << endl<<endl;
cout << Tabs(2)<< "Player1 Win Times: "<< GameResults.Player1WinTimes << endl<<endl;
cout << Tabs(2)<< "Computer Win Times: "<< GameResults.Computer2WinTimes<<endl<<endl;
cout << Tabs(2)<< "Total Draw Times: "<< GameResults.DrawTimes<< endl<<endl;
cout << Tabs(2)<< "Winner Name: "<< GameResults.WinnerName<<endl<<endl;

}


void StartGame(){
    char playAgain = 'Y';
    do {
    ResetScreen();
    stGameResults  GameResults = playGame(HowManyRounds("How many rounds do you want to play from 1 -10 ? -> "));
    ShowGameOver();
    ShowFinalGameResult(GameResults);
    cout << endl << Tabs(2) << "Do you want to play again ? -> ";
    cin >> playAgain;
    }while (playAgain == 'y' || playAgain == 'Y');
    ResetScreen();

}

int main(){
    srand((unsigned) time(0));

    StartGame();

    return 0;
}