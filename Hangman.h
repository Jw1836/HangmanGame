//
// Created by jesse on 11/20/2021.
//

#ifndef HANGMAN_HANGMAN_H
#define HANGMAN_HANGMAN_H
using namespace std;
#include <vector>


class Hangman {
public:
    Hangman();
    void PartialPrint(vector<char> guesses);
    void FullPrint();
    void SetWord(int a);
    int GetSize(){return theWord.size();}
    bool Search(char val);
    bool FinishedOrNot(vector<char> guesses);
private:
    vector<char> theWord;
    vector<char> word1{'c', 'h', 'e', 'e', 's', 'e'};
    vector<char> word2{'o', 'c', 't', 'o', 'b', 'e', 'r'};
    vector<char> word3{'c', 'h', 'r','i',  's', 't', 'm', 'a', 's'};
    vector<char> word4{'a', 'p', 'r', 'i', 'l'};
    vector<char> word5{'b', 'a', 'c', 'o', 'n'};
    vector<char> word6{'c', 'a', 'm', 'b', 'o', 'd', 'i', 'a'};
    vector<char> word7{'c', 'a', 'l', 'i', 'f', 'o', 'r', 'n', 'i', 'a'};
    vector<char> word8{'c', 'o', 'm', 'p', 'u', 't', 'e', 'r'};
    vector<char> word9{'b', 'e', 'e'};
    vector<char> word10{'c', 'h', 'i', 'c', 'k', 'e', 'n'};
};


#endif //HANGMAN_HANGMAN_H
