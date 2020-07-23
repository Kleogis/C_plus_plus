#ifndef JOSEPHUSPROB_H
#define JOSEPHUSPROB_H

#include <iostream>
#include <string>
using namespace std;

struct JosephusNode {
	  string name;
	  JosephusNode *next;
    JosephusNode(string);
};

class JosephusList {
 private:
	  JosephusNode *head;
	  JosephusNode *tail;
 public:
  	JosephusList();
	  void add(string);
		void Lets_Play(int, string, int, int); 
};

#endif