#include <iostream>
#include <string>

using namespace std;

class Node {

public:
    Node(string);
    string data;
    Node* left;
    Node* right;
    Node* parent;
    int balanceFactor;
};