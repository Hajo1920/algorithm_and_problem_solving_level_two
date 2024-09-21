#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

enum enQuestionLevel {Easy=1, Medium=2, Hard=3, Mixed=4};

enum enOperation {Addition=1, Subtraction=2, Multiplication=3, Division=4, MixedOperation=5};

enum enPassFail {Pass=1, Fail=2};

struct stQuestion{ 
    int Number1 = 0; 
    int Number2 = 0; 
    enOperation OperationType; 
    enQuestionLevel QuestionLevel; 
    int CorrectAnswer = 0; 
    int PlayerAnswer = 0; 
    bool AnswerResult = false; 
};

struct stQuizz{ 
    stQuestion QuestionList[100];
    short NumberOfQuestions; 
    enQuestionLevel QuestionsLevel; 
    enOperation OpType; 
    short NumberOfWrongAnswers = 0; 
    short NumberOfRightAnswers = 0; 
    bool isPass = false; };


 short ReadRandom(short from, short to){
    short random = rand() % (to - from) + from;
    return random;
}

short ReadQuestionAmount(){
    short quesitons;
    do {
        cout << endl;
        cout << "How many Questions do you want to answer 1 - 20: ";
        cin >> quesitons;
    }while (quesitons < 1 || quesitons > 20);
    return quesitons;
}

void ResetScreen(){
    system("cls");
    system("color 0F");
}

enQuestionLevel ReadQuestionLevel(){
    short questionLevel;
    do {
        cout << endl;
        cout << "Enter question level [1] Easy [2]Medium [3]Hard [4]Mixed ? ";
        cin >> questionLevel;
    }while (questionLevel < 1 || questionLevel > 4);

    return (enQuestionLevel) questionLevel;
}

enOperation ReadOperationType(){
    short operationType;
    do {
        cout << endl;
        cout << "Choose Operation type: Addition[1] Sub[2] Mult[3] Division[4] Mixed[5] ? ";
        cin >> operationType;

    }while (operationType < 1 || operationType > 5);

    return (enOperation) operationType;
}


int Calculator (int Num1, int Num2, enOperation OperationType){
   switch (OperationType) {
    
    case enOperation::Addition:
     return Num1 + Num2;
     break;
    case enOperation::Subtraction:
     return Num1 - Num2;
     break;
    case enOperation::Multiplication:
     return Num1 * Num2;
     break;
     case enOperation::Division:
     return Num1 / Num2;
     default:
     return Num1 + Num2;

   }
  
}

enOperation GetRandomOperation(){
    int Opt = ReadRandom(1, 4);
    return (enOperation) Opt;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperation OpType){
    stQuestion Question;
    if(QuestionLevel == enQuestionLevel::Mixed){
        QuestionLevel = (enQuestionLevel) ReadRandom(1, 3);
    }

    if(OpType == enOperation::MixedOperation){
        OpType = GetRandomOperation();
    }

    Question.OperationType = OpType;

    switch (QuestionLevel) {

        case enQuestionLevel::Easy:
            Question.Number1 = ReadRandom(1, 10);
            Question.Number2 = ReadRandom(1, 10);
            Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
            Question.QuestionLevel = QuestionLevel;
            return Question;

        case enQuestionLevel::Medium:
            Question.Number1 = ReadRandom(50, 100);
            Question.Number2 = ReadRandom(50, 100);
            Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
            Question.QuestionLevel = QuestionLevel;
            return Question;

        case enQuestionLevel::Hard:
            Question.Number1 = ReadRandom(100, 500);
            Question.Number2 = ReadRandom(100, 500);
            Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
            Question.QuestionLevel = QuestionLevel;
            return Question;

        default:
            Question.Number1 = ReadRandom(1, 10);
            Question.Number2 = ReadRandom(1, 10);
            Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);
            Question.QuestionLevel = QuestionLevel;
            return Question;
    

    }

    return Question;

}

void GenerateQuizQuestions(stQuizz& Quizz){
    for(short question = 0; question < Quizz.NumberOfQuestions; question++){
        Quizz.QuestionList[question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

string GetOperationSymbol(enOperation OpType){
    switch (OpType) {

        case enOperation::Addition:
           return "+";
        case enOperation::Subtraction:
           return "-";
        case enOperation::Multiplication:
           return "*";
        case enOperation::Division:
           return "/";
        default:
          return "Mix";
    }
}

short ReadQuestionAnswer(){
    short answer;
    cin >> answer;
    return answer;
}

void PrintQuestion(stQuizz& Quizz, short QuestionNumber){
    cout<< "\n";
    cout<< "Question ["<<QuestionNumber+1<<"/"<<Quizz.NumberOfQuestions<<"] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1<<endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2<<" ";
    cout << GetOperationSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n_______________" << endl;

}

void SetScreenColor(bool Right) {
     if (Right) system("color 2F"); //turn screen to Greenelse     
                  
      else { system("color 4F"); //turn screen to Red        
          cout  <<  "\a"; }   
                
    } 

void CorrectTheQuestionAnswer( stQuizz& Quizz, short QuestionNumber) {
     if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer){
             Quizz.QuestionList[QuestionNumber].AnswerResult = false; 
             Quizz.NumberOfWrongAnswers++ ;           
             cout     <<     "Worng Answer :-( \n";           
             cout     <<     "The right answer is: ";           
             cout     <<Quizz.QuestionList[QuestionNumber].CorrectAnswer;           
             cout     <<     "\n";      

             } else {    

            Quizz.QuestionList[QuestionNumber].AnswerResult = true; 
            Quizz.NumberOfRightAnswers++;           
            cout     <<     "Right Answer :-) \n";      
            }         

            SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
     } 

void AnswerAndPrintQuizzQuestions(stQuizz& Quizz){
    for(short questionNumber = 0; questionNumber < Quizz.NumberOfQuestions; questionNumber++){
        PrintQuestion(Quizz, questionNumber);

        Quizz.QuestionList[questionNumber].PlayerAnswer = ReadQuestionAnswer();

        CorrectTheQuestionAnswer(Quizz, questionNumber);

    }

    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}



stQuizz GamePlayGround(){
    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadQuestionAmount();
    Quizz.QuestionsLevel = ReadQuestionLevel ();
    Quizz.OpType = ReadOperationType();
    GenerateQuizQuestions(Quizz);
    AnswerAndPrintQuizzQuestions(Quizz);

    return Quizz;
}

string GetFinalResultsText(bool isPass){
    if(isPass) return "Pass :) ";
    return "Fail :( ";
}

string GetQuestionLevelText(enQuestionLevel Level){
    switch (Level) {
        case enQuestionLevel::Easy:
           return "Easy";
        case enQuestionLevel::Medium:
           return "Medium";
        case enQuestionLevel::Hard:
           return "Hard";
        case enQuestionLevel::Mixed:
           return "Mixed";
        default:
           return "Easy";
        
    }
}

string GetOperationSymbolText(enOperation OpType){
    switch (OpType) {

        case enOperation::Addition:
           return "Addition";
        case enOperation::Subtraction:
           return "Subtraction";
        case enOperation::Multiplication:
           return "Multiplication";
        case enOperation::Division:
           return "Division";
        default:
          return "Mix";
    }
}



void ShowQuizzResult(stQuizz Quizz){
    ResetScreen();
    cout     <<     "\n";      
    cout     <<     "______________________________\n\n"; 
    cout << " Final Resutls is " <<  GetFinalResultsText(Quizz.isPass);      
    cout     <<     "\n______________________________\n\n"; 
    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;      
    cout     <<     "Questions Level: " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;      
    cout     <<     "Operation Type: " << GetOperationSymbolText(Quizz.OpType) << endl;      
    cout     <<     "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;      
    cout     <<     "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;      
    cout     <<     "______________________________\n";  
}

void StartGame(){
    char playAgian = 'y';
    do {
        ResetScreen();
       stQuizz Quizz = GamePlayGround();
        ShowQuizzResult(Quizz);
        cout << "Do you want to take a quiz again ? Yes[y] or No[any key]: ";
        cin >> playAgian;

    }while (playAgian == 'Y' || playAgian=='y');
    
}

int main(){
    srand((unsigned) time(NULL));

    StartGame();
    return 0;
}