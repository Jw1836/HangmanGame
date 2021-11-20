//
// Created by jesse on 11/20/2021.
//
#include<iostream>
#include <vector>
using namespace std;
#include "Hangman.h"

Hangman :: Hangman(){
}
void Hangman ::FullPrint() { // normal print of vector
    for(int i = 0; i < theWord.size(); i++){
        cout << theWord.at(i);
    }
    cout << endl;
}
void Hangman ::PartialPrint(vector<char> guesses){
vector<char> temp = theWord;
    for(int i = 0; i < theWord.size(); i++){ // sets the vector to a temporary one, switching guesses to underscore
        for(int j = 0; j < guesses.size(); j++){
            if(theWord.at(i) == guesses.at(j)){
                temp.at(i) = '_';
            }
        }
    }
    for(int k = 0; k < temp.size(); k++){ // turns the '_' of temp into the letters of word, switching it
        if(temp.at(k) == '_'){
            temp.at(k) = theWord.at(k);
        }
        else{
            temp.at(k) = '_';
        }
    }
    for(int i = 0; i < temp.size(); i++){ // prints out temp as the vector showing guesses
        cout << temp.at(i);
    }
    cout << endl;
}
void Hangman:: SetWord(int a){
    if(a == 1){
        theWord = word1;
    }
    else if(a == 2) {
        theWord = word2;
    }
    else if(a == 3){
        theWord = word3;
    }
    else if(a ==4){
        theWord = word4;
    }
    else if(a == 5){
        theWord = word5;
    }
    else if(a == 6){
        theWord = word6;
    }
    else if(a == 7){
        theWord = word7;
    }
    else if(a == 8){
        theWord = word8;
    }
    else if(a == 9){
        theWord = word9;
    }
    else if(a == 10){
        theWord = word10;
    }
}
bool Hangman :: Search(char val){ // look for val
    bool found = false;
    for(int i = 0; i < theWord.size(); i++){
        if(val == theWord.at(i)){
            found = true;
            break;
        }
    }
    return found;
}
bool Hangman ::FinishedOrNot(vector<char> guesses) { // if the guesses line up with the word, finish loop
    int count = 0;
    for(int i = 0; i < theWord.size(); i++){
        for(int j = 0; j < guesses.size(); j++){
            if(theWord.at(i) == guesses.at(j))
                count++;
        }
    }
    if(count == theWord.size()){
        return true;
    }
    else{
        return false; // keep going
    }
}