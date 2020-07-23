#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int data;
	IntNode *next;
    IntNode();
	IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList(); //done
	~IntList();  //done
	void push_front(int);  //done
	void pop_front();
	bool empty() const;   //done
	const int & front() const;  //done
	const int & back() const;   //done
	friend ostream & operator<<(ostream &, const IntList & );  //done
    
    //new functions
    IntList(const IntList &cpy); // the copy constructor. Make sure this performs deep copy
    IntList & operator=(const IntList &rhs); //the overloaded assignment operator. Make sure this performs deep copy
    void push_back(int value); //Inserts a data value (within a new node) at the back end of the list
    void clear(); //Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list
    void selection_sort(); //Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers
    void insert_ordered(int value); // Inserts a data value (within a new node) in an ordered list
    void remove_duplicates(); //Removes all duplicate data values (actually removes the nodes that contain the values) within the list
};

#endif

