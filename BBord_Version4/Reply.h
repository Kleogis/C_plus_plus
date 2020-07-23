#ifndef __REPLY_H__
#define __REPLY_H__

#include "Message.h"

class Reply : public Message {

 public:
   //default constructor
   Reply();

   /* Parameterized constructor - similar to Message's constructor except:
    * The subject should be initialized to "Re: <sbjct>" not <sbjct>.
    */
   Reply(const string &, 
      const string &, 
      const string &, 
      unsigned);
 
   bool isReply() const; // Returns true
 
   /* to_formatted_string writes the contents of the Reply to a string in the 
    * following format:
    
   <begin_reply>
   :id: 4
   :subject: single line
   :from: author
   :children: 5 6 [this line should not be printed if there are no children.]
   :body: multiple lines
   2nd line
   <end>

   * the line starting with :children: has the list of id's of all children 
   * (See file specs. for details)
   * This function should not assume the last character in body is a newline.
   * In other words, this function must manually add a newline after the last 
   * line of the body (line 3 in this example).
   * Also, the last character in the string must be a newline.
   */
   string toFormattedString() const; // New !!
    //private:
    //void addReply(); Asks the user to enter a reply to a given Message (which may be either a Topic or a Reply, so we can habdle nested replies)
   
};

#endif