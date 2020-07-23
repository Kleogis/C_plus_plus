#include <iostream>
#include <string>

using namespace std;

#include "BBoard.h"

int main(int argc, char *argv[]) {
   
   string userfile = argv[1];
   
   BBoard bb("CS12 Bulletin Board");
   
   // load users from file
   if (!bb.loadUsers(userfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }
   if (!bb.login()) {
      cout << "Login not successful" << endl;
      return 1;
   }
   bb.run();

   return 0;
}
