//Created by Jayden Lui, Viktoriia Liu and Kevin Brewer

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>

#define MAX_SIZE 20

using namespace std;

template<typename T>
class stack {
  private:
    T data[MAX_SIZE];
    int size;
  public:
    stack();
    void push(T val);
    void pop();
    T top();
    bool empty();
};

template<typename T>
stack<T>::stack() {
    size = 0;
}

template<typename T>
void stack<T>::push(T val) {
    if (size == MAX_SIZE) {
        throw overflow_error("Called push on full stack.");
    }
    else {
        data[size] = val;
        size++;
    }
}

template<typename T>
void stack<T>::pop() {
    if (size == 0) {
        throw out_of_range("Called pop on empty stack.");
    }
    else {
        size--;
    }
}

template<typename T>
T stack<T>::top() {
    if (size == 0) {
        throw underflow_error("Called top on empty stack.");
    }
    else {
        return data[size - 1];
    }
}

template<typename T>
bool stack<T>::empty() {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

#endif