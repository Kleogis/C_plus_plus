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

    private:
        unsigned sz;                      // stores the size of the IntVector (the number of elements currently being used).
        unsigned cap;                     // store the size of the array
        int *data;                        // stores the address of the dynamically-allocated array of integers
};


#endif
