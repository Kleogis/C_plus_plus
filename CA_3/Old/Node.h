#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>
using namespace std;

class Node{
  friend class BSTree;
  private:
    Node *LeftChild;
    Node *RightChild;
    string data;
    int count;

  public:
    Node(string Data);
    ~Node();
};

#endif