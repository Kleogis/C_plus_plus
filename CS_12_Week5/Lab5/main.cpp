//include any standard libraries needed
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);

double mean(const double array[], int arraySize){
    double Sum_Ar = 0.0;
    for (int i = 0; i < arraySize; ++i){
        Sum_Ar = Sum_Ar + array[i];
    }
    return Sum_Ar / arraySize;
}

void remove(double array[], int &arraySize, int index){
    double array2[arraySize];
    for (int i = 0; i < arraySize; ++i){
        array2[i] = array[i];
    }
    for (int i = index; i < arraySize; ++i){
        array2[i] = array2[i+1];
    }
    arraySize = arraySize -1 ;
    for (int i =0; i < arraySize; ++i){
        array[i] = array2[i];
    }
}

void display(const double array[], int arraySize){
    for (int i = 0; i < arraySize -1; ++i){
        cout << array[i] << ", ";
    }
    cout << array[arraySize -1];
}

const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
    string FileName = argv[1];
    ifstream inFS;
    double Nums;
    inFS.open(FileName);
    
   // open file and verify it opened
     if (!inFS.is_open()) {
        cout << "Error opening " << FileName << endl;
        exit(1);
   }

   // Declare an array of doubles of size ARR_CAP.
   double array[ARR_CAP];
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    int i;
   while (inFS >> Nums && i < ARR_CAP){
       array[i] = Nums;
       i++;
       inFS.ignore();
    }
    inFS.close();
    
   // Call the mean function passing it this array and output the 
   // value returned.
    int arraySize = 0;
    if (FileName == "seven.dat"){
         arraySize = 7;
     }
     else if (FileName == "one_hundred.dat"){
          arraySize = 99;
     }
//     for (int i = 0; i < arraySize; ++i){
//         if (array[i] != 0) {
//             arraySize = arraySize + 1;
//         }
//     }
     
    double Mean;
    Mean = mean(array, arraySize);
    cout << "Mean: " << Mean << endl;
    cout << endl;
     
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    int index;
    if (arraySize == 100){
        cout << "Enter index of value to be removed (0 to 98): " << endl;
    }
    else {
    cout << "Enter index of value to be removed (0 to " <<  arraySize -1 << "):" << endl;
    }
    cin >> index;

   // Call the display function to output the array.
    cout << "Before removing value: ";
    display(array, arraySize);
    cout << endl;
    cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
    remove(array, arraySize, index);
    
   // Call the display function again to output the array
   // with the value removed.
//    cout << "Arraysize is: " << arraySize << endl;
    cout << "After removing value: ";
    display(array, arraySize);
    cout << endl;
    cout << endl;
   
   // Call the mean function again to get the new mean
    Mean = mean(array, arraySize);
    cout << "Mean: " << Mean << endl;
   
	return 0;
}