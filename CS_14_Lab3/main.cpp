//Created by Viktoriia Liu 4/15/2020 for CS014
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
  //Find index of smallest remaining element
  unsigned indexSmallest = index;
  for (unsigned j = index + 1; j < vals.size(); ++j){
    if (vals.at(j) < vals.at(indexSmallest)){
      indexSmallest = j;
    }
  }
  return indexSmallest;
}

template <typename T>
void selection_sort(vector<T> &vals){
  unsigned i;
  T temp; //Temporary variable for swap
  for (i = 0; i < vals.size(); ++i){
    unsigned indexSmallest = min_index(vals, i);
    //swap number[i] and number[indexSmallest]
    temp = vals.at(i);
    vals.at(i) = vals.at(indexSmallest);
    vals.at(indexSmallest)=temp;
  }
}


template <typename T>
T getElement(vector<T> vals, int index){
  unsigned inx = static_cast<unsigned>(index);
  for (unsigned i = 0; i < vals.size(); ++i){
    if(i == inx){
      return vals.at(i);
    }
  }
  // Error checking, reasonable index
   if (inx < 0 || inx > vals.size()) {
      throw out_of_range("Invalid index. Out of range exception occured.");
   }
  return vals.at(0);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main() {
  vector<int> vect{78, 1, 86, 42, 10};
  for (unsigned i = 0; i < vect.size(); ++i){
    cout << vect.at(i) << ' ';
  }
  cout << endl;
  selection_sort(vect);
  for (unsigned i = 0; i < vect.size(); ++i){
    cout << vect.at(i) << ' ';
  }
  cout << endl;

  vector<double> vect1{78.76, 1.234, 86.085, 42.37, 10.32};
  for (unsigned i = 0; i < vect1.size(); ++i){
    cout << vect1.at(i) << ' ';
  }
  cout << endl;
  selection_sort(vect1);
  for (unsigned i = 0; i < vect1.size(); ++i){
    cout << vect1.at(i) << ' ';
  }
  cout << endl;

vector<char> vect2{'f', 't', 'w', 'j', 'a'};
  for (unsigned i = 0; i < vect2.size(); ++i){
    cout << vect2.at(i) << ' ';
  }
  cout << endl;
  selection_sort(vect2);
  for (unsigned i = 0; i < vect2.size(); ++i){
    cout << vect2.at(i) << ' ';
  }
  cout << endl;

  vector<string> vect3{"Jessy", "Cody", "Jack", "Sam", "Poky"};
  for (unsigned i = 0; i < vect3.size(); ++i){
    cout << vect3.at(i) << ' ';
  }
  cout << endl;
  selection_sort(vect3);
  for (unsigned i = 0; i < vect3.size(); ++i){
    cout << vect3.at(i) << ' ';
  }
  cout << endl;

//Part B
  
  srand(time(0));
  vector<char> vals = createVector();
  char curChar;
  int index;
  int numOfRuns = 10;

  try {
  while(--numOfRuns >= 0){
    
    cout << "Enter a number: " << endl;
    cin >> index;
    curChar = getElement(vals,index);
    cout << "Element located at " << index << ": is " << curChar << endl;
    }
  }
    catch (runtime_error &excpt) {
      // Prints the error message passed by throw statement
         cout << excpt.what() << endl;
         cout << "out of range exception occured" << endl;
    }

   return 0;



}