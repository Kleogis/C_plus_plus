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
    // 
    void IntList::push_front(int value) {
        IntNode* currNode = new IntNode(value);
        currNode->next = dummyHead->next;
        currNode->prev = dummyHead;
        currNode->next->prev = currNode;
        dummyHead->next = currNode;
    }
    //
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
    //
    void IntList::push_back(int value) {
        IntNode* currNode = new IntNode(value);
        currNode->next = dummyTail;
        currNode->prev = dummyTail->prev;
        currNode->prev->next = currNode;
        dummyTail->prev = currNode;
    }
    void IntList::pop_back() {
        if (dummyHead->next == dummyTail) {
            return;
        }
        IntNode* currNode = nullptr;
        currNode = dummyTail->prev->prev;
        dummyTail->prev = currNode;
        delete dummyTail->prev->next;
        dummyTail->prev->next = dummyTail;
    }
    //
    bool IntList::empty() const {
        if (dummyHead->next == dummyTail) {
            return true;
        }
        else {
            return false;
        }
    }
    ostream &operator<<(ostream &out, const IntList &rhs) {
        if (rhs.dummyHead->next == rhs.dummyTail) {
            return out;
        }
        IntNode *node = rhs.dummyHead->next;
        while (node != rhs.dummyTail) {
            out << node->data;
            if (node->next != rhs.dummyTail) {
                out << ' ';
            }
            node = node->next;
        }
        return out;
    }
    void IntList::printReverse() const {
        IntNode *node = dummyTail->prev;
        while (node != dummyHead) {
            cout << node->data;
            if (node->prev != dummyHead) {
                cout << ' ';
            }
            node = node->prev;
        }
    }