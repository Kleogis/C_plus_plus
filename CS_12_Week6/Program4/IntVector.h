#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
using namespace std;

class IntVector {
    public:
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
    
    // new functions
        int & at(unsigned index);  //done
        void insert(unsigned index, int value); //done
        void erase(unsigned index); //done
        int & front();     //done
        int & back();      //done
        void assign(unsigned n, int value);//done
        void push_back(int value); //done
        void pop_back();   //done
        void clear();      //done
        void resize(unsigned size, int value = 0); //done
        void reserve(unsigned n);

    private:
        unsigned sz;                      // stores the size of the IntVector (the number of elements currently being used).
        unsigned cap;                     // store the size of the array
        int *data;                        // stores the address of the dynamically-allocated array of integers
        void expand();                    // double the size of array
        void expand(unsigned amount);     // expands the size of array by amount
};


#endif