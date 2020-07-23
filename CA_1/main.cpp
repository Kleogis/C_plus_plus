#include <iostream>
#include <string>
#include "JosephusProb.h"

using namespace std;

int main() {
  JosephusList Circle = JosephusList();
	int n;
	cout << "Enter the number of people in the initial circle: ";
	cin >> n;
  int Start;
	cout << "Enter the number of a person to start counting from: ";
	cin >> Start;
  int k;
	cout << "How many to skip? ";
	cin >> k;
  string fileName;
	cout << "Enter file name: ";
	cin >> fileName;
	Circle.Lets_Play(n, fileName, Start, k);
  


  return 0;
}