#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    delete head;
    delete tail;
}

const int& IntList::front() const {
    return head->data;
}

const int& IntList::back() const {
    return tail->data;
}

bool IntList::empty() const{
    if (head == nullptr){
        return true;
    }
    else{
        return false;
    } 
}

void IntList::push_front(int NewNode){
     IntNode * temp = new IntNode(NewNode);
        temp->next = this->head;
        this->head = temp;
     if (tail == nullptr){
         tail = head;
     }
}

ostream & operator<<(ostream & out, const IntList & list1){
    IntNode* curr = list1.head;

    while (curr != nullptr){
        out << curr->data;
        curr = curr->next;

        if (curr != 0){
            out << " ";
        }
    }   

    return out;
    
}

void IntList::pop_front(){
    this->head = head->next; 
}