#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   string nameStr;
   string outfileStr;
   nameStr = argv[1];
   outfileStr = argv[2];
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   
   // Create input stream and open input csv file.
    ifstream inFS;
    int Nums;
    inFS.open(nameStr);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
    if (!inFS.is_open()) {
        cout << "Could not open file data1.csv." << endl;
    return 1; // 1 indicates error
   }
       
   // Read in integers from input file to vector.
    vector<int> Inputs;
    while (inFS >> Nums){
        Inputs.push_back(Nums);
        inFS.ignore();
    }

   
   // Close input stream.
    inFS.close();
   
   // Get integer average of all values read in.
    int Sum1 = 0;
    int Avg1 = 0;
    int count = 0;
    for (unsigned int i =0; i < Inputs.size(); ++i){
        Sum1 = Sum1 + Inputs.at(i);
        count = count + 1;
    }
    Avg1 = Sum1 / count;
   
   // Convert each value within vector to be the difference between the original value and the average.
    for (unsigned int i = 0; i < Inputs.size(); ++i){
        Inputs.at(i) = Inputs.at(i) - Avg1;
    }
   
   // Create output stream and open/create output csv file.
    ofstream infoOSS(outfileStr);
    

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
    if (!infoOSS.is_open()) {
        cout << "Could not open file new_data.csv." << endl;
    return 1; // 1 indicates error
    }
     
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
    for (unsigned int i = 0; i < Inputs.size()-1; ++i ){
        infoOSS << Inputs.at(i) << ", ";
    }
    infoOSS << Inputs.at(Inputs.size()-1);
   
   // Close output stream.
    infoOSS.close();
   
   return 0;
}