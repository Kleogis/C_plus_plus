#include <iostream>
#include <fstream>
#include <string>
#include "JosephusProb.h"
using namespace std;

JosephusNode::JosephusNode(string n) {
	name = n;
	next = nullptr;
}

JosephusList::JosephusList(){
  head = nullptr;
  tail = nullptr;
}

void JosephusList::add(string name) {
	JosephusNode* New_Node = new JosephusNode(name);
  // if list is empty
	if (head == nullptr) {
		head = New_Node;
		tail = New_Node;
    //shoul it point to New_Node?
		head->next = head;
	}
	else {
		tail->next = New_Node;
		tail = New_Node;
		New_Node->next = head;
	}
}

void JosephusList::Lets_Play(int n, string fileName, int Start, int k) {
	//create stream
  ifstream FSin;
	FSin.open(fileName);
  // open file and verify it opened
  if (!FSin.is_open()) {
    cout << "Error opening " << fileName << endl;
      exit(1);
  }
	string input;
  
	int i = 0;
	while (FSin >> input && i < n) {
		add(input);
		i += 1;
	}
  //close stream
  FSin.close();
	//if list is empty
  if (n == 0){
    cout << "The circle has no players" << endl;
  }
  //if list is not empty
	else if (head->next != head) {
		JosephusNode* Current = head;
		JosephusNode* Previous = tail;
		
		i = 1;
    //k​: how many people to skip (if k = 1, the person next to initial is executed; k = 2, then every second person is to be executed)
    //i <= Start if k = 1 skips 1 person between
		while (i < Start) {
			Previous = Current;
			Current = Current->next;
			i += 1;
		}
		
		while (Current->next != Current) { //looping until one node left
			int kcount = 0;
			
			while (kcount != k) {
				Previous = Current;
				Current = Current->next;
				kcount += 1;
			}
			string title;
			title = Current->name;
			Previous->next = Current->next;
			cout << title << " was removed from the circle" << endl;
			delete Current;
			Current = Previous->next;
		}

		cout << "The name of the lucky survivor: " << Current->name << endl;
	}
}

