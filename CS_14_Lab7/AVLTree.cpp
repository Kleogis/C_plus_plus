#include <iostream>
#include <string>
#include <fstream>
#include "AVLTree.h"

using namespace std;

//Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string & Word) {
  Node* newNode = new Node(Word);
	Node* curr = root;
	Node* Parent = NULL;
	
	if (root == NULL) {
		root = newNode;
		root->balanceFactor = -1;
		return;
	}
	
	while (curr != NULL) {
		Parent = curr;
		if (newNode->data == Parent->data) {
			return;
		}
		
		if (newNode->data < Parent->data) {
			curr = curr->left;
		}
		
		if (newNode->data >= Parent->data){
			curr = curr->right;
		}
	}
	
	if (newNode->data < Parent->data) {
		Parent->left = newNode;
		newNode->parent = Parent;
	}
	else if (newNode->data > Parent->data) {
		Parent->right = newNode;
		newNode->parent = Parent;
	}

	setBalanceFactors(root);
	balance(newNode);
}

//Return the balance factor of a given node.
int AVLTree::balanceFactor(Node* n) {
    int lHeight = 0;
    int rHeight = 0;

    if(n == NULL) {
        return -1;
    }
    if(n->left) {
        lHeight = getHeight(n->left);
    }
    else {
        lHeight = -1;
    }
    if(n->right) {
        rHeight = getHeight(n->right);
    }
    else {
        rHeight = -1;
    }
    return lHeight-rHeight;
}

//Traverse and print the tree in inorder notation. 
//Print the string followed by its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

//Given by zybooks
//Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

//Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
Node* AVLTree::findUnbalancedNode(Node* n) {
    Node* currNode = n;
    while (currNode != NULL) {
        if (balanceFactor(currNode) >= 2 || balanceFactor(currNode) <= -2) {
            return currNode;
        }
        else {
            currNode = currNode->parent;
        }
    }
    return NULL;
}

//Rotate the subtree to left at the given node and returns the new subroot.
Node* AVLTree::rotateLeft(Node* n) {
  Node* Parent = n->parent;
	Node* Child_R = n->right;
	Node* Child_L = Child_R->left;
	
	if (Parent == NULL) {
		root = Child_R;
	}
	else {
		if (Parent->data > n->data) {
			Parent->left = Child_R;
		}
		else if (Parent->data < n->data){
			Parent->right = Child_R;
		}
	}
	
	Child_R->left = n;
	n->right = Child_L;
	Child_R->parent = n->parent;
	n->parent = Child_R;
	
	return Child_R;

}

//Rotate the subtree to right at the given node and returns the new subroot.
Node* AVLTree::rotateRight(Node* n) {
  Node* Parent = n->parent;
	Node* Child_L = n->left;
	Node* Child_R = Child_L->right;
	
	if (Parent == NULL) {
		root = Child_L;
	}
	else {
		if (Parent->data > n->data) {
			Parent->left = Child_L;
		}
		else if (Parent->data < n->data){
			Parent->right = Child_L;
		}
	}
	
	Child_L->right = n;
	n->left = Child_R;
	Child_L->parent = n->parent;
	n->parent = Child_L;
	
	return Child_L;
}

//Prints the nodes in the correct format.
void AVLTree::printBalanceFactors(Node* n) {
    if (n != NULL) {
        printBalanceFactors(n->left);
        cout << n->data << "(" << balanceFactor(n) << "), ";
        printBalanceFactors(n->right);
    }
}

//Given by zybooks
void AVLTree::visualizeTree(ofstream & outFS, Node* n) {
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}

//Returns the height of node "n" recursively
int AVLTree::getHeight(Node* n) const {
    if (n == NULL) {
        return -1;
    }
    else if (n->left == NULL && n->right == NULL) {
        return 0;
    }

    int lHeight = getHeight(n->left);
    int rHeight = getHeight(n->right);

    if (lHeight > rHeight) {
        return lHeight + 1;
    }
    else {
        return rHeight + 1;
    }
    return 0;
}

//Assigns balance factors to nodes
void AVLTree::setBalanceFactors(Node* n) {
    if (n != NULL) {
        n->balanceFactor = balanceFactor(n);
        setBalanceFactors(n->left);
        setBalanceFactors(n->right);
    }
}

//If a node is unbalanced it rotates the tree, then setBalanceFactors
void AVLTree::balance(Node* n) {
	while (findUnbalancedNode(n) != NULL) {
		Node* Un_Node= findUnbalancedNode(n);
		int B_Factor = balanceFactor(Un_Node);
		int B_Factor_Left = balanceFactor(Un_Node->left);
		int B_Factor_Right = balanceFactor(Un_Node->right);
		
		if (B_Factor == -2 && B_Factor_Left == -1) {
			rotateLeft(Un_Node);
		}
		else if (B_Factor == 2 && B_Factor_Left == -1) {
			rotateLeft(Un_Node->left);
			rotateRight(Un_Node);
		}
		else if (B_Factor == 2 && B_Factor_Right == 1 ){
			rotateRight(Un_Node);
		}
		else {
			rotateRight(Un_Node->right);
			rotateLeft(Un_Node);
		}
		setBalanceFactors(root);
	}
}