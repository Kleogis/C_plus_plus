#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#include "IntVector.h"


//constractors
IntVector::IntVector(){
    sz = 0;
    cap = 0; 
    data = 0;
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

void IntVector::expand(){
    int* tempo = new int[cap * 2];
    for( unsigned int i = 0; i < cap; i++ ) {
        tempo[i] = data[i];  //copies data from original to temporary array
    }
    delete [] data; // delete original
    data = tempo;    //assign the address of temp to data
    if (cap == 0){
        cap = 1;
    }
    else{
        cap = cap * 2;
    }
}

void IntVector::expand(unsigned amount){
    int* tempo = new int[cap + amount];
    for( unsigned int i = 0; i < cap; i++ ) {
        tempo[i] = data[i];  //copies data from original to temporary array
    }
    delete [] data; // delete original
    data = tempo;    //assign the address of temp to data
    cap = cap + amount;
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

int & IntVector::at(unsigned index){
if( index >= sz) {  
        throw out_of_range("IntVector::at_range_check");
    }
        return data[index];     //returns the value at given index
}

int & IntVector::front(){
    return data[0];
}

int & IntVector::back(){
    return data[sz-1];
}

void IntVector::clear(){
    sz = 0;
    return;
}

void IntVector::pop_back(){
    sz = sz - 1;
    return;
}

void IntVector::insert(unsigned index, int value){
    if (index > sz){
        throw out_of_range("IntVector::insert_range_check");
    }
    if (sz == 0){
        expand(1);
    }
    
    if (cap > sz){
        for(unsigned i = sz; i > index; --i){
            data[i] = data[i-1];
        }
        data[index] = value;
    }
    else if (cap <= sz){
        expand();
        for(unsigned i = sz; i > index; --i){
            data[i] = data[i-1];
        }
        data[index] = value;
    }
    sz = sz + 1;
    return;
}

void IntVector::push_back(int value){
    if (sz >= cap){
        expand();
    }
    else if (cap == 0){
        expand();
    }
    data[sz] = value;
    sz = sz + 1;
    return;
}

void IntVector::erase(unsigned index){
    if (index >= sz){
        throw out_of_range("IntVector::erase_range_check");
    }
    for(unsigned i = index; i < sz-1; ++i){
        data[i] = data[i+1];
    }
    sz = sz - 1;
    return;
}

void IntVector::resize(unsigned size, int value){
    if (size <= sz){
        sz = size;
    }
    else if (size > sz){
        if (size > cap * 2){
        expand(size - cap);
        }
        else if (size > cap && size < (cap * 2)){
        expand();
        }
    }
        
    for (unsigned i = sz; i < size; ++i){
        data[i] = value;
    }
    sz = size; 
    return;
}

void IntVector::assign(unsigned n, int value){

    delete [] data;
    data = new int[n];
    sz = n;
    if (n > cap * 2){
        expand(n - cap);
    }
    else if (n > cap && n < (cap * 2)){
        expand();
    }
    
    for (unsigned i = 0; i < n; ++i){
        data[i] = value;
    }
}

void IntVector::reserve(unsigned n){
    if (n > cap){
        cap = n;
    }
    else{
        return;
    }
    return;
}