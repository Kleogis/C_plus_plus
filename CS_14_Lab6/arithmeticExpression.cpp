//Created by Viktoriia Liu, Jayden Lui and Kevin Brewer
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <sstream>
#include <string>
#include "arithmeticExpression.h"
using namespace std;
/* Initializes an empty tree and sets the infixExpression
   to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string &str) {
    infixExpression = str;
    root = 0;
}
/* Converts the infixExpression to its equivalent postfix string
      and then generates the tree and assigns the root node to the 
      root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree() {
    string postFix = infix_to_postfix();
    stack<TreeNode*> stac;
    TreeNode* currNode, *node1, *node2;
    char currChar;
    char key = 'a';
    for (unsigned int i = 0; i < postFix.length(); i++, key++){
        currChar = postFix[i];
        currNode = new TreeNode(currChar, key);
        if (priority(currChar) != 0) {
            node2 = stac.top();
            stac.pop();
            node1 = stac.top();
            stac.pop();
            currNode->left = node1;
            currNode->right = node2;
        }
        stac.push(currNode);
    }
    root = stac.top();
}
/* Calls the recursive infix function. */
void arithmeticExpression::infix() {
    infix(root);
}
/* Calls the recursive prefix function. */
void arithmeticExpression::prefix() {
    prefix(root);
}
/* Calls the recursive postfix function. */
void arithmeticExpression::postfix() {
    postfix(root);
}
/* Calls the recursive visualizeTree function and generates the .png file using system call. */
void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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
/* Helper function that returns an integer according to
      the priority of the given operator. */
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}
/* Helper function that returns the postfix notation equivalent
      to the given infix expression */
string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}
/* Helper function that outputs the infix notation of the arithmetic expression tree
      by performing the inorder traversal of the tree.
      An opening and closing parenthesis must be added at the 
      beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode *curr) {
    if (curr->left == 0 && curr->right == 0) { // If curr is a leaf node
      cout << curr->data;
    }
    else {
        cout << "(";
        infix(curr->left); // Recursive call on left branch
        cout << curr->data; // Prints root after the entire left branch is printed
        infix(curr->right); // Recursive call on right branch
        cout << ")";
    }
}
/* Helper function that outputs the prefix notation of the arithmetic expression tree
      by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode *curr) {
   if (curr->left == 0 && curr->right == 0) { // If curr is a leaf node
      cout << curr->data;
   }
   else {
      cout << curr->data; // Prints the root
      prefix(curr->left); // Recursive call on left branch
      prefix(curr->right); // Recursive call on right branch
   }
}
/* Helper function that outputs the postfix notation of the arithmetic expression tree
      by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode *curr) {
    if (curr->left == 0 && curr->right == 0) { // If curr is a leaf node
        cout << curr->data;
    }
    else {
        postfix(curr->left); // Recursive call on left branch
        postfix(curr->right); // Recursive call on right branch
        cout << curr->data; // Prints the root
    }
}
/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream &outFS, TreeNode *node) {
    if (node != 0) {
        outFS << node->key << "[ label = \"" << node->data << "\" ]" << endl;
        if (node->left != 0) {
            outFS << node->key << "->" << node->left->key << "[ label = \"" << node->left->data << "\" ]" << endl;
            visualizeTree(outFS, node->left); // Recursive call on left branch
        }
        if (node->right != 0) {
            outFS << node->key << "->" << node->right->key << "[ label = \"" << node->right->data << "\" ]" << endl;
            visualizeTree(outFS, node->right); // Recursive call on right branch
        }
        outFS << endl;
    }
}