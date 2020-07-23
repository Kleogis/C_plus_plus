//Created by Viktoriia Liu, Jayden Lui and Kevin Brewer
#include "Node.h"
#include "BSTree.h"
#include<iostream>
#include<string>
using namespace std;

BSTree::BSTree() {
    root = NULL;
}

BSTree::~BSTree() {
    delete root;
}

bool BSTree::search(const string &key) const {
	bool Key_String_Present = search(key, root);
	return Key_String_Present;
}

bool BSTree::search(const string &key, Node *node) const {
	Node *curr = node;
	if (curr == NULL) {
		return false;
	}
	else if (key == curr->data) {
		return true;
	}
	else {
		if (curr->data < key) {
			return search(key, curr->RightChild);
		}
		else{
			return search(key, curr->LeftChild);
		}
	}
}

void BSTree::preOrder() const {
	preOrder(root);
	cout << endl;
}

void BSTree::preOrder(Node *curr) const {
	if(curr != 0) {
		cout << curr->data << '(' << curr->count << "), ";
		preOrder(curr->LeftChild);
		preOrder(curr->RightChild);
	}
}

void BSTree::inOrder() const {
	inOrder(root);
	cout << endl;
}

void BSTree::inOrder(Node *curr) const {
	if(curr != 0) {
		inOrder(curr->LeftChild);
		cout << curr->data << '(' << curr->count << "), ";
		inOrder(curr->RightChild);
	}
}

void BSTree::postOrder() const {
	postOrder(root);
	cout << endl;
}

void BSTree::postOrder(Node *curr) const {
	if(curr != 0) {
		postOrder(curr->LeftChild);
		postOrder(curr->RightChild);
		cout << curr->data << '(' << curr->count << "), ";
	}
}

int BSTree::height(const string &Data) const {
    if(!search(Data)) {
        return -1;
    }
    Node *curr = Find(Data, root);
    Node *currLeft = curr;
    Node *currRight = curr;
    int Left_Part = 0;
    int Right_Part = 0;
    
    if(curr->LeftChild != 0) {
        currLeft = currLeft->LeftChild;
        Left_Part = Left_Part +1;
        Left_Part = Left_Part + height(currLeft->data);
    }
    if(curr->RightChild != 0) {
        currRight = currRight->RightChild;
        Right_Part = Right_Part +1;
        Right_Part = Right_Part + height(currRight->data);
    }
    if(Left_Part >= Right_Part) {
        return Left_Part;
    }
    else {
        return Right_Part;
    }
}

string BSTree::smallest() const {
  Node* curr = root;  
  if(curr == NULL) {
    return "";
  }
  else {
    while (curr->LeftChild != NULL){
		  curr = curr->LeftChild;
	  }
   	return curr->data;
  }
}

string BSTree::largest() const {
  Node* curr = root;
	if (curr == NULL){
		return "";
  }
  else {
	  while (curr->RightChild != NULL){
		  curr = curr->RightChild;
	  }
    return curr->data;
  }
}

Node* BSTree::Find(const string &Data, Node* curr) const {
  if(curr != NULL) {
    if(Data == curr->data) {
      return curr;
    }
    else {
      if(Data < curr->data) {
        return Find(Data, curr->LeftChild);
      }
      else {
        return Find(Data, curr->RightChild);
      }
    }
  }
    else {
      return NULL;
    }
}

void BSTree::insert(const string& Data) {
    if(root == NULL) {
      root = new Node(Data);
      return;
    }
    Node* curr = root;
    while(curr != NULL) {
      if(curr->data == Data) {
        curr->count = curr->count + 1;
        return;
      }
      else if(curr->data < Data) {
        if(curr->RightChild == NULL) {
          curr->RightChild = new Node(Data);
          return;
        }
        else {
          curr = curr->RightChild;
        }
      }
      else { 
        if(curr->LeftChild == NULL) {
          curr->LeftChild= new Node(Data);
          return;
        }
          else {
          curr = curr->LeftChild;
          }
      }
    }
}

void BSTree::remove(const string& Data) {
  if(root == NULL){
    return;
}
    //call recursive
    remove(NULL, root, Data);
}

void BSTree::remove(Node* parent, Node* curr, string Data) {
    if(curr == NULL)
      return;

    if(curr->data < Data) {
        remove(curr, curr->RightChild, Data);
    }
    else if(curr->data > Data) {
        remove(curr, curr->LeftChild, Data);
    }
    else {
      //#1: count > 1
      if(curr->count > 1) {
        curr->count = curr->count - 1;
      }
      //#2: Node has no children
      else if(curr->LeftChild == NULL && curr->RightChild == NULL) {
        if(root == curr)
          root = NULL;
        else if(parent->RightChild == curr) {
          parent->RightChild = NULL;
        }
        else
          parent->LeftChild = NULL;
        }
        //#3: Node has NO left child
        else if(curr->LeftChild == NULL) {
          parent = curr;
          Node* node = curr->RightChild;
          while(node->LeftChild != NULL) {
            parent = node;
            node = node->LeftChild;
          }
          string temp_Str = node->data;
          int temp_Num = node->count;

          node->count = 1;
          remove(parent,node, node->data);
          curr->data = temp_Str;
          curr->count = temp_Num;
        }
        //#4: Node has a left child
        else {
            parent = curr;
            Node* node = curr->LeftChild;
            while(node->RightChild != NULL) {
              parent = node;
              node = node->RightChild;
            }
            string temp_Str = node->data;
            int temp_Num = node->count;
            node->count = 1;
            remove(parent,node, node->data);
            curr->data = temp_Str;
            curr->count = temp_Num;
        }
        return;
    }
}