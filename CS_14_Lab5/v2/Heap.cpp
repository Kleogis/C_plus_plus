//Created by Jayden Lui, Viktoriia Liu and Kevin Brewer
#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob* job) {
    if (numItems < MAX_HEAP_SIZE) {
        arr[numItems] = job;
        int i = numItems;
        numItems++;
        while ((i != 0) && (arr[parent(i)] -> getPriority() < arr[i] -> getPriority())) {
            swap(parent(i),i);
            i = parent(i);
        }
    }
}

void Heap::dequeue () {
  if(numItems > 0) {
    PrintJob* job = arr[0];
    arr[0] = arr[numItems - 1];
    numItems--;
    delete job;
    trickleDown(0);
  }
}

PrintJob* Heap::highest() {
  return arr[0];
}

void Heap::print() {
    if (numItems > 0) {
        cout << "Priority: " << arr[0] -> getPriority() 
        << ", Job Number: " << arr[0] -> getJobNumber() 
        << ", Number of Pages: " << arr[0] -> getPages() 
        << endl;
    }
}

void Heap::trickleDown(int i) {
  //BASE CASE: heap is empty or child position >= array size or root value >= both children nodes
  if(numItems == 0 || 2*i+1>=numItems || 2*i+2>=numItems || (arr[i] >= arr[2*i + 1] && arr[i] >= arr[2*i + 2])) {
    return;
  }
  //if current number of items in heap > 0 and one of the child nodes is > parent node
  if(arr[2*i + 1] >= arr[2*i + 2]) {
  //swap parent and [2*i+1] child
    PrintJob* temp = arr[i];
    arr[i] = arr[2*i+1];
    arr[2*i+1] = temp;
  //Recursion call trickleDown with 2*i+1 parameter
    trickleDown(2*i+1);
  }
  else {
    //swap parent and [2*i+2] child
    PrintJob* temp = arr[i];
    arr[i] = arr[2*i+2];
    arr[2*i+2] = temp;
  //Recursion call trickleDown with 2*i+2 parameter
    trickleDown(2*i+2);
  }
}

//helper functions
void Heap::swap(int i, int j) {
    PrintJob* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Heap::parent(int i) {
    return (i-1)/2;
}