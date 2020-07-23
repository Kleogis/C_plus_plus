#include <string>
#include <iostream>

using namespace std;
#include "Message.h"

Message::Message(){
    author = "";
    subject = "";
    body = ""; 
    id = 0;
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned sz_list){
    author = athr;
    subject = sbjct;
    this->body = body; 
    id = sz_list;
}

//destructor
Message::~Message(){
//     //what are those 2 pointers???
//     for (unsigned i = 0; i < childList.size(); ++i)
//         delete childList.at(i);
}

string Message::toFormattedString() const{ //New
//    :id: 4
//    :subject: single line
//    :from: author
//    :children: 5 6 [this line should not be printed if there are no children.]
//    :body: multiple lines - line 1
    stringstream input;
    string msgString;
    input << ":id: " << id << endl;
    input << ":subject: " << subject << endl;
    input << ":from: " << author << endl;
    if(childList.size() != 0){
        input << ":children: ";
        for(unsigned i = 0; i < childList.size(); i++){
            input << (childList.at(i))->getID();
            if(i != childList.size() - 1){
            input << " ";
            }
        }
    input << endl;
    }
    input << ":body: " << body << endl;
    input << "<end>" << endl;
    msgString = input.str();
    return msgString;
}

void Message::print(unsigned ind) const{ // New !!
    string n;
    for (unsigned i = 0; i < ind; ++i){
        n += "  ";
    }
    if(ind != 0)
        cout << endl;
    cout << n << "Message #" << id << ": " << subject << endl;
    cout << n << "from " << author << ": ";
    for (unsigned j = 0; j < body.size(); j++){
        cout << body.at(j);
        if (body.at(j) == '\n'){
            cout << n;
        }
    }
    cout << endl;
    if (childList.size() != 0){
        for (unsigned k = 0; k < childList.size(); k++){
            childList.at(k)->print(ind + 1);
        }
    }
 }
     
unsigned Message::getID() const{ // New !!
    return id;
} 

// Adds a pointer to the child to the parent's child_list. 
void Message::addChild(Message * child){  // New !! 
    childList.push_back(child);
}

const string & Message::getSubject() const{
    return subject;
}

// string Message::Get_body() const{
//     return body;
// }

// string Message::Get_author() const{
//     return author;
// }