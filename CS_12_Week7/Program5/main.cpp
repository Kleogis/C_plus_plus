#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pushfront 100" << endl;
      list1.push_front(100);
      cout << "pushfront 200" << endl;
      list1.push_front(200);
      cout << "pushfront 300" << endl;
      list1.push_front(300);
      cout << "list1: " << list1 << endl;
      cout << endl;
      cout << "Calling list1 destructor..." << endl;
   }
   cout << "list1 destructor returned" << endl;
   
   // Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
    
    //test push_back
    {
    cout << "List3 push_back testing: " << endl;
    IntList list3;
    list3.push_back(100);
    list3.push_back(5);
    list3.push_back(1000);
    cout << "list3: " << list3 << endl;
    
    //test sort algorithm
    list3.push_front(1);
    list3.push_front(200);
    list3.push_front(200);
    list3.push_front(900);
    cout << "List3 sorting algorithm: " << endl;
    list3.selection_sort();
    cout << "list3: " << list3 << endl;
    
    //test insert_ordered
    cout << "List3 insert ordered: " << endl;
    list3.insert_ordered(50);
    cout << "list3: " << list3 << endl;
    list3.insert_ordered(0);
    cout << "list3: " << list3 << endl;
    cout << "Empty list list4" << endl;
//    IntList list4;
//    list4.insert_ordered(20);
    
    list3.insert_ordered(1230);
//    cout << "list4: " << list4 << endl;
    cout << "list3: " << list3 << endl;
    cout << "Test remove duplicates" << endl;  
    list3.remove_duplicates();
    cout << "list3: " << list3 << endl;
    
    }
    
    

   
   return 0;
}
