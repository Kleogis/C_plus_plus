#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;

#include "WordLadder.h"
//Constructor
WordLadder::WordLadder(const string &File_Name) {
  ifstream if_ST;
  string Word;
  //Open Dictionary file
  if_ST.open(File_Name);
  if(!if_ST.is_open()) {
    cout << "Could not open file " << File_Name << "." << endl;
    return;
  }
  //reading words from Dictionary into ifstream if_ST 
  while(if_ST >> Word) {
    //Check if word has 5 characters; if yes - add word into list dict
    if(Word.size() != 5) {
      cout << "Must be 5 character word." << endl;
    }
    else {
      dict.push_back(Word);
    }
  }
  if_ST.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
  ofstream of_ST;
  queue<stack<string> > Queue;
  stack<string> Stack;
  string Word;
  // iterates through list of objects
  //C++ : Different Ways to iterate over a List of objects  //https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/
  list<string>::iterator i;

  of_ST.open(outputFile);
  //check if output file is open
  if(!of_ST.is_open()) {
    cout << "Could not open file " << outputFile << "." << endl;
    return;
  }

  //if first and last words are the same 
  if(start == end) {
    of_ST << start;
    return;
  }
  //add first word into a stack and remove it from the list
  Stack.push(start);
  Queue.push(Stack);
  dict.remove(start);

  while(!Queue.empty()) {
    Word = Queue.front().top();
    for(i = dict.begin(); i != dict.end(); ++i) {
      if(Check(Word, *i)) {
        if(*i == end) {
          Queue.front().push(end);
          Output(Queue.front(), of_ST);
          return;
        }
        Stack = Queue.front();
        Stack.push(*i);
        Queue.push(Stack);
        i = dict.erase(i);
        --i;
      }
    }
    Queue.pop();
  }

  if(of_ST.is_open()) {
    of_ST << "No Word Ladder Found." << endl;
  }
  of_ST.close();
  return;
}
//Function checks if current word and word from dictionary are different only by one letter and returns True; oterwise returns False
bool WordLadder::Check(string Word, string Dict_Word) {
  int count = 0;
  for(unsigned i = 0; i < 5; ++i) {
    if(Word.at(i) == Dict_Word.at(i)) {
      ++count;
    }
  }
  if(count == 4) {
    return true;
  }
  else{
    return false;
  }
}

void WordLadder::Output(stack<string> Stack, ofstream & of_ST) {  
  vector<string> Word_List;
  int i = 0;
  //Copy words from stack into a vector
  while(!Stack.empty()) {
    Word_List.push_back(Stack.top()); //copy the top element of stack to the end of vector
    Stack.pop(); //removes top element from stack
    ++i; //counting words in stack/vector
  }

  if(of_ST.is_open()){
    while(i != 0){
      --i;
      of_ST << Word_List.at(i); //copy words from vector in ofstring
      if(i != 0) {
        of_ST << " ";
      }
    }
  }
  return;
}