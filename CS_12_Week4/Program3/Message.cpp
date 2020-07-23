#include <string>
#include <iostream>

using namespace std;
#include "Message.h"

Message::Message(){
    author = "";
    subject = "";
    body = "";    
}

Message::Message(const string &athr, const string &sbjct, const string &body){
    author = athr;
    subject = sbjct;
    this->body = body; 
}

void Message::display() const{
//    cout << endl;
    cout << subject << endl;
    cout << "from " << Get_author()<< ": " << Get_body() << endl;
    return;
}

string Message::Get_author() const{
    return author;
}

string Message::Get_subject() const{
    return subject;
}

string Message::Get_body() const{
    return body;
}