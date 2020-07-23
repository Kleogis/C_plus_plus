#ifndef __BBOARD_H__
#define __BBOARD_H__

#include <string>
#include <vector>
using namespace std;

#include "BBoard.h"
#include "Message.h"
#include "Topic.h"
#include "User.h"
#include "Reply.h"

class BBoard {
 private:
   string title;
	vector<User> userList;
	const User * currentUser;
	vector<Message *> messageList;
 public:
	BBoard();
	BBoard(const string & ttl);
	~BBoard();
	bool loadUsers(const string & userfile);
	bool loadMessages(const string & datafile); //New
	bool saveMessages(const string & datafile); //New
	void login(); // Changed
	void run();
 private:
    void addTopic();
    void addReply();
    void display() const;
    bool userExists(const string &, const string &) const;
    
};

#endif