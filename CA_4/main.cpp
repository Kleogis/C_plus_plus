#include <iostream>
#include <string>
#include "Jug.h"

using namespace std;

int main() {

  //Case #1
   string solution1;
   Jug head1(3, 5, 4, 1, 2, 3, 4, 5, 6);
   if (head1.solve(solution1) != 1) {
      cout << "Error 3" << endl;
   }
   cout << solution1 << endl << endl;

  //Case #2
   string solution2;
   Jug head2( 3, 5, 4, 1, 1, 1, 1, 1, 2);         
   if(head2.solve(solution2) != 1) {
      cout << "Error 3" << endl;
   }
   cout << solution2 << endl;

}