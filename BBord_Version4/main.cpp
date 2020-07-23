#include <iostream>

using namespace std;

#include "BBoard.h"

int main(int argc, char *argv[]) {

   if (argc != 3) {
      cout << "Usage: " << argv[0] << " user_file data_file" << endl;
      return 1;
   }
   string userfile = argv[1];
   string datafile = argv[2];
   
   BBoard bb("CS12 Bulletin Board");
   
   // load users from file
   if (!bb.loadUsers(userfile)) {
      cout << "ERROR: Cannot load users from " << userfile << endl;
      return 1;
   }
   
   // load messages   
   if (!bb.loadMessages(datafile)) {
      cout << "ERROR: Cannot load messages from " << datafile << endl;
      return 1;
   }
   
   bb.login();
   bb.run();

   // save messages
   if (!bb.saveMessages(datafile)) {
      cout << "ERROR: Cannot save messages to " << datafile << endl;
      return 1;
   }

   return 0;
}
