#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string Somefile){
   ifstream inFS;
   int fileNum;
   int sum1 = 0;
   inFS.open(Somefile);
   
   if (!inFS.is_open()) {
      cout << "Error opening " << Somefile << endl;
      return 1; // 1 indicates error
   }
   while (inFS >> fileNum) {
//     cout << fileNum << endl;
//    if(!fileNum.empty()){
        sum1 = sum1 + fileNum;
//     }
     
   }
//   sum1 = sum1 - fileNum;

   inFS.close();
   return (sum1);
}

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   if (sum != 1){
      cout << "Sum: " << sum << endl;
   }
   return 0;
}

// Place fileSum implementation here
