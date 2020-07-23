#include <iostream>
using namespace std;

#include "BBoard.h"
#include "Message.h"
#include "Reply.h"

Reply::Reply() : Message()
{}

Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned sz_list) : Message(athr, (sbjct), body, sz_list)
{}

bool Reply::isReply() const{
    return true;
}

string Reply::toFormattedString() const{
    string formString;
    formString += "<begin_reply>\n";
    formString += Message::toFormattedString();
    return formString;   
}