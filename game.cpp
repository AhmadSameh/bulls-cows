#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void printIntro();
void playGame();
string pickWord();
string getAnswer(int i);
bool askToPlayAgain();
bool guessValidity(string Guess);
int checkForBulls(string Guess, string isogram);
int checkForCows(string Guess, string isogram);
bool isGameWon(int bulls);

int main(){
    do{
        printIntro();
        playGame();
    }while(askToPlayAgain());
    return 0;
}


void printIntro(){
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun word game" << endl;
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
}


string pickWord(){
    srand (time(NULL));
    int i =rand()%21;
    string word[] = {"slope", "stein", "bread", "guest", "story", "piano", "power", "ratio", "virus", "movie", "month", "thing", "steak", "honey", "chest", "blade", "bonus", "woman", "death", "heart", "slime"};
    return word[i];
}


void playGame(){
    string isogram = pickWord();
    for (int i = 0; i < 5; i++) {
        string Guess = getAnswer(i);
        if(guessValidity(Guess))  { i--;  }
        else{
            int bulls = checkForBulls(Guess, isogram);
            int cows = checkForCows(Guess, isogram);
            cout << "Your Guess was: " << Guess << endl;

            cout << "Bulls: " << bulls << "   Cows: " << cows << endl;
            if(isGameWon(bulls)){
                cout << "BULLSEYE" << endl;
                break;
            }
        }
        cout << "Your Guess was: " << Guess << endl;
    }
}


bool guessValidity(string Guess) {
    if  (Guess.length() != 5){
        cout << "Please Enter a Valid Answer \"a 5 letter word\"" << endl;
        return 1;
    }
    for(int i=0; i<5; i++){
        if((count(Guess.begin(), Guess.end(), Guess[i])) > 1 ){
            cout << "Please Enter a Valid Answer \"unrepeated letters\"" << endl;
            return 1;
        }
        if (Guess[i]<65 || (Guess[i]>90 && Guess[i]<97) || Guess[i]>122){
            cout << "Please Enter a Valid Answer \"no special characters or numbers\"" << endl;
            return 1;
        }
    }
}


string getAnswer(int i){
    cout << "Try " << i+1 << ". Enter a Guess: ";
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}


bool askToPlayAgain(){
    cout << "Do you want to play again ?";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'Y') || (Response[0] == 'y');
}


int checkForBulls(string Guess, string isogram){
    int bulls = 0;
    for (int i=0; i<5; i++){
        if(isupper(Guess[i])){ Guess[i]= Guess[i] + 32; }
        if(isogram[i] == Guess[i]){ bulls++; }
    }
    return bulls;
}


int checkForCows(string Guess, string isogram){
    int cows=0;
    for(int i =0; i<5; i++){
        if(isupper(Guess[i]))   { Guess[i]= Guess[i] + 32; }
        if(isogram[i]==Guess[i])   { continue; }
        if (isogram.find(Guess[i]) != string::npos)   { cows++; }
    }
    return cows;
}


bool isGameWon(int bulls){
    if(bulls == 5) { return 1; }
    else { return  0; }
}