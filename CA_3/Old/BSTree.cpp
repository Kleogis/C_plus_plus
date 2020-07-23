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

// void BSTree::insert( const string & Data) {
// 	if (Data == "\n") {
// 		cout << "Error: nullpointer";
// 		return;
// 	}
	
// 	Node *node = new Node(Data);

// 	if (root == NULL) {
// 		root = node;
// 		root->LeftChild = NULL;
// 		root->RightChild = NULL;
// 		root->count = root->count + 1;
// 	}
// 	else {
// 		Node *curr = root;
// 		while (curr != NULL) {
// 			if (node->data == curr->data) {
// 				curr->count = curr->count + 1;
// 				return;
// 			}

// 			if (node->data < curr->data) {
// 				if (curr->LeftChild == NULL) {
// 					curr->LeftChild = node;
// 					node->count = node->count + 1;
// 					curr = NULL;
// 				}
// 				else {
// 					curr = curr->LeftChild;
// 				}
// 			}

// 			else {
// 				if (node->data > curr->data) {
// 					if (curr->RightChild == NULL) {
// 						curr->RightChild = node;
// 						node->count = node->count + 1;
// 						curr = NULL;
// 					}
// 					else {
// 						curr = curr->RightChild;
// 					}
// 				}
// 			}
// 		}
// 	}
// }
//ZyBook BTS Insert Algorithm
// BSTInsert(tree, node) {
//  if (tree⇢root is null)
//    tree⇢root = node
//    node⇢left = null
//    node⇢right = null
//  else
//    cur = tree⇢root
//    while (cur is not null) 
//      if (node⇢key < cur⇢key)
//         if (cur⇢left is null)
//           cur⇢left = node
//           cur = null
//         else
//           cur = cur⇢left
//      else 
//         if (cur⇢right is null)
//           cur⇢right = node
//           cur = null
//         else
//           cur = cur⇢right       
//    node⇢left = null
//    node⇢right = null
// }

void BSTree::remove(const string &Data) {
    if(root->LeftChild == NULL && root->RightChild == NULL) {
        delete root;
        root = NULL;
        return;
    }
	remove(root, Data);
}

Node* BSTree::remove(Node* node, const string  &Data) {
	if (Data == "\n") {
		return root;
	}

	if (root == NULL) {
		return root;
	}

	if (Data < node->data) { 
		node->LeftChild = remove(node->LeftChild, Data);
	}
	else if (Data > node->data) {  
		node->RightChild = remove(node->RightChild, Data);
	}
	else {
		if (node->count > 1) {
			node->count = node->count - 1;
		}
		else if (node->LeftChild == NULL && node->RightChild == NULL) {
			if (root == node) {
				return root = NULL;
			}
			delete node;
			return 0;
		}
		else if (node->LeftChild == NULL) {
      Node* temp = node->RightChild;
      while(temp!=NULL) {
        temp = temp->RightChild;
      }
			node->data = temp->data;
			node->count = temp->count;
			temp->count = 0;

			node->RightChild = remove(node->RightChild, temp->data);
			return node;
		}
		else if (node->RightChild == NULL) {
			Node *temp1 = node->LeftChild;
      while(temp1!=NULL) {
        temp1 = temp1->LeftChild;
      }
			node->data = temp1->data;
			node->count = temp1->count;
			temp1->count = 0;
			node->LeftChild = remove(node->LeftChild, temp1->data);
			return node;
		}
		else {
			Node *temp2 = node->LeftChild;
      while(temp2!=NULL) {
        temp2 = temp2->LeftChild;
      }
			node->data = temp2->data;
			node->count = temp2->count;
			temp2->count = 1;
			node->LeftChild = remove(node->LeftChild, temp2->data);
		}
	}
	return node;
}

void BSTree::insert(const string& str) {
    if(root == nullptr) {
        root = new Node(str);
        return;
    }
    Node* curr = root;
    while(curr != nullptr) {
        if(curr->data == str) {
            curr->count = curr->count + 1;
            return;
        }
        else if(curr->data < str) {
            if(curr->RightChild == nullptr) {
                curr->RightChild = new Node(str);
                return;
            }
            else {
                curr = curr->RightChild;
            }
        }
        else { 
            if(curr->LeftChild == nullptr) {
                curr->LeftChild= new Node(str);
                return;
            }
            else {
                curr = curr->LeftChild;
            }
        }
    }
}