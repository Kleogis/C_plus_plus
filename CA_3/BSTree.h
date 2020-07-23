//Created by Viktoriia Liu, Jayden Lui and Kevin Brewer
#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"
#include<iostream>
#include<string>

using namespace std;

class BSTree {
    private:
        Node *root;
        void inOrder(Node *) const;
        void postOrder(Node *) const;
        void preOrder(Node *) const;
        void remove(Node* , Node* , string);
        bool search(const string &, Node *) const;
        Node* Find(const string &, Node* ) const;


    public:
        BSTree();
        ~BSTree();

        void insert(const string &);
        void remove(const string &);
        bool search(const string &) const;
        string largest() const;
        string smallest() const;
        int height(const string &) const;
        void preOrder() const;
        void postOrder() const;
        void inOrder() const;
};

#endif
