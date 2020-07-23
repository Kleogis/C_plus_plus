#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    while (!empty()){
        pop_front();
    }
    head = nullptr;
    tail = nullptr;
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
     if (empty()) {
         head = tail = temp;
     }
     else {
        temp->next = head;
        head = temp;
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
 //   this->head = head->next;
    
    if (head == 0){
        return;
    }
    else if (head != 0)
    {
    IntNode *temp = head->next;
    delete head;
    head = temp;
    }
    
    return;
}

IntList::IntList(const IntList &cpy){
//     if (cpy.head == nullptr)
//         return;

//     // Create a temp variable since cpy.current doesn't move/change.
//     IntNode *temp = cpy.head;
//     IntNode *current = nullptr;
//     tail = nullptr;
    

//     // Allocate a new node in memory.
//     head = nullptr;
    
//     // Copy over the data.
//     head->data = temp->data;
//     // Set the 'next' data to null (the loop will fill this in). 
//     head->next = nullptr;
//     // Point 'current' to 'head'.
//     current = head;

//     // Move to next item in cpy's list.
//     temp = temp->next;

//     while (temp != nullptr)
//     {
//         // Allocate new memory for a new 'node'.
//         current->next = nullptr;
//         // Point to this new 'node'.
//         current = current->next;
//         // Copy over the data.
//         current->data = temp->data;
//         // By default set the 'next' to null.
//         current->next = nullptr;
//         // Move along cpy's list.
//         temp = temp->next;
//     }
        head = nullptr;
        tail = nullptr;
    
    for (IntNode *temp = cpy.head; temp != nullptr; temp = temp->next)
    {
        this->push_back(temp->data);
    }   
    return;
 }

IntList & IntList::operator=(const IntList &rhs){
//     if (this != &rhs){
//         clear();
//         head = rhs.head;
//         tail = rhs.tail;
//     }
//     return *this;

    if (this != &rhs)
    {
        clear();
        for (IntNode *i = rhs.head; i != 0; i = i->next)
        {
            this->push_back(i->data);
        }
    }
    
    return *this;
}

void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    if(empty()){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void IntList::clear(){

//     while (!empty()) {
//         pop_front();
//     }
//     head = nullptr;
//     tail = nullptr;
    
    IntNode* current = head;

    while (current != nullptr){
       head = head->next;
       delete current;
       current = head;
       }
    head = nullptr;
    tail = nullptr;
    current =nullptr;
}

void IntList::selection_sort(){
    for (IntNode* current = head; current != nullptr; current = current->next) {
        IntNode* smallest = current;
        for (IntNode* min = current; min != nullptr; min = min -> next) {
            if (min->data < smallest->data) {
                smallest = min;
            }
        }
        
        int temp = current->data;
        current->data = smallest->data;
        smallest->data = temp;
        
    }
}

void IntList::insert_ordered(int value){
    
    IntNode* temp = new IntNode(value);
    IntNode* current = nullptr;
    IntNode* nextNode = nullptr;
    
    if (empty()) {
        push_front(value);
        delete temp;
        return;
    }
    
    else if (value <= head->data) {
        push_front(value);
        delete temp;
        return;
    }
    
    else if (temp->data >= tail-> data) {
        push_back(value);
        delete temp;
        return;
    }
    
    for (current = head; current != nullptr; current = current->next) {
        nextNode = current->next;
        if (temp->data <= nextNode->data) {
            current->next = temp;
            temp->next = nextNode;
            return;
        }
    }
    
    return;
    
}

void IntList::remove_duplicates(){
     IntNode *current = head;
     IntNode *temp = nullptr;
     IntNode *previous = nullptr;
    //empty list
    if (current == nullptr){
        return;
    }
    //list with one node
    if (current->next == nullptr){
        return;
    }

//     if (current != nullptr && current->next != nullptr){
//         while (current != nullptr){
//             previous = current;
//             temp = current->next;
//             while (temp != nullptr){
//                 if (temp->data == current->data){
//                     temp = temp->next;
//                     previous->next = temp;
//                 }
//                 else{
//                     previous = temp;
//                     temp = temp->next;
//                     }
//                 }
//             }
//             current = current->next;
//         }
//     }
    
//    IntNode *previous = nullptr;
    for (current = head; current != 0; current = current->next)
    {
        previous = current;
        for (temp = current->next; temp != 0; temp= temp->next)
        {
            if (current->data == temp->data)
            {
                if (temp == tail)
                {
                    tail = previous;
                }
                previous->next = temp->next;
                delete temp;
            }
            else
            {
               previous = previous->next;
            }
        }
    }

}