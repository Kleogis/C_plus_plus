#include <iostream>
#include "Node.h"
#include <string>

using namespace std;

class AVLTree {

public:
    AVLTree() {
        root = NULL;
    }
    void insert(const string &);
    int balanceFactor(Node*);
    void printBalanceFactors();
    void visualizeTree(const string &);

private:
    Node* root;
    Node* findUnbalancedNode(Node*);
    Node* rotateLeft(Node*);
    Node* rotateRight(Node*);
    void printBalanceFactors(Node*);
    void visualizeTree(ofstream &, Node*);
    int getHeight(Node*) const;
    void balance(Node*);
    void setBalanceFactors(Node*);
};