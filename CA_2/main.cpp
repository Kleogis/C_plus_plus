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


int main() {
   string Dictionary_File;
   string Initial_Word;
   string Final_Word;
   string Output_File;
   cout << "Enter the name of the dictionary file: ";
   cin >> Dictionary_File;
   cout << endl;
   cout << "Enter the name of the output file: ";
   cin >> Output_File;
   cout << endl;
   cout << "Enter the first word: ";
   cin >> Initial_Word;
   cout << endl;
   while (Initial_Word.size() != 5) {
      cout << "Must be 5 character word." << endl
         << "Please reenter the first word: ";
      cin >> Initial_Word;
      cout << endl;
   }
   cout << "Enter the last word: ";
   cin >> Final_Word;
   cout << endl;
   while (Final_Word.size() != 5) {
      cout << "Must be 5 character word." << endl
         << "Please reenter the last word: ";
      cin >> Final_Word;
      cout << endl;
   }
   
	WordLadder word_list1(Dictionary_File);
	
	word_list1.outputLadder(Initial_Word, Final_Word, Output_File);

   return 0;
}