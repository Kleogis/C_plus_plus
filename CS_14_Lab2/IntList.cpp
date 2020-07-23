//Created by Viktoriia Liu, Jayden Lui and Kevin Brewer for CS014, April, 2020

#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList() {
  dummyHead = new IntNode(0);
  dummyTail = new IntNode(0);
  dummyHead->prev = nullptr;
  dummyHead->next = dummyTail;
  dummyTail->prev = dummyHead;
  dummyTail->next = nullptr;
}

IntList::~IntList() {
  while (!empty()) {
    pop_back();
  }
}

ostream &operator<<(ostream &out, const IntList &rhs) {
  if (!rhs.empty()) {
    IntNode* curr = rhs.dummyHead->next;
      while (curr->next != rhs.dummyTail) {
        out << curr->data << " ";
        curr = curr->next;
      }
      out << curr->data;
  }
  return out;
}

void IntList::printReverse() const {
  if (!empty()) {
    IntNode* curr = dummyTail->prev;
      while (curr->prev != dummyHead) {
        cout << curr->data << " ";
        curr = curr->prev;
      }
      cout << curr->data;
  }
}

void IntList::pop_back() {
	if (!empty()) {
		IntNode* LastNode = dummyTail->prev;
		IntNode* PrevNode = LastNode->prev;
		PrevNode->next = dummyTail;
		dummyTail->prev = PrevNode;
		delete LastNode;
	}
}

void IntList::push_front(int value) {
  IntNode* currNode = new IntNode(value);
  currNode->next = dummyHead->next;
  currNode->prev = dummyHead;
  currNode->next->prev = currNode;
  dummyHead->next = currNode;
}

void IntList::pop_front() {
  if (dummyHead->next == dummyTail) {
    return;
  }
  IntNode* currNode = nullptr;
  currNode = dummyHead->next->next;
  dummyHead->next = currNode;
  delete currNode->prev;
  currNode->prev = dummyHead;
} 

void IntList::push_back(int value) {
  IntNode* currNode = new IntNode(value);
  currNode->next = dummyTail;
  currNode->prev = dummyTail->prev;
  currNode->prev->next = currNode;
  dummyTail->prev = currNode;
}

bool IntList::empty() const {
  if (dummyHead->next == dummyTail) {
    return true;
  }
  else {
    return false;
  }
}