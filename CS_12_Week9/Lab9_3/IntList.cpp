#include <ostream>
#include <iostream>
#include "IntList.h"

using namespace std;


IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(int a) const{
    if (head == nullptr){
        return false;
    }
    return (exists(head, a));
}

bool IntList::exists(IntNode * b, int c) const{
    if(b->data != c && b->next == nullptr){
        return false;
    }
    if(b->data != c){
        return exists(b->next, c);
    }
    return true;
}

ostream & operator<<(ostream & d, const IntList & e){
    if(e.head == nullptr){
        return d;
    }
    d << e.head->data;
    return(operator<<(d, e.head->next));
}

ostream & operator<<(ostream & f, IntNode * g){
    if(g == nullptr){
        return f;
    }
    else{
    f << " ";
    f <<g->data;
    }
    return (operator<<(f, g->next));
}

