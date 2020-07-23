#include <iostream>

using namespace std;

#include "IntVector.h"


//constractors
IntVector::IntVector(){
    sz = 0;
    cap = 0; 
    data = nullptr;
}

IntVector::IntVector(unsigned size){
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < sz; ++i){
        data[i] = 0;
    }
}

IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < sz; ++i){
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete [] data;    //destructor that deletes the dynamic array
}

unsigned IntVector::size() const{
    return sz;
}

unsigned IntVector::capacity() const{
    return cap;
}

bool IntVector::empty() const{
    if (sz == 0){
        return true;
    }
    else{
        return false;
    }
}
const int& IntVector::at(unsigned index) const{
    if( index >= sz) {  
        throw out_of_range("IntVector::at_range_check");
//        exit(1);
    }
    
    return data[index];     //returns the value at given index
}
    
const int & IntVector::front() const{
    return data[0];
}

const int & IntVector::back() const{
    return data[sz-1];
}
