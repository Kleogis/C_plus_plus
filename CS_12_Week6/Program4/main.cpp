#include <iostream>
#include <string>
//#include <vector>
#include <cmath>
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
    cout << endl;
    
    // insert
    cout << "~~~~Testing Insert Function~~~~" << endl;
    Vec3.insert(3, 5);
    cout << "Insert 5 at index 3: " << Vec3 << endl;
    cout << "size: " << Vec3.size() << endl;
    cout << "capacity: " << Vec3.capacity() << endl;
    Vec3.insert(0, 14);
    cout <<"Insert 14 at index 0: " << Vec3 << endl;
    cout << "size: " << Vec3.size() << endl;
    cout << "capacity: " << Vec3.capacity() << endl;
    IntVector Vec8(3);
    Vec8.insert(3, 9);
    cout <<"Vec8: Insert 9 at index 3: " << Vec8 << endl;
    cout << "size: " << Vec8.size() << endl;
    cout << "capacity: " << Vec8.capacity() << endl;
    cout << endl;
    
    //push_back
    cout << "~~~~Testing Push_back Function~~~~" << endl;
    cout << "Vector 3 size: " << Vec3.size() << endl;
    cout << "Vector 3 capacity: " << Vec3.capacity() << endl;
    Vec3.push_back(65);
    cout <<"Vec3: Push_back 65: "<< Vec3 << endl;
    cout << "Vector 3 size: " << Vec3.size() << endl;
    cout << "Vector 3 capacity: " << Vec3.capacity() << endl;
    Vec3.push_back(75);
    cout <<"Vec3: Push_back 75: "<< Vec3 << endl;
    cout << "Vector 3 size: " << Vec3.size() << endl;
    cout << "Vector 3 capacity: " << Vec3.capacity() << endl;
    IntVector Vec7(3);
    Vec7.push_back(75);
    cout <<"Vec7: Push_back 75: "<< Vec7 << endl;
    cout << "Vector 7 size: " << Vec7.size() << endl;
    cout << "Vector 7 capacity: " << Vec7.capacity() << endl;
    cout << endl;
    
    //erase
    cout << "~~~~Testing Erase Function~~~~" << endl;
    IntVector Vec9(5);
    cout << "Vec9 size: " << Vec9.size() << endl;
    Vec9.erase(4);
    cout <<"Vec9: Erase index 4 : "<< Vec9 << endl;
    cout << "Vec 9 size: " << Vec9.size() << endl;
    cout << "Vector 9 capacity: " << Vec9.capacity() << endl;
    Vec9.erase(0);
    cout <<"Vec9: Erase index 0 : "<< Vec9 << endl;
    cout << "Vec 9 size: " << Vec9.size() << endl;
    cout << "Vector 9 capacity: " << Vec9.capacity() << endl;
//     Vec3.erase(20);
//     cout <<"Erase index 20 : "<< Vec3 << endl;
    cout << endl;
    
    //resize
    cout << "~~~~Testing Resize Function~~~~" << endl;
    IntVector Vec5(4, 2);
    cout << "Vector 5(4, 2): " << Vec5 << endl;
    cout << "Vector 5 (4, 2) size: " << Vec5.size() << endl;
    cout << "Vector 5 (4, 2) capacity: " << Vec5.capacity() << endl;
    Vec5.resize(7, 3);
    cout << "Vector 5.resize(7, 3): " << Vec5 << endl;
    cout << "Vector 5 (7, 3) size: " << Vec5.size() << endl;
    cout << "Vector 5 (7, 3) capacity: " << Vec5.capacity() << endl;
    Vec5.resize(20, 1);
    cout << "Vector 5.resize(20, 1): " << Vec5 << endl;
    cout << "Vector 5 (20, 1) size: " << Vec5.size() << endl;
    cout << "Vector 5 (20, 1) capacity: " << Vec5.capacity() << endl;
    cout << endl;
    
    //assign
    cout << "~~~~Testing Assign Function~~~~" << endl;
    IntVector Vec6(5, 1);
    cout << "Vector 6 (5, 1) size: " << Vec6.size() << endl;
    cout << "Vector 6 (5,1) capacity: " << Vec6.capacity() << endl;
    Vec6.assign(6, 0);
    cout << "Vector 6.assign(6, 0) size: " << Vec6.size() << endl;
    cout << "Vector 6.assign(6,0) capacity: " << Vec6.capacity() << endl;
    Vec6.assign(22, 3);
    cout << "Vector6.assign(22,3): " << Vec6 << endl;
    cout << "Vector 6 size: " << Vec6.size() << endl;
    cout << "Vector 6 capacity: " << Vec6.capacity() << endl;
    Vec6.assign(2, 8);
    cout << "Vector 6.assign(2, 8): " << Vec6 << endl;
    cout << "Vector 6 size: " << Vec6.size() << endl;
    cout << "Vector 6 capacity: " << Vec6.capacity() << endl;
    cout << endl;
    
    //reserve
    cout << "~~~~Testing Reserve Function~~~~" << endl;
    cout << "Vector 6 size: " << Vec6.size() << endl;
    cout << "Vector 6 capacity: " << Vec6.capacity() << endl;
    Vec6.reserve(100);
    cout << "Vector 6 capacity after reserve(100): " << Vec6.capacity() << endl;
    Vec6.reserve(20);
    cout << "Vector 6 capacity after reserve(20): " << Vec6.capacity() << endl;
    cout << endl;
   return 0;
}

