#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string, char);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);

   cout << endl;

   chCnt = charCnt(filename, ch);
   if (chCnt != -1){ 
      cout << "# of " << ch << "'s: " << chCnt << endl;
   }
   return 0;
}

// Place charCnt implementation here
int charCnt(string Somefile, char ch){
   int sum1 = 0;
   ifstream inFS;
   char fileNum; 
   inFS.open(Somefile);
   
   
   if (!inFS.is_open()) {
      cout << "Error opening " << Somefile << endl;
      return -1; // indicates error
   }
   while (inFS.get(fileNum)) {
      
      if (fileNum == ch){
         sum1 = sum1 + 1;
      }
   }

   inFS.close();
   return (sum1);
}