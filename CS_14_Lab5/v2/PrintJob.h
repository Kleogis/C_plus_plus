//Created by Jayden Lui, Viktoriia Liu and Kevin Brewer
#ifndef __PRINTJOB_H
#define __PRINTJOB_H

#include <iostream>
using namespace std;

class PrintJob {
private:
  int priority;
  int jobNumber;
  int numPages;

public:
  PrintJob ( int, int, int);
  int getPriority ( );
  int getJobNumber ( );
  int getPages ( );
  //You can add additional functions here
};
#endif