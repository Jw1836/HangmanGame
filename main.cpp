#include <iostream>
#include <ctime>
 // Thanks for looking at my Code. This program took me 2 hours and 55 minutes to complete.
using namespace std;
#include "Hangman.h"

void Print(vector<char> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}
int main() {
    int iterCount = 1;
    int countGuessesWrong = 0;
    int countGuessesRight = 0;
    char userChar;
    char guess;
    bool found;
    bool check = false;
    vector<char> rightStuff;
    vector<char> wrongStuff;
    vector<char> guessList;
    Hangman word;

    // Welcome Message
    cout << "Welcome to Hangman! The computer will randomly choose a word,"
         << " and you have to guess it, letter by letter!" << endl;

    while (check == false) {
        if(iterCount == 1) {
            srand(time(0));
            int rando = (rand() % 10) + 1;
            word.SetWord(rando);
            cout << "This word has " << word.GetSize() << " letters." << endl;
        }
        cout << "Please enter a guess: ";
        cin >> guess;
        tolower(guess); // just in case user enters in an upper case letter
        iterCount ++ ; // counter the iterations so the random num is reset when user wins
        guessList.push_back(guess); // add guess to list
        found = word.Search(guess);
        if (found == true) {
            cout << "Nice Job! If we fill in your guess to this word, here's what it looks like: " << endl;
            word.PartialPrint(guessList);
            rightStuff.push_back(guess);
            countGuessesRight++;
        }
        else {
            wrongStuff.push_back(guess);
            countGuessesWrong++;
            cout << "The following letters that you've guessed are not in the word:";
            Print(wrongStuff);
        }
        // guesses so far
        cout << "Incorrect guesses you've made so far: " << countGuessesWrong << endl;
        cout << "Correct guesses you've made so far: " << countGuessesRight << endl;
        if (word.FinishedOrNot(rightStuff) == true) { // if you win
            cout << "The word was: ";
            word.FullPrint(); // show user the word
            cout << endl;
            cout << "You have successfully guessed the word. Great Job!" << endl;
            cout << "It only took you " << countGuessesWrong + countGuessesRight << " number of guesses!" << endl;
            cout << "Would you like to try again or quit?(press 'p' to play again, 'q' to quit)" << endl;
            cin >> userChar;
            if (userChar == 'q') {
                cout << "Thanks for playing! Have a good day. " << endl <<
                "Goodbye!" << endl;
                break;
            } else { // reset all values for next iteration 
                countGuessesWrong = 0;
                countGuessesRight = 0;
                iterCount = 1;
                guessList.clear();
                rightStuff.clear();
                wrongStuff.clear();
                continue;
            }
        }
    }
        return 0;
    }

