#include <iostream>
using namespace std;

#include "IntVector.h"

ostream& operator <<(ostream& out, const  IntVector& vec){
    for(unsigned i = 0; i < vec.size(); ++i){
        out << vec.at(i) << " ";
    }
    return out;
}

int main() {
   
    IntVector Vec1;
    cout << "Default constructor: size: " << Vec1.size() << endl;
    cout << "Default constructor: capacity: " << Vec1.capacity() << endl;
    cout << "Default constructor: is empty: " << Vec1.empty() << endl;
    
    IntVector Vec2(10, 2);
    cout << "Constructor: size: " << Vec2.size() << endl;
    cout << "Constructor: capacity: " << Vec2.capacity() << endl;
    cout << "Constructor: is empty: " << Vec2.empty() << endl;
    
    cout << "Vector value at index 2: " << Vec2.at(1) << endl;
//    cout << "Vector value at index 11: " << Vec2.at(11) << endl;
    cout << "Testing front: " << Vec2.front() << endl;
    cout << "Testing back: " << Vec2.back() << endl;
    
    IntVector Vec3(15);
    cout << "Default constructor: size: " << Vec3.size() << endl;
    cout << "Default constructor: capacity: " << Vec3.capacity() << endl;
    cout << "Default constructor: is empty: " << Vec3.empty() << endl;
    cout << "Testing front: " << Vec3.front() << endl;
    cout << "Testing back: " << Vec3.back() << endl;
   return 0;
}

