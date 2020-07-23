#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

#include "BBoard.h"
#include "Message.h"
#include "Topic.h"

Topic::Topic() : Message()
{}

Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned sz_list) : Message(athr, sbjct, body, sz_list)
{}

bool Topic::isReply() const{
    return false;
}

string Topic::toFormattedString() const{
    string formString;
    formString += "<begin_topic>\n";
    formString += Message::toFormattedString();
    return formString;
}