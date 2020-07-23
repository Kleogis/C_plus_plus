//Created by Viktoriia Liu, Jayden Lui and Kevin Brewer for CS014, April, 2020
#include <iostream>
#include "IntList.h"
using namespace std;

int main() {
    cout << "Creating new IntList." << endl;
    IntList* list1 = new IntList();
    cout << "Printing empty list in reverse: ";
    list1->printReverse();
    cout << endl << endl;

    list1->push_front(5);
    list1->push_front(6);
    list1->push_front(7);
    cout << "Printing empty list in reverse: ";
    list1->printReverse();
    cout << endl << endl;
    cout << "Forward: " << *list1 << endl;
    cout << endl << endl;

    list1->push_back(500);
    list1->push_back(600);
    list1->push_back(700);
    cout << "Printing empty list in reverse: ";
    list1->printReverse();
    cout << endl << endl;
    cout << "Forward: " << *list1 << endl;
    cout << endl << endl;

    list1->pop_back();
    cout << "Printing empty list in reverse: ";
    list1->printReverse();
    cout << endl << endl;
    cout << "Forward: " << *list1 << endl;
    cout << endl << endl;

    list1->pop_front();
    cout << "Printing empty list in reverse: ";
    list1->printReverse();
    cout << endl << endl;
    cout << "Forward: " << *list1 << endl;
    cout << endl << endl;


  return 0;
}