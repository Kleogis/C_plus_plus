#include "Node.h"
#include<iostream>
#include<string>
using namespace std;

Node::Node(string Data){
	data = Data;
	count = 1;
	LeftChild = NULL;
	RightChild = NULL;
}

Node::~Node(){
  delete LeftChild;
  delete RightChild;
}

