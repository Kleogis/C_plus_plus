#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Message.h"

class Topic : public Message {
   
 // no new member variables
 public:

	//default constructor
	Topic();
	
	//Parameterized constructor
	Topic(const string &, 
	      const string &, 
	      const string &, 
	      unsigned);
	
	bool isReply() const;  // Returns false
	  
	/* to_formatted_string writes the contents of the Topic to a 
	* string in the following format:
	
	<begin_topic>
	:id: 4
	:subject: single line
	:from: author
	:children: 5 6 [this line should not be printed if there are no children.]
	:body: multiple lines - line 1
	line 2
	line 3
	<end>
	
	* line starting with :children: has the id's of all children 
	* (See file specifcations for details)
	* This function should not assume the last character in body is a newline.
	* In other words, this function must manually add a newline after the last    
	* line of the body (line 3 in the above example).
	* Also, the last character in the string must be a newline.
	*/
	string toFormattedString() const;  // New !!
//private:
    //void addTopic(); Asks the user to create a new Topic. Every Topic includes a subject and a body.
};

#endif